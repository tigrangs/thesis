#ifndef MATRIX_ANALIZER_HPP
#define MATRIX_ANALIZER_HPP

#include "analyzed_data.hpp"

class matrix;

class matrix_analyzer
{
public:
    static matrix_analyzer* get_instance();

private:
    explicit matrix_analyzer();
    matrix_analyzer(const matrix_analyzer&);
    matrix_analyzer& operator=(const matrix_analyzer&);

public:
   analyzed_data analyze(const matrix* m, const unsigned sub_matrixes_size);
};

#endif // MATRIX_ANALIZER_HPP
