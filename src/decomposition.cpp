#include "skgeom.hpp"

void init_decomposition(py::module &m)
{
    py::class_<Ptd>(m, "Decomposition_ptd");

    py::class_<Sabd>(m, "Decomposition_sabd");
}
