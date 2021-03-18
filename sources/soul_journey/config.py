# Copyright © Noé Perard-Gayot 2021.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #

def can_build(env, platform):
    return env.module_check_dependencies("soul_journey", ["utility_ai"])

def configure(env):
    pass


def get_doc_classes():
    return [
        "GridNode",
    ]


def get_doc_path():
    return "doc_classes"
