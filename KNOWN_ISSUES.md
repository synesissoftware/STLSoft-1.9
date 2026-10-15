# STLSoft - Known Issues:

> **Semi-frozen / maintenance**
>
> **STLSoft-1.9** is a historical, maintenance-only line. It remains available for
> consumers that must stay on the 1.9 API (for example compatibility matrices),
> but all **new development** and **new consumers** MUST use
> **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
> Feature work belongs on tip; this repository only receives recognition and
> packaging fixes required by historical consumers.

----


## Maintenance policy

* Feature work and new consumers belong on **[synesissoftware/STLSoft](https://github.com/synesissoftware/STLSoft)** (tip).
* This 1.9 line is **semi-frozen**: recognition / packaging fixes for historical consumers only.


## STLSoft 1.9 Known Issues:

 * There are some problems with GCC 4+ in compiling the fixed array classes with the subscript operators.

 * The GCC atomic integer APIs are not yet used. This is planned for the future.

 * The documentation is still hopeless. This will be addressed in the release of 1.12.

 * Several `unixstl::system_traits` methods are declared but not defined, with the intention to flesh them out from Linux system calls (and have emulations/workarounds for other architectures)


<!-- ########################### end of file ########################### -->

