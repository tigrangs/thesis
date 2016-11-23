#include "analize_manager.hpp"

#include "evenly_destributed.hpp"
#include "sorted_matrix.hpp"
#include "matrix_analyzer.hpp"
#include "better_aprox_matix.hpp"

#include <iostream>
#include <cassert>

analize_manager* analize_manager::get_instance()
{
    static analize_manager* instance = new analize_manager();
    return instance;
}

analize_manager::analize_manager()
    : m_matrix_count(0)
    , m_internal_matrix_size(0)
    , m_matrix_size(0, 0)
    , m_value_range(0, 0)
    , m_mode(sorted)
{
}

void analize_manager::set_matrix_count(unsigned c)
{
    m_matrix_count = c;
}

const analize_manager::data& analize_manager::get_analized_data() const
{
    return m_data;
}

void analize_manager::set_internal_matrix_size(unsigned s)
{
    m_internal_matrix_size = s;
}

void analize_manager::set_matrix_size(unsigned w, unsigned h)
{
    m_matrix_size = std::pair<unsigned, unsigned>(w, h);
}

void analize_manager::set_value_range(int begin, int end)
{
    assert(begin < end);
    m_value_range = std::pair<int, int>(begin, end);
}

matrix* analize_manager::create_sorted_matrix()
{
    sorted_matrix* m = new sorted_matrix(m_matrix_size.first);
    m->fill_with_sorting(m_internal_matrix_size,
            m_value_range.first, m_value_range.second);
    return m;
}

matrix* analize_manager::create_evenly_matrix()
{
    evenly_destributed* m = new evenly_destributed(m_matrix_size.first);
    m->fill(m_internal_matrix_size,
            m_value_range.first, m_value_range.second);
    return m;
}

matrix* analize_manager::create_better_aprox_matrix()
{
    better_aprox_matrix* m = new better_aprox_matrix(m_matrix_size.first);
    m->fill(m_internal_matrix_size,
            m_value_range.first, m_value_range.second);
    return m;

}

void analize_manager::run()
{
    m_data.clear();
    for (unsigned i = 0; i < m_matrix_count; ++i) {
        matrix* m = 0;
        switch (m_mode) {
            case sorted:
                m = create_sorted_matrix();
                break;
            case evenly:
                m = create_evenly_matrix();
                break;
            case better:
                m = create_better_aprox_matrix();
                break;
            default:
                m = 0;
                break;
        }
        assert(0 != m);
        typedef matrix_analyzer MA;
        MA* ma = MA::get_instance();
        assert(ma != 0);
        m_data.push_back(ma->analyze(m, m_internal_matrix_size));
    }
}

void analize_manager::set_mode(analize_manager::mode m)
{
    std::cout<<m<<std::endl;
    m_mode = m;
}
