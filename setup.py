import glob
import os
from setuptools import Extension, setup

os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"

module = Extension("pypre",
               language="c++",
               sources=[f for f in glob.glob('src/*.cpp')],
               include_dirs=['external/miracl','external/proxylib'],
               library_dirs=['external/miracl','external/proxylib'],
               extra_link_args=['-Lexternal/miracl'],
               # extra_link_args=['-Wl,--export-dynamic'],
               libraries=[":external/miracl/miracl.a"]
)

setup(name='pypre',
     version='1.0',
     description='Python wrapper for custom C++ extension',
     ext_modules=[module])