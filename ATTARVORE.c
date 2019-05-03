# EDD-ARVORE-

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
}item;

typedef struct nozin *Ponteiro;

typedef struct nozin{
    item elemento;
    Ponteiro esquerda;
    Ponteiro direita;
}nozin;

bool inicia_arvore(Ponteiro *arvore) {
    (*arvore) = NULL;
}

bool esta_vazia(Ponteiro *arvore){
    if((*arvore) == NULL){
        return true;

    }
}

bool inserir(Ponteiro *arvore, item elemento){

    if((*arvore) == NULL){
        (*arvore) = malloc(sizeof(nozin));
        (*arvore)->elemento = elemento;
        (*arvore)->direita = (*arvore)->esquerda = NULL;
//        printf("%d\n", (*arvore)->elemento.chave);
        return true;
    }

    if((*arvore)->elemento.chave == elemento.chave){
        return false;
    }
    if((*arvore)->elemento.chave > elemento.chave){
        return inserir(&(*arvore)->esquerda, elemento);
    }
    else{
        return inserir(&(*arvore)->direita, elemento);
    }

}

void Pre_ordem(Ponteiro *arvore){
    if(*arvore == NULL)
        return;
    printf("%d\n", ((*arvore)->elemento.chave));
    Pre_ordem(&(*arvore)->esquerda);
    Pre_ordem(&(*arvore)->direita);

}
void Pos_ordem(Ponteiro *arvore){
    if(*arvore == NULL)return;
    Pos_ordem(&(*arvore)->esquerda);
    Pos_ordem(&(*arvore)->direita);
    printf("%d\n", (*arvore)->elemento.chave);
}

void Em_ordem(Ponteiro *arvore){
    if(*arvore == NULL) return;
    Em_ordem(&(*arvore)->esquerda);
    printf("%d\n", (*arvore)->elemento.chave);
    Em_ordem(&(*arvore)->direita);
}
bool Procura(Ponteiro *arvore, int elemento, item *porra){
    if((*arvore)== NULL){
        printf("elemento nao existe\n");
        return false;
    }
    if((*arvore)->elemento.chave == elemento){
        *porra= (*arvore)->elemento;
        printf("elemento encontrado: %i\n", porra->chave);
        return true;
    }
    if((*arvore)->elemento.chave >elemento){
        return Procura(&(*arvore)->esquerda, elemento, porra);
    }
    else{
        return Procura(&(*arvore)->direita, elemento, porra);
    }

}

bool remocao(Ponteiro *arvore, item chave){
    Ponteiro aux;

    if((*arvore)== NULL){
        return false;
    }
    if((*arvore)->elemento.chave == chave.chave){
        aux= (*arvore);
        if((*arvore)->esquerda == NULL){
           (*arvore) = (*arvore)->direita;
           free(aux);
        }
        if((*arvore)->esquerda == NULL){
            (*arvore) = (*arvore)->direita;
            free(aux);
        }
        if((*arvore)->direita == NULL && (*arvore)->esquerda == NULL){
            (*arvore)= (*arvore)->esquerda;
            free(aux);
        }
        if((*arvore)->esquerda !=NULL && (*arvore)->direita != NULL){

        }



    }
}

/*bool remove(Ponteiro *arvore, item elemento) {
    if(Procura(&(*arvore), elemento.chave) == true){

    }
}
*/


int main() {
    Ponteiro raiz;
    item X;
    item Y;
    inicia_arvore(&raiz);
    X.chave=10;
    inserir(&raiz, X);
    X.chave= 20;
    inserir(&raiz, X);
    X.chave=4;
    inserir(&raiz, X);
    X.chave =3;
    inserir(&raiz, X);
    X.chave =15;
    inserir(&raiz, X);
    X.chave =22;
    inserir(&raiz, X);
    X.chave =5;
    inserir(&raiz, X);
    Em_ordem(&raiz);
    Procura(&raiz, 3, &Y);
    Procura(&raiz, 80, &Y);
    Procura(&raiz, 25,&Y);





    return 0;
}
