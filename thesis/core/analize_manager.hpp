#ifndef ANALIZE_MANAGER_HPP
#define ANALIZE_MANAGER_HPP

#include "analyzed_data.hpp"

#include <list>

class analize_manager
{
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
    typedef std::list<analyzed_data> data;

    const data& get_analized_data() const;

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
};

#endif // ANALIZE_MANAGER_HPP
