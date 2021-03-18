#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "r_lc.h"
#include "r_mc.h"
#include "rs.h"
                        
int main(){
    char file[20] = "temp.c";

    printf("All operations will be performed on the file: %s\n", file);

    remove_single_line_comments(file); 
    printf("Removed Single line comments\n");
    remove_multi_line_comments(file);
    printf("Removed multi line comments\n");
    remove_spaces(file);
    printf("Removed spaces\n");

    printf("Check the file: %s\n", file);


    return 0;
}