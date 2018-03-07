from distutils.core import setup
from distutils.extension import Extension

setup(
    name='yo-world',
    version='0.1',
    ext_modules=[
        Extension(
            'this_is_hello',
            sources=['this_is_hello.cpp'],
            libraries=['boost_python-mt'],
        )
    ])
