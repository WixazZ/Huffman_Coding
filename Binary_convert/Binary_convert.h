/*****************************************************************//**
 * \file   binary_convert.h
 * \brief  binary convert functions header
 *
 * \author Arthur Godinho (https://github.com/arthurg01)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/
#ifndef HUFFMAN_CODING_BINARY_CONVERT_H
#define HUFFMAN_CODING_BINARY_CONVERT_H
#include "../Fct_nb_occ/Comptage_Occ.h"

/**
 * @brief convert caractere
 * @param value to convert
 * @param tab who receive the value binary
 * @return return tab
*/
int * binary_convert_caractere(int val, int* tab);
/**
 * @brief function who convert the text in binary and write in binary.txt
 */
void binary_convert();
#endif //HUFFMAN_CODING_BINARY_CONVERT_H
