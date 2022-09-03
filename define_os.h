#ifndef DEFINE_OS_H /* include guard */

    #define DEFINE_OS_H

    /* detect system type */

    #ifdef _WIN32

        #define OS_WIN /* Windows system */
        /* use WinAPI */
        #define WIN32_LEAN_AND_MEAN /* exclude some of the less frequently used APIs */
        #include <windows.h>

    #elif defined (__unix__) || defined (__linux__)

        #define OS_NIX      /* Unix-like system */
        #include <unistd.h> /* use POSIX */

    #else /* the OS is none of the above and is not supported by this program */

        #define UNSUPPORTED_OS -2

    #endif

    /*
        TODO
        develop something for macos or other apple systems, for example 
        #elif defined __APPLE__ || defined __MACH__TARGET_OS_MAC
    */

#endif