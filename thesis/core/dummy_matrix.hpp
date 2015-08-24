#ifndef DUMMY_MATRIX
#define DUMMY_MATRIX

#include "matrix.hpp"
#include "rundom_number_generator.hpp"

#include <cassert>

class dummy_matrix : public matrix
{
public:
    dummy_matrix(unsigned size)
            : matrix(size, size)
    {}

public:
    virtual void fill_matrix(int begin, int end)
    {
        typedef rundom_number_generator RND;
        RND* rnd = RND::get_instance();
        assert(rnd != 0);
        for (unsigned i = 0; i < get_height(); ++i) {
            for (unsigned j = 0; j < get_width(); ++j) {
                set_value(i, j, rnd->get_number(begin, end));
            }
        }
    }

};

#endif // DUMMY_MATRIX
