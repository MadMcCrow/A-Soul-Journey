#!/usr/bin/env python
#
# Custom.py : 
#             custom.py file for building godot for this project
#
# Copyright © Noé Perard-Gayot 2021.                                                                                        #
# Licensed under the MIT License. You may obtain a copy of the License at https://opensource.org/licenses/mit-license.php   #
#

# import functions: 
from godotbuildtool.functions.platform import findFolder
from godotbuildtool.functions.platform import getPlatform
from godotbuildtool.functions.platform import isLinux
from godotbuildtool.functions.platform import isWindows
from godotbuildtool.functions.platform import isArm
from godotbuildtool.functions.platform import isMacOs
from godotbuildtool.functions.git      import getGitFolders


extra_suffix = "soul_journey"
custom_modules = findFolder("../", "modules")

bits     = getPlatform()[0]
arch     = getPlatform()[2]
platform = getPlatform()[1]

#target (debug|release_debug|release)
target="debug"

# optimize is  (speed|size) 
optimize = "speed"

# Build the tools (a.k.a. the Godot editor) (yes|no)
tools = True

# tests: Build the unit tests (yes|no)
tests = False

# use_precise_math_checks: Math checks use very precise epsilon (debug option) (yes|no)
use_precise_math_checks = False

# disable deprecated options : fails instead to keep this project updated
deprecated = False
minizip = True
xaudio2 =  isWindows()

## [ built-in option ]
#builtin_bullet: Use the built-in Bullet library (yes|no)
#builtin_certs: Use the built-in SSL certificates bundles (yes|no)
#builtin_enet: Use the built-in ENet library (yes|no)
#builtin_freetype: Use the built-in FreeType library (yes|no)
#builtin_glslang: Use the built-in glslang library (yes|no)
#builtin_libogg: Use the built-in libogg library (yes|no)
#builtin_libpng: Use the built-in libpng library (yes|no)
#builtin_libtheora: Use the built-in libtheora library (yes|no)
#builtin_libvorbis: Use the built-in libvorbis library (yes|no)
#builtin_libvpx: Use the built-in libvpx library (yes|no)
#builtin_libwebp: Use the built-in libwebp library (yes|no)
#builtin_wslay: Use the built-in wslay library (yes|no)
#builtin_mbedtls: Use the built-in mbedTLS library (yes|no)
#builtin_miniupnpc: Use the built-in miniupnpc library (yes|no)
#builtin_opus: Use the built-in Opus library (yes|no)
#builtin_pcre2: Use the built-in PCRE2 library (yes|no)
#builtin_pcre2_with_jit: Use JIT compiler for the built-in PCRE2 library (yes|no)
#builtin_recast: Use the built-in Recast library (yes|no)
#builtin_rvo2: Use the built-in RVO2 library (yes|no)
#builtin_squish: Use the built-in squish library (yes|no)
#builtin_vulkan: Use the built-in Vulkan loader library and headers (yes|no)
#builtin_xatlas: Use the built-in xatlas library (yes|no)
#builtin_zlib: Use the built-in zlib library (yes|no)
#builtin_zstd: Use the built-in Zstd library (yes|no)


## [ general compilation option ]
vsproj =  isWindows()  # vsproj: Generate a Visual Studio solution (yes|no)
verbose  = False 
progress = False

# warnings: Level of compilation warnings (extra|[all]|moderate|no)
# werror: Treat compiler warnings as errors (yes|[no]) 
# dev: If yes, alias for verbose=yes warnings=extra werror=yes (yes|no)
# macports_clang: Build using Clang from MacPorts ([no]|5.0|devel)
# disable_3d: Disable 3D nodes for a smaller executable (yes|[no])
# disable_advanced_gui: Disable advanced GUI nodes and behaviors (yes|no)
# no_editor_splash: Don't use the custom splash screen for the editor (yes|no)
# system_certs_path: Use this path as SSL certificates default for editor (for package maintainers)


## [ specific compilation option ]
# CXX = g++
# CC   = gcc
# LINK = gcc
# CCFLAGS
# CFLAGS
# CXXFLAGS
# LINKFLAGS
use_llvm    =  True
use_lld     =  use_llvm
use_thinlto =  False  # https://clang.llvm.org/docs/ThinLTO.html Link time optimisation
use_static_cpp =  isWindows()
#use_coverage: Test Godot coverage (yes|no)
#use_ubsan: Use LLVM/GCC compiler undefined behavior sanitizer (UBSAN) (yes|no)
#use_asan: Use LLVM/GCC compiler address sanitizer (ASAN)) (yes|no)
#use_lsan: Use LLVM/GCC compiler leak sanitizer (LSAN)) (yes|no)
#use_tsan: Use LLVM/GCC compiler thread sanitizer (TSAN)) (yes|no)
pulseaudio =  isLinux()
udev       =  isLinux()
execinfo   =  isWindows()

#debug_symbols = 'yes' if "debug" in str(target) else 'no'
#separate_debug_symbols = False

# disable touch input events
touch = False

## [Modules ]

module_opensimplex_enabled      = True
module_denoise_enabled          = True  # ligtmap denoiser
module_assimp_enabled           = True # Open Asset Import Library
module_freetype_enabled         = True
module_csg_enabled              = True  # constructive solid geometry
module_glslang_enabled          = True # Reference compiler front end for the OpenGL ES and OpenGL shading languages.  
module_hdr_enabled              = True
module_lightmapper_rd_enabled   = True
module_regex_enabled            = True
module_gdnavigation_enabled     = True  # TODO/FIXME :Godot will not load without this module

# Godot scripting
module_visual_script_enabled  = True    # visual scripting can be used for low importance stuff
module_gdnative_enabled       = False
module_gdscript_enabled       = True    # GDScript is used to try stuff
module_mono_enabled           = False

module_bullet_enabled           = True
module_camera_enabled           = False # no camera video feed
module_gridmap_enabled          = False # we use our custom system ours is simpler
module_gltf_enabled             = False # no gltf for now.

# Mobile
module_gamecenter_enabled       = False # iOS gamecenter
module_camera_iphone_enabled    = False
module_icloud_enabled           = False
module_inappstore_enabled       = False
module_mobile_vr_enabled        = False
module_arkit_enabled            = False
module_mbedtls_enabled          =  isArm(arch)


# Video Codecs Support
module_vorbis_enabled = False
module_webm_enabled   = False
module_webp_enabled   = False
module_theora_enabled = False

# Audio Codecs Support
module_stb_vorbis_enabled   = True
module_ogg_enabled          = True
module_opus_enabled         = True

# Image
module_svg_enabled    = True
module_tga_enabled    = True
module_pvr_enabled    = True
module_bmp_enabled    = True
module_jpg_enabled    = True

# image compression
module_squish_enabled           = True  
module_basis_universal_enabled  = True  # Basis Universal is a "supercompressed" GPU texture compression system
module_cvtt_enabled             = True
module_dds_enabled              =  isWindows()  # DirectDraw Surface

# OpenEXR
module_tinyexr_enabled = False

# The V-HACD library decomposes a 3D surface into a set of "near" convex parts.
module_vhacd_enabled = False


# Network protocols
module_webrtc_enabled    = False
module_websocket_enabled = False
module_upnp_enabled      = False
module_enet_enabled      = False
module_etc_enabled       = False
module_jsonrpc_enabled   = False

# Xatlas
module_xatlas_unwrap_enabled: False
