//
// Created by parad on 19/11/2020.
//

#ifndef HUFFMAN_CODING_HUFFMAN_TREE_H
#define HUFFMAN_CODING_HUFFMAN_TREE_H
typedef struct occ_char{
    char c;
    int occurence;
}Occ_Char;

typedef struct huffman_tree{
    struct occ_char struct_c;
    struct huffman_tree *right;
    struct huffman_tree *left;
}Huffman_Tree;


typedef struct same_number_position {
    int pos;
    struct same_number_position *next;
}Same_Number_Position;

/*
typedef struct list_occ_char {
    Occ_Char element;
    struct list_occ_char *next;
}List_Occ_Char;
*/

typedef struct list_huffman_tree {
    Huffman_Tree *element;
    struct list_huffman_tree *next;
}List_Huffman_Tree;

#endif //HUFFMAN_CODING_HUFFMAN_TREE_H



