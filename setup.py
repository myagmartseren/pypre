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
               libraries=["miracl",'proxylib'],
               extra_link_args=["-Wl,--no-as-needed"]
)

setup(name='pypre',
      license='Apache',
      author="Myagmartseren",
      author_email='myagmartseren7@gmail.com',
      description='Proxy Re-encryption Python library',
      url='https://github.com/myagmartseren/pre_python',
      ext_modules=[module],
      include_dirs=['external/proxylib/','external/miracl/']
)
