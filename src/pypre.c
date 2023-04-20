// #include <stdio.h>
// #include <Python.h>
// #include "proxylib.h"

// static PyObject *core_vector_sub(PyObject *self, PyObject *args);

// // wrapper function for cfactorial_sum
// static PyObject *DemoLib_cFactorialSum(PyObject *self, PyObject *args)
// {
//     char *char_nums;
//     if (!PyArg_ParseTuple(args, "s", &char_nums))
//     {
//         return NULL;
//     }

//     unsigned long fact_sum = 0;
//     // fact_sum = cfactorial_sum(char_nums);

//     return Py_BuildValue("i", fact_sum);
// }

// // module's function table
// static PyMethodDef module_methods[] = {
//     {
//         "sfactorial_sum",                                           // name exposed to Python
//         DemoLib_cFactorialSum,                                      // C wrapper function
//         METH_VARARGS,                                               // received variable args (but really just 1)
//         "Calculates factorial sum from digits in string of numbers" // documentation
//     },
//     {NULL, NULL, 0, NULL}};

// // modules definition
// static struct PyModuleDef module_def = {
//     PyModuleDef_HEAD_INIT,
//     "pypre",
//     "Demo Python wrapper for custom C extension library.",
//     -1,
//     module_methods};

// PyMODINIT_FUNC PyInit_pypre(void)
// {
//     return PyModule_Create(&module_def);
// }


#include <Python.h>

static PyMethodDef module_methods[] = {
    // ... list of module functions and methods ...
    {NULL, NULL, 0, NULL} // sentinel
};

static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "pypre",
    NULL,
    -1,
    module_methods
};

PyMODINIT_FUNC PyInit_pypre(void) {
    return PyModule_Create(&module_def);
}