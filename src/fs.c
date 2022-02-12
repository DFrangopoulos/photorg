/**
 * @file fs.c
 * @author dfrangopoulos (github.com/dfrangopoulos)
 * @brief Filesystem Interface
 * @version 0.1
 * @date 2022-02-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "fs.h"



/**
 * @brief Recursively lists all contents of a directory
 * @details 
 * 1. Recursively follows directories
 * 2. Ignores all but regular files
 * 3. Does not follow symbolic links
 * 
 * @param[in]   dir Input directory 
 */
void list_files(char *dir){
    
    DIR *d = NULL;
    struct dirent *directory;
    struct stat s_stat;
    char new_dir[4096]; /**< String that holds the current directory path (max path for ext4)*/

    if(dir != NULL)
        d = opendir(dir);
    
    if(d != NULL){
        while((directory = readdir(d)) != NULL){
            memset(new_dir,0x00,4096);
            snprintf(new_dir,4096,"%s/%s",dir,directory->d_name);
            // recurse for directories and ignore . and ..
            if(directory->d_type == DT_DIR && strcmp(directory->d_name,".") != 0 && strcmp(directory->d_name,"..") != 0){
                list_files(new_dir);
            } else if(directory->d_type == DT_REG){
                //get size
                if (stat(new_dir,&s_stat) == 0){
                    printf("%ld: %s/%s -- %ld\n",directory->d_ino, dir, directory->d_name, s_stat.st_size);
                }else{
                    err_handler(ERR_STAT_FAIL,"MINOR: Could not stat file");
                }
            }
        }
        closedir(d);
    }
    return;
}

/**
 * @brief Translates the dirent filetype character to a human readable string. (DBG)
 * 
 * @param[in]   type    d_type from dirent (filetype character)
 * @param[out]  stype   human readable translation of d_type
 */
void ftype_translator(unsigned char type, char* stype){
    switch (type){
    case DT_BLK:
        snprintf(stype,20,"Block Device");
        break;
    case DT_CHR:
        snprintf(stype,20,"Character Device");
        break;        
    case DT_DIR:
        snprintf(stype,20,"Directory");
        break;
    case DT_FIFO:
        snprintf(stype,20,"Named Pipe");
        break;
    case DT_LNK:
        snprintf(stype,20,"Symbolic Link");
        break;        
    case DT_REG:
        snprintf(stype,20,"Regular File");
        break;          
    case DT_SOCK:
        snprintf(stype,20,"UNIX Socket");
        break; 
    default:
        snprintf(stype,20,"Unknown Device");
        break;
    }
    return;
}