#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <proxylib.h>
#include <proxylib_pre1.h>


#pragma region Curve Params
typedef struct
{
    PyObject_HEAD
    CurveParams *curveParams;
} PyCurveParams;

static void PyCurveParams_dealloc(PyCurveParams *self)
{
    delete self->curveParams;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

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
    return 0;
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
    PyCurveParams_getsetters,                              /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyCurveParams_init,                          /* tp_init */
    0,                                                     /* tp_alloc */
    PyCurveParams_new                                      /* tp_new */
};

static int PyCurveParams_Check(PyObject *obj) {
    return PyObject_IsInstance(obj, (PyObject*)&PyCurveParamsType);
}

#pragma endregion Curve Params

#pragma region Proxy PK PRE1
typedef struct
{
    PyObject_HEAD
    ProxyPK_PRE1 *proxyPK_PRE1;
} PyProxyPK_PRE1;

static void PyProxyPK_PRE1_dealloc(PyProxyPK_PRE1 *self)
{
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *PyProxyPK_PRE1_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyProxyPK_PRE1 *self;
    self = (PyProxyPK_PRE1 *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->proxyPK_PRE1 = new ProxyPK_PRE1();
    }
    return (PyObject *)self;
}

static int PyProxyPK_PRE1_init(PyProxyPK_PRE1 *self, PyObject *args, PyObject *kwds)
{
    self->proxyPK_PRE1 = new ProxyPK_PRE1();
    return 0;
}
static PyMethodDef PyProxyPK_PRE1_methods[] = {
    {NULL} /* Sentinel */
};

static PyGetSetDef PyProxyPK_PRE1_getsetters[] = {
    {NULL} /* Sentinel */
};
static PyTypeObject PyProxyPK_PRE1Type = {
    PyVarObject_HEAD_INIT(NULL, 0) "proxylib.ProxyPK_PRE1",/* tp_name */
    sizeof(PyProxyPK_PRE1),                                /* tp_basicsize */
    0,                                                     /* tp_itemsize */
    (destructor)PyProxyPK_PRE1_dealloc,                    /* tp_dealloc */
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
    "ProxyPK_PRE1 object",                                 /* tp_doc */
    0,                                                     /* tp_traverse */
    0,                                                     /* tp_clear */
    0,                                                     /* tp_richcompare */
    0,                                                     /* tp_weaklistoffset */
    0,                                                     /* tp_iter */
    0,                                                     /* tp_iternext */
    PyProxyPK_PRE1_methods,                                /* tp_methods */
    0,                                                     /* tp_members */
    0,                                                     /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyProxyPK_PRE1_init,                         /* tp_init */
    0,                                                     /* tp_alloc */
    PyProxyPK_PRE1_new                                     /* tp_new */
};

#pragma endregion Proxy PK PRE1

#pragma region Proxy SK PRE1
typedef struct
{
    PyObject_HEAD
    ProxySK_PRE1 *proxySK_PRE1;
} PyProxySK_PRE1;


static void PyProxySK_PRE1_dealloc(PyCurveParams *self)
{
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject *PyProxySK_PRE1_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyProxySK_PRE1 *self;
    self = (PyProxySK_PRE1 *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->proxySK_PRE1 = new ProxySK_PRE1();
    }
    return (PyObject *)self;
}

static int PyProxySK_PRE1_init(PyProxySK_PRE1 *self, PyObject *args, PyObject *kwds)
{
    self->proxySK_PRE1 = new ProxySK_PRE1();
    return 0;
}

static PyMethodDef PyProxySK_PRE1_methods[] = {
    {NULL} /* Sentinel */
};

static PyGetSetDef PyProxySK_PRE1_getsetters[] = {
    {NULL} /* Sentinel */
};

// Define the PyTypeObject for PyCurveParams
static PyTypeObject PyProxySK_PRE1Type = {
    PyVarObject_HEAD_INIT(NULL, 0) "proxylib.ProxySK_PRE1", /* tp_name */
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
    "ProxySK_PRE1 object",                                  /* tp_doc */
    0,                                                     /* tp_traverse */
    0,                                                     /* tp_clear */
    0,                                                     /* tp_richcompare */
    0,                                                     /* tp_weaklistoffset */
    0,                                                     /* tp_iter */
    0,                                                     /* tp_iternext */
    PyProxySK_PRE1_methods,                                 /* tp_methods */
    0,                                                     /* tp_members */
    0,                                                     /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyProxySK_PRE1_init,                          /* tp_init */
    0,                                                     /* tp_alloc */
    PyProxySK_PRE1_new                                      /* tp_new */
};
#pragma endregion Proxy SK PRE1

#pragma region ECn
typedef struct
{
    PyObject_HEAD
    ECn *ecn;
} PyECn;

#pragma endregion ECn

#pragma region Proxy Ciphertext PRE1
typedef struct
{
    PyObject_HEAD
    ProxyCiphertext_PRE1 *proxyCiphertext_PRE1;
} PyProxyCiphertext_PRE1;

#pragma endregion Proxy Ciphertext PRE1

#pragma region Module functions

static PyObject* PyPRE1_generate_params(PyObject *self, PyObject *args) {
    
    if (PyTuple_Size(args) !=1){
        PyErr_SetString(PyExc_RuntimeError, "Should have CurveParams");
        return Py_None;
    }

    PyObject *arg = PyTuple_GetItem(args, 0);

    if (!PyCurveParams_Check(arg)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast CurveParams");
        return Py_None;
    }

    PyCurveParams *curveParams = (PyCurveParams *)PyTuple_GetItem(args, 0);

    int result = PRE1_generate_params(*curveParams->curveParams);
    if (!result) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to generate params");
        return PyBool_FromLong(result);
    }

    Py_INCREF(Py_None);
    return PyBool_FromLong(result);
}


static PyObject* PyPRE1_keygen(PyObject *self, PyObject *args) {
    if (PyTuple_Size(args) !=3){
        PyErr_SetString(PyExc_RuntimeError, "Should have CurveParams");
        return Py_None;
    }

    PyObject *arg = PyTuple_GetItem(args, 0);

    if (!PyCurveParams_Check(arg)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast CurveParams");
        return Py_None;
    }

    PyCurveParams *curveParams = (PyCurveParams *)PyTuple_GetItem(args, 0);

    if (!PRE1_generate_params(*curveParams->curveParams)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to generate params");
        return Py_None;
    }

    Py_INCREF(Py_None);
    return Py_None;
}

static PyMethodDef module_methods[] = {
    {"PRE1_generate_params", PyPRE1_generate_params, METH_VARARGS, "Generate curve parameters for the PRE1 scheme."},
    {NULL, NULL, 0, NULL}
};

#pragma endregion Module functions

#pragma region Main module init
static struct PyModuleDef module_def = {
    PyModuleDef_HEAD_INIT,
    "pypre",
    0,  // m_doc
    -1, // m_size
    module_methods,// m_methods
    /*
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

    PyObject *module = PyModule_Create(&module_def);

    Py_INCREF(&PyCurveParamsType);
    if (PyModule_AddObject(module, "CurveParams", (PyObject *)&PyCurveParamsType) < 0)
    {
        Py_DECREF(&PyCurveParamsType);
        Py_DECREF(module);
        return NULL;
    }

    extern PyTypeObject PyProxyPK_PRE1Type;
    if (PyType_Ready(&PyProxyPK_PRE1Type) < 0)
        return NULL;

    Py_INCREF(&PyProxyPK_PRE1Type);
    if (PyModule_AddObject(module, "PK_PRE1", (PyObject *)&PyProxyPK_PRE1Type) < 0)
    {
        Py_DECREF(&PyProxyPK_PRE1Type);
        Py_DECREF(module);
        return NULL;
    }

    extern PyTypeObject PyProxySK_PRE1Type;
    if (PyType_Ready(&PyProxySK_PRE1Type) < 0)
        return NULL;

    Py_INCREF(&PyProxySK_PRE1Type);
    if (PyModule_AddObject(module, "SK_PRE1", (PyObject *)&PyProxySK_PRE1Type) < 0)
    {
        Py_DECREF(&PyProxySK_PRE1Type);
        Py_DECREF(module);
        return NULL;
    }
    // PyModule_AddObject(module, "__version__", PyUnicode_FromString(VERSION));

    if (PyErr_Occurred())
        PyErr_SetString(PyExc_ImportError, "pypre: init failed");

    return module;
}


#pragma endregion Main module init
