from setuptools import setup

setup(name='pymeshlab',
      version='0.1',
      description='A Python interface to MeshLab',
      url='https://github.com/cnr-isti-vclab/PyMeshLab',
      author='Alessandro Muntoni, Paolo Cignoni',
      author_email='alessandro.muntoni@isti.cnr.it',
      license='GPL3',
      packages=['pymeshlab', 'pymeshlab.tests'],
      include_package_data=True,
      zip_safe=False)
