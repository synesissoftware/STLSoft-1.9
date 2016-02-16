cmake_minimum_required(VERSION 3.9 FATAL_ERROR)
project(STLSoft
    DESCRIPTION "STLSoft is a suite of libraries that provide STL extensions and facades over operating-system and technology-specific APIs."
    LANGUAGES C CXX)

# Directory for CMake specific extensions and source files.
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# Set build type to Debug if this is a Git repository.
# Otherwise set to Release.
# Unless user overrides on the command line.
include(BuildType)

# Handle version number
set(RX_WS "[ \t\r\n]")
file(READ "${CMAKE_SOURCE_DIR}/include/stlsoft/stlsoft.h" _header_file)
string(REGEX MATCH "#define${RX_WS}+_STLSOFT_VER_MAJOR${RX_WS}+([0-9]+)" MAJOR_DUMMY ${_header_file})
set(_VERSION_MAJOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#define${RX_WS}+_STLSOFT_VER_MINOR${RX_WS}+([0-9]+)" MINOR_DUMMY ${_header_file})
set(_VERSION_MINOR ${CMAKE_MATCH_1})
string(REGEX MATCH "#define${RX_WS}+_STLSOFT_VER_REVISION${RX_WS}+([0-9]+)" PATCH_DUMMY ${_header_file})
set(_VERSION_PATCH ${CMAKE_MATCH_1})

# Set project version number here
set(PROJECT_VERSION_MAJOR ${_VERSION_MAJOR})
set(PROJECT_VERSION_MINOR ${_VERSION_MINOR})
set(PROJECT_VERSION_PATCH ${_VERSION_PATCH})
set(PROJECT_VERSION "${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}")

# Adhere strictly to C and C++ standards plus extensions.
# These are actually useless since we do not compile anything.
# They merely state our intension.
set(CMAKE_C_STANDARD 90)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON) # GNU extensions and POSIX standard
set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# #########################################################
# Preparations for installing

# Provides install directory variables as defined by the GNU Coding Standards.
include(GNUInstallDirs)

# #########################################################
# Build

# Our library is header-only, so from CMake's perspective
# only interfaces are necessary, no source code.
add_library(STLSoft INTERFACE)
target_include_directories(STLSoft INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>)

# This does not actually install anything...
install(TARGETS STLSoft
    EXPORT project-targets
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
# ... and we have to manually copy the header files.
install(DIRECTORY
    ${CMAKE_SOURCE_DIR}/include/acestl
    ${CMAKE_SOURCE_DIR}/include/atlstl
    ${CMAKE_SOURCE_DIR}/include/comstl
    ${CMAKE_SOURCE_DIR}/include/dotnetstl
    ${CMAKE_SOURCE_DIR}/include/inetstl
    ${CMAKE_SOURCE_DIR}/include/mfcstl
    ${CMAKE_SOURCE_DIR}/include/platformstl
    ${CMAKE_SOURCE_DIR}/include/rangelib
    ${CMAKE_SOURCE_DIR}/include/stlsoft
    ${CMAKE_SOURCE_DIR}/include/unixstl
    ${CMAKE_SOURCE_DIR}/include/winstl
    ${CMAKE_SOURCE_DIR}/include/wtlstl
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# #########################################################
# Export and install the project

string(TOLOWER ${PROJECT_NAME} EXPORT_NAME)

# Prepare a config and config-version files
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/cmake/${EXPORT_NAME}-config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake
    INSTALL_DESTINATION ${LIB_INSTALL_DIR}/${EXPORT_NAME}/cmake
)
write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY AnyNewerVersion
)

export(EXPORT project-targets
    FILE "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-targets.cmake"
    NAMESPACE "${PROJECT_NAME}::"
)

# Install to GNU type subdirs under CMAKE_INSTALL_PREFIX
install(EXPORT project-targets
    NAMESPACE "${PROJECT_NAME}::"
    FILE "${EXPORT_NAME}-targets.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)
install( FILES
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake/${EXPORT_NAME}-config-version.cmake"
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${EXPORT_NAME}
)

# Store the current build directory in the CMake
# user package registry for package.
# This helps dependent projects use a package
# from the current project’s build tree,
# i.e. without installing it.
export(PACKAGE "${PROJECT_NAME}")

