//
// Created by Romain on 30/11/2020.
//

#ifndef HUFFMAN_CODING_LOT_2_H
#define HUFFMAN_CODING_LOT_2_H
typedef struct occ_char{
    char character;
    int occurence;
}Occ_Char;

typedef struct huffman_tree{
     Occ_Char struct_c;
    struct huffman_tree *right;
    struct huffman_tree *left;
}Huffman_Tree;

typedef struct list_huffman_tree {
    Huffman_Tree *element;
    struct list_huffman_tree *next;

}List_Huffman_Tree;
Huffman_Tree* allocate_huffman_branch();
List_Huffman_Tree* allocate_list_huffman_branch();
int get_size(char *filename);
void printchar(char* chain, int size);
char* fileread(char* chain);
List_Huffman_Tree *lettersearch(const char* chain,int size,int SizeHuff);
void printlist(List_Huffman_Tree *nboccletter);
void Main_Occ();
#endif //HUFFMAN_CODING_LOT_2_H
