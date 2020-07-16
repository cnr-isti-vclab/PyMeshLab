import sys
import platform

for arg in sys.argv:
	if arg=='--includes':
		includes = '"' + sys.exec_prefix + '\\include' + '"'
		includes = includes.replace('\\', '/')
		print(includes)
	elif arg=='--extension-suffix':
		version = str(platform.python_version())
		version = version.replace('.', '')[:-1]
		print('cp-'+version+'-win_amd64')