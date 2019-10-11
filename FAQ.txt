============================================================================
STLSoft - FAQ

; Created:  29th March 2002
; Updated:  11th October 2019

============================================================================



The FAQ list is under (constant) development. If you post a question on the
Tutorials forum (https://sourceforge.net/forum/forum.php?forum_id=903893)
it will be used to create one.

FAQs:
=====

Q1: "How do I build STLSoft?"

A1:
  You don't: STLSoft is 100% header-only, so all you have to do is #include
  it. We do recommend that you use an environment variable, e.g. STLSOFT, so
  that you can use new versions of the library from your projects without
  disruption.


Q2: "How do I install STLSoft?"

A2:
  There are three steps:
    1. Download the latest distribution of STLSoft, from http://stlsoft.org/
    2. Unzip it to a directory of your choice, e.g /3pty/stlsoft-1.9.98
    3. Define an environment variable STLSOFT, whose value is the directory
       in which you unzipped it, e.g. STLSOFT=/3pty/stlsoft-1.9.98


Q3: "How do I use STLSoft?"

A3:
  Assuming you've installed it (as per instructions A2):

  In your IDE settings, add the include directory $(STLSOFT)/include, OR in
  your makefiles, add the include directory:
    * -I$STLSOFT/include (if you're on UNIX), OR
    * -I%STLSOFT%/include (if you're on Windows)


Q4: "Does STLSoft have unit-tests?"

A4:
  Yes, but for various reasons they're not available with the STLSoft 1.9
  distribution. When STLSoft 1.11 is released it will include unit-tests.


Q5: "What is STLSoft 1.10?"

A5:
  STLSoft 1.10 is the next version of STLSoft. As well as containing several
  new components, it also incorporates wholesale refactoring of code and of
  the structural aspects (including packaging and directories). STLSoft 1.10
  is available (in beta form) from GitHub:

  https://github.com/synesissoftware/STLSoft-1.10

=============================== End of file ================================
