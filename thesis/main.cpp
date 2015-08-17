#include "sorted_matrix.hpp"
#include "matrix_analyzer.hpp"

int main()
{
    sorted_matrix m(10);
    m.fill_with_sorting(2,0,100000000);
    m.print();
    typedef matrix_analyzer MA;
    MA* ma = MA::get_instance();
    analyzed_data d = ma->analyze(&m, 2);
    d.print();
    return 0;
}
