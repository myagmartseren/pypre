import glob
from setuptools import Extension, setup

module = Extension("pypre",
                  sources=[f for f in glob.glob('src/*.cpp')]+['external/proxylib_pre1.cpp'])

setup(name='pypre',
     version='1.0',
     description='Python wrapper for custom C extension',
     ext_modules=[module])