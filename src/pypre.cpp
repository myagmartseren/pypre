#include <stdio.h>
#include <Python.h>
#include "proxylib.h"
#include "proxylib_pre1.h"

#define READ_BUFFER_SIZE 22050

static PyObject* py_pre1_keygen(PyObject* self, PyObject* args) {
    float speed;
    if (! PyArg_ParseTuple(args, "f", &speed)) { return NULL; }
    if (speed < 0.2 || speed > 6.0) {
        PyErr_SetString(PyExc_TypeError, "speed should be between 0.2 and 6.0");
        return NULL;
    }
    sonicSetSpeed(PY_SONIC(self)->stream, speed);
    Py_INCREF(Py_None);
    return Py_None;
}

// module's function table
static PyMethodDef module_methods[] = {
    // {"sfactorial_sum",py_pre_init,METH_VARARGS,""},
    {NULL, NULL, 0, NULL}
};

// modules definition
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "pypre",     // name of module exposed to Python
    "Demo Python wrapper for custom C extension library.", // module documentation
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_pypre(void)
{
    return PyModule_Create(&module_def);
}

