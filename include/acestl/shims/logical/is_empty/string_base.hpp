/* /////////////////////////////////////////////////////////////////////////
 * File:        acestl/shims/logical/is_empty/string_base.hpp
 *
 * Purpose:     Helper functions for ACE_String_Base class.
 *
 * Created:     16th December 2004
 * Updated:     15th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2004-2019, Matthew Wilson and Synesis Software
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


/** \file acestl/shims/logical/is_empty/string_base.hpp
 *
 * \brief [C++] Primary include file for is_empty attribute shims
 *   for <code>ACE_String_Base</code>
 *   (\ref group__concept__shim__collection_logical__is_empty "is_empty Collection Logical Shim").
 */

#ifndef ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE
#define ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE_MAJOR     2
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE_MINOR     0
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE_REVISION  3
# define ACESTL_VER_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE_EDIT      13
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef ACESTL_INCL_ACESTL_HPP_ACESTL
# include <acestl/acestl.hpp>
#endif /* !ACESTL_INCL_ACESTL_HPP_ACESTL */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_UTIL_HPP_FEATURES
# include <stlsoft/shims/logical/is_empty/util/features.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_LOGICAL_IS_EMPTY_UTIL_HPP_FEATURES */

#include <ace/String_Base.h>        // for ACE_String_Base<>

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _STLSOFT_NO_NAMESPACE
namespace stlsoft
{
#endif /* !_STLSOFT_NO_NAMESPACE */

/* /////////////////////////////////////////////////////////////////////////
 * Shims
 */

#ifdef STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP

STLSOFT_OPEN_WORKER_NS_(is_empty_ns)

    no_type is_empty_helper_assistant(ACE_String_Base<ss_char_a_t> const*, ACE_String_Base<ss_char_a_t> const*)
    {
        return no_type();
    }

    inline ss_bool_t is_empty_helper(ACE_String_Base<ss_char_a_t> const& s, no_type)
    {
        return 0 != s.length();
    }


    no_type is_empty_helper_assistant(ACE_String_Base<ss_char_w_t> const*, ACE_String_Base<ss_char_w_t> const*)
    {
        return no_type();
    }

    inline ss_bool_t is_empty_helper(ACE_String_Base<ss_char_w_t> const& s, no_type)
    {
        return 0 != s.length();
    }

STLSOFT_CLOSE_WORKER_NS_(is_empty_ns)

#else /* ? STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP */

/** \brief Indicates whether the string is empty
 *
 * \ingroup group__concept__shim__collection_logical__is_empty
 *
 */
inline int is_empty(ACE_String_Base<ss_char_a_t> const& s)
{
    return 0 != s.length();
}

/** \brief Indicates whether the string is empty
 *
 * \ingroup group__concept__shim__collection_logical__is_empty
 *
 */
inline int is_empty(ACE_String_Base<ss_char_w_t> const& s)
{
    return 0 != s.length();
}

#endif /* STLSOFT_SHIM_LOGICAL_IS_EMPTY_NEEDS_HELP */

////////////////////////////////////////////////////////////////////////////
// Unit-testing

#ifdef STLSOFT_UNITTEST
# include "./unittest/string_base_unittest_.h"
#endif /* STLSOFT_UNITTEST */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* !_STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* ACESTL_INCL_ACESTL_SHIMS_LOGICAL_IS_EMPTY_HPP_STRING_BASE */

/* ///////////////////////////// end of file //////////////////////////// */

