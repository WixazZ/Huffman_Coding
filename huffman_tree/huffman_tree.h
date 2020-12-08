//
// Created by parad on 19/11/2020.
//

#ifndef HUFFMAN_CODING_HUFFMAN_TREE_H
#define HUFFMAN_CODING_HUFFMAN_TREE_H
#include "../Fct_nb_occ/Comptage_Occ.h"
int min_occu_list_place(List_Huffman_Node *root);
List_Huffman_Node *get_node(List_Huffman_Node *root, int idx);
void del_node(List_Huffman_Node *root, int idx);
Huffman_Tree *create_huffman_tree(List_Huffman_Node *root);
#endif //HUFFMAN_CODING_HUFFMAN_TREE_H



