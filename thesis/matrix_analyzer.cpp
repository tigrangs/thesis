#include "matrix_analyzer.hpp"
#include "matrix.hpp"

#include <cassert>

matrix_analyzer::matrix_analyzer()
{
}

matrix_analyzer* matrix_analyzer::get_instance()
{
    static matrix_analyzer* instance = new matrix_analyzer();
    return instance;
}

analyzed_data matrix_analyzer::analyze(const matrix *m, const unsigned sub_matrixes_size)
{
    assert(m != 0);
    analyzed_data data(m, sub_matrixes_size);
    for (unsigned i = 0; i < m->get_height() - sub_matrixes_size; ++i) {
        for (unsigned j = 0; j < m->get_width() - sub_matrixes_size; ++j) {
            int sum_val = 0;
            for (unsigned k = i ; k < i + sub_matrixes_size; ++k) {
                for (unsigned p = j; p < j + sub_matrixes_size; ++p) {
                        sum_val += m->get_value(k, p);
                }
            }
            data.add_data(j, i, j + sub_matrixes_size - 1, i + sub_matrixes_size - 1, sum_val);
        }
    }
    return data;
}
