#include "sorted_matrix.hpp"
#include "rundom_number_generator.hpp"

#include <cassert>
#include <vector>

sorted_matrix::sorted_matrix(unsigned size)
	: matrix(size, size)
	, m_internal_size(0)
{}

void sorted_matrix::fill_with_sorting(unsigned size, int begin, int end)
{
	assert(size < get_width());
	assert(begin < end);
	m_internal_size = size;
	fill_matrix(begin, end);
}

void sorted_matrix::fill_matrix(int begin, int end)
{
	assert(m_internal_size != 0);
	typedef rundom_number_generator RND;
	RND* rnd = RND::get_instance();
	assert(rnd != 0);
	std::vector<int> numbers(get_width());
	for (unsigned i = 0; i < get_widt(); ++i) {
		numbers[i] = rnd->get_number(begin, end);
	}
	std::sort(numbers.begin(), numbers.end());
	for ()
}
