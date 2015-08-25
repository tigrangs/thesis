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
    int max_val = 0;
    unsigned tx = 0, ty = 0, bx = 0, by = 0;
    for (unsigned i = 0; i < m->get_height() - sub_matrixes_size; ++i) {
        for (unsigned j = 0; j < m->get_width() - sub_matrixes_size; ++j) {
            int sum_val = 0;
            for (unsigned k = i ; k < i + sub_matrixes_size; ++k) {
                for (unsigned p = j; p < j + sub_matrixes_size; ++p) {
                        sum_val += m->get_value(k, p);
                }
            }
            data.add_data(j, i, j + sub_matrixes_size - 1, i + sub_matrixes_size - 1, sum_val);
            if (sum_val > max_val) {
                max_val = sum_val;
                ty = i;
                tx = j;
                by = i + sub_matrixes_size - 1;
                bx = j + sub_matrixes_size - 1;
            }
        }
    }
    data.set_max_data(tx, ty, bx, by, max_val);
    return data;
}
