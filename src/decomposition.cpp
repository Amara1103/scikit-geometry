#include "skgeom.hpp"

void init_polygon(py::module &m)
{
    py::class_<Ptd>(m, "Decomposition")
        .def("ptd", &Ptd::ptd);

    py::class_<Sabd>(m, "Decomposition")
        .def("sabd", &Sabd::sabd);
}
