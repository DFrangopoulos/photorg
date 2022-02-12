/**
 * @file main.c
 * @author dfrangopoulos (github.com/dfrangopoulos)
 * @brief Program Entry Point
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "main.h"

int main(int argc, char **argv){

    check_args(argc,argv);

    list_files(argv[1]);

    printf("Done!\n");
    return 0;
}

/**
*   \brief      Input argument checker
*   \details    Verifies the number of input arguments and checks that argv[1] is a full path
*   \param[in]  argc    Argument count
*   \param[in]  argv    Input arguments
*   \return     None
*
*/
void check_args(int argc, char **argv){
    switch(argc){
        case 2:
            if(argv[1][0]!='/')
                err_handler(ERR_ARG_FAIL,"FATAL: ARG1 is not a full path");
            break;
        default:
            err_handler(ERR_ARG_FAIL,"FATAL: Wrong number of input arguments.");
            break;
    }
    return;
}

/**
*   \brief      Error handler
*   \details    Handles caught errors
*   \param[in]  err_code    Error code
*   \param[in]  message     Custom error message (optional)
*   \return     None
*/
void err_handler(uint8_t err_code, char *message){
    switch(err_code){
        case ERR_ARG_FAIL:
            if(message!=NULL){fprintf(stderr,"%s\n",message);}
            exit(FAILURE);
        case ERR_STAT_FAIL:
            if(message!=NULL){fprintf(stderr,"%s\n",message);}
        default:
            fprintf(stderr,"Unknonw Error\n");
            exit(FAILURE);
    }
    return;
}