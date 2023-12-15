/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/meta/is_fundamental_type.hpp (originally MTBase.h, ::SynesisStl)
 *
 * Purpose:     is_fundamental_type meta class.
 *
 * Created:     19th November 1998
 * Updated:     15th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2005-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/meta/is_fundamental_type.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::is_fundamental_type meta class
 *  template
 *   (\ref group__library__meta "Template Meta-programming" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE
#define STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE_MAJOR     1
# define STLSOFT_VER_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE_MINOR     1
# define STLSOFT_VER_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE_REVISION  1
# define STLSOFT_VER_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE_EDIT      10
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_BOOL_TYPE
# include <stlsoft/meta/is_bool_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_BOOL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE
# include <stlsoft/meta/is_character_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_CHARACTER_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE
# include <stlsoft/meta/is_integral_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_INTEGRAL_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE
# include <stlsoft/meta/is_floating_point_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FLOATING_POINT_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE
# include <stlsoft/meta/is_void_type.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_VOID_TYPE */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES
# include <stlsoft/meta/capabilities.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_CAPABILITIES */
#ifdef STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF
# ifndef STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF
#  include <stlsoft/meta/select_first_type_if.hpp>
# endif /* !STLSOFT_INCL_STLSOFT_META_HPP_SELECT_FIRST_TYPE_IF */
#endif /* STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF */
#ifndef STLSOFT_INCL_STLSOFT_META_HPP_YESNO
# include <stlsoft/meta/yesno.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_YESNO */
#ifndef STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_
# include <stlsoft/meta/util/meta_.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_META_UTIL_HPP_META_ */

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

/** \brief Traits type used to determine whether the given type is a
 *    fundamental type.
 *
 * \ingroup group__library__meta
 */
template <ss_typename_param_k T>
struct is_fundamental_type
{
    enum
    {
        value   =   is_integral_type<T>::value
                ||  is_floating_point_type<T>::value
                ||  is_bool_type<T>::value
                ||  is_void_type<T>::value
                ||  is_character_type<T>::value
    };

#ifdef STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF
    typedef ss_typename_type_k select_first_type_if<yes_type, no_type, value>::type     type;
#else /* ? STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF */
    typedef value_to_yesno_type<value>::type                                            type;
#endif /* STLSOFT_META_HAS_SELECT_FIRST_TYPE_IF */
};

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/is_fundamental_type_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_META_HPP_IS_FUNDAMENTAL_TYPE */

/* ///////////////////////////// end of file //////////////////////////// */

