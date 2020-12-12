/*****************************************************************//**
 * \file   huffman_tree.c
 * \brief  Huffman_tree functions
 *
 * \author Alexis Paradiso (https://github.com/WixazZ)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "huffman_tree.h"
int taille(List_Huffman_Node*t){
    int p =1;
    while (t->next !=NULL){
        t=t->next;
        p++;
    }
    return p;
}
/*
int SPACING = 10;
// Displays a tree with the leaves first, going back to the root
void print_tree_2D(List_Huffman_Node *root, int space)
{
    if (root == NULL)
        return;

    space += SPACING;

    // Process right children first
    print_tree_2D(root->element->right, space);

    // Display the current node
    printf("\n");
    for (int i = SPACING; i < space; i++)
        printf(" ");

    if (root->element->struct_c.character== -1)
    {
        printf("(%d)\n", root->element->struct_c.occurence);
    }
    else
    {
        printf("(%s, %d)\n", (root->element->struct_c.character == "\n" ? "LF/NL" : &(root->element->struct_c.character)), root->element->struct_c.occurence);
    }

    // Process left children afterwards
    print_tree_2D(root->element->left, space);
}

void print_tree_2D_wrapper(List_Huffman_Node *root)
{
    print_tree_2D(root, 0);
}*/

int min_occu_list_place(List_Huffman_Node *root) {
    List_Huffman_Node * curr = root;
    //int leng = taille(root);
    int curr_min = root->element->struct_c.occurence;
    int curr_idx = 0;
    int idx = 0;
    while (curr->next != NULL)  {
        idx++;
        curr = curr->next;
        if (curr->element->struct_c.occurence < curr_min) {
            curr_min = curr->element->struct_c.occurence;
            curr_idx = idx;
        }
    }
    return curr_idx;
}

List_Huffman_Node *del_ele_list(List_Huffman_Node *c, int p) {
    if (c == NULL) {
        if (c->next == NULL) {
            c->element->struct_c.character = '\0';
            c->element->struct_c.occurence = -1;
        } else {
            List_Huffman_Node *P, *free_P;
            P = c;
            if (p == 0) {
                free_P = c;
                c = c->next;
                free(free_P);
            } else {
                for (int i = 1; i < p; ++i) {
                    P = P->next;
                }
                if (P->next != NULL) {
                    free_P = P->next;
                    P->next = P->next->next;
                    free(free_P);
                } else if (P->next == NULL) {
                    free_P = P->next;
                    P->next = NULL;
                    free(free_P);
                }
            }
        }
    }

    return c;
}

List_Huffman_Node *get_node(List_Huffman_Node *root, int idx) {
    List_Huffman_Node *curr = root;
    for (int i = 0; i < idx; i++) {
        curr = curr->next;
    }
    return curr;
}
//trier list en fonction occ
/*
Huffman_Tree *create_huffman_tree(List_Huffman_Node *root){

    int finish = 0;
    Huffman_Tree *full_huffman_tree = allocate_huffman_branch();
    if(root->next == NULL){
        full_huffman_tree = root->element;
        finish = 1;
    }
    int min;
    List_Huffman_Node *P = NULL;
    List_Huffman_Node *P_second = NULL;

    while(finish == 0 ){
        if (root->next == NULL)
            finish = 1;
        if (full_huffman_tree -> left == NULL && full_huffman_tree->right == NULL){
            min = min_occu_list_place(root);
            P = root;
            for (int i = 0; i < min; ++i) {
                P=P->next;
            }

            full_huffman_tree->left = P->element;
            full_huffman_tree->struct_c.occurence+=full_huffman_tree->left->struct_c.occurence;
            if(finish != 1)
                root = del_ele_list(root, min);

        } else if(full_huffman_tree ->left != NULL && full_huffman_tree->right == NULL){

            min = min_occu_list_place(root);
            P = root;
            for (int i = 0; i < min; ++i) {
                P=P->next;
            }

            full_huffman_tree->right = P->element;
            full_huffman_tree->struct_c.occurence = full_huffman_tree->right->struct_c.occurence + full_huffman_tree->left->struct_c.occurence;
            if(finish != 1)
                root = del_ele_list(root, min);

        } else if (full_huffman_tree->left != NULL && full_huffman_tree->right !=NULL){
            P = root;
            min = min_occu_list_place(root);
            for (int i = 0; i < min; ++i) {
                P=P->next;
            }
            if (P->next == NULL)
                P->next = allocate_list_huffman_branch();
            P->next->element = full_huffman_tree;
            full_huffman_tree = allocate_huffman_branch();
            if (finish == 1 ){ //dernier
                full_huffman_tree->right = P->next->element;
                full_huffman_tree->left = P->element;
                full_huffman_tree->struct_c.occurence = P->element->struct_c.occurence +P->next->element->struct_c.occurence;
            }
        }
    }
    free(root);
    return full_huffman_tree;
}*/
void del_node(List_Huffman_Node *root, int idx) {
    List_Huffman_Node *prev;
    List_Huffman_Node *curr = root;
    if (idx == 0) {
        if (root->next == NULL) {
            List_Huffman_Node dead_node;
            dead_node.element = malloc(sizeof (Huffman_Tree));
            dead_node.element->struct_c.occurence=-2;
            *root = dead_node;
        } else {
            *root = *(root->next);
            //curr->next = NULL;
            return;
        }
    }
    for (int i = 0; i < idx; i++) {
        prev = curr;
        curr = curr->next;
        if (curr == NULL) {
            printf("Error: no element at index %d", idx);
            return;
        } else if (i == idx-1) {
            prev->next = curr->next;
            //curr->next = NULL;
            return;
        } else if (curr->next == NULL && i + 1 == idx) {
            prev->next = NULL;
        }
    }
}



Huffman_Tree *create_huffman_tree(List_Huffman_Node *root) {
    List_Huffman_Node *P_first, *P_second, *P_new;
    int min;
    while (root->next != NULL) {
        min = min_occu_list_place(root);
        P_first = get_node(root, min);
        //lenght = taille(root);
        del_node(root, min);
        //lenght = taille(root);
        min = min_occu_list_place(root);
        P_second = get_node(root, min);
        //printf("%c",P_second->element->struct_c.character);

        P_new = allocate_list_huffman_branch();
        P_new->element->struct_c.occurence =
                P_first->element->struct_c.occurence + P_second->element->struct_c.occurence;
        P_new->element->left = P_first->element;
        P_new->element->right = P_second->element;
        del_node(root, min);
        if (root->element->struct_c.occurence == -2){
            root =NULL;
        }
        P_new->next = root;
        root = P_new;
    }
    return root->element;
}
