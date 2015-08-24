#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <vector>

class matrix
{
public:
    matrix(unsigned n, unsigned m);
    virtual ~matrix();

public:
    unsigned get_width() const;
    unsigned get_height() const;

public:
    int get_value(unsigned i, unsigned j) const;

public:
    void print();
    void clear();

private:
    void init();

protected:
    typedef std::vector<int> ints;
    virtual void fill_matrix(ints&) = 0;

protected:
    void set_value(unsigned i, unsigned j, int v);

private:
    int** m_matrix;
    unsigned m_width;
    unsigned m_height;

private:
    matrix(const matrix&);
    matrix& operator=(const matrix&);
};

#endif // MATRIX_HPP
