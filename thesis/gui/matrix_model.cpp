#include "matrix_model.hpp"

#include <cassert>

matrix_model::matrix_model(QObject *parent)
    : QAbstractTableModel(parent)
    , m_matrix(0)
{
}

void matrix_model::set_matrix(const matrix *m)
{
    assert(m != 0);
    beginResetModel();
    m_matrix = m;
    endResetModel();
}

int matrix_model::rowCount(const QModelIndex&) const
{
    assert(m_matrix != 0);
    return m_matrix->get_height();
}

int matrix_model::columnCount(const QModelIndex&) const
{
    assert(m_matrix != 0);
    return m_matrix->get_width();
}

QVariant matrix_model::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole) {
        assert(m_matrix != 0);
        return QVariant(m_matrix->get_value(index.row(), index.column()));
    }
    return QVariant();
}

QModelIndex matrix_model::parent(const QModelIndex&) const
{
    return QModelIndex();
}
