#include "processors_num.h"

int get_processors_num(void)
{
    int processors_num = -1;

    #ifdef UNSUPPORTED_OS /* the OS is not supported */
        fprintf(stderr, "This machine's OS is currently not supported by this program.\n");
        return UNSUPPORTED;
    #endif

    /* use winAPI and get the amount of processors using SYSTEM_INFO -> dwNumberOfProcessors */
    #ifdef OS_WIN /* Windows system */
        SYSTEM_INFO sys_info;
        GetSystemInfo(&sys_info);
        processors_num = sys_info.dwNumberOfProcessors;

        if (processors_num < 1) /* failure */
        {
            fprintf(stderr, "Could not determine number of processors configured (on Windows):\n%s\n", strerror (errno));
            return FAILURE;
        }

        return processors_num;
    #endif

    /* use POSIX and get the amount of processors using _SC_NPROCESSORS_CONF */
    #ifdef OS_NIX
        #ifdef _SC_NPROCESSORS_CONF
            processors_num = sysconf(_SC_NPROCESSORS_CONF);
            if (processors_num < 1)
            {
                fprintf(stderr, "Could not determine number of processors configured (on Unix-like):\n%s\n", strerror (errno));
                return FAILURE;
            }
            return processors_num;
        #else
            fprintf(stderr, "get_processors_num() failed:\n%s\n", strerror (errno));
            return FAILURE;
        #endif
    #endif

    fprintf(stderr, "get_processors_num() failed:\n%s\n", strerror (errno));
    return FAILURE;

}