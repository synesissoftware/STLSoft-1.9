/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/detector/has_pointer.hpp (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     Definition of the has_pointer member type detector.
 *
 * Created:     19th November 1998
 * Updated:     15th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 1998-2019, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the names of
 *   any contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file stlsoft/meta/detector/has_pointer.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::has_pointer member type
 *   detector class template
 *   (\ref group__library__meta "Template Meta-programming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER
#define STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_MAJOR    4
# define STLSOFT_VER_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_MINOR    0
# define STLSOFT_VER_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_REVISION 2
# define STLSOFT_VER_STLSOFT_META_DETECTOR_HPP_HAS_POINTER_EDIT     131
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES
# include <stlsoft/meta/n_types.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_N_TYPES */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* _STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

template <ss_typename_param_k T>
one_t has_pointer_function(...);

template <ss_typename_param_k T>
five_t has_pointer_function(ss_typename_type_k T::pointer const volatile *);

/** \brief traits type used to determine whether a given type has a member \c pointer
 *
 * \ingroup group__library__meta
 */
template <ss_typename_param_k T>
struct has_pointer
{
    typedef T   test_type;

private:
    static T    t;
public:

    enum { value = sizeof(has_pointer_function<T>(0)) == sizeof(five_t) };
};

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION

STLSOFT_TEMPLATE_SPECIALISATION
struct has_pointer<void>
{
    typedef void    test_type;

    enum { value = 0 };
};

#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */


/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} /* namespace stlsoft */
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_META_DETECTOR_HPP_HAS_POINTER */

/* ///////////////////////////// end of file //////////////////////////// */

