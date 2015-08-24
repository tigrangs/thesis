#include "analyzed_data.hpp"

#include "matrix.hpp"

#include <cassert>
#include <iostream>

analyzed_data::analyzed_data(const matrix *m, unsigned step)
    : m_matrix(m)
    , m_step(step)
{
    assert(m != 0);
}

analyzed_data::analyzed_data(const analyzed_data & d)
{
    assert(d.m_matrix != 0);
    m_matrix = d.m_matrix;
    m_data = d.m_data;
    m_step = d.m_step;
}

analyzed_data& analyzed_data::operator=(const analyzed_data& d)
{
    assert(d.m_matrix != 0);
    m_matrix = d.m_matrix;
    m_data = d.m_data;
    m_step = d.m_step;
    return *this;
}

const matrix* analyzed_data::get_matrix() const
{
    return m_matrix;
}

void analyzed_data::add_data(unsigned tx, unsigned ty, unsigned bx, unsigned by, int value)
{
    assert(m_matrix != 0);
    assert(tx < m_matrix->get_width());
    assert(ty < m_matrix->get_height());
    assert(bx < m_matrix->get_width());
    assert(by < m_matrix->get_height());
    coordinates c = {tx, ty, bx, by};
    m_data[c] = value;
}

bool analyzed_data::coordinates::operator<(const analyzed_data::coordinates& b) const
{
    if (m_top_left_x < b.m_top_left_x) {
        return true;
    }
    if (m_top_left_x == b.m_top_left_x && m_top_left_y < b.m_top_left_y) {
        return true;
    }
    return false;
}

int analyzed_data::get_data(unsigned tx, unsigned ty, unsigned bx, unsigned by) const
{
    assert(m_matrix != 0);
    assert(tx < m_matrix->get_width());
    assert(ty < m_matrix->get_height());
    assert(bx < m_matrix->get_width());
    assert(by < m_matrix->get_height());
    coordinates c = {tx, ty, bx, by};
    return m_data.at(c);
}

void analyzed_data::print() const
{
    assert(m_matrix != 0);
    for (unsigned i = 0; i < m_matrix->get_height() - m_step; ++i) {
        for (unsigned j = 0; j < m_matrix->get_width() - m_step; ++j) {
            std::cout<<j<<" "<<i<<std::endl;
            std::cout<<j+m_step - 1<<" "<<i+m_step - 1<<std::endl;
            std::cout<<get_data(j, i, j + m_step - 1, i + m_step - 1)<<std::endl;
        }
    }
}
