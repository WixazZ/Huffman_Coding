/*****************************************************************//**
 * \file   encoding.c
 * \brief  Encoding functions
 * 
 * \author Adam Louafi (https://github.com/adam-louafi)
 * \date   November 2020
 * \version 1.0
 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "encoding.h"

int * search_dico(int c_search, size_t *size){
    int* tab= NULL;
    FILE *dico = fopen(DICO, "r");
    int cursor = 0;
    do{
        cursor = fgetc(dico);
    } while (EOF != cursor && cursor != c_search);
    if (cursor == '\n'){
        cursor = fgetc(dico);
    }
    while (cursor!='\n'&& cursor!=EOF){
        if(cursor =='1'||cursor=='0'){
            (*size)++;
            tab = realloc(tab,sizeof(int)*(*size) );
            tab[*size-1] = cursor;
        }
        cursor = fgetc(dico);
    }
    fclose(dico);
    return tab;
}

void huffman_to_file(){
    FILE *input = fopen(INPUT, "r");
    FILE *output = fopen(OUTPUT, "w+");
    size_t size = 0;
    int cursor = 0;
    int* tab_bin =NULL;
    do{
        cursor = fgetc(input);
        tab_bin = search_dico(cursor, &size);
        for (int i = 0; i < size; ++i) {
            fputc(tab_bin[i],output );
        }
        size =0;
    } while (EOF != cursor);

    fclose(input);
    fclose(output);
}




