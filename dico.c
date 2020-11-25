#include <stdio.h>
#include <stdlib.h>


void dico (tree* huffman,char* array,int i){
//char array=malloc(sizeof(char));
char array[20];
FILE* dico;
dico=fopen("dico.txt","a+");
	if (huffman->left==NULL && huffman->right==NULL){
        fprintf(dico,"%s : %s\n",huffman->char,array);
		//free(array);
		}
	else{
        array[i]='0'; //mettre dans le tableau 0 ou 1
		dico(huffman->left,array[i+1],i);
        array[i]='1';
		dico(huffman->right,array[i+1],i);}

}

typedef struct list{
    char data;
    struct list* next;
}list;

void dico (tree* huffman,list *list){
    fct(huffman,list);
    if (huffman!=NULL)
        if (huffman->left==NULL && huffman->right==NULL){
            fprintf(dic,"%s : %s\n",huffman->data,list->data);
            suppr_list(list);}

        if (huffman->left==NULL && huffman->right!=NULL){
            list->data='1';
            dico(huffman->right,list->next);}
        if (huffman->left!=NULL && huffman->right==NULL){
            list->data='0';
            dico(huffman->left,list->next);}
        if (huffman->left!=NULL && huffman->right!=NULL){
            (list->data='0')=dico(huffman->left,list->next);
            (list->data='1')=dico(huffman->right,list->next);
        }
    }

void fct (tree* huffman,list* list){

    //list* list=malloc(sizeof(*list));
    FILE* dic;
    dic=fopen("dico.txt","a+");

    }

void fct2 (tree* huffman){

    //list* list=malloc(sizeof(*list));
    FILE* dic;
    dic=fopen("dico.txt","a+");

    }

void suppr_liste(list* list){
    list* p=list;
    while (list!=NULL){
        p=list;
        list=list->next;
        free(p);
    }
}


