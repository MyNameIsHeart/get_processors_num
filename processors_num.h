/* header to processors_num.c */

#ifndef PROCESSORS_NUM_H /* include guard */

    #define PROCESSORS_NUM_H

    #include "libs.h" /* include C standard libraries */
    #include "define_os.h" /* determine system type */

    /*
        TODO
        develop something for macos or other apple systems, for example 
        #elif defined __APPLE__ || defined __MACH__TARGET_OS_MAC
    */

    /* defines */
    #define FAILURE -1

    /* function prototypes and documentation */

    /* TODO: write doc */
    int get_processors_num(void);

#endif
