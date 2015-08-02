#include "dummy_matrix.hpp"

int main()
{
	dummy_matrix m(20);
	m.print();
	m.fill_matrix(0,1000);
	m.print();
	return 0;
};
