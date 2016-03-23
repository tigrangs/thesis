#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

class QComboBox;
class QLineEdit;
class QTableView;

class matrix_model;

class main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit main_window(QWidget *parent = 0);

private:
    void init();

private slots:
    void run_analize();
    void clear();
    void change_current_matrix(QString);

private:
    QTableView* m_view;
    QLineEdit* m_matrix_size;
    QLineEdit* m_internal_matrix_size;
    QLineEdit* m_data_begin;
    QLineEdit* m_data_end;
    QLineEdit* m_matrix_number;
    QWidget* m_matrix_id;
    QComboBox* m_matrix_combo;
    matrix_model* m_model;
};

#endif // MAIN_WINDOW_HPP
