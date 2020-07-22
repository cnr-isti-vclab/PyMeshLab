import platform,os
#if platform.system()=='Windows':
this_path = os.path.abspath(os.path.dirname(__file__))
first_path = os.path.join(this_path, 'lib')
second_path = os.path.join(first_path, 'meshlab')
os.environ['PATH'] = first_path + '\\;' + os.environ['PATH']
os.environ['PATH'] = second_path + '\\;' + os.environ['PATH']

#from . import pymeshlabserver
