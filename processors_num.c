#include "processors_num.h"

/*
    a function to determine the amount of processors a machine has.
    if available, the func uses winAPI and gets the amount of processors using GetSystemInfo -> dwNumberOfProcessors.
    if winAPI is not available, the func uses unistd.h and gets the amount of processors using _SC_NPROCESSORS_CONF.
    - returns -1 on failure.
    - should work both on Windows and Unix-like systems.
 */
int get_processors_num_alpha(void)
{
    int processors_num = -1;

    #ifdef OS_WIN
        #ifndef _SC_NPROCESSORS_CONF /* running on windows os */
            SYSTEM_INFO sys_info;
            GetSystemInfo(&sys_info);
            processors_num = sysconf(sys_info.dwNumberOfProcessors)
            if (processors_num < 1)
            {
                fprintf(stderr, "Could not determine number of processors configured (on Windows):\n%s\n", strerror (errno));
                return FAILURE;
            }
            return processors_num;
        #endif
    #endif
    #if defined OS_NIX && defined _SC_NPROCESSORS_CONF /* running on unix-like os */
        processors_num = sysconf(_SC_NPROCESSORS_CONF);
        if (processors_num < 1)
        {
            fprintf(stderr, "Could not determine number of processors configured (on Unix-like):\n%s\n", strerror (errno));
            return FAILURE;
        }
        return processors_num;
    #else
        fprintf(stderr, "get_processors_num_alpha() failed");
        return FAILURE;
    #endif
}

/*
    a function to determine the amount of cpu cores a unix-like system has, using sys/sysinfo.h
    - returns -1 on failure.
    - works only on Unix-like systems.
    - returns 0 if run on windows
*/
int get_processors_num_beta(void)
{
    int processors_num = -1;

    #ifdef OS_NIX /* running on unix-like os */

        processors_num = get_nprocs();

        if (processors_num < 1)
        {
            fprintf(stderr, "Could not determine number of processors configured (on Unix-like):\n%s\n", strerror (errno));
            return FAILURE;
        }

        return processors_num;

    #else

        #ifdef OS_WIN /* running on windows */
            fprintf(stderr, "get_processors_num_beta() is for unix-like systems only:\n%s\n", strerror (errno));
            return 0;
        #endif

        fprintf(stderr, "Could not perform get_processors_num_beta():\n%s\n", strerror (errno));
        return FAILURE;
    
    #endif
}