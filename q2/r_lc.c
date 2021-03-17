#include <stdio.h>
#include <string.h>

void remove_single_line_comments(char *file){ 
    FILE* buffer; 
    char c; 
    if ( (buffer = fopen(file, "r+")) != 0) 
    while ( (c = getc(buffer)) != 255 && c != EOF){

        if ( c == '\"'){
            while( (c = getc(buffer)) != '\"')
                continue;
        }


        if ( c == '/'){ 
            c = getc(buffer); 
            if ( c == '/'){ 
                fseek(buffer, ftell(buffer) - 2, SEEK_SET); 
                int comLength = 0; 
                while ( (c = getc(buffer)) != '\n') 
                    comLength++; 
                fseek(buffer, ftell(buffer) - (comLength + 1), SEEK_SET); 
                char data[comLength]; 
                memset(data, ' ', sizeof(data));           
                fwrite(data, comLength, 1, buffer); 
                fseek(buffer, ftell(buffer) + 2, SEEK_SET); 
            } else if ( c == '*'){
                while(1){
                    c = getc(buffer);
                    if(c == '*')
                        if((c = getc(buffer)) == '/')
                            break;
                }
            }
        }
    } 
    fclose(buffer); 
} 
