/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/internal/windows_version.h
 *
 * Purpose:     Windows version discrimination.
 *
 * Created:     4th August 2015
 * Updated:     5th August 2015
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2015, Matthew Wilson and Synesis Software
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 * - Neither the name(s) of Matthew Wilson and Synesis Software nor the
 *   names of any contributors may be used to endorse or promote products
 *   derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * ////////////////////////////////////////////////////////////////////// */


/** \file winstl/internal/windows_version.h
 *
 * \brief [C, C++] Windows version discrimination
 *   (\ref group__library__utility "Utility" Library).
 */

#ifndef WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION
#define WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
#define WINSTL_VER_WINSTL_INTERNAL_H_WINDOWS_VERSION_MAJOR      1
#define WINSTL_VER_WINSTL_INTERNAL_H_WINDOWS_VERSION_MINOR      0
#define WINSTL_VER_WINSTL_INTERNAL_H_WINDOWS_VERSION_REVISION   2
#define WINSTL_VER_WINSTL_INTERNAL_H_WINDOWS_VERSION_EDIT       2
#endif /* !STLSOFT_DOCUMENTATION_SKIP_SECTION */

/* /////////////////////////////////////////////////////////////////////////
 * Includes
 */

#ifndef WINSTL_INCL_WINSTL_H_WINSTL
# include <winstl/winstl.h>
#endif /* !WINSTL_INCL_WINSTL_H_WINSTL */

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

/* /////////////////////////////////////////////////////////////////////////
 * helper functions
 */

#ifdef __cplusplus
namespace ximpl_
{
#endif /* __cplusplus */

STLSOFT_INLINE
DWORD
WinSTL_C_internal_GetVersion_(void)
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1700
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

    return STLSOFT_NS_GLOBAL(GetVersion)();

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1700
# pragma warning(pop)
#endif
}

STLSOFT_INLINE
BOOL
WinSTL_C_internal_GetVersionEx_(
    OSVERSIONINFO*  osvi
)
{
#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1700
# pragma warning(push)
# pragma warning(disable : 4996)
#endif

    return STLSOFT_NS_GLOBAL(GetVersionEx)(osvi);

#if defined(STLSOFT_COMPILER_IS_MSVC) && \
    _MSC_VER >= 1700
# pragma warning(pop)
#endif
}

STLSOFT_INLINE
BOOL
WinSTL_C_internal_GetWkstaVersionInfo_(
    DWORD*  verMajor
,   DWORD*  verMinor
)
{
    typedef struct _WKSTA_INFO_100_ {
        DWORD   wki100_platform_id_;
        LPWSTR  wki100_computername_;
        LPWSTR  wki100_langroup_;
        DWORD   wki100_ver_major_;
        DWORD   wki100_ver_minor_;
    } WKSTA_INFO_100_;

    BOOL            r   =   FALSE;
    HMODULE const   hm  =   STLSOFT_NS_GLOBAL(LoadLibraryA)("netapi32.dll");

    WINSTL_ASSERT(NULL != verMajor);
    WINSTL_ASSERT(NULL != verMinor);

    if(NULL != hm)
    {
        union u_aq_
        {
            FARPROC                     fp;
#ifdef STLSOFT_CF_STDCALL_SUPPORTED
            DWORD     (STLSOFT_STDCALL *fn)(LPWSTR, WORD, LPBYTE*);
#else
            DWORD                     (*fn)(LPWSTR, WORD, LPBYTE*);
#endif
        } u_aq;
        union u_fr_
        {
            FARPROC                     fp;
#ifdef STLSOFT_CF_STDCALL_SUPPORTED
            DWORD     (STLSOFT_STDCALL *fn)(void*);
#else
            DWORD                     (*fn)(void*);
#endif
        } u_fr;

        u_aq.fp =   STLSOFT_NS_GLOBAL(GetProcAddress)(hm, "NetWkstaGetInfo");
        u_fr.fp =   STLSOFT_NS_GLOBAL(GetProcAddress)(hm, "NetApiBufferFree");

        if( NULL != u_aq.fp &&
            NULL != u_fr.fp)
        {
            LPBYTE pData;

            if(0 == (*u_aq.fn)(NULL, 100, &pData))
            {
                WKSTA_INFO_100_ const* const info = STLSOFT_REINTERPRET_CAST(WKSTA_INFO_100_*, pData);

                *verMajor   =   info->wki100_ver_major_;
                *verMinor   =   info->wki100_ver_minor_;

                (*u_fr.fn)(pData);

                r = TRUE;
            }
        }

        STLSOFT_NS_GLOBAL(FreeLibrary)(hm);
    }

    return r;
}

#ifdef __cplusplus
} /* namespace ximpl_ */
#endif /* __cplusplus */

/* /////////////////////////////////////////////////////////////////////////
 * functions
 */

STLSOFT_INLINE
BOOL
WinSTL_C_internal_IsWindows9x(
    ws_uint_t*  verMajor
,   ws_uint_t*  verMinor
,   ws_uint_t*  buildNumber
)
{
#ifdef __cplusplus
    using namespace ximpl_;
#endif /* __cplusplus */

    DWORD const     version_    =   WinSTL_C_internal_GetVersion_();
    ws_uint_t const verMajor_   =   STLSOFT_STATIC_CAST(ws_uint_t, LOBYTE(LOWORD(version_)));
    ws_uint_t const verMinor_   =   STLSOFT_STATIC_CAST(ws_uint_t, HIBYTE(LOWORD(version_)));
    ws_uint_t       dummy_;

    if(NULL == verMajor)
    {
        verMajor = &dummy_;
    }
    if(NULL == verMinor)
    {
        verMinor = &dummy_;
    }
    if(NULL == buildNumber)
    {
        buildNumber = &dummy_;
    }

    *verMajor           =   verMajor_;
    *verMinor           =   verMinor_;
    *buildNumber        =   0;

    if(0 == (0x80000000 & version_))
    {
        *buildNumber    =   STLSOFT_STATIC_CAST(ws_uint_t, HIWORD(version_));
    }

    return 0 != (0x80000000 & version_);
}

STLSOFT_INLINE
BOOL
WinSTL_C_internal_GetVersionEx(
    OSVERSIONINFO*  osvi
)
{
#ifdef __cplusplus
    using namespace ximpl_;
#endif /* __cplusplus */

    if(WinSTL_C_internal_GetVersionEx_(osvi))
    {
        if( 6 == osvi->dwMajorVersion &&
            2 == osvi->dwMinorVersion)
        {
            DWORD   verMajor;
            DWORD   verMinor;

            if(WinSTL_C_internal_GetWkstaVersionInfo_(&verMajor, &verMinor))
            {
                osvi->dwMajorVersion    =   verMajor;
                osvi->dwMinorVersion    =   verMinor;
            }
        }

        return TRUE;
    }

    return FALSE;
}

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

#endif /* WINSTL_INCL_WINSTL_INTERNAL_H_WINDOWS_VERSION */

/* ///////////////////////////// end of file //////////////////////////// */
