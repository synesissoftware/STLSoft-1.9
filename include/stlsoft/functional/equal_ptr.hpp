/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/functional/equal_ptr.hpp
 *
 * Purpose:     Definition of stlsoft::equal_ptr predicate class.
 *
 * Created:     7th November 2004
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


/** \file stlsoft/functional/equal_ptr.hpp
 *
 * \brief [C++ only] Definition of the stlsoft::equal_ptr predicate, which
 *   uses attribute shims to generalise comparison of raw/smart pointers
 *   (\ref group__library__functional "Functional" Library).
 */

#ifndef STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR
#define STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR_MAJOR     3
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR_MINOR     0
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR_REVISION  1
# define STLSOFT_VER_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR_EDIT      24
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef STLSOFT_INCL_STLSOFT_H_STLSOFT
# include <stlsoft/stlsoft.h>
#endif /* !STLSOFT_INCL_STLSOFT_H_STLSOFT */
#ifndef STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR
# include <stlsoft/shims/attribute/get_ptr.hpp>
#endif /* !STLSOFT_INCL_STLSOFT_SHIMS_ATTRIBUTE_HPP_GET_PTR */

#ifdef STLSOFT_CF_std_NAMESPACE
# include <functional>
#endif /* STLSOFT_CF_std_NAMESPACE */

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

/** \brief Predicate used to test the equivalence of pointers
 *
 * \ingroup group__library__functional
 *
 */
template<   ss_typename_param_k P
        ,   ss_typename_param_k A = P const&
        >
// [[synesis:class:function-class:unary-predicate: equal_ptr]]
struct equal_ptr
#ifdef STLSOFT_CF_std_NAMESPACE
    : public stlsoft_ns_qual_std(unary_function)<A, ss_bool_t>
#endif /* STLSOFT_CF_std_NAMESPACE */
{
public:
    equal_ptr(P t)
        : m_p(t)
    {}

public:
    /// Returns true if the given instance's underlying pointer is
    /// equal to that of the contained pointer.
    ss_bool_t operator ()(A p) const
    {
        return stlsoft_ns_qual(get_ptr)(p) == stlsoft_ns_qual(get_ptr)(m_p);
    }

private:
    P   m_p;
};


/* ////////////////////////////////////////////////////////////////////// */

#ifndef _STLSOFT_NO_NAMESPACE
} // namespace stlsoft
#endif /* _STLSOFT_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* !STLSOFT_INCL_STLSOFT_FUNCTIONAL_HPP_EQUAL_PTR */

/* ///////////////////////////// end of file //////////////////////////// */

