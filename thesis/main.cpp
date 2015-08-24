#include "core/sorted_matrix.hpp"
#include "core/matrix_analyzer.hpp"
#include "core/analize_manager.hpp"

#include "gui/main_window.hpp"

#include <QApplication>

int main(int argc, char** argv)
{
    QApplication app(argc, argv);
    main_window mw;
    mw.show();
/*    typedef analize_manager AM;
    AM* am = AM::get_instance();
    am->set_internal_matrix_size(5);
    am->set_matrix_count(1000);
    am->set_matrix_size(20, 20);
    am->set_value_range(0, 100000000);
    am->run();
    const AM::data& d = am->get_analized_data();
    for (AM::data::const_iterator i = d.begin(); i != d.end(); ++i) {
//        (*i).print();
    }*/
/*    sorted_matrix m(10);
    m.fill_with_sorting(2,0,100000000);
    m.print();
    typedef matrix_analyzer MA;
    MA* ma = MA::get_instance();
    analyzed_data d = ma->analyze(&m, 2);
    d.print();*/
    return app.exec();
}
