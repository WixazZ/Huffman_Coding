#include <stdio.h>
#include <stdlib.h>
#include "dico.h"


void call (tree* huffman){
    char array[20];
    FILE* dico;
    dico=fopen("dico.txt","a+");
    int i = 0;
    dico_(huffmann, array, i, dico);
    free(array);
}

void dico_ (tree* huffman,char* arrayy,int i, FILE* dico){
	if (huffman->left==NULL && huffman->right==NULL){
        fprintf(dico,"%s : %s\n",huffman->char,arrayy);
		//free(arrayy);
	}
	else{
        arrayy[i]='0'; //mettre dans le tableau 0 ou 1
		dico_(huffman->left,arrayy,i+1);
        arrayy[i]='1';
		dico_(huffman->right,arrayy,i+1);}
}
