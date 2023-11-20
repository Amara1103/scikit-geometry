#include "skgeom.hpp"
#include <pybind11/pybind11.h>
#include <pybind11/pytypes.h>
#include <pybind11/operators.h>
#include <pybind11/stl.h>
void init_decomposition(py::module &m)
{
    py::class_<Ptd>(m, "Decomposition")
        .def(py::init<>());

    py::class_<Sabd>(m, "Decomposition")
        .def(py::init<>());
}
