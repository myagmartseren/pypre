#include <stdio.h>
#include <Python.h>
#include "proxylib_api.h"

#define READ_BUFFER_SIZE 22050

static PyObject *py_pre_init(PyObject* self, PyObject* args) {
     char *seedbuf = NULL;
    int bufsize = 0;

    if (!PyArg_ParseTuple(args, "si", &seedbuf, &bufsize)) {
        return NULL;
    }

    // Initialize the library
    int err = proxylib_initLibrary(seedbuf, bufsize);
    if (err != ERROR_NONE){
        PyErr_SetString(PyExc_RuntimeError, "Failed to initialize library");
        return NULL;
    }
    Py_INCREF(Py_None);
    return Py_None;;
}

// module's function table
static PyMethodDef module_methods[] = {
    {"sfactorial_sum",py_pre_init,METH_VARARGS,""},
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

