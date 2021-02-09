#!/usr/bin/env python
#
# main.py :
#               Setup this project according to platform
#				this replaces the improper makefile that used to call scons
#
# Copyright © Noé Perard-Gayot 2020.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #
#

#
#	remove unnecesary files
#
def clean():
    pass
#
#	print help info
#	TODO : automate this
#
def _help():
    pass

#
#	handle command line argument
#
def arg_condition( condition : list) -> list:
    retval = []
    from sys import argv
    for cd in condition :
        retval += [t for t in argv[1:] if t.startswith(cd)] 
    return retval

#
#	Main setup function
#
def main():
    

    if arg_condition(["--help", "-h"]):
        _help()
        return

    json = arg_condition(["--json", "-j", "j", "json"])
    try :
        json_config = json[0].split('=')[1]
    except :
        json_config = None
        pass
    print(json_config)

    if arg_condition(["--build", "-b", "-b", "build"]):
        if json_config != None :
            from functions import build
            build.build(str(json_config))

    if arg_condition(["--shortcut", "-s", "s", "shortcut"]):
        from shortcuts import shortcut
        shortcut()


# Run setup program
if __name__ == "__main__":
    # add functions to path:
    import sys
    # insert at 1, 0 is the script path (or '' in REPL)
    sys.path.insert(1, './functions')
    main()