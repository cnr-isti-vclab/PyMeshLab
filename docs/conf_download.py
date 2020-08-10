from setuptools import setup
import platform
import sys
import os
import urllib.request
import zipfile

#short sha of las tag
import subprocess
tmp = 'git rev-list --tags --max-count=1'
process = subprocess.Popen(tmp.split(), stdout=subprocess.PIPE)
sha, error = process.communicate()
sha=str(sha)[2:42]
bash_command = 'git describe --tags ' + sha
process = subprocess.Popen(bash_command.split(), stdout=subprocess.PIPE)
last_tag, error = process.communicate()
last_tag=str(last_tag)[2:-3]
print(last_tag)

osused = 'Linux' #'macOS', 'Windows'
pythonversion = '3.8'

baseurl = 'https://github.com/alemuntoni/PyMeshLab/releases/download/' + last_tag + '/'
filename = 'PyMeshLab_' + osused + '_python' + pythonversion + '.zip'
url = baseurl + filename


print('Downloading ' + filename)
urllib.request.urlretrieve(url, './' + filename)

with zipfile.ZipFile(filename, 'r') as zip_ref:
    zip_ref.extractall('../pymeshlab/')

os.remove(filename)

os.system("python3 conf.py")

# Configuration file for the Sphinx documentation builder.
#
# This file only contains a selection of the most common options. For a full
# list see the documentation:
# https://www.sphinx-doc.org/en/master/usage/configuration.html

# -- Path setup --------------------------------------------------------------

# If extensions (or modules to document with autodoc) are in another directory,
# add these directories to sys.path here. If the directory is relative to the
# documentation root, use os.path.abspath to make it absolute, like shown here.
#
sys.path.insert(0, os.path.abspath('../pymeshlab'))


# -- Project information -----------------------------------------------------

project = 'PyMeshLab'
copyright = '2020, Alessandro Muntoni, Paolo Cignoni'
author = 'Alessandro Muntoni, Paolo Cignoni'


# -- General configuration ---------------------------------------------------

# Add any Sphinx extension module names here, as strings. They can be
# extensions coming with Sphinx (named 'sphinx.ext.*') or your custom
# ones.
extensions = [ 
    'sphinx.ext.autodoc',
    'sphinx.ext.intersphinx',
    'sphinx.ext.autosummary',
    'sphinx.ext.napoleon',
    'readthedocs_ext.readthedocs'
]

# Add any paths that contain templates here, relative to this directory.
templates_path = ['_templates']

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path.
exclude_patterns = ['_build', 'Thumbs.db', '.DS_Store']


# -- Options for HTML output -------------------------------------------------

# The theme to use for HTML and HTML Help pages.  See the documentation for
# a list of builtin themes.
#
html_theme = 'alabaster'

# Add any paths that contain custom static files (such as style sheets) here,
# relative to this directory. They are copied after the builtin static files,
# so a file named "default.css" will overwrite the builtin "default.css".
html_static_path = ['_static']
