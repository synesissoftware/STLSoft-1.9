

#include <platformstl/platformstl.h>

#if defined(PLATFORMSTL_OS_IS_UNIX)
# include <unixstl/system/console_functions.h>
#elif defined(PLATFORMSTL_OS_IS_WINDOWS)
# include <winstl/system/console_functions.h>
#else
# error Operating-system not discriminated
#endif


#ifdef __cplusplus

#else /* ? __cplusplus */

# if defined(PLATFORMSTL_OS_IS_UNIX)
#  define platformstl_C_get_console_width       unixstl_C_get_console_width
# elif defined(PLATFORMSTL_OS_IS_WINDOWS)
#  define platformstl_C_get_console_width       winstl_C_get_console_width
# endif

#endif /* __cplusplus */

/* ///////////////////////////// end of file //////////////////////////// */
