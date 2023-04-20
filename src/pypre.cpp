#include <stdio.h>
#include <Python.h>
#include "proxylib.h"

// wrapper function for cfactorial_sum
static PyObject *DemoLib_cFactorialSum(PyObject *self, PyObject *args)
{
    char *char_nums;
    if (!PyArg_ParseTuple(args, "s", &char_nums))
    {
        return NULL;
    }

    unsigned long fact_sum =0 ;
    // fact_sum = cfactorial_sum(char_nums);

    return Py_BuildValue("i", fact_sum);
}

// module's function table
static PyMethodDef DemoLib_FunctionsTable[] = {
    {
        "sfactorial_sum",                                           // name exposed to Python
        DemoLib_cFactorialSum,                                      // C wrapper function
        METH_VARARGS,                                               // received variable args (but really just 1)
        "Calculates factorial sum from digits in string of numbers" // documentation
    },
    {NULL, NULL, 0, NULL}};

// modules definition
static struct PyModuleDef DemoLib_Module = {
    PyModuleDef_HEAD_INIT,
    "demo",                                                // name of module exposed to Python
    "Demo Python wrapper for custom C extension library.", // module documentation
    -1,
    DemoLib_FunctionsTable};

PyMODINIT_FUNC PyInit_demo(void)
{
    return PyModule_Create(&DemoLib_Module);
}