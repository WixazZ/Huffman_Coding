/*****************************************************************//**
 * \file   huffman_tree.h
 * \brief  Huffman_tree functions header
 *
 * \author Alexis Paradiso (https://github.com/WixazZ)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/

#ifndef HUFFMAN_CODING_HUFFMAN_TREE_H
#define HUFFMAN_CODING_HUFFMAN_TREE_H
#include "../Fct_nb_occ/Comptage_Occ.h"

/**
 * @param List of node
 * @return position of the min occurences
*/
int min_occu_list_place(List_Huffman_Node *root);
/**
 * @param List of node
 * @param the position of node
 * @return position where i need to place
*/
List_Huffman_Node *get_node(List_Huffman_Node *root, int idx);
/**
 * @brief delete the element in list
 * @param List of node
 * @param position of the min occurences
*/
void del_node(List_Huffman_Node *root, int idx);
/**
 * @brief principal function to create a Huffman tree
 * @param List of node
 * @return structure Huffman_Tree
*/
Huffman_Tree *create_huffman_tree(List_Huffman_Node *root);
#endif //HUFFMAN_CODING_HUFFMAN_TREE_H



