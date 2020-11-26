//
// Created by parad on 19/11/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include "huffman_tree.h"

Huffman_Tree* allocate_huffman_branch(){
    Huffman_Tree *HT;
    HT = malloc(sizeof(Huffman_Tree));
    HT->struct_c.c = '\0';
    HT->struct_c.occurence = 0;
    HT->right = NULL;
    HT->left = NULL;
    return HT;
}

List_Huffman_Tree* allocate_list_huffman_branch(){
    List_Huffman_Tree *LHT = NULL;
    LHT->element = allocate_huffman_branch();
    LHT->next = NULL;
    return LHT;
}

int min_occu_list_place(List_Huffman_Tree *c) {
    int min = -1;

    if (c != NULL) {
        min = 0;
        int forward = 1;
        int elem = c->element->struct_c.occurence;
        List_Huffman_Tree *P;
        P = c;
        while (P->next != NULL) {
            if (P->element->struct_c.occurence < elem) {
                min = forward;
                elem = P->element->struct_c.occurence;
                forward++;
            }
        }
    }
    return min;
}

List_Huffman_Tree * del_ele_list(List_Huffman_Tree *c, int p){
    if (c->next == NULL){
        c->element->struct_c.c = '\0';
        c->element->struct_c.occurence = -1;
    }else {
        List_Huffman_Tree *P, *free_P;
        P = c;
        if (p == 1) {
            free_P = c;
            c = c->next;
            free(&free_P);
        } else {
            for (int i = 1; i < p; ++i) {
                P = P->next;
            }
            if (P->next->next != NULL) {
                free_P = P->next;
                P->next = P->next->next;
                free(&free_P);
            } else if (P->next->next == NULL) {
                free_P = P->next;
                P->next = NULL;
                free(&free_P);
            }
        }
    }
    return c;
}



Huffman_Tree *create_huffman_tree(List_Huffman_Tree *all_char){


    Huffman_Tree *full_huffman_tree = allocate_huffman_branch();
    int min = min_occu_list_place(all_char);
    List_Huffman_Tree *P = all_char;
    while (all_char->next != NULL){
        P=P->next;
    }

    full_huffman_tree->left->struct_c = P->element->struct_c;
    full_huffman_tree->struct_c.occurence =  full_huffman_tree->left->struct_c.occurence;
    all_char = del_ele_list(all_char, min);

    while(all_char->next != NULL){
        if (full_huffman_tree ->left == NULL){

            min = min_occu_list_place(all_char);
            P = all_char;
            while (all_char->next != NULL){
                P=P->next;
            }

            full_huffman_tree->left->struct_c = P->element->struct_c;
            full_huffman_tree->struct_c.occurence =  full_huffman_tree->left->struct_c.occurence;
            all_char = del_ele_list(all_char, min);

        } else if(full_huffman_tree ->left != NULL && full_huffman_tree->right == NULL){

            min = min_occu_list_place(all_char);
            P = all_char;
            while (all_char->next != NULL){
                P=P->next;
            }

            full_huffman_tree->right->struct_c = P->element->struct_c;
            full_huffman_tree->struct_c.occurence =  full_huffman_tree->right->struct_c.occurence;
            all_char = del_ele_list(all_char, min);
        }
        if (full_huffman_tree->left !=NULL && full_huffman_tree->right !=NULL){
            while (all_char->next != NULL){
                P=P->next;
            }
            P->next->element = full_huffman_tree;
            full_huffman_tree = allocate_huffman_branch();
        }
    }

    return full_huffman_tree;

}


int main(){
    return 0;
}