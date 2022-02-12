/**
 * @file main.h
 * @author dfrangopoulos (github.com/dfrangopoulos)
 * @brief Header for main.c
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "libs.h"
#include "fail_codes.h"

#ifndef FS_H
    #define FS_H
    #include "fs.h"
#endif

#ifndef DATA_H
    #define DATA_H
    #include "data.h"
#endif

//Support Functions
void check_args(int argc, char **argv);
void err_handler(uint8_t err_code, char *message);