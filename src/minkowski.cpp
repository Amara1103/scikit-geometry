// #include "skgeom.hpp"
// #include <CGAL/minkowski_sum_2.h>

// template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
// Polygon_with_holes_2 get_minkowski(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
// {
//     return CGAL::minkowski_sum_2(p, q, decomposition1, decomposition2);
// }

// void init_minkowski(py::module &m)
// {
//     auto sub = m.def_submodule("minkowski");
//     sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_2, Sabd, Sabd>);
//     sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_2, Ptd, Sabd>);
//     sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_with_holes_2, Sabd, Ptd>);
//     sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_with_holes_2, Ptd, Ptd>);
// }

#include "skgeom.hpp"
#include <CGAL/minkowski_sum_2.h>
#include <type_traits>
template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
Polygon_with_holes_2 get_minkowski(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
{
    Ptd ptd;
    Sabd sabd;
    if (std::is_same<decltype(p), Polygon_2>::value)
    {
        // 如果为polygon_2类型，设置分解模式为sabd
        decomposition1 = sabd;
    }
    else
    {
        decomposition1 = ptd;
    }
    if (std::is_same<decltype(q), Polygon_2>::value)
    {
        // 如果为polygon_，设置分解模式为sabd
        decomposition2 = sabd;
    }
    else
    {
        decomposition2 = ptd;
    }

    return CGAL::minkowski_sum_2(p, q, decomposition1, decomposition2);
}

void init_minkowski(py::module &m)
{
    auto sub = m.def_submodule("minkowski");
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_2>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_2>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_with_holes_2>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_with_holes_2>);
}
