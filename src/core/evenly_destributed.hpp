#ifndef EVENLY_DESTRIBUTED_HPP
#define EVENLY_DESTRIBUTED_HPP

#include "matrix.hpp"

class evenly_destributed : public matrix
{
public:
    evenly_destributed(unsigned size);

private:
    virtual void fill_matrix(ints&);

public:
    void fill(unsigned size, int begin, int end);

private:
    void fill_parts(unsigned top_left_x, unsigned top_left_y,
                    unsigned bottom_right_x, unsigned bottom_right_y,
                    const std::vector<int>&, unsigned begin);

private:
    unsigned m_internal_size;
};

#endif // EVENLY_DESTRIBUTED_HPP
