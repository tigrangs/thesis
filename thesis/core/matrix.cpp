#include "matrix.hpp"

#include <cassert>
#include <iostream>

matrix::matrix(unsigned n, unsigned m)
        : m_matrix(0)
        , m_width(m)
        , m_height(n)
{
    init();
}

void matrix::init()
{
    assert(m_matrix == 0);
    m_matrix = new int*[m_height];
    for (unsigned i = 0; i < m_height; ++i) {
        m_matrix[i] = new int[m_width];
    }
    clear();
}

void matrix::clear()
{
    assert(m_matrix != 0);
    for (unsigned i = 0; i < m_height; ++i) {
        for (unsigned j = 0; j < m_width; ++j) {
            m_matrix[i][j] = 0;
        }
    }
}

void matrix::print()
{
    assert(m_matrix != 0);
    std::cout<<std::endl;
    for (unsigned i = 0; i < m_height; ++i) {
        for (unsigned j = 0; j < m_width; ++j) {
            std::cout<<m_matrix[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

unsigned matrix::get_width() const
{
    return m_width;
}

unsigned matrix::get_height() const
{
    return m_height;
}

void matrix::set_value(unsigned i, unsigned j, int v)
{
    assert(m_matrix != 0);
    assert(i < get_height());
    assert(j < get_width());
    m_matrix[i][j] = v;
}

int matrix::get_value(unsigned i, unsigned j) const
{
    assert(m_matrix != 0);
    assert(i < get_height());
    assert(j < get_width());
    return m_matrix[i][j];
}

matrix::~matrix()
{
    for (unsigned i = 0; i < m_height; ++i) {
        delete[] m_matrix[i];
    }
    delete[] m_matrix;
}
