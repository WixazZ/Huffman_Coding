//
// Created by Romain on 30/11/2020.
//

#ifndef HUFFMAN_CODING_LOT_2_H
#define HUFFMAN_CODING_LOT_2_H
#include <stdlib.h>
#include <stdio.h>

#define INPUT "files/input.txt"
#define DICO "files/dico.txt"
#define OUTPUT "files/output.txt"

typedef struct occ_char{
    char character;
    int occurence;
}Occ_Char;

typedef struct huffman_tree{
     Occ_Char struct_c;
    struct huffman_tree *right;
    struct huffman_tree *left;
}Huffman_Tree;

typedef struct list_huffman_node {
    Huffman_Tree *element;
    struct list_huffman_node *next;

}List_Huffman_Node;
Huffman_Tree* allocate_huffman_branch();
List_Huffman_Node* allocate_list_huffman_branch();
List_Huffman_Node *lettersearch(int SizeHuff);
void printlist(List_Huffman_Node *nboccletter);
List_Huffman_Node * Main_Occ();
#endif //HUFFMAN_CODING_LOT_2_H
