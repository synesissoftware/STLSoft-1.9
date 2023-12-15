# STLSoft-1.9

> Note
> **STLSoft-1.9** is now obsolete; please instead use **STLSoft 1.10**, which may be obtained from https://github.com/synesissoftware/STLSoft-1.10


----


## Table of Contents <!-- omit in toc -->

- [STLSoft-1.9](#stlsoft-19)
  - [Introduction](#introduction)
  - [Installation](#installation)
  - [Components](#components)
  - [Examples](#examples)
  - [Project Information](#project-information)
    - [Where to get help](#where-to-get-help)
    - [Contribution guidelines](#contribution-guidelines)
    - [Dependencies](#dependencies)
    - [Related projects](#related-projects)
    - [License](#license)


## Introduction

**STLSoft** is a suite of C and C++ libraries that provides:
- STL extensions;
- General-purpose utility components;
- Facades over operating-system and technology-specific APIs.

The overarching characteristic of STLSoft is that it is *lightweight*. That sounds great, but what does it actually mean? Specifically, the **STLSoft** libraries share the following characteristics:

- "**100% header-only**" - all components within the libraries are entirely defined within header files, meaning that users need only `#include` the requisite files to access the functionality;
- "**Intersecting Conformance**" -  similar, but not-identical, components from different projects (e.g. **UNIXSTL** and **WinSTL**) are structurally conformant (they share compatible syntax, and corresponding semantics, without being related by type) only to the degree of the intersection of identical functionality, rather than employing significant additional functionality to achieve total structural conformance. For example, though both the `unixstl::filesystem_traits` and `winstl::filesystem_traits` traits classes provide the `stat()` and `f!stat()` operations, `lstat()` is provided only by `unixstl::filesystem_traits`;
- **Maximum Cohesion with Minimal Coupling** - achieved by extensive use of generalising mechanisms, particularly "*shims*", e.g. types that manipulate character strings are able to interact with arbitrary string types, not just `char const*` and `std::string`;
- **Very High Efficiency** - Second only to *Robustness*, all components in the libraries are implemented with a view to maximum efficient. This is aided by the extensive use of efficient utility classes, such as `stlsoft::auto_buffer` and `stlsoft::scoped_handle`;

**NOTE**: It is important to understand that _**STLSoft** is not a framework_. Each library component is as "thin" as possible to provide its given function. The intent is that STLSoft components are used as building blocks for writing higher level components - applications, classes, libraries, servers. **STLSoft** has been used extensively in the development of software in all these guises.

... more information TBC as we move towards a full (non-beta) release


## Installation

There are two main ways to install **STLSoft-1.9**:

1. As downloaded archive, using environment variables;
2. Cloning project, using environment variables;

See [INSTALL.md](./INSTALL.md) for details of these options, and also for an explanation of the top-level build scripts in the project.


## Components

T.B.C.


## Examples

T.B.C.


## Project Information

### Where to get help

[GitHub Page](https://github.com/synesissoftware/STLSoft-1.9 "GitHub Page")

### Contribution guidelines

Defect reports, feature requests, and pull requests are welcome on https://github.com/synesissoftware/STLSoft-1.9.

If you'd like to help out with the project, please raise an issue via [GitHub Issues Page](https://github.com/synesissoftware/STLSoft-1.9/issues "GitHub Issues Page") - you'll be very welcome!

### Dependencies

There are no dependencies

### Related projects

Projects that depend on **STLSoft** - though for some it is only for test - include:

* [**b64**](https://github.com/synesissoftware/b64)
* [**cstring**](https://github.com/synesissoftware/cstring)
* [**FastFormat**](https://github.com/synesissoftware/FastFormat)
* [**libpath**](https://github.com/synesissoftware/libpath)
* [**Pantheios**](https://github.com/synesissoftware/Pantheios)
* [**recls**](https://github.com/synesissoftware/recls)
* [**shwild**](https://github.com/synesissoftware/shwild)
* [**UNIXem**](https://github.com/synesissoftware/UNIXem)
* [**xTests**](https://github.com/synesissoftware/xTests)

### License

**STLSoft** is released under the 3-clause BSD license. See [LICENSE](./LICENSE) for details.


<!-- ########################### end of file ########################### -->

