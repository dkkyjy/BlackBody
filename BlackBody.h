#include <Python.h>
#include <numpy/arrayobject.h>

double c = 3.00e+10;
double h = 6.63e-27;
double k = 1.38e-16;

PyObject* Planck(PyObject* self, PyObject* args);
PyObject* RJ(PyObject* self, PyObject* args);
PyObject* Wien(PyObject* self, PyObject* args);
