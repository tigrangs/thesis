#ifndef MATRIX_MODEL_H
#define MATRIX_MODEL_H

#include <QAbstractTableModel>

#include "../core/analyzed_data.hpp"

class matrix_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit matrix_model(QObject *parent = 0);

public:
    void set_data(const analyzed_data& m);

public:
    virtual int columnCount(const QModelIndex & = QModelIndex()) const;
    virtual QVariant data(const QModelIndex & index, int role = Qt::DisplayRole) const;
    virtual QModelIndex parent(const QModelIndex &) const;
    virtual int rowCount(const QModelIndex & = QModelIndex()) const;

private:
    analyzed_data m_data;
};

#endif // MATRIX_MODEL_H
