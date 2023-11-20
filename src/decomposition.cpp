#include "skgeom.hpp"
#include <pybind11/stl.h>
#include <pybind11/complex.h>
#include <pybind11/functional.h>
#include <pybind11/chrono.h>
void init_decomposition(py::module &m)
{
    py::class_<Ptd>(m, "Decomposition_Ptd")
        .def(py::init<>());

    py::class_<Sabd>(m, "Decomposition_Sabd")
        .def(py::init<>());
}
