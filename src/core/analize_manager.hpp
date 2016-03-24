#ifndef ANALIZE_MANAGER_HPP
#define ANALIZE_MANAGER_HPP

#include "analyzed_data.hpp"

#include <vector>

class analize_manager
{
public:
    enum mode {
        sorted = 0,
        evenly = 1
    };

public:
    void set_mode(mode m);

public:
    static analize_manager* get_instance();

public:
    void set_internal_matrix_size(unsigned);

public:
    void set_matrix_size(unsigned, unsigned);

public:
    void set_matrix_count(unsigned);

public:
    void set_value_range(int begin, int end);

public:
    void run();

public:
    typedef std::vector<analyzed_data> data;

    const data& get_analized_data() const;

private:
    matrix* create_sorted_matrix();
    matrix* create_evenly_matrix();

private:
    analize_manager();
    analize_manager(const analize_manager&);
    analize_manager& operator=(const analize_manager &);

private:
    unsigned m_matrix_count;
    unsigned m_internal_matrix_size;
    std::pair<unsigned,unsigned> m_matrix_size;
    std::pair<int, int> m_value_range;
    data m_data;
    mode m_mode;
};

#endif // ANALIZE_MANAGER_HPP
