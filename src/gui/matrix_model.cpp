#include "matrix_model.hpp"
#include "../core/matrix.hpp"

#include <QColor>
#include <QDebug>

#include <cassert>

matrix_model::matrix_model(QObject *parent)
    : QAbstractTableModel(parent)
    , m_data(0, 0)
{
}

void matrix_model::set_data(const analyzed_data& d)
{
    beginResetModel();
    m_data = d;
    endResetModel();
}

int matrix_model::rowCount(const QModelIndex&) const
{
    assert(m_data.get_matrix() != 0);
    return m_data.get_matrix()->get_height();
}

int matrix_model::columnCount(const QModelIndex&) const
{
    assert(m_data.get_matrix() != 0);
    return m_data.get_matrix()->get_width();
}

QVariant matrix_model::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }
    if (role == Qt::DisplayRole) {
        assert(m_data.get_matrix() != 0);
        return QVariant(m_data.get_matrix()->get_value(index.row(), index.column()));
    }
    if (role == Qt::BackgroundRole) {
        int max_value = 0;
        unsigned tx = 0, ty = 0, bx = 0, by = 0;
        m_data.get_max_data(tx, ty, bx, by, max_value);
        if (index.row() - 1 <= by && index.row() - 1 >= ty && index.column() - 1 <= bx && index.column() - 1 >= tx) {
            return QVariant(QColor(Qt::red));
        }
    }
    if (role == Qt::ToolTipRole) {
        int max_value = 0;
        unsigned tx = 0, ty = 0, bx = 0, by = 0;
        m_data.get_max_data(tx, ty, bx, by, max_value);
        if (index.row() - 1 <= by && index.row() - 1 >= ty && index.column() - 1 <= bx && index.column() - 1 >= tx) {
            return QVariant(max_value);
        }
    }
    return QVariant();
}

QModelIndex matrix_model::parent(const QModelIndex&) const
{
    return QModelIndex();
}
