#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int chave;
}item;

typedef struct Noarvore *Ponteiro;

typedef struct Noarvore{
    item elemento;
    Ponteiro direita;
    Ponteiro esquerda;
    int altura;
}Noarvore;

void inicia_arvore(Ponteiro *arvore){
    (*arvore) = NULL;

}
bool esta_vazia(Ponteiro *arvore){
    if((*arvore)==NULL){
        return true;
    } else{
        return false;
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
int altura_arvore(Ponteiro *arvore){
    if((*arvore)== NULL){
        return 0;
    }else{
        return (*arvore)->altura;
    }


}
int atualiza_altura(Ponteiro *arvore){
    int AD=0,AE=0;
    AE= altura_arvore(&(*arvore)->esquerda);
    AD= altura_arvore(&(*arvore)->direita);
    if(AE>AD){
        return AE+1;
    }else{
        return AD+1;
    }
}

void simples_esquerda(Ponteiro *arvore){
    Ponteiro u;
    u=(*arvore)->direita;
    (*arvore)->direita=u->esquerda;
    u->esquerda=(*arvore);
    (*arvore)->altura=0;
    (*arvore)=u;
}
void simples_direita(Ponteiro *arvore){
    Ponteiro u;
    u=(*arvore)->direita;
    (*arvore)->esquerda=u->direita;
    u->direita=(*arvore);
    (*arvore)->altura=0;
    (*arvore)=u;
}

void dupla_esquerda(Ponteiro *arvore){
    Ponteiro u,v;
    u=(*arvore)->direita;
    v=u->esquerda;
    (*arvore)->esquerda=v->direita;
    u->esquerda=v->direita;
    v->direita=u;
    v->esquerda=(*arvore);
    (*arvore)=v;
    v->altura=atualiza_altura(&(*arvore));
    u->altura=atualiza_altura(&(*arvore));
}

void dupla_direita(Ponteiro *arvore){
    Ponteiro u,v;
    u=(*arvore)->esquerda;
    v=u->direita;
    u->direita=v->esquerda;
    v->esquerda=u;
    (*arvore)->esquerda = v->direita;
    v->direita =(*arvore);
    (*arvore)=v;
    v->altura=atualiza_altura(&(*arvore));
    u->altura=atualiza_altura(&(*arvore));

}




bool Aplicar_rotacao(Ponteiro *arvore){
    


}

bool inserir(Ponteiro *arvore, item elemento){
    if(esta_vazia(&(*arvore))== true){
        (*arvore)= malloc(sizeof(Noarvore));
        (*arvore)->elemento= elemento;
        (*arvore)->esquerda=NULL;
        (*arvore)->direita=NULL;
        (*arvore)->altura=0;
        return true;
    }
    bool deucerto;
    if(elemento.chave == (*arvore)->elemento.chave){
        return false;
    }
    if(elemento.chave > (*arvore)->elemento.chave){
        deucerto= inserir(&(*arvore)->direita, elemento);
    }else{
        deucerto=inserir(&(*arvore)->esquerda, elemento);
    }
    if(deucerto==false){
        return false;
    }else{
        Aplicar_rotacao(&(*arvore));
    }
    atualiza_altura();


}








int main() {

    return 0;
}