/* Include guard */
#ifndef PROCESSORS_NUM_H
#define PROCESSORS_NUM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/* If available, use WinAPI. If not, use POSIX */

#ifdef _WIN32 /* running on windows os */
    #define OS_WIN
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
#else 
    #if defined __unix__ || defined linux
        /* running on unix \ unix-like os */
        #define OS_NIX
        #include <unistd.h>
        #include <sys/sysinfo.h>
    #endif
#endif



#define FAILURE -1


#endif
