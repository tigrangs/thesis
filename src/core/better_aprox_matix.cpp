#include "better_aprox_matix.hpp"
#include "rundom_number_generator.hpp"

#include <algorithm>
#include <cassert>
#include <vector>
#include <iostream>

better_aprox_matrix::better_aprox_matrix(unsigned size)
        : matrix(size, size)
        , m_internal_size(0)
{}

void better_aprox_matrix::fill(unsigned size, int begin, int end)
{
    assert(size < get_width());
    assert(begin < end);
    m_internal_size = size;
    assert(get_width() == get_height());
    assert(get_width() % size == 0);
    typedef rundom_number_generator RND;
    RND* rnd = RND::get_instance();
    assert(rnd != 0);
    std::vector<int> numbers(get_width() * get_height());
    for (unsigned i = 0; i < numbers.size(); ++i) {
        numbers[i] = rnd->get_number(begin, end);
    }
    std::sort(numbers.begin(), numbers.end(), std::greater<int>());
    fill_matrix(numbers);
}

void better_aprox_matrix::fill_matrix(ints &numbers)
{
    assert(m_internal_size != 0);
    /*unsigned data_begin = 0;
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
            fill_parts(i, j, bx, by, numbers, data_begin / 2);
            data_begin += (bx - i)  * (by - j);
        }
    }*/
    fill_parts(0, 0, get_width(), get_height(), numbers);
}

void better_aprox_matrix::fill_parts(unsigned top_left_x, unsigned top_left_y,
                               unsigned bottom_right_x, unsigned bottom_right_y,
                               const std::vector<int> & data)
{
    if (data.size() <= m_internal_size * m_internal_size) {
        fill_single_matrix(top_left_x, top_left_y, bottom_right_x, bottom_right_y, data);
        return;
    }
    std::vector<int> d(data.size()/4);
    std::copy_n(data.begin(), data.size() / 4, d.begin());
    fill_parts(top_left_x, top_left_y, bottom_right_x / 2, bottom_right_y / 2, d);
    d.clear();
    ints::const_iterator b = data.begin();
    ints::const_iterator e = data.begin();
    std::advance(b, data.size() / 4 + 1);
    std::advance(e, data.size() / 2 + 1);
    std::copy(b, e, d.begin());
    fill_parts(bottom_right_x / 2 + 1, top_left_y, bottom_right_x, bottom_right_y / 2, d);
    d.clear();
    std::copy(data.begin() + data.size() / 2, data.begin() + 3 * data.size() / 4, d.begin());
    fill_parts(top_left_x, top_left_y / 2, bottom_right_x / 2, bottom_right_y, d);
    d.clear();
    std::copy(data.begin() + 3 * data.size() / 4, data.end(), d.begin());
    fill_parts(bottom_right_x /2, top_left_y / 2, bottom_right_x, bottom_right_y, d);
}

void better_aprox_matrix::fill_single_matrix(unsigned top_left_x, unsigned top_left_y,
                                             unsigned bottom_right_x, unsigned bottom_right_y,
                                             const std::vector<int>& data)
{
    unsigned b_count = 0, e_count = 0; // TODO colculate real values
    bool is_from_begin = true;
    for (unsigned j = top_left_y; j < bottom_right_y; ++j) {
        for (unsigned i = top_left_x; i < bottom_right_x; ++i) {
            set_value(i, j, is_from_begin ? data[b_count] : data[data.size() - 1 - e_count]);
            if (is_from_begin) {
                ++b_count;
            } else {
                ++e_count;
            }
            is_from_begin = !is_from_begin;
        }
    }
}
