import glob
import os
from setuptools import Extension, setup

os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"

module = Extension("pypre",
                language="c++",
                sources=[f for f in glob.glob('src/*.c')]+['external/proxylib/proxylib_pre1.cpp'],
                include_dirs=['external/miracl'],
                compiler="g++"
)

setup(name='pypre',
     version='1.0',
     description='Python wrapper for custom C++ extension',
     ext_modules=[module])