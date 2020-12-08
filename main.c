//
// Created by Alexis Paradiso on 08/12/2020.
//

#include "Fct_nb_occ/Comptage_Occ.h"
#include "huffman_tree/huffman_tree.h"
#include "Encoding/encoding.h"
#include "Dico/dico.h"
#include <time.h>

int main() {
    printf("****************************************\n");
    printf("\n");
    printf("\n");
    printf("        Codage de Huffman\n");
    printf("\n");
    printf("\n");
    printf("****************************************\n\n\n");
    FILE * input = fopen(INPUT,"r");
    FILE * output= fopen(OUTPUT,"r");
    FILE * dico = fopen(DICO,"r");
    if (input == NULL){
        printf("Pour continuer vous devez creer un dossier files et creer un fichier input.txt a l'interieur\n");
    } else if (output == NULL){
        printf("Pour continuer vous devez creer un dossier files et creer un fichier output.txt a l'interieur\n");
    } else if (dico == NULL){
        printf("Pour continuer vous devez creer un dossier files et creer un fichier dico.txt a l'interieur\n");
    } else{
        fclose(input);
        fclose(output);
        fclose(dico);
        int in;
        do {
            printf("\n\n Voulez-vous codez(0) ou (Bientot)decodez(1) un fichier ?\n");
            scanf("%d",&in);
        } while (in!=0);

        clock_t t1,t2;
        float temps;
        t1 = clock();
        huffman_to_file();
        List_Huffman_Node *P = Main_Occ();
        Huffman_Tree *f;
        f = create_huffman_tree(P);
        call_dico(f);
        huffman_to_file();
        t2 = clock();
        temps = (float)(t2-t1)/1000000;
        printf("\nLe fichier a mis %fs a ce coder\n", temps);
    }
    return 0;
}