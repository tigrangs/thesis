#include "main_window.hpp"
#include "matrix_model.hpp"
#include "../core/analize_manager.hpp"

#include <QGridLayout>
#include <QTableView>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
#include <QDockWidget>
#include <QPushButton>
#include <QIntValidator>
#include <QHeaderView>
#include <QStringList>

#include <cassert>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , m_view(0)
    , m_matrix_size(0)
    , m_internal_matrix_size(0)
    , m_data_begin(0)
    , m_data_end(0)
    , m_matrix_number(0)
    , m_matrix_id(0)
    , m_model(0)
    , m_matrix_combo(0)
{
    init();
}

void main_window::init()
{
    m_view = new QTableView(this);
    setCentralWidget(m_view);
    QWidget* c_widget = new QWidget();
    QGridLayout* layout = new QGridLayout(c_widget);
    c_widget->setLayout(layout);
    QLabel* size_label = new QLabel("Matrix size:", c_widget);
    QLineEdit* matrix_size = new QLineEdit(c_widget);
    matrix_size->setValidator(new QIntValidator(matrix_size));
    layout->addWidget(size_label, 0, 0);
    layout->addWidget(matrix_size, 0, 1);
    QLabel* internal_size_label = new QLabel("Internal Matrix size:", c_widget);
    QLineEdit* internal_matrix_size = new QLineEdit(c_widget);
    internal_matrix_size->setValidator(new QIntValidator(internal_matrix_size));
    layout->addWidget(internal_size_label, 1, 0);
    layout->addWidget(internal_matrix_size, 1, 1);
    QLabel* matrix_number_label = new QLabel("Matrix numbers:", c_widget);
    QLineEdit* matrix_number = new QLineEdit(c_widget);
    matrix_number->setValidator(new QIntValidator(matrix_number));
    layout->addWidget(matrix_number_label, 2, 0);
    layout->addWidget(matrix_number, 2, 1);
    QLabel* data_range_label = new QLabel("Data range:", c_widget);
    QLineEdit* data_begin = new QLineEdit(c_widget);
    QLineEdit* data_end = new QLineEdit(c_widget);
    data_begin->setValidator(new QIntValidator(data_begin));
    data_end->setValidator(new QIntValidator(data_end));
    layout->addWidget(data_range_label, 3, 0);
    layout->addWidget(data_begin, 3, 1);
    layout->addWidget(data_end, 3, 2);
    QPushButton* run_button = new QPushButton("Run", c_widget);
    layout->addWidget(run_button, 4, 0, 1, 3);
    connect(run_button, SIGNAL(pressed()), this, SLOT(run_analize()));
    QPushButton* clear_button = new QPushButton("Clear", c_widget);
    layout->addWidget(clear_button, 5, 0, 1, 3);
    connect(clear_button, SIGNAL(pressed()), this, SLOT(clear()));
    m_matrix_id = new QWidget(c_widget);
    QHBoxLayout* l = new QHBoxLayout(m_matrix_id);
    m_matrix_id->setLayout(l);
    QLabel* matrix_id_label = new QLabel("Generated matrix ID:", m_matrix_id);
    l->addWidget(matrix_id_label);
    QComboBox* matrix_id = new QComboBox(c_widget);
    connect(matrix_id, SIGNAL(editTextChanged(QString)), this, SLOT(change_current_matrix(QString)));
    matrix_id->setEditable(true);
    matrix_id->setValidator(new QIntValidator(m_matrix_id));
    l->addWidget(matrix_id);
    m_matrix_combo = matrix_id;
    l->setMargin(0);
    layout->addWidget(m_matrix_id, 6, 0, 1, 3);
    m_matrix_id->setVisible(false);
    QDockWidget* dock_widget = new QDockWidget("Options", this);
    dock_widget->setWidget(c_widget);
    addDockWidget(Qt::TopDockWidgetArea, dock_widget);
    m_internal_matrix_size = internal_matrix_size;
    m_matrix_size = matrix_size;
    m_data_begin = data_begin;
    m_data_end = data_end;
    m_matrix_number = matrix_number;
}

int get_number(const QLineEdit* e)
{
    assert(e != 0);
    return e->text().toInt();
}

void main_window::run_analize()
{
    typedef analize_manager AM;
    AM* am = AM::get_instance();
    am->set_internal_matrix_size(get_number(m_internal_matrix_size));
    am->set_matrix_count(get_number(m_matrix_number));
    am->set_matrix_size(get_number(m_matrix_size), get_number(m_matrix_size));
    am->set_value_range(get_number(m_data_begin), get_number(m_data_end));
    am->run();
    assert(m_view != 0);
    matrix_model* m = new matrix_model(m_view);
    m_model = m;
    m->set_data(*(am->get_analized_data().begin()));
    m_view->setModel(m);
    assert(m_matrix_id != 0);
    m_matrix_id->setVisible(true);
    QStringList l;
    int max_num = get_number(m_matrix_number);
    for (int i = 0; i < max_num; ++i) {
        l.push_back(QString::number(i));
    }
    m_matrix_combo->insertItems(0, l);
}

void main_window::change_current_matrix(QString d)
{
    typedef analize_manager AM;
    AM* am = AM::get_instance();
    if (d.toInt() < get_number(m_matrix_number))
    m_model->set_data((am->get_analized_data())[d.toInt()]);
}

void main_window::clear()
{

}

