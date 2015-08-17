#ifndef SORTED_MATRIX_HPP
#define SORTED_MATRIX_HPP

#include "matrix.hpp"

#include <vector>

class sorted_matrix : public matrix
{
public:
    sorted_matrix(unsigned size);

public:
    void fill_with_sorting(unsigned size, int begin, int end);

private:
    virtual void fill_matrix(ints&);

private:
    void fill_parts(unsigned top_left_x, unsigned top_left_y,
                    unsigned bottom_right_x, unsigned bottom_right_y,
                    const std::vector<int>&, unsigned begin);

private:
    unsigned m_internal_size;

};

#endif // SORTED_MATRIX_HPP
