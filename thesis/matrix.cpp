#include "matrix.hpp"

#include <cassert>
#include <iostream>

matrix::matrix(unsigned n, unsigned m)
	: m_width(m)
	, m_hight(n)
	, m_matrix(0)
{
	init();
}

void matrix::init()
{
	assert(m_matrix == 0);
	m_matrix = new int*[m_hight];
	for (unsigned i = 0; i < m_hight; ++i) {
		m_matrix[i] = new int[m_width];
	}
	clear();
}

void matrix::clear()
{
	assert(m_matrix == 0);
	for (unsigned i = 0; i < m_hight; ++i) {
		for (unsigned j = 0; j < m_width; ++j) {
			m_matrix[i][j] = 0;
		}
	}
}

void matrix::print()
{
	assert(m_matrix != 0);
	std::cout<<std::endl;
	for (unsigned i = 0; i < m_hight; ++i) {
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

unsigned matrix::get_hight() const
{
	return m_hight;
}

void matrix::set_value(unsigned i, unsigned j, int v)
{
	assert(m_matrix != 0);
	assert(i < get_hight());
	assert(j < get_width());
	m_matrix[i][j] = v;
}

matrix::~matrix()
{
	for (unsigned i = 0; i < m_hight; ++i) {
		delete[] m_matrix[i];
	}
	delete[] m_matrix;
}
