#include <stdio.h>
#include <string.h>

void remove_multi_line_comments(char *file){ 
    FILE* buffer; 
    char c; 
    int comStart, comEnd; 
    if ( (buffer = fopen(file, "r+")) != 0) 
        while( (c = getc(buffer)) != EOF && c != 255){

            if ( c == '\"'){
                while( (c = getc(buffer)) != '\"')
                    continue;
            }

            if (c == '/'){ 
                c = getc(buffer); 
                if ( c == '*'){ 
                    comStart = ftell(buffer) - 2; 
                    while( (c = getc(buffer)) != '*')  
                        continue; 
                    if( (c = getc(buffer)) == '/') 
                        comEnd = ftell(buffer); 
                
                    fseek( buffer, comStart, SEEK_SET ); 
                    while( comStart != comEnd ){ 
                        putc(' ', buffer); 
                        comStart++; 
                        fseek( buffer, comStart, SEEK_SET ); 
                    } 
                } 
            } 
        }
    
    
    fclose(buffer); 
} 

