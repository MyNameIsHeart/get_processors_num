/* header to processors_num.c */

#ifndef PROCESSORS_NUM_H /* include guard */

    #define PROCESSORS_NUM_H

    #include "libs.h" /* include C standard libraries */
    #include "define_os.h" /* determine system type */

    /* defines */
    #define FAILURE -1

    /* function prototypes and documentation */

    /*
        returns the number of processors a machine has.
        prints error messages.
        returns -1 on failure, -2 on unsuppported systems.
     */
    int get_processors_num(void);

#endif
