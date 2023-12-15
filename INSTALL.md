# STLSoft - Install <!-- omit in toc -->

> Note
> **STLSoft-1.9** is now obsolete; please instead use **STLSoft 1.10**, which may be obtained from https://github.com/synesissoftware/STLSoft-1.10


----


## Table of Contents <!-- omit in toc -->

- [Installing](#installing)
  - [As downloaded archive, using environment variables](#as-downloaded-archive-using-environment-variables)
  - [Cloning project, using environment variables](#cloning-project-using-environment-variables)
- [Use of environment variables in other open-source projects.](#use-of-environment-variables-in-other-open-source-projects)
- [Understanding the top-level project build scripts](#understanding-the-top-level-project-build-scripts)


## Installing

There are two options for installing **STLSoft**, depending on how you obtain it.


### As downloaded archive, using environment variables

If you obtain the latest release as an archive, e.g. from the [STLSoft SourceForge project](https://sourceforge.net/projects/stlsoft/):

1. Download the latest distribution, e.g. **STLSoft-1.9.136.zip**;

2. Unzip it to a directory of your choice, as in:

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ unzip STLSoft-1.9.136.zip
```

3. Define an environment variable `STLSOFT`, whose value is the directory in which you unzipped it, e.g. `STLSOFT=~/open-source/STLSoft-1.9.136`, and then specify `$(STLSOFT)/include` (**UNIX**) or `%STLSOFT%\include` (**Windows**) in your project files and makefiles;


### Cloning project, using environment variables

If you clone the project from https://github.com/synesissoftware/STLSoft-1.9:

1. Clone, e.g. **STLSoft-1.9.136.zip**;

```bash
$ mkdir -p ~/open-source
$ cd ~/open-source
$ git clone -b master https://github.com/synesissoftware/STLSoft-1.9
```

2. Define an environment variable `STLSOFT`, whose value is the directory in which you cloned it, e.g. `STLSOFT=~/open-source/STLSoft-1.9`, and then specify `$(STLSOFT)/include` (**UNIX**) or `%STLSOFT%\include` (**Windows**) in your project files and makefiles;


----


## Use of environment variables in other open-source projects.

Unless you are certain that your projects, and all the projects upon which they depend, all use **STLSoft** via **CMake** then it is recommended that you define an `STLSOFT` environment variable.

For example, if you're using **UNIX** and you install to
**/usr/local/stlsoft/stlsoft-1.9.136**
then you should set the environment variable `STLSOFT` to
**/usr/local/stlsoft/stlsoft-1.9.136**
in which case the file `stlsoft/stlsoft.h`, for example, will be located in `$STLSOFT/include/stlsoft/stlsoft.h`.

Conversely, if you're using **Windows** and you intall to
**C:\3pty\STLSoft\stlsoft-1.9.136**
then you should set the environment variable `STLSoft` to
**C:\3pty\STLSoft\stlsoft-1.9.136**
in which case the file `stlsoft/stlsoft.h`, for example, will be located in `C:\3pty\STLSoft\stlsoft-1.9.136\stlsoft\stlsoft.h`.

The makefiles / project files of several other open-source projects expect this symbol, including:

| Project     | Project home                                  |
| ----------- | --------------------------------------------  |
| b64         | https://github.com/synesissoftware/b64        |
| CLASP       | https://github.com/synesissoftware/CLASP      |
| cstring     | https://github.com/synesissoftware/cstring    |
| FastFormat  | https://github.com/synesissoftware/FastFormat |
| libCLImate  | https://github.com/synesissoftware/libCLImate |
| Pantheios   | https://github.com/synesissoftware/Pantheios  |
| recls       | https://github.com/synesissoftware/recls      |
| shwild      | https://github.com/synesissoftware/shwild     |
| VOLE        | https://github.com/synesissoftware/VOLE       |
| xTests      | https://github.com/synesissoftware/xtests     |

**NOTE**: If you're using **STLSoft** on `UNIX`, you might want to apply `dos2unix` over all the files before using it. You *must* do this if you're using the **SunPro C compiler** - this action is carried out automatically, for example, by the **Pantheios** makefile(s).


----


## Understanding the top-level project build scripts

This project comes with a number of scripts useful for building with **CMake**, as follows:

| Script                    | Purpose |
| ------------------------- | ------- |
| **prepare_cmake.sh**          | Creates/reinitialises the **CMake** build script(s).<br/><br/>This is the primary script, and is used to generate all the **CMake** build artefacts. We recommend that you use the command  as follows:</br></br>&nbsp;&nbsp;&nbsp;&nbsp;`./prepare_cmake.sh -m -v`.<br/><br/>The flag `-m` executes a build upon successful generation completes, and the flag `-v` generates verbose makefile(s). Use `./prepare_cmake.sh --help` for further information. |
| **build_cmake.sh**            | Executes **CMake**-generated artefacts to (re)build project.<br/><br/>Performs a (re)build, meaningful only once `prepare_cmake.sh` has been run once to generate all the **CMake** build artefacts.<br/><br/>Use `./build_cmake.sh --help` for further information. |
| **clean_cmake.sh**            | Executes **CMake**-generated artefacts to clean project.<br/><br/>Performs a (re)build, meaningful only once `prepare_cmake.sh` has been run once to generate all the **CMake** build artefacts and a build has been run.<br/><br/>Use `./clean_cmake.sh --help` for further information. |
| **run_all_unit_tests.sh**     | Runs all (matching) unit-test programs.<br/><br/>Performs a build and then recursively runs and executes all (excutable programs) matching the shell patterns `test_*` and `test.*`.<br/><br/>Use `./run_all_unit_tests.sh --help` for further information. |
| **remove_cmake_artefacts.sh** | Removes all known **CMake** artefacts.<br/><br/>Removes all known **CMake** build artefacts from the build directory (currently hard-coded to `./_build`) to prepare for complete regeneration using `prepare_cmake.sh`.<br/><br/>Use `./remove_cmake_artefacts.sh --help` for further information. |


<!-- ########################### end of file ########################### -->

