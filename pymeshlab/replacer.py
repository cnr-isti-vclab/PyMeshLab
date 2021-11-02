import re
from pathlib import Path
from shutil import copyfile
import os


def replace_all(text, dic):
    for i, j in dic.items():
        text = text.replace(i, j)
    return text

# replaces all the old filter names with the new ones, using the file
# keys.txt that contains the pairs {oldname, newname}
def replace_pymeshlab_filter_names(input_script, output_script = None):
    if output_script is None:
        output_script = input_script
    keys = {}
    this_dir = os.path.dirname(os.path.realpath(__file__))
    with open(this_dir + '/keys.txt') as f:
        for line in f:
            (key, val) = line.split()
            # make sure that the keys are methods appied on an object
            # (starting with '.' and ending with '(') or a parameter of a
            # function (the apply_filter function)
            keys['.' + key + '('] = '.' + val + '('
            keys['"' + key + '"'] = '"' + val + '"'
            keys["'" + key + "'"] = "'" + val + "'"

    txt = Path(input_script).read_text()
    txt = replace_all(txt, keys)

    with open(output_script, "w") as myfile:
        myfile.write(txt)

    print(input_script + ' filter names have been replaced and saved in ' + output_script + '.')
