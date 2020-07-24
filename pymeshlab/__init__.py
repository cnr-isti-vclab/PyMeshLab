import platform
import os
this_path = os.path.abspath(os.path.dirname(__file__))
first_path = os.path.join(this_path, 'lib')
second_path = os.path.join(first_path, 'meshlab')
if platform.system() == 'Windows':
	os.environ['PATH'] = first_path + '\\;' + os.environ['PATH']
	os.environ['PATH'] = second_path + '\\;' + os.environ['PATH']
else:
	os.environ['PATH'] = first_path + ':' + os.environ['PATH']
	os.environ['PATH'] = second_path + ':' + os.environ['PATH']
	
print("\n$$$$$$$PATH:" + os.environ['PATH'] + "\n")
