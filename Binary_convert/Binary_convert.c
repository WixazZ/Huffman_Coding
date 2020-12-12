/*****************************************************************//**
* \file Binary_convert.c
* \brief binary convert functions
*
* \author Arthur Godinho (https://github.com/arthurg01)
* \version 1.0
* \date December 2020
*********************************************************************/

#include "Binary_convert.h"
int * binary_convert_caractere(int val, int* tab){
    int i;
    for(i=7; val > 0; i--){
        tab[i] = val%2;
        val = val/2;
    }
    return tab;
}

void binary_convert(){
    FILE * input = fopen(INPUT,"r");
    FILE * output = fopen(BINARY,"w+");
    int* tab = malloc(8* sizeof(int*));
    for (int i = 0; i < 8; ++i) {
        tab[i]=0;
    }
    char c;
    if (input!=NULL){
        c = fgetc(input);

        while (EOF != c){
            tab = binary_convert_caractere(c, tab);
            for (int i = 0; i < 8; ++i) {
                //printf("%d\n", tab[i]);
                fprintf(output, "%d", tab[i]);
            }
            c = fgetc(input);
        }
    }

    fclose(input);
    fclose(output);
}
