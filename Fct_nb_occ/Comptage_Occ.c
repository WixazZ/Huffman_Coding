//
// Created by Romain on 30/11/2020.
//

#include "Comptage_Occ.h"
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

Huffman_Tree* allocate_huffman_branch(){
    Huffman_Tree *HT;
    HT = malloc(sizeof(Huffman_Tree));
    HT->struct_c.character = '\0';
    HT->struct_c.occurence = 0;
    HT->right = NULL;
    HT->left = NULL;
    return HT;
}
List_Huffman_Tree* allocate_list_huffman_branch(){
    List_Huffman_Tree *LHT = NULL;
    LHT = malloc(sizeof(List_Huffman_Tree));
    LHT->element = allocate_huffman_branch();
    LHT->next = NULL;
    return LHT;
}

int get_size(char *filename){
    struct stat st;
    int size;
    stat(filename, &st);
    size = st.st_size;
    return size;
}

void printchar(char* chain, int size){
    for (int i = 0; i < size; ++i) {
        printf("%c",chain[i]);
    }

}
char* fileread(char* chain) {

    FILE *file;
    int x = get_size("C:\\Users\\Romain\\CLionProjects\\Huffman_Coding\\Alice.txt");
    chain = realloc(chain, x);
    file = fopen("C:\\Users\\Romain\\CLionProjects\\Huffman_Coding\\Alice.txt", "a+");
    if (file != NULL){
        fscanf(file,"%[^\0]", chain);
        fclose(file);
    }
    return chain;
}
List_Huffman_Tree *lettersearch( const char* chain,int size,int SizeHuff){
    List_Huffman_Tree *nboccletters;
    char c ='\0';
    nboccletters =allocate_list_huffman_branch();
    nboccletters->element->struct_c.character = chain[0];
    nboccletters->element->struct_c.occurence = 1;
    SizeHuff = 1;
    for (int i = 1; i < size; ++i) {
        c = chain[i];
        List_Huffman_Tree *p =nboccletters;
        int a=0;
        while (p->next != NULL){
            if (c == p->element->struct_c.character) {
                p->element->struct_c.occurence += 1;
                a = 1;
            }
            p = p->next;
        }
        if (c == p->element->struct_c.character) {
            p->element->struct_c.occurence += 1;
            a = 1;
        }
        if (a == 0) {
            List_Huffman_Tree *new = allocate_list_huffman_branch();
            new->element->struct_c.character = c;
            new->element->struct_c.occurence = 1;
            new->next = NULL;
            p->next = new;
            SizeHuff += 1;



        }
    }
    return nboccletters;
}
void printlist(List_Huffman_Tree *nboccletters){
    List_Huffman_Tree *p =nboccletters;
    while (p->next != NULL){
        printf("la lettre %c a %d occurences\n",p->element->struct_c.character, p->element->struct_c.occurence);
        p = p->next;
    }
    printf("la lettre %c a %d occurences\n",p->element->struct_c.character, p->element->struct_c.occurence);
}
void Main_Occ(){
    int SizeHuff = 0;
    int size = get_size("C:\\Users\\Romain\\CLionProjects\\Huffman_Coding\\Alice.txt");
    char *chain = NULL;
    chain = fileread(chain);
    List_Huffman_Tree *nboccletters  = lettersearch(chain,size,SizeHuff);
    //printchar(chain,size);
    //printlist(nboccletters);
}