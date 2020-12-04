/*****************************************************************//**
 * \file   encoding.c
 * \brief  Encoding functions
 * 
 * \author Adam Louafi (61043077+adam-louafi@users.noreply.github.com)
 * \date   November 2020
 * \version 1.0
 *********************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/*
const int MAX_SIZE = 18;
const char DICO[] = "dico.txt";
unable to make constant work 
*/

char* character_to_binary(FILE* dico, char character, char* bit_string){
    int search_char = 0;
    int i = 0, x = 0;
    char bin_string[18] = "";
    char jump_new_line[] = "";
    dico = fopen("dico.txt", "r");
    while (search_char != character && search_char != EOF) {
        search_char = fgetc(dico);
        if (search_char != character) {
            fgets(jump_new_line, 25, dico);
        }
    }
    if (search_char != EOF) {
        if (character == '\n') {
            search_char = fgetc(dico);
        }
        while (search_char != '\n' && search_char != EOF) {
            search_char = fgetc(dico);
            if (search_char == '1' || search_char == '0') {
                bin_string[i] = search_char;
                i++;
            }
        }
    }
    for(x=i;x<18;x++){
        bin_string[x] = '\0'; // necessary since bit_string takes other values for no reason
        }    
    strcpy(bit_string,bin_string);
    fclose(dico);
    return bit_string;
}
void huffman_to_file(FILE* input, FILE* output, FILE* dico, char* huffman_code){
    int search_char = 0;
    input = fopen("input.txt","r");
    dico = fopen("dico.txt","r");
    output = fopen("huffman.txt","w+");
    while(search_char != EOF){
        search_char = fgetc(input);
        huffman_code = character_to_binary(dico,search_char,huffman_code);
        if(search_char != EOF){
            fputs(huffman_code,output);
        }    
    }
    fclose(input);
    fclose(output);
}

//main integration template
int main(){ 
    clock_t timer = clock();
    FILE* dico = NULL;
    FILE* input = NULL;
    FILE* output = NULL; 
    char* huffman_code = malloc(sizeof(char) * 18);
    huffman_to_file(input,output,dico,huffman_code);
    timer = clock() - timer;
    double elapsed_time = ((double)timer)/CLOCKS_PER_SEC;
    printf("\nElapsed time : %f\n", elapsed_time);
    free(huffman_code);
    return 0;
}