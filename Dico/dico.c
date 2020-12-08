#include "dico.h"

void dico_(Huffman_Tree * huffman, char* arrayy, int i, FILE* dico){
    if (huffman->left==NULL && huffman->right==NULL){
        fprintf(dico,"%c : %s\n",huffman->struct_c.character,arrayy);
    }
    else{
        arrayy[i]='0'; //mettre dans le tableau 0 ou 1
        dico_(huffman->left,arrayy,i+1,dico);
        arrayy[i]='1';
        dico_(huffman->right,arrayy,i+1,dico);}
}

void call_dico (Huffman_Tree * huffman){
    int taille = 20;
    char array[taille];
    for (int i = 0; i < taille; ++i) {
        array[i]=0;
    }
    FILE* dico;
    dico=fopen(DICO,"w+");
    int i = 0;
    dico_(huffman, array, i, dico);
    fclose(dico);
}

