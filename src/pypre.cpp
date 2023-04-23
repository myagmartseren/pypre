#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <proxylib.h>

typedef struct
{
    PyObject_HEAD
        CurveParams *curveParams;
} PyCurveParams;

static PyObject *PyCurveParams_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyCurveParams *self;
    self = (PyCurveParams *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->curveParams = new CurveParams();
    }
    return (PyObject *)self;
}

static int PyCurveParams_init(PyCurveParams *self, PyObject *args, PyObject *kwds)
{
    self->curveParams = new CurveParams();

    // Initialize curve parameters here
    // ...

    return 0;
}

static void PyCurveParams_dealloc(PyCurveParams *self)
{
    // delete self->curveParams;
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyMethodDef PyCurveParams_methods[] = {
    {NULL} /* Sentinel */
};

static PyGetSetDef PyCurveParams_getsetters[] = {
    {NULL} /* Sentinel */
};

// Define the PyTypeObject for PyCurveParams
static PyTypeObject PyCurveParamsType = {
    PyVarObject_HEAD_INIT(NULL, 0) "proxylib.CurveParams", /* tp_name */
    sizeof(PyCurveParams),                                 /* tp_basicsize */
    0,                                                     /* tp_itemsize */
    (destructor)PyCurveParams_dealloc,                     /* tp_dealloc */
    0,                                                     /* tp_print */
    0,                                                     /* tp_getattr */
    0,                                                     /* tp_setattr */
    0,                                                     /* tp_reserved */
    0,                                                     /* tp_repr */
    0,                                                     /* tp_as_number */
    0,                                                     /* tp_as_sequence */
    0,                                                     /* tp_as_mapping */
    0,                                                     /* tp_hash  */
    0,                                                     /* tp_call */
    0,                                                     /* tp_str */
    0,                                                     /* tp_getattro */
    0,                                                     /* tp_setattro */
    0,                                                     /* tp_as_buffer */
    Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,              /* tp_flags */
    "CurveParams object",                                  /* tp_doc */
    0,                                                     /* tp_traverse */
    0,                                                     /* tp_clear */
    0,                                                     /* tp_richcompare */
    0,                                                     /* tp_weaklistoffset */
    0,                                                     /* tp_iter */
    0,                                                     /* tp_iternext */
    PyCurveParams_methods,                                 /* tp_methods */
    0,                                                     /* tp_members */
    0,                                                     /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyCurveParams_init,                          /* tp_init */
    0,                                                     /* tp_alloc */
    PyCurveParams_new                                      /* tp_new */
};

static struct PyModuleDef moduledef = {
    PyModuleDef_HEAD_INIT,
    "pypre",
    0,  // m_doc
    -1, // m_size
        /*
        PyCurveParams_methods,// m_methods
        NULL,                 // m_reload
        NULL,                 // m_traverse
        NULL,                 // m_clear
        NULL                  // m_free
        */
};
PyMODINIT_FUNC PyInit_pypre(void);

PyObject *PyInit_pypre(void)
{
    extern PyTypeObject PyCurveParamsType;
    if (PyType_Ready(&PyCurveParamsType) < 0)
        return NULL;

    PyObject *module = PyModule_Create(&moduledef);

    Py_INCREF(&PyCurveParamsType);
    if (PyModule_AddObject(module, "Pypre", (PyObject *)&PyCurveParamsType) < 0)
    {
        Py_DECREF(&PyCurveParamsType);
        Py_DECREF(module);
        return NULL;
    }

    // PyModule_AddObject(module, "__version__", PyUnicode_FromString(VERSION));

    if (PyErr_Occurred())
        PyErr_SetString(PyExc_ImportError, "sonic: init failed");

    return module;
}