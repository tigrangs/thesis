#include "sorted_matrix.hpp"
#include "rundom_number_generator.hpp"

#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

sorted_matrix::sorted_matrix(unsigned size)
        : matrix(size, size)
        , m_internal_size(0)
{}

void sorted_matrix::fill_with_sorting(unsigned size, int begin, int end)
{
    assert(size < get_width());
    assert(begin < end);
    m_internal_size = size;
    assert(get_width() == get_height());
    typedef rundom_number_generator RND;
    RND* rnd = RND::get_instance();
    assert(rnd != 0);
    std::vector<int> numbers(get_width() * get_height());
    for (unsigned i = 0; i < numbers.size(); ++i) {
        numbers[i] = rnd->get_number(begin, end);
    }
    std::sort(numbers.begin(), numbers.end());
    fill_matrix(numbers);
}

void sorted_matrix::fill_matrix(ints &numbers)
{
    assert(m_internal_size != 0);
    unsigned data_begin = 0;
    for (unsigned i = 0; i < get_width(); i += m_internal_size) {
        for (unsigned j = 0; j < get_height(); j += m_internal_size) {
            unsigned bx = i + m_internal_size;
            unsigned by = j + m_internal_size;
            if (bx > get_width()) {
                bx = get_width();
            }
            if (by > get_height()) {
                by = get_height();
            }
            fill_parts(i, j, bx, by, numbers, data_begin);
            data_begin += (bx - i)  * (by - j);
        }
    }
}


void sorted_matrix::fill_parts(unsigned top_left_x, unsigned top_left_y,
                               unsigned bottom_right_x, unsigned bottom_right_y,
                               const std::vector<int> & data, unsigned begin)
{
    unsigned count = 0;
    for (unsigned j = top_left_y; j < bottom_right_y; ++j) {
        for (unsigned i = top_left_x; i < bottom_right_x; ++i) {
            set_value(i, j, data[begin + count]);
            ++count;
        }
    }
}
