#include "Comptage_Occ.h"
#include <stdlib.h>
#include <stdio.h>
#define TEXT "input.txt"

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

List_Huffman_Tree *lettersearch(int SizeHuff){
    List_Huffman_Tree *nboccletters;
    char c ='\0';
    FILE* file = fopen(TEXT,"r");
    nboccletters =allocate_list_huffman_branch();
    nboccletters->element->struct_c.character = fgetc(file);
    nboccletters->element->struct_c.occurence = 1;
    SizeHuff = 1;
    while (c != EOF){
        c = fgetc(file);
        if (c>0){
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
List_Huffman_Tree * Main_Occ(){
    int SizeHuff = 0;
    List_Huffman_Tree *nboccletters  = lettersearch(SizeHuff);
    //printlist(nboccletters);
    return nboccletters;
}
