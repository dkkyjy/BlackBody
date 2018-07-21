#include <math.h>
#include "BlackBody.h"


double Planck_(double nu, double T){
    return 2 * h * pow(nu, 3) / pow(c, 2) * 1 / (exp((h*nu)/(k*T)) - 1);
}

double RJ_(double nu, double T){
    return 2 * pow(nu, 2) / pow(c, 2) * k * T;
}

double Wien_(double nu, double T){
    return 2 * h * pow(nu, 3) / pow(c, 2) * exp(-1 * (h*nu)/(k*T));
}


PyObject* Planck(PyObject* self, PyObject* args){
    PyArrayObject* nu;
    double T;
    PyArg_ParseTuple(args, "O!d", &PyArray_Type, &nu, &T);

    PyArrayObject* in_array = nu;
    PyObject* out_array = PyArray_NewLikeArray(in_array, PyArray_ANYORDER, NULL, 0);
    PyArrayIterObject* in_iter = PyArray_IterNew(in_array);
    PyArrayIterObject* out_iter = PyArray_IterNew(out_array);
    while(in_iter->index < in_iter->size && out_iter->index < out_iter->size){
        double* in_dataptr = in_iter->dataptr;
        double* out_dataptr = out_iter->dataptr;
        *out_dataptr = Planck_(*in_dataptr, T);
        PyArray_ITER_NEXT(in_iter);
        PyArray_ITER_NEXT(out_iter);
    }
    Py_DECREF(in_iter);
    Py_DECREF(out_iter);
    Py_INCREF(out_array);
    return out_array;    
}

PyObject* RJ(PyObject* self, PyObject* args){
    PyArrayObject* nu;
    double T;
    PyArg_ParseTuple(args, "O!d", &PyArray_Type, &nu, &T);

    PyArrayObject* in_array = nu;
    PyObject* out_array = PyArray_NewLikeArray(in_array, PyArray_ANYORDER, NULL, 0);
    PyArrayIterObject* in_iter = PyArray_IterNew(in_array);
    PyArrayIterObject* out_iter = PyArray_IterNew(out_array);
    while(in_iter->index < in_iter->size && out_iter->index < out_iter->size){
        double* in_dataptr = in_iter->dataptr;
        double* out_dataptr = out_iter->dataptr;
        *out_dataptr = RJ_(*in_dataptr, T);
        PyArray_ITER_NEXT(in_iter);
        PyArray_ITER_NEXT(out_iter);
    }
    Py_DECREF(in_iter);
    Py_DECREF(out_iter);
    Py_INCREF(out_array);
    return out_array;    
}

PyObject* Wien(PyObject* self, PyObject* args){
    PyArrayObject* nu;
    double T;
    PyArg_ParseTuple(args, "O!d", &PyArray_Type, &nu, &T);

    PyArrayObject* in_array = nu;
    PyObject* out_array = PyArray_NewLikeArray(in_array, PyArray_ANYORDER, NULL, 0);
    PyArrayIterObject* in_iter = PyArray_IterNew(in_array);
    PyArrayIterObject* out_iter = PyArray_IterNew(out_array);
    while(in_iter->index < in_iter->size && out_iter->index < out_iter->size){
        double* in_dataptr = in_iter->dataptr;
        double* out_dataptr = out_iter->dataptr;
        *out_dataptr = Wien_(*in_dataptr, T);
        PyArray_ITER_NEXT(in_iter);
        PyArray_ITER_NEXT(out_iter);
    }
    Py_DECREF(in_iter);
    Py_DECREF(out_iter);
    Py_INCREF(out_array);
    return out_array;    
}


static PyMethodDef BlackBody[] = 
{
    {"Planck", (PyCFunction)Planck, METH_VARARGS, "calculate the Planck emission of Synchrotron"},
    {"RJ", (PyCFunction)RJ, METH_VARARGS, "calculate the Rayleigh-Jeans emission of Synchrotron"},
    {"Wien", (PyCFunction)Wien, METH_VARARGS, "calculate the Wien emission of Synchrotron"},
    {NULL, NULL}
};

static struct PyModuleDef moduledef = {
        PyModuleDef_HEAD_INIT,
        "BlackBody",
        NULL,
        -1,
        BlackBody,
        NULL,
        NULL,
        NULL,
        NULL
};

PyMODINIT_FUNC
PyInit_BlackBody(void)
{
    PyObject *module = PyModule_Create(&moduledef);
    import_array();
    return module;
}
