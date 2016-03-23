#include "evenly_destributed.hpp"

evenly_destributed::evenly_destributed(unsigned size)
    : matrix(size, size)
{}

void evenly_destributed::fill(int size, int begin, int end)
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

void evenly_destributed::fill_matrix(ints &numbers)
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
            data_begin += (bx - i)  * (by - j); // TODO
        }
    }
}

void evenly_destributed::fill_parts(unsigned top_left_x, unsigned top_left_y,
                               unsigned bottom_right_x, unsigned bottom_right_y,
                               const std::vector<int> & data, unsigned begin)
{
    unsigned count = 0; // TODO colculate real values
    for (unsigned j = top_left_y; j < bottom_right_y; ++j) {
        for (unsigned i = top_left_x; i < bottom_right_x; ++i) {
            set_value(i, j, data[begin + count]);
            ++count;
        }
    }
}
