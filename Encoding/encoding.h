/*****************************************************************//**
 * \file   encoding.h
 * \brief  Encoding functions header
 * 
 * \author Adam Louafi (61043077+adam-louafi@users.noreply.github.com)
 * \version 1.0
 * \date   December 2020
 *********************************************************************/
#include "encoding.c"
/**
 * @brief translates character to binary
 * @param dico huffman dictionary
 * @param character character looked for
 * @param bit_string string containing translation
 * @return char array
*/
char* character_to_binary(FILE* dico, char character, char* bit_string);

/**
 * @brief translates text to huffman code
 * @param input text
 * @param output output text written in huffman code
 * @param dico huffman dictionary
 * @param huffman_code array containing return of character_to_binary()
*/
void huffman_to_file(FILE* input, FILE* output, FILE* dico, char* huffman_code);