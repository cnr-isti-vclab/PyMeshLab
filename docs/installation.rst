.. _installation:

Install PyMeshLab
==================

You can easily install PyMeshLab using pip:

.. code-block:: none

   pip3 install pymeshlab

**Note**: if the installation fails, please double check that you are running
a **64bit** Python version.

Requirements
------------

PyMeshLab requires Python >= 3.7 (64 bit), and `numpy`_.
`Polyscope`_ is optional to render the MeshSet state.

.. _numpy: https://numpy.org/
.. _Polyscope: https://polyscope.run/

Nightly builds
--------------

PyMeshLab has an automatic build system that allows to generate python wheels
for each update and patch done in the source code of the project.
You can try the last nightly build by following the steps listed in `this wiki
page <https://github.com/cnr-isti-vclab/PyMeshLab/wiki/How-to-install-the-last-nightly-version>`_
of the official GitHub repository.

For nightly builds, we suggest to use `Python Virtual Environments <https://docs.python.org/3/tutorial/venv.html>`_
and to avoid making them the main PyMeshLab installation.
