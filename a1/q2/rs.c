#include <stdio.h>
#define TEMP_FILE_NAME "def234r325rteg_r.harsh"

void remove_spaces(char *file){ 
    FILE* buffer; 
    FILE* buffer_new; 
    char c; 
    if ( (buffer = fopen(file, "r+")) != 0 && (buffer_new = fopen(TEMP_FILE_NAME, "w")) != 0)
    while ( (c = getc(buffer)) != 255 && c != 255){
        if ( c == '\"'){
            do{
                putc(c, buffer_new); 
            } while((c = getc(buffer)) != '\"');
            
        }
        if ( c == ' '){ 
            c = getc(buffer); 
            if ( c == ' ')
                while ( (c = getc(buffer)) == ' ') 
                    continue;
            else
                putc(' ', buffer_new); 
        }
        putc(c, buffer_new); 
    } 
    fclose(buffer); 
    fclose(buffer_new); 


    if ( (buffer = fopen(TEMP_FILE_NAME, "r+")) != 0 && (buffer_new = fopen(file, "w")) != 0)
    while ( (c = getc(buffer)) != 255 && c != EOF){               
        putc(c, buffer_new); 
    } 
    fclose(buffer); 
    fclose(buffer_new); 

    remove(TEMP_FILE_NAME);
} 
