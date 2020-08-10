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
urllib.request.urlretrieve(url, this_directory + '/' + filename)

with zipfile.ZipFile(filename, 'r') as zip_ref:
    zip_ref.extractall('pymeshlab/')

os.remove(this_directory + '/' + filename)
