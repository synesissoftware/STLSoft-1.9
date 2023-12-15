# STLSoft - Known Issues:

> Note
> **STLSoft-1.9** is now obsolete; please instead use **STLSoft 1.10**, which may be obtained from https://github.com/synesissoftware/STLSoft-1.10


----


## STLSoft 1.10 Known Issues:

 * There are some problems with GCC 4+ in compiling the fixed array classes with the subscript operators.

 * The GCC atomic integer APIs are not yet used. This is planned for the future.

 * The documentation is still hopeless. This will be addressed in the release of 1.12.

 * Several `unixstl::system_traits` methods are declared but not defined, with the intention to flesh them out from Linux system calls (and have emulations/workarounds for other architectures)


<!-- ########################### end of file ########################### -->

