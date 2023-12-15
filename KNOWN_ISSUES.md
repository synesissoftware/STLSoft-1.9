============================================================================
STLSoft - Known Issues:

; Created:  29th March 2002
; Updated:  9th September 2015

============================================================================


STLSoft 1.9 Known Issues:
-------------------------

 * There are some problems with GCC 4+ in compiling the fixed array classes
   with the subscript operators.

 * The GCC atomic integer APIs are not yet used. This is planned for the
   future.

 * The documentation is still hopeless. This will be addressed in the
   release of 1.12.

 * Several unixstl::system_traits methods are declared but not defined, with
   the intention to flesh them out from Linux system calls (and have
   emulations/workarounds for other architectures)

=============================== End of file ================================
