import glob
import os
from setuptools import Extension, setup

os.environ["CC"] = "g++"
os.environ["CXX"] = "g++"

module = Extension("pypre",
               language="c++",
               sources=[f for f in glob.glob('src/*.c')],
               include_dirs=['external/miracl','external/proxylib'],
               library_dirs=['external/miracl','external/proxylib'],
               extra_link_args=['-Lexternal/miracl'],
               # extra_link_args=['-Wl,--export-dynamic'],
               libraries=["external/miracl/miracl.a",'proxylib']
)

setup(name='pypre',
      license='Apache',
      author="Myagmartseren",
      author_email='myagmartseren7@gmail.com',
      description='Proxt Re-encryption Python library',
      url='https://github.com/myagmartseren/pre_python',
      ext_modules=[module],
      include_dirs=['external/proxylib/','external/miracl/']
)
