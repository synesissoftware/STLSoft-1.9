/* /////////////////////////////////////////////////////////////////////////
 * File:        winstl/window/message_functions.h (originally MWBase.h, ::SynesisWin)
 *
 * Purpose:     Message functions.
 *
 * Created:     7th May 2000
 * Updated:     15th December 2023
 *
 * Home:        http://stlsoft.org/
 *
 * Copyright (c) 2019-2023, Matthew Wilson and Synesis Information Systems
 * Copyright (c) 2000-2019, Matthew Wilson and Synesis Software
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


/** \file winstl/window/message_functions.h
 *
 * \brief [C, C++] Message functions
 *   (\ref group__library__windows_window "Windows Window" Library).
 */

#ifndef WINSTL_INCL_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS
#define WINSTL_INCL_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS

#ifndef STLSOFT_DOCUMENTATION_SKIP_SECTION
# define WINSTL_VER_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS_MAJOR    4
# define WINSTL_VER_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS_MINOR    0
# define WINSTL_VER_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS_REVISION 2
# define WINSTL_VER_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS_EDIT     40
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
 * C functions
 */

STLSOFT_INLINE LRESULT winstl__SendMessageA(HWND    hwnd
                                        ,   UINT    uMsg
                                        ,   WPARAM  wParam
                                        ,   LPARAM  lParam)
{
    return STLSOFT_NS_GLOBAL(SendMessageA)(hwnd, uMsg, wParam, lParam);
}

STLSOFT_INLINE LRESULT winstl__SendMessageW(HWND    hwnd
                                        ,   UINT    uMsg
                                        ,   WPARAM  wParam
                                        ,   LPARAM  lParam)
{
    return STLSOFT_NS_GLOBAL(SendMessageW)(hwnd, uMsg, wParam, lParam);
}

STLSOFT_INLINE LRESULT winstl__SendMessage( HWND    hwnd
                                        ,   UINT    uMsg
                                        ,   WPARAM  wParam
                                        ,   LPARAM  lParam)
{
    return STLSOFT_NS_GLOBAL(SendMessage)(hwnd, uMsg, wParam, lParam);
}

/* /////////////////////////////////////////////////////////////////////////
 * C++ functions
 */

#ifndef _WINSTL_NO_NAMESPACE
inline LRESULT SendMessageA(HWND    hwnd
                        ,   UINT    uMsg
                        ,   WPARAM  wParam
                        ,   LPARAM  lParam)
{
    return winstl__SendMessageA(hwnd, uMsg, wParam, lParam);
}

inline LRESULT SendMessageW(HWND    hwnd
                        ,   UINT    uMsg
                        ,   WPARAM  wParam
                        ,   LPARAM  lParam)
{
    return winstl__SendMessageW(hwnd, uMsg, wParam, lParam);
}

#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#ifndef _WINSTL_NO_NAMESPACE
# if defined(_STLSOFT_NO_NAMESPACE) || \
     defined(STLSOFT_DOCUMENTATION_SKIP_SECTION)
} /* namespace winstl */
# else
} /* namespace winstl_project */
} /* namespace stlsoft */
# endif /* _STLSOFT_NO_NAMESPACE */
#endif /* !_WINSTL_NO_NAMESPACE */

/* ////////////////////////////////////////////////////////////////////// */

#endif /* WINSTL_INCL_WINSTL_WINDOW_H_MESSAGE_FUNCTIONS */

/* ///////////////////////////// end of file //////////////////////////// */

