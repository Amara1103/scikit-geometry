#include "skgeom.hpp"
#include <CGAL/minkowski_sum_2.h>
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>


template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
Polygon_with_holes_2 get_minkowski(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
{
    return CGAL::minkowski_sum_2(p, q, decomposition1, decomposition2);
}

void init_minkowski(py::module &m)
{
    auto sub = m.def_submodule("minkowski");
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_2, Sabd, Sabd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_2, Ptd, Sabd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_with_holes_2, Sabd, Ptd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_with_holes_2, Ptd, Ptd>);
}
