#include "skgeom.hpp"
#include <CGAL/minkowski_sum_2.h>
#include <CGAL/Polygon_vertical_decomposition_2.h>
#include <CGAL/Polygon_triangulation_decomposition_2.h>
#include <CGAL/Small_side_angle_bisector_decomposition_2.h>

typedef CGAL::Polygon_vertical_decomposition_2<Kernel> Pvd;
typedef CGAL::Polygon_triangulation_decomposition_2<Kernel> Ptd;
typedef CGAL::Small_side_angle_bisector_decomposition_2<Kernel> Sabd;

template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
Polygon_with_holes_2 get_minkowski(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
{
    return CGAL::minkowski_sum_2(p, q, decomposition1, decomposition2);
}

template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
Polygon_with_holes_2 get_minkowski_wrapper(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
{
    return get_minkowski(p, q, decomposition1, decomposition2);
}

void init_minkowski(py::module &m)
{
    Ptd ptd;
    Sabd sabd;
    auto sub = m.def_submodule("minkowski");
    sub.def("minkowski_sum_pp", &PYBIND11_OVERLOAD(Polygon_with_holes_2, get_minkowski_wrapper, Polygon_2, Polygon_2, sabd, sabd));
    sub.def("minkowski_sum_ph", &PYBIND11_OVERLOAD(Polygon_with_holes_2, get_minkowski_wrapper, Polygon_with_holes_2, Polygon_2, ptd, sabd));
    sub.def("minkowski_sum_hp", &PYBIND11_OVERLOAD(Polygon_with_holes_2, get_minkowski_wrapper, Polygon_2, Polygon_with_holes_2, sabd, ptd));
    sub.def("minkowski_sum_hh", &PYBIND11_OVERLOAD(Polygon_with_holes_2, get_minkowski_wrapper, Polygon_with_holes_2, Polygon_with_holes_2, ptd, ptd));
}
