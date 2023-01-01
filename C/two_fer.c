// two_fer.h

#ifndef TWO_FER_H
#define TWO_FER_H

#define BUFFER_SIZE (100)


void two_fer(char *buffer, const char *name);

#endif

// two_fer.c

#include "two_fer.h"
#include "stddef.h"
#include "string.h"

void two_fer(char *buf, const char *name){
    char *str_base = "One for you, one for me.";
    
    if (name == NULL){
        strcpy(buf, str_base);
    }
    else{
        
        int pos_base = 0;
        int pos_buf = 0;
        int space_counter=0;
        while(str_base[pos_base] != '.'){
            *(buf+pos_buf) = str_base[pos_base];
            pos_base++;
            pos_buf++;
            if (str_base[pos_base] == '.'){
                *(buf+pos_buf) = str_base[pos_base];
                pos_buf++;
                *(buf+pos_buf) = '\0';
            }
            if (str_base[pos_base] == ' ' && space_counter <= 2){
                space_counter++;
            }
            if (space_counter == 2){
                *(buf+pos_buf) = str_base[pos_base];
                pos_buf++;
                pos_base = pos_base +4; // voltar a atribuir a partir de "", one for me"
                int name_letters_counter = 0;
                while(name_letters_counter < (int)strlen(name)){
                    *(buf + pos_buf + name_letters_counter) = name[name_letters_counter];
                    name_letters_counter++;
                }
                pos_buf += name_letters_counter;
                space_counter++;
            }
            
        }
    }
}
