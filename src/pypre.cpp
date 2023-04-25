#define PY_SSIZE_T_CLEAN
#include <zzn.h>
#include <miracl.h>

#include <Python.h>
#include <proxylib.h>
#include <proxylib_pre1.h>

#pragma region Common types
typedef struct
{
    PyObject_HEAD
    ZZn2 *zzn2;
} PyZZn2;

static void PyZZn2_dealloc(PyZZn2 *self)
{
    delete self->zzn2;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject* PyZZn2_New(PyTypeObject* type, PyObject* args, PyObject* kwargs)
{
    PyZZn2 *self;
    self = (PyZZn2 *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->zzn2 = new ZZn2();
    }
    return (PyObject *)self;
}

static int PyZZn2_init(PyZZn2 *self, PyObject *args, PyObject *kwds)
{
    self->zzn2 = new ZZn2();
    return 0;
}

static PyMethodDef PyZZn2_methods[] = {
    {NULL} /* Sentinel */
};

static PyGetSetDef PyZZn2_getsetters[] = {
    {NULL} /* Sentinel */
};

// Define the PyTypeObject for PyCurveParams
static PyTypeObject PyZZn2Type = {
    PyVarObject_HEAD_INIT(NULL, 0) "proxylib.CurveParams", /* tp_name */
    sizeof(PyZZn2),                                 /* tp_basicsize */
    0,                                                     /* tp_itemsize */
    (destructor)PyZZn2_dealloc,                     /* tp_dealloc */
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
    "ZZn2 object",                                  /* tp_doc */
    0,                                                     /* tp_traverse */
    0,                                                     /* tp_clear */
    0,                                                     /* tp_richcompare */
    0,                                                     /* tp_weaklistoffset */
    0,                                                     /* tp_iter */
    0,                                                     /* tp_iternext */
    PyZZn2_methods,                                 /* tp_methods */
    0,                                                     /* tp_members */
    PyZZn2_getsetters,                              /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyZZn2_init,                          /* tp_init */
    0,                                                     /* tp_alloc */
    PyZZn2_New                                      /* tp_new */
};

static int PyZZn2_Check(PyObject *obj) {
    return PyObject_IsInstance(obj, (PyObject*)&PyZZn2Type);
}

#pragma endregion Common types

#pragma region Curve Params
typedef struct
{
    PyObject_HEAD
    CurveParams *params;
} PyCurveParams;

static void PyCurveParams_dealloc(PyCurveParams *self)
{
    delete self->params;
    Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *PyCurveParams_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
    PyCurveParams *self;
    self = (PyCurveParams *)type->tp_alloc(type, 0);
    if (self != NULL)
    {
        self->params = new CurveParams();
    }
    return (PyObject *)self;
}

static int PyCurveParams_init(PyCurveParams *self, PyObject *args, PyObject *kwds)
{
    self->params = new CurveParams();
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
    ProxyPK_PRE1 *publicKey;
} PyProxyPK_PRE1;

static void PyProxyPK_PRE1_dealloc(PyProxyPK_PRE1 *self)
{
    delete self->publicKey;
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject* PyProxyPK_PRE1_New(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    PyProxyPK_PRE1 *self;
    self = (PyProxyPK_PRE1 *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->publicKey = new ProxyPK_PRE1();
    }
    return (PyObject *)self;
}

static int PyProxyPK_PRE1_init(PyProxyPK_PRE1 *self, PyObject *args, PyObject *kwds)
{
    self->publicKey = new ProxyPK_PRE1();
    return 0;
}
PyObject* PyProxyPK_PRE1_publicKey_to_python(ProxyPK_PRE1* publicKey) {
  PyObject* py_publicKey = NULL;
  if (publicKey != NULL) {
    cout <<"convert function"<< publicKey->Zpub1;
    cout <<"convert function"<< publicKey->Ppub2;
    py_publicKey = Py_BuildValue("(i)", publicKey->Zpub1);
  }
  return py_publicKey;
}

static PyObject* PyProxyPK_PRE1_GetPublicKey(PyProxyPK_PRE1* self) {
  return PyProxyPK_PRE1_publicKey_to_python(self->publicKey);
}

ProxyPK_PRE1* PyProxyPK_PRE1_python_to_publicKey(PyObject* py_publicKey) {
  ProxyPK_PRE1* publicKey = NULL;
  if (py_publicKey != NULL) {
    char* zpub1 = NULL;
    PyArg_ParseTuple(py_publicKey, "s", &zpub1);
    if (zpub1 != NULL) {
      publicKey = new ProxyPK_PRE1();
      publicKey->Zpub1 = zpub1;
    }
  }
  return publicKey;
}

static void PyProxyPK_PRE1_SetPublicKey(PyProxyPK_PRE1* self, PyObject* publicKey) {
  self->publicKey = PyProxyPK_PRE1_python_to_publicKey(publicKey);
}

static PyMethodDef PyProxyPK_PRE1_methods[] = {
    {NULL} /* Sentinel */
};

ZZn2 PyProxyPK_PRE1_GetZpub1(PyProxyPK_PRE1* self) {
  return self->publicKey->Zpub1;
}

void PyProxyPK_PRE1_SetZpub1(PyProxyPK_PRE1* self, ZZn2 Zpub1) {
  self->publicKey->Zpub1 = Zpub1;
}

static PyGetSetDef PyProxyPK_PRE1_getsetters[] = {
    // {"zpub1", (getter)PyProxyPK_PRE1_GetZpub1, (setter)PyProxyPK_PRE1_SetZpub1, "Zpub1", NULL},
    {"publicKey", (getter)PyProxyPK_PRE1_GetPublicKey, (setter)PyProxyPK_PRE1_SetPublicKey, "Public Key", NULL},
    {NULL, NULL, NULL, NULL, NULL} /* Sentinel */
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
    PyProxyPK_PRE1_getsetters,                             /* tp_getset */
    0,                                                     /* tp_base */
    0,                                                     /* tp_dict */
    0,                                                     /* tp_descr_get */
    0,                                                     /* tp_descr_set */
    0,                                                     /* tp_dictoffset */
    (initproc)PyProxyPK_PRE1_init,                         /* tp_init */
    0,                                                     /* tp_alloc */
    PyProxyPK_PRE1_New                                     /* tp_new */
};

static int PyProxyPK_PRE1_Check(PyObject *obj) {
    return PyObject_IsInstance(obj, (PyObject*)&PyProxyPK_PRE1Type);
}

#pragma endregion Proxy PK PRE1

#pragma region Proxy SK PRE1
typedef struct
{
    PyObject_HEAD
    ProxySK_PRE1 *secretKey;
} PyProxySK_PRE1;

static void PyProxySK_PRE1_dealloc(PyProxySK_PRE1 *self)
{
    delete self->secretKey;
    Py_TYPE(self)->tp_free((PyObject *)self);
}

static PyObject* PyProxySK_PRE1_New(PyTypeObject *type, PyObject *args, PyObject *kwds) {
    PyProxySK_PRE1 *self;
    self = (PyProxySK_PRE1 *)type->tp_alloc(type, 0);
    if (self != NULL) {
        self->secretKey = new ProxySK_PRE1();
    }
    return (PyObject *)self;
}

static int PyProxySK_PRE1_init(PyProxySK_PRE1 *self, PyObject *args, PyObject *kwds)
{
    self->secretKey = new ProxySK_PRE1();
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
    (destructor)PyProxySK_PRE1_dealloc,                     /* tp_dealloc */
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
    PyProxySK_PRE1_New                                      /* tp_new */
};

static int PyProxySK_PRE1_Check(PyObject *obj) {
    return PyObject_IsInstance(obj, (PyObject*)&PyProxySK_PRE1Type);
}

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

#pragma region PRE 1 Functions

static PyObject* PyPRE1_generate_params(PyObject *self, PyObject *args) {
    if (PyTuple_Size(args) !=1){
        PyErr_SetString(PyExc_RuntimeError, "Should have CurveParams");
        return Py_None;
    }

    PyObject *params = PyTuple_GetItem(args, 0);

    if (!PyCurveParams_Check(params)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast CurveParams");
        return Py_None;
    }

    PyCurveParams *pyParams = (PyCurveParams *)params;

    int result = PRE1_generate_params(*pyParams->params);
    if (!result) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to generate params");
        return PyBool_FromLong(result);
    }

    Py_INCREF(Py_None);
    return PyBool_FromLong(result);
}

static PyObject* PyPRE1_keygen(PyObject *self, PyObject *args) {
    if (PyTuple_Size(args) !=3){
        PyErr_SetString(PyExc_RuntimeError, "Should have 3 parameters");
        return Py_None;
    }

    PyObject *tempParams = PyTuple_GetItem(args, 0);
    if (!PyCurveParams_Check(tempParams)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast CurveParams");
        return Py_None;
    }
    PyCurveParams *pyParams = (PyCurveParams *)tempParams;
    printf("pyParams->params address: %p\n", pyParams->params);

    PyObject *tempPublicKey = PyTuple_GetItem(args, 1);
    if (!PyProxyPK_PRE1_Check(tempPublicKey)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast PK_PRE1");
        return Py_None;
    }
    PyProxyPK_PRE1 *pyPublicKey = (PyProxyPK_PRE1 *)tempPublicKey;
    printf("pyPublicKey->publicKey address: %p\n", pyPublicKey->publicKey);

    PyObject *tempSecretKey = PyTuple_GetItem(args, 2);
    if (!PyProxySK_PRE1_Check(tempSecretKey)) {
        PyErr_SetString(PyExc_RuntimeError, "Failed to cast SK_PRE1");
        return Py_None;
    }
    PyProxySK_PRE1 *pySecretKey = (PyProxySK_PRE1 *)tempSecretKey;
    printf("pySecretKey->secretKey address: %p\n", pySecretKey->secretKey);

    int result = PRE1_keygen(*pyParams->params, *pyPublicKey->publicKey, *pySecretKey->secretKey);
    
    Py_INCREF(Py_None);
    return PyBool_FromLong(result);
}

static PyMethodDef module_methods[] = {
    {"PRE1_generate_params", PyPRE1_generate_params, METH_VARARGS, "Generate curve parameters for the PRE1 scheme."},
    {"PRE1_keygen", PyPRE1_keygen, METH_VARARGS, "Generate curve parameters for the PRE1 scheme."},

    {NULL, NULL, 0, NULL}
};

#pragma endregion PRE 1 Functions

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
