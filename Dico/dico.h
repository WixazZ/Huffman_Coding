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
void call_dico (Huffman_Tree * huffman);
void dico_(Huffman_Tree * huffman,char* arrayy,int i, FILE* dico);
#endif //HUFFMAN_CODING_DICO_H
