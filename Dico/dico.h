/*****************************************************************//**
* \file dico.h
* \brief Header of the dico
*
* \author Arthur Lin arthur.lin@efrei.net
* \date December 2020
*********************************************************************/

#ifndef HUFFMAN_CODING_DICO_H
#define HUFFMAN_CODING_DICO_H
#include "../Fct_nb_occ/Comptage_Occ.h"

/**
 * @brief function to call dico
 * @param huffman huffman tree
*/
void call_dico (Huffman_Tree * huffman);

/**
 * @brief function which will insert 0 or 1 to file.txt
 * @param huffman huffman tree
 * @param arrayy stocking data in array
 * @param i counter for the array
 * @param dico the file.txt that will contain the dico
*/
void dico_(Huffman_Tree * huffman,char* arrayy,int i, FILE* dico);

#endif //HUFFMAN_CODING_DICO_H
