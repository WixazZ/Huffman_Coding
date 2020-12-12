/*****************************************************************//**
 * \file   Comptage_Occ.c
 * \brief  Comptage_Occ function
 *
 * \author Romain EYBRARD (https://github.com/EzzaaX/)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/
#include "Comptage_Occ.h"

Huffman_Tree* allocate_huffman_branch(){
    Huffman_Tree *HT = malloc(sizeof(Huffman_Tree));
    HT->struct_c.character = '\0';
    HT->struct_c.occurence = 0;
    HT->right = NULL;
    HT->left = NULL;
    return HT;
}
List_Huffman_Node* allocate_list_huffman_branch(){
    List_Huffman_Node *LHT = malloc(sizeof(List_Huffman_Node));
    LHT->element = allocate_huffman_branch();
    LHT->next = NULL;
    return LHT;
}

List_Huffman_Node *lettersearch(int SizeHuff){
    List_Huffman_Node *nboccletters;
    char c ='\0';
    FILE* file = fopen(INPUT,"r+");
    if (file == NULL)
        printf("ERREUR\n");
    nboccletters =allocate_list_huffman_branch();
    nboccletters->element->struct_c.character = fgetc(file);
    nboccletters->element->struct_c.occurence = 1;
    SizeHuff = 1;
    while (c != EOF){
        c = fgetc(file);
        if (c>0){
            List_Huffman_Node *p =nboccletters;
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
                List_Huffman_Node *new = allocate_list_huffman_branch();
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
void printlist(List_Huffman_Node *nboccletters){
    List_Huffman_Node *p =nboccletters;
    int a=0;
    while (p->next != NULL){
        printf("la lettre %c a %d occurences\n",p->element->struct_c.character, p->element->struct_c.occurence);
        a++;
        p = p->next;
    }
    printf("la lettre %c a %d occurences\n",p->element->struct_c.character, p->element->struct_c.occurence);
    a++;
    printf("%d",a);
}
List_Huffman_Node * Main_Occ(FILE* input){
    int SizeHuff = 0;
    List_Huffman_Node *nboccletters  = lettersearch(SizeHuff);
    //printlist(nboccletters);
    return nboccletters;
}
