/*****************************************************************//**
 * \file   Comptage_Occ.h
 * \brief  Comptage_Occ header
 *
 * \author Romain EYBRARD (https://github.com/EzzaaX/)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMAN_CODING_LOT_2_H
#define HUFFMAN_CODING_LOT_2_H
#include <stdlib.h>
#include <stdio.h>

#define INPUT "cmake-build-debug/files/input.txt"
#define DICO "cmake-build-debug/files/dico.txt"
#define OUTPUT "cmake-build-debug/files/output.txt"

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
/**
 * /brief function to allocate a new node
 * /return HT Human node
*/
Huffman_Tree* allocate_huffman_branch();
/**
 * \brief function to add a node to the list
 * \return LHT list of Huffman nodes
*/
List_Huffman_Node* allocate_list_huffman_branch();
/**
 * \brief Function creating the list of occurrences
 * \param SizeHuff the current size of the list
 * \return nboccletter list of occurrences
*/
List_Huffman_Node *lettersearch(int SizeHuff);
/**
 * \brief  list print for testing purpose
 * \param nboccletter list of Huffman nodes
*/
void printlist(List_Huffman_Node *nboccletter);
/**
 * \brief Main function
 * \param input.txt the input text
 * \return nboccletter list of Huffman nodes
*/
List_Huffman_Node * Main_Occ();
#endif //HUFFMAN_CODING_LOT_2_H
