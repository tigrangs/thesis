#ifndef MAIN_WINDOW_HPP
#define MAIN_WINDOW_HPP

#include <QMainWindow>

class QTableView;

class main_window : public QMainWindow
{
    Q_OBJECT
public:
    explicit main_window(QWidget *parent = 0);

private:
    QTableView* m_view;

};

#endif // MAIN_WINDOW_HPP
