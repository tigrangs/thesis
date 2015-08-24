#include "main_window.hpp"

#include <QGridLayout>
#include <QTableView>
#include <QComboBox>
#include <QLabel>
#include <QDockWidget>

main_window::main_window(QWidget *parent)
    : QMainWindow(parent)
    , m_view(0)
{
    m_view = new QTableView(this);
    setCentralWidget(m_view);
    QWidget* c_widget = new QWidget();
    QGridLayout* layout = new QGridLayout(c_widget);
    c_widget->setLayout(layout);
    QLabel* size_label = new QLabel("Matrix size:", c_widget);
    QComboBox* matrix_size = new QComboBox(c_widget);
//    matrix_size->addItems();
    layout->addWidget(size_label, 0, 0);
    layout->addWidget(matrix_size, 0, 1);
    QLabel* internal_size_label = new QLabel("Internal Matrix size:", c_widget);
    QComboBox* internal_matrix_size = new QComboBox(c_widget);
    layout->addWidget(internal_size_label, 1, 0);
    layout->addWidget(internal_matrix_size, 1, 1);
    QDockWidget* dock_widget = new QDockWidget("Options", this);
    dock_widget->setWidget(c_widget);
    addDockWidget(Qt::RightDockWidgetArea, dock_widget);
}
