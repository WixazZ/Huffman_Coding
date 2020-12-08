/*****************************************************************//**
 * \file   encoding.h
 * \brief  Encoding functions header
 * 
 * \author Adam Louafi (61043077+adam-louafi@users.noreply.github.com)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/
#include "../Fct_nb_occ/Comptage_Occ.h";
/**
 * @brief translates character to binary
 * @param c_search character looked for
 * @param size size of returned array 
 * @return int array
*/
int* search_dico(int c_search, size_t* size);
/**
 * @brief translates text to huffman code
*/
void huffman_to_file();