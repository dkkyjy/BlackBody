import numpy as np
from distutils.core import setup, Extension

BlackBody_module = Extension('BlackBody',
                             sources=['BlackBody.c'],
                             include_dirs=[np.get_include()],
                            )

setup(name = 'BlackBody',
      version = '0.1',
      author = 'Duan Kaikai',
      description = 'BlackBody emission',
      ext_modules = [BlackBody_module],
      py_modules = ['BlackBody'],
     )
