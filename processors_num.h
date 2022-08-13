/* header for processors_num */


/* include guard */
#ifndef PROCESSORS_NUM_H
#define PROCESSORS_NUM_H


/* include standard libs */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>


/* detect system type */

#ifdef _WIN32
    /* Windows system */
    #define OS_WIN
#elif defined __unix__ || defined __linux__
    /* Unix-like system */
    #define OS_NIX
#else
    #define UNSUPPORTED_OS -2 /* the OS is none of the above  */
#endif
/*
    TODO
    develop something for macos or other apple systems, for example 
    #elif defined __APPLE__ || defined __MACH__TARGET_OS_MAC
*/


#ifdef OS_WIN /* includes for Windows systems */
    /* use WinAPI */
    #define WIN32_LEAN_AND_MEAN /* excluding some of the less frequently used APIs */
    #include <windows.h>
#endif


#ifdef OS_NIX /* includes for Unix-like systems */
    /* use POSIX */
    #include <unistd.h>
    /*#include <sys/sysinfo.h>*/
#endif


/* macros */
#define FAILURE -1


/* function prototypes and documentation */

/* TODO: right doc */
int get_processors_num(void);


#endif /* end include guard */
