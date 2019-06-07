import sys
import os
import shutil

def copy(src, dest):
    try:
        shutil.copytree(src, dest)
    except OSError as e:
        print('Directory not copied. Error: %s' % e)

def make_new_proj(projname):
    copy("template", projname)

if (__name__ == "__main__"):
    if (len(sys.argv)>1):
        for name in sys.argv[1:]:
            make_new_proj(name)

    else:
        print("Must specify project name")

    