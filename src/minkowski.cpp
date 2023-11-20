#include "skgeom.hpp"
#include <CGAL/minkowski_sum_2.h>

// Wrap Sabd
class PySabd : public CGAL::Small_side_angle_bisector_decomposition_2<Kernel>
{
public:
    using CGAL::Small_side_angle_bisector_decomposition_2<Kernel>::Small_side_angle_bisector_decomposition_2;
};

// Wrap Ptd
class PyPtd : public CGAL::Polygon_triangulation_decomposition_2<Kernel>
{
public:
    using CGAL::Polygon_triangulation_decomposition_2<Kernel>::Polygon_triangulation_decomposition_2;
};
template <typename T1, typename T2, typename Decomposition1, typename Decomposition2>
Polygon_with_holes_2 get_minkowski(T1 p, T2 q, Decomposition1 decomposition1, Decomposition2 decomposition2)
{
    return CGAL::minkowski_sum_2(p, q, decomposition1, decomposition2);
}

void init_minkowski(py::module &m)
{
    auto sub = m.def_submodule("minkowski");
    // Bind Sabd
    py::class_<PySabd>(m, "Sabd");
    // Bind Ptd
    py::class_<PyPtd>(m, "Ptd");
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_2, Sabd, Sabd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_2, Ptd, Sabd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_2, Polygon_with_holes_2, Sabd, Ptd>);
    sub.def("minkowski_sum", &get_minkowski<Polygon_with_holes_2, Polygon_with_holes_2, Ptd, Ptd>);
}