#!/usr/bin/env python
#
# shortcuts.py :
#               helper to generate shorcuts after compilation
#
# Copyright © Noé Perard-Gayot 2020.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #
#

def _description(JsonConfig :str):
    d = JsonConfig['project']
    return d['description']


def _projectName(JsonConfig :str):
    d = JsonConfig['project']
    return d['name']

#
#   Desktop file generation
#	This creates a shortcut for linux users
#
def generateDesktopFile(path):
    text = "[Desktop Entry]\nName={Name}\nComment={Comment}\nExec={bin} {args}\nIcon={icon}\nTerminal={bterm}\nType=Application"
    # find binary
    bin_path = str()
    project_path = str()
    icon_path = str()
    try:
        from functions import findFiles
        from functions import findFilesList
        bin_path = findFilesList(
            _godotPath() + "/bin", [str(_projectName()).lower(), ".tools.", "bin"])[0]
        project_path = findFiles(str(_projectName()), ".godot")[0]
        icon_path = findFiles(str(_projectName()), "icon")[0]
    except:
        raise
    # create desktop file
    try:
        # \see import config
        arguments = "${path_to_project} --editor --upwards".format(
            path_to_project=project_path)
        d = text.format(Name=_projectName(), Comment=_description(),
                        bin=bin_path, args=arguments, icon=icon_path, bterm="true")

        d_file = open(path, "w")
        d_file.writelines(d)
        d_file.close()
    except:
        raise


#
#	will create a shortcut to the editor
#
def shortcut():
    try:
        from os import getcwd
        from functions import isLinux
        if isLinux():
            generateDesktopFile(getcwd() + "/" + _projectName() + ".desktop")
        else:
            raise NotImplementedError
    except:
        raise