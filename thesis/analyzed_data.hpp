#ifndef ANALYZED_DATA_HPP
#define ANALYZED_DATA_HPP

#include <map>

class matrix;

class analyzed_data
{
public:
    analyzed_data(const matrix* m, unsigned step);
    analyzed_data(const analyzed_data&);
    analyzed_data& operator=(const analyzed_data&);

public:
    const matrix* get_matrix() const;

public:
    void print() const;

public:
    void add_data(unsigned, unsigned, unsigned, unsigned, int);

public:
    int get_data(unsigned, unsigned, unsigned, unsigned) const;

private:
    struct coordinates
    {
    public:
        bool operator<(const coordinates&) const;

    public:
        unsigned m_top_left_x;
        unsigned m_top_left_y;
        unsigned m_bottom_right_x;
        unsigned m_bottom_right_y;
    };

private:
    const matrix* m_matrix;
    unsigned m_step;
    std::map<coordinates, int> m_data;
};

#endif // ANALYZED_DATA_HPP
