from setuptools import setup
import platform
import os

# this setup.py assumes that pymeshlab has been already built,
# installed in the pymeshlab directory of this repository
# and then deployed. See the scripts directory for more info.

# read the contents of README file
from os import path
this_directory = path.abspath(path.dirname(__file__))
with open(path.join(this_directory, 'README.md'), encoding='utf-8') as f:
    long_description = f.read()

f = open("PYML_VERSION", "r")
pymeshlabversion = f.read()

install_requires = ['numpy']

try:
    from wheel.bdist_wheel import bdist_wheel as _bdist_wheel
    class bdist_wheel(_bdist_wheel):
        def finalize_options(self):
            _bdist_wheel.finalize_options(self)
            self.root_is_pure = False
        def get_tag(self):
            a, b, c = super().get_tag()
            if platform.system() == 'Windows':
                platform_tag = 'win_amd64'
            elif platform.system() == 'Linux':
                platform_tag = 'manylinux1_x86_64'
            elif platform.system() == 'Darwin':
                platform_tag = 'macosx_10_11_x86_64'
            return a, b, platform_tag
except ImportError:
    bdist_wheel = None

setup(
    name='pymeshlab',
    version=pymeshlabversion,
    cmdclass={'bdist_wheel': bdist_wheel},
    description='A Python interface to MeshLab',
    long_description=long_description,
    long_description_content_type='text/markdown',
    url='https://github.com/cnr-isti-vclab/PyMeshLab',
    author='Alessandro Muntoni, Paolo Cignoni',
    author_email='alessandro.muntoni@isti.cnr.it',
    license='GPL3',
    install_requires=install_requires,
    packages=['pymeshlab', 'pymeshlab.tests'],
    include_package_data=True,
    zip_safe=False
)
