#!/usr/bin/env python
#
# functions.py : 
#             useful functions for the python modules in this folder
#
# Copyright © Noé Perard-Gayot 2020.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #
#

def JsonConfig(path = './', override_globals = False) ->dict :
    '''
    importJsonConfig() :
    import our json file as a dict, into the global()[]
    '''
    from os.path import isfile
    from .platform import findFiles
    if not isfile(path) :
        path = findFiles(path, "config.json")
    json_dict = dict()
    f = None
    try:
        f = open(path, "r")
        s = str(f.read())
        from json import loads
        json_dict = loads(s)
        if override_globals : 
            for k, v in json_dict.items() :
                globals()[k] = v
    except:
        raise
    finally:
        if f != None :
            f.close()
    return json_dict