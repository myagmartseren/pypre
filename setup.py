import glob
from setuptools import Extension, setup

module = Extension("pypre",
                language="c++",
                sources=[f for f in glob.glob('src/*.c')]+['external/proxylib/proxylib_pre1.cpp'],
                extra_compile_args=["-I./external/miracl", "-O2", "-v"],
                include_dirs=['external/miracl'],
                libraries=["miracl"],
                compiler="g++"
)

setup(name='pypre',
     version='1.0',
     description='Python wrapper for custom C++ extension',
     ext_modules=[module])