import sys,os
this_path = os.path.abspath(os.path.dirname(__file__))
print("---- argv: " + sys.argv[0])
print("---- path: " + this_path)
first_path = os.path.join(this_path, 'lib')
sys.path.append(first_path)
sys.path.append(os.path.join(first_path, 'meshlab'))