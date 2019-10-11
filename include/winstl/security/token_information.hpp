/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/security/token_information.hpp
 *
 * Purpose:     Helper for accessing token information.
 *
 * Created:     20th June 2003
 * Updated:     1st October 2016
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2003-2016, Matthew Wilson and Synesis Software
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


/** \file winstl/security/token_information.hpp
 *
 * \brief [C++ only] Definition of the winstl::token_information class
 *   (\ref group__library__security "Security" Library).
 */

#ifndef WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION
#define WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_MAJOR     4
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_MINOR     2
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_REVISION  2
# define WINSTL_VER_WINSTL_SECURITY_HPP_TOKEN_INFORMATION_EDIT      55
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */
#ifndef WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR
# include <winstl/memory/processheap_allocator.hpp>
#endif /* !WINSTL_INCL_WINSTL_MEMORY_HPP_PROCESSHEAP_ALLOCATOR */
#ifndef STLSOFT_INCL_STLSOFT_ERROR_HPP_EXCEPTIONS
# include <stlsoft/error/exceptions.hpp>      // for null_exception_policy
#endif /* !STLSOFT_INCL_STLSOFT_ERROR_HPP_EXCEPTIONS */
#ifndef WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE
# include <winstl/error/last_error_scope.hpp>
#endif /* !WINSTL_INCL_WINSTL_ERROR_HPP_LAST_ERROR_SCOPE */

#ifndef STLSOFT_INCL_UTILITY
# define STLSOFT_INCL_UTILITY
# include <utility>
#endif /* !STLSOFT_INCL_UTILITY */

/* /////////////////////////////////////////////////////////////////////////
 * Namespace
 */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
/* There is no stlsoft namespace, so must define ::winstl */
namespace winstl
{
# else
/* Define stlsoft::winstl_project */

namespace stlsoft
{

namespace winstl_project
{

# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

enum
{
        TokenRestrictedSids         =   1 + TokenStatistics
    ,   TokenSessionId
    ,   TokenGroupsAndPrivileges
    ,   TokenSessionReference
    ,   TokenSandBoxInert
    ,   TokenAuditPolicy
    ,   TokenOrigin
};

/* /////////////////////////////////////////////////////////////////////////
 * Classes
 */

/** \brief traits type used to determine the data type for a given \c TOKEN_INFORMATION_CLASS
 *
 * \ingroup group__library__security
 *
 */
template <TOKEN_INFORMATION_CLASS C>
struct token_information_traits;


#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenUser>
{
    typedef TOKEN_USER                      data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenGroups>
{
    typedef TOKEN_GROUPS                    data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenPrivileges>
{
    typedef TOKEN_PRIVILEGES                data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenOwner>
{
    typedef TOKEN_OWNER                     data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenPrimaryGroup>
{
    typedef TOKEN_PRIMARY_GROUP             data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenDefaultDacl>
{
    typedef TOKEN_DEFAULT_DACL              data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenSource>
{
    typedef TOKEN_SOURCE                    data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenType>
{
    typedef TOKEN_TYPE                      data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenImpersonationLevel>
{
    typedef SECURITY_IMPERSONATION_LEVEL    data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<TokenStatistics>
{
    typedef TOKEN_STATISTICS                data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<static_cast<TOKEN_INFORMATION_CLASS>(TokenRestrictedSids)>
{
    typedef TOKEN_GROUPS                    data_type;
};

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<static_cast<TOKEN_INFORMATION_CLASS>(TokenSessionId)>
{
    typedef DWORD                           data_type;
};

#if defined(WINSTL_TOKEN_INFORMATION_TOKEN_GROUPS_AND_PRIVILEGES_SUPPORT) || \
    (   !defined(WINSTL_TOKEN_INFORMATION_NO_GUESS) && \
        defined(SE_MANAGE_VOLUME_NAME))
STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<static_cast<TOKEN_INFORMATION_CLASS>(TokenGroupsAndPrivileges)>
{
    typedef TOKEN_GROUPS_AND_PRIVILEGES     data_type;
};
#endif /* TOKEN_GROUPS_AND_PRIVILEGES */

STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<static_cast<TOKEN_INFORMATION_CLASS>(TokenSandBoxInert)>
{
    typedef DWORD                           data_type;
};

#if defined(WINSTL_TOKEN_INFORMATION_TOKEN_ORIGIN_SUPPORT) /* || \
    (   !defined(WINSTL_TOKEN_INFORMATION_NO_GUESS) && \
        defined(SE_MANAGE_VOLUME_NAME)) */
STLSOFT_TEMPLATE_SPECIALISATION
struct token_information_traits<static_cast<TOKEN_INFORMATION_CLASS>(TokenOrigin)>
{
    typedef TOKEN_ORIGIN                    data_type;
};
#endif /* TOKEN_ORIGIN */



#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

// token_information
/** \brief Provides typed access to token information.
 *
 * \ingroup group__library__security
 */
template<
    TOKEN_INFORMATION_CLASS C
#ifdef STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT
# ifdef __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE
#  pragma message(_sscomp_fileline_message("Note that we have to have data_type as a parameter, otherwise VC5&6 have a cow"))
# endif /* __SYNSOFT_DBS_COMPILER_SUPPORTS_PRAGMA_MESSAGE */
,   ss_typename_param_k     X = stlsoft_ns_qual(null_exception_policy)
,   ss_typename_param_k     D = ss_typename_type_def_k token_information_traits<C>::data_type
,   ss_typename_param_k     A = processheap_allocator<ss_byte_t>
#else /* ? STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
,   ss_typename_param_k     X /* = stlsoft_ns_qual(null_exception_policy) */
,   ss_typename_param_k     D /* = token_information_traits<C>::data_type */
,   ss_typename_param_k     A /* = processheap_allocator<ss_byte_t> */
#endif /* STLSOFT_CF_TEMPLATE_CLASS_DEFAULT_CLASS_ARGUMENT_SUPPORT */
>
class token_information
{
/// \name Member Types
/// @{
public:
    typedef token_information<C, X, D, A>               class_type;
    typedef token_information_traits<C>                 traits_type;
    typedef X                                           exception_thrower_type;
    typedef D                                           data_type;
    typedef A                                           allocator_type;
    typedef ss_size_t                                   size_type;
/// @}
private:
    typedef std::pair<void*, size_t>                    mem_block_type_;

/// \name Construction
/// @{
public:
    /// \brief Constructs an instance from the given access token
    ///
    ss_explicit_k token_information(HANDLE hToken)
        : m_data(init_(hToken))
    {}

private:
    static
    mem_block_type_
    init_(
        HANDLE hToken
    )
    {
        DWORD   cbRequired;
        DWORD   dwError;

        ::GetTokenInformation(hToken, C, NULL, 0, &cbRequired);
        dwError = ::GetLastError();
        if(ERROR_INSUFFICIENT_BUFFER != dwError)
        {
            // Report error
            exception_thrower_type()(dwError);
        }
        else
        {
            data_type* const data = reinterpret_cast<data_type*>(allocator_type().allocate(cbRequired));

            if(NULL == data)
            {
                // Report error
                exception_thrower_type()(ERROR_NOT_ENOUGH_MEMORY);

                // Set the last error, in case the client code is not using exception reporting
                ::SetLastError(ERROR_NOT_ENOUGH_MEMORY);
            }
            else
            {
                if(!::GetTokenInformation(hToken, C, data, cbRequired, &cbRequired))
                {
                    // Scope the last error, in case the client code is not using exception reporting
                    last_error_scope scope;

#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
                    allocator_type().deallocate(reinterpret_cast<ss_byte_t*>(data), cbRequired);
#else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
                    allocator_type().deallocate(reinterpret_cast<ss_byte_t*>(data));
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */

                    // Report error
                    exception_thrower_type()(DWORD((scope)));
                }

                return mem_block_type_(data, cbRequired);
            }
        }

        return mem_block_type_(NULL, 0);
    }
public:

    ~token_information() STLSOFT_NOEXCEPT
    {
#ifdef STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT
        allocator_type().deallocate(m_data.first, m_data.second);
#else /* ? STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
        allocator_type().deallocate(m_data.first);
#endif /* STLSOFT_LF_ALLOCATOR_DEALLOCATE_HAS_COUNT */
    }
/// @}

/// \name Conversion
/// @{
public:
    data_type* get() const
    {
        return static_cast<data_type*>(m_data.first);
    }
    size_type size() const
    {
        return m_data.second;
    }

    operator data_type *()
    {
        return get();
    }
    operator data_type const* () const
    {
        return get();
    }

    data_type *operator ->()
    {
        return get();
    }
    data_type const* operator ->() const
    {
        return get();
    }
/*
    operator ws_bool_t () const
    {
        return 0 != m_data;
    }
*/
    ws_bool_t operator !() const
    {
        return 0 == m_data.second;
    }
/// @}

/// \name Implementation
/// @{
private:
/// @}

/// \name Members
/// @{
private:
    mem_block_type_ const   m_data;
/// @}

/// \name Not to be implemented
/// @{
private:
    token_information(token_information const&);
    token_information& operator =(token_information const&);
/// @}
};

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} // namespace winstl
# else
} // namespace winstl_project
} // namespace stlsoft
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_SECURITY_HPP_TOKEN_INFORMATION */

/* ///////////////////////////// end of file //////////////////////////// */
