/* /////////////////////////////////////////////////////////////////////////
 * File:        stlsoft/internal/cccap/obsolete.h
 *
 * Purpose:     Obsolete
 *
 * Created:     11th May 2008
 * Updated:     15th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2008-2019, Matthew Wilson and Synesis Software
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


/** \file stlsoft/internal/cccap/obsolete.h
 *
 * Obsolete features
 * (\ref group__library__internal).
 */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define STLSOFT_VER_H_STLSOFT_CCCAP_OBSOLETE_MAJOR     1
# define STLSOFT_VER_H_STLSOFT_CCCAP_OBSOLETE_MINOR     2
# define STLSOFT_VER_H_STLSOFT_CCCAP_OBSOLETE_REVISION  1
# define STLSOFT_VER_H_STLSOFT_CCCAP_OBSOLETE_EDIT      7
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Obsolete
 */

#ifdef STLSOFT_PPF_pragma_message_SUPPORT
# define STLSOFT_CF_PRAGMA_MESSAGE_SUPPORT
#endif /* STLSOFT_PPF_pragma_message_SUPPORT */

#ifdef STLSOFT_PPF_pragma_once_SUPPORT
# define STLSOFT_CF_PRAGMA_ONCE_SUPPORT
#endif /* STLSOFT_PPF_pragma_once_SUPPORT */

#ifdef STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT
# define STLSOFT_CF_COUNTER_SYMBOL_SUPPORT
#endif /* STLSOFT_PPF_COUNTER_SYMBOL_SUPPORT */

#ifdef STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT
# define STLSOFT_CF_FUNCTION_SYMBOL_SUPPORT
#endif /* STLSOFT_PPF_FUNCTION_SYMBOL_SUPPORT */

#ifdef STLSOFT_PPF_func_SYMBOL_SUPPORT
# define STLSOFT_CF_func_SYMBOL_SUPPORT
#endif /* STLSOFT_PPF_func_SYMBOL_SUPPORT */

#ifdef STLSOFT_PPF_VARIADIC_MACROS_SUPPORT
# define STLSOFT_CF_SUPPORTS_VARIADIC_MACROS
#endif /* STLSOFT_PPF_VARIADIC_MACROS_SUPPORT */

#ifdef STLSOFT_CF_BUILTIN_bool_SUPPORT
# define STLSOFT_CF_NATIVE_BOOL_SUPPORT
#endif /* STLSOFT_CF_BUILTIN_bool_SUPPORT */

#ifdef STLSOFT_CF_char_IS_UNSIGNED
# define STLSOFT_CF_CHAR_IS_UNSIGNED
#endif /* STLSOFT_CF_char_IS_UNSIGNED */

#ifdef STLSOFT_CF_return_void_SUPPORT
# define STLSOFT_CF_COMPILER_SUPPORTS_RETURN_VOID
#endif /* STLSOFT_CF_return_void_SUPPORT */


/* keywords */

#ifdef STLSOFT_CF_explicit_KEYWORD_SUPPORT
# define STLSOFT_CF_EXPLICIT_KEYWORD_SUPPORT
#endif

#ifdef STLSOFT_CF_mutable_KEYWORD_SUPPORT
# define STLSOFT_CF_MUTABLE_KEYWORD_SUPPORT
#endif

#ifdef STLSOFT_CF_nullptr_KEYWORD_SUPPORT
# define STLSOFT_CF_BUILTIN_nullptr_SUPPORT
#endif

#ifdef STLSOFT_CF_override_KEYWORD_SUPPORT
# define STLSOFT_CF_OVERRIDE_KEYWORD_SUPPORT
#endif





#ifdef STLSOFT_CF_TEMPLATE_FUNCTION_TEMPLATE_REQUIRES_TEMPLATE_PARAMETERS_IN_FUNCTION_PARAMETER_LIST
# define STLSOFT_CF_TEMPLATE_TYPE_REQUIRED_IN_ARGS
#endif /* STLSOFT_CF_TEMPLATE_FUNCTION_TEMPLATE_REQUIRES_TEMPLATE_PARAMETERS_IN_FUNCTION_PARAMETER_LIST */

#ifdef STLSOFT_CF_EXCEPTION_OPERATOR_NEW_THROWS_BAD_ALLOC
# define STLSOFT_CF_THROW_BAD_ALLOC
#endif /* STLSOFT_CF_EXCEPTION_OPERATOR_NEW_THROWS_BAD_ALLOC */

#ifdef STLSOFT_CF_TEMPLATE_DEFAULT_FUNDAMENTAL_PARAMETER_SUPPORT
# define STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_FUNDAMENTAL_ARGUMENT_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_DEFAULT_FUNDAMENTAL_PARAMETER_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_DEFAULT_TYPE_PARAMETER_SUPPORT
# define STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_DEFAULT_TYPE_PARAMETER_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_PARAMETER_SUPPORT
# define STLSOFT_CF_MEM_FUNC_AS_TEMPLATE_PARAM_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_PARAMETER_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_SUPPORT
# define STLSOFT_CF_MEMBER_TEMPLATE_FUNCTION_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_MEMBER_FUNCTION
# define STLSOFT_CF_MEMBER_TEMPLATE_OVERLOAD_DISCRIMINATED
#endif /* STLSOFT_CF_TEMPLATE_MEMBER_FUNCTION_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_MEMBER_FUNCTION */

#ifdef STLSOFT_CF_TEMPLATE_CTOR_TEMPLATE_SUPPORT
# define STLSOFT_CF_MEMBER_TEMPLATE_CTOR_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_CTOR_TEMPLATE_SUPPORT */

#ifndef STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR
# define STLSOFT_CF_NO_COPY_CTOR_AND_COPY_CTOR_TEMPLATE_OVERLOAD
#endif /* !STLSOFT_CF_TEMPLATE_COPY_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_COPY_CONSTRUCTOR */

#ifdef STLSOFT_CF_TEMPLATE_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_CONSTRUCTOR
# define STLSOFT_CF_MEMBER_TEMPLATE_CTOR_OVERLOAD_DISCRIMINATED
#endif /* STLSOFT_CF_TEMPLATE_CONSTRUCTOR_TEMPLATE_OVERLOAD_DISCRIMINATED_AGAINST_NON_TEMPLATE_CONSTRUCTOR */

#ifdef STLSOFT_CF_TEMPLATE_MEMBER_RANGE_FUNCTION_TEMPLATE_SUPPORT
# define STLSOFT_CF_MEMBER_TEMPLATE_RANGE_METHOD_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_MEMBER_RANGE_FUNCTION_TEMPLATE_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_MEMBER_CLASS_TEMPLATE_SUPPORT
# define STLSOFT_CF_MEMBER_TEMPLATE_CLASS_SUPPORT
#endif /* STLSOFT_CF_TEMPLATE_MEMBER_CLASS_TEMPLATE_SUPPORT */

#ifdef STLSOFT_CF_TEMPLATE_SPECIALISATION_SYNTAX_SUPPORT
# define STLSOFT_CF_TEMPLATE_SPECIALISATION_SYNTAX
#endif /* STLSOFT_CF_TEMPLATE_SPECIALISATION_SYNTAX_SUPPORT */

#ifdef STLSOFT_CF_ADL_SUPPORT
# define STLSOFT_CF_ADL_LOOKUP_SUPPORT
#endif /* STLSOFT_CF_ADL_SUPPORT */

/* ///////////////////////////// end of file //////////////////////////// */

