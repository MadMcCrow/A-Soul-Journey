#!/usr/bin/env python
#
# build.py :
#               functions dedicated to building this project
#				this replaces the improper makefile that used to call scons
#
# Copyright © Noé Perard-Gayot 2020.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #
#


def _godotPath(JsonConfig :str):
    d = JsonConfig['godot']
    return d['path']

def _customPath(JsonConfig :str):
    d = JsonConfig['project']
    return d['custom.py']


def _shared(JsonConfig :str):
    d = JsonConfig['build']
    return d['shared']

def _sources(JsonConfig :str):
    d = JsonConfig['project']
    return d['sources']



# color output
def _buildPrint(mode, txt, end='\n') :
    from .colors import color
    if "HEADER" in mode :
        color.print(color.HEADER, str(txt), end = end)
    if "BUILD" in mode :
        color.print(color.LESS, str(txt), end = end)
    if "INFO" in mode :
        color.print(color.OKBLUE, str(txt), end = end)
    if "ERROR" in mode :
        color.print(color.ERROR, str(txt), end = end)
    if "WARNING" in mode :
        color.print(color.WARNING,str(txt), end = end)


#
#   Exception class for when things go south
#
class BuildError(Exception):
    pass


#
#  measure time
#
def _buildTime():
    time = 0
    try:
        from time import perf_counter_ns as nsec
        time = nsec() / 1e9
    finally:
        return time


def _sharedLib():
    shared_modules = ""
    try:
        from .platform import getGitFolders
        from .platform import importJsonConfig
        module_list = getGitFolders(_sources())
        for module in module_list:
            module_shared_var_name = '_'.join(
                ['module', module.split('/', 1)[1], 'shared'])
            shared_modules += '='.join([module_shared_var_name, "yes"]) + ' '
    except:
        raise
    finally:
        return shared_modules


#
#	generate correct build command
#
def _buildCommand(custom_path: str, shared=False, extra=""):
    buildcommand = "scons -j{threads}  profile={custom} {extra}"
    import multiprocessing
    cpu = multiprocessing.cpu_count()
    Extra = (_sharedLib() if shared else " ") + extra
    return buildcommand.format(threads=cpu, custom=custom_path, extra=Extra)


#
#	analyse output text and scan for error
#
def _parseBuildOutput(line :str):
    out = line.replace('\n', '')
    error = False
    try: 
        import re
        error   = bool(re.match(r'[\w\W]*\serror(.*)$', str(line) ))
        warning = bool(re.match(r'[\w\W]*\swarning(.*)$', str(line) ))
    except:
        pass
    finally:
        if error :
            _buildPrint("ERROR", '\r' + out)
            return False
        _buildPrint( "WARNING" if warning else "BUILD" ,'\r' + out + " ", end='\x1b[1K' ) 
        return True
   


def _runScons(cmd : str, godot_path : str ) :
    import subprocess
    import shlex
    scons = subprocess.Popen(shlex.split(cmd), cwd=godot_path, stdout=subprocess.PIPE,  encoding="utf-8")
    while True:
        line = scons.stdout.readline()
        if not line:
            break
        if not _parseBuildOutput(line):
            if scons != None:
                scons.terminate()
            raise BuildError
    print('\r', end = '\x1b[1K') # clean terminal

#
#	build godot with custom profile
#
def build(json_path : str):
    # config is in json form now
    from .json import JsonConfig
    JsonConfig = JsonConfig(json_path)
    start_time = _buildTime()
    _buildPrint("HEADER", "--- build started  ---")
    try:
        cmd = _buildCommand(_customPath(JsonConfig), _shared(JsonConfig), "")
        _buildPrint("INFO", "building godot with command : \n{}".format(cmd))
        _runScons(cmd, _godotPath(JsonConfig))
    except:
        _buildPrint("ERROR" , "Failed to buid {} with {}".format(_godotPath(JsonConfig), _customPath(JsonConfig)))
        raise
    else:
        buildtime = _buildTime() - start_time
        _buildPrint("HEADER", "--- build finished in {:.3f} seconds ---".format(buildtime))
