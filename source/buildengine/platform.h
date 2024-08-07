#ifndef _INCLUDE_PLATFORM_H_
#define _INCLUDE_PLATFORM_H_

#if !defined(__has_include)
# define __has_include(foo) 0
#endif /* !__has_include */

#if (defined PLATFORM_WIN32)
# include "win32_compat.h"
#elif (defined PLATFORM_MACOSX)
# include "unix_compat.h"
# include <machine/endian.h>
#elif (defined PLATFORM_FREEBSD)
# include "unix_compat.h"
# include <sys/endian.h>
#elif (defined PLATFORM_UNIX)
# include "unix_compat.h"
# if !defined(__SUNPRO_C) && (defined(HAVE_ENDIAN_H) || __has_include(<endian.h>))
#  include <endian.h>
# else
#  if defined(HAVE_MACHINE_ENDIAN_H) || __has_include(<machine/endian.h>)
#   include <machine/endian.h>
#  else
#   if defined(HAVE_SYS_ENDIAN_H) || __has_include(<sys/endian.h>)
#    include <sys/endian.h>
#   else
#    if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#     warning "platform.h wants to include an endianness header on unix-likes!"
#    endif /* __GNUC__ && !__STRICT_ANSI__ */
#   endif /* HAVE_SYS_ENDIAN_H */
#  endif /* HAVE_MACHINE_ENDIAN_H */
# endif /* !__SUNPRO_C && HAVE_ENDIAN_H */
#elif (defined PLATFORM_DOS)
# include "doscmpat.h"
#else
# error "Define your platform!"
#endif /* Platform check */

#ifdef PLATFORM_MACOSX
    /* may be an x86 Mac, so turn off PowerPC ASM and Altivec if needed... */
    #if __POWERPC__
        #define HAVE_POWERPC 1
    #endif
#endif

#ifdef PLATFORM_LINUXPPC
#define HAVE_POWERPC 1
#endif

#if (!defined __EXPORT__)
#define __EXPORT__
#endif

#if ((defined PLATFORM_SUPPORTS_SDL) && (!defined PLATFORM_TIMER_HZ))
#define PLATFORM_TIMER_HZ 100
#endif

#if (!defined PLATFORM_TIMER_HZ)
#error You need to define PLATFORM_TIMER_HZ for your platform.
#endif

#if (defined __WATCOMC__)
#define snprintf _snprintf
#endif

#if (defined __SUNPRO_C)
#define __inline inline
#endif

static __inline unsigned short _swap16(unsigned short D)
{
#if HAVE_POWERPC
    register unsigned short returnValue;
    __asm__ volatile("lhbrx %0,0,%1"
        : "=r" (returnValue)
        : "r" (&D)
    );
    return returnValue;
#else
    return((D<<8)|(D>>8));
#endif
}

static __inline unsigned int _swap32(unsigned int D)
{
#if HAVE_POWERPC
    register unsigned int returnValue;
    __asm__ volatile("lwbrx %0,0,%1"
        : "=r" (returnValue)
        : "r" (&D)
    );
    return returnValue;
#else
    return((D<<24)|((D<<8)&0x00FF0000)|((D>>8)&0x0000FF00)|(D>>24));
#endif
}

#if HAVE_POWERPC
#define PLATFORM_BIGENDIAN 1
#define BUILDSWAP_INTEL16(x) _swap16(x)
#define BUILDSWAP_INTEL32(x) _swap32(x)
#else
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define PLATFORM_LITTLEENDIAN 1
#define BUILDSWAP_INTEL16(x) (x)
#define BUILDSWAP_INTEL32(x) (x)
#else
#define PLATFORM_BIGENDIAN 1
#define BUILDSWAP_INTEL16(x) _swap16(x)
#define BUILDSWAP_INTEL32(x) _swap32(x)
#endif
#endif

extern int has_altivec;  /* PowerPC-specific. */

#endif  /* !defined _INCLUDE_PLATFORM_H_ */

/* end of platform.h ... */


