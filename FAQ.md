# STLSoft - FAQ <!-- omit in toc -->

> Note
> **STLSoft-1.9** is now obsolete; please instead use **STLSoft 1.10**, which may be obtained from https://github.com/synesissoftware/STLSoft-1.10


----


The FAQ list is under (constant) development. If you post a question on the
Issues forum (https://github.com/synesissoftware/STLSoft-1.10/issues)
it will be used to create one.


## Table of Contents <!-- omit in toc -->

- [Q1: "How do I build STLSoft?"](#q1-how-do-i-build-stlsoft)
- [Q2: "How do I install STLSoft?"](#q2-how-do-i-install-stlsoft)
- [Q3: "How do I use STLSoft?"](#q3-how-do-i-use-stlsoft)
- [Q4: "Does STLSoft have unit-tests?"](#q4-does-stlsoft-have-unit-tests)
- [Q5: "Is STLSoft still relevant given the widespread support for 'Modern C++'?"](#q5-is-stlsoft-still-relevant-given-the-widespread-support-for-modern-c)
- [Q6: "What is STLSoft-1.10?"](#q6-what-is-stlsoft-110)


# FAQs: <!-- omit in toc -->

## Q1: "How do I build STLSoft?"

You don't!

STLSoft is 100% header-only, so all you have to do is `#include` it. We do recommend that you use an environment variable, e.g. `STLSOFT`, so that you can use new versions of the library from your projects without disruption.


## Q2: "How do I install STLSoft?"

Basically, there are three ways:

1. As downloaded archive, using environment variables;
2. Cloning project, using environment variables;
3. Cloning project, installing via CMake;

Option 3 is recommended.

See [INSTALL.md](./INSTALL.md) for details of these options.


## Q3: "How do I use STLSoft?"

Assuming you've installed it using environment variables (as per instructions in [Q2](#q2-how-do-i-install-stlsoft)), then:

* in your IDE settings, add the include directory `$(STLSOFT)/include`; or
* in your makefiles, add the include directory `-I$STLSOFT/include` (UNIX) or `-I%STLSOFT%/include` (Windows);


## Q4: "Does STLSoft have unit-tests?"

Yes, there are *many* such, but for various reasons they're not available with the STLSoft 1.10 distribution. When STLSoft 1.11 is released it will include unit-tests, which will likely be a mix of [**xTests**](https://github.com/synesissoftware/xTests) and [**Catch2**](https://github.com/catchorg/Catch2) unit-test libraries, both of which will be bundled with distributions.


## Q5: "Is STLSoft still relevant given the widespread support for 'Modern C++'?"

This is a good question. Over the remainder of 2023 and into 2024 we will be updating all the "Synesis" open-source libraries - including
[**b64**](https://github.com/synesissoftware/b64),
[**FastFormat**](https://github.com/synesissoftware/FastFormat),
[**Pantheios**](https://github.com/synesissoftware/Pantheios),
[**recls**](https://github.com/synesissoftware/recls),
[**shwild**](https://github.com/synesissoftware/shwild),
and more - in light of 'Modern C++' and determining how well this can be achieved with standard C++ facilities alone. This will inform the future of **STLSoft**, which may be to invest much further effort into the exist 1.x stream or, perhaps, create a new 2.x stream that does not need to worry itself with the very extensive compiler-feature-detection and missing-feature-detection that comprises much of the current (1.x) **STLSoft** facilities.

## Q6: "What is STLSoft-1.10?"

**STLSoft-1.10** is the next version of **STLSoft**, and is now available after many years in beta (during which time our major contributor has been busy commercially). As well as containing several new components, it also incorporates wholesale refactoring of code and of the structural aspects (including packaging and directories). **STLSoft-1.10** is available (in beta form) from GitHub:

  https://github.com/synesissoftware/STLSoft-1.10


<!-- ########################### end of file ########################### -->

