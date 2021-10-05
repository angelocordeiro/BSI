#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[100];
    int idade;
}Pessoa;

int main(){
    //alocação dinâmica
    Pessoa* p = malloc(sizeof(Pessoa));
    scanf(" %[^\n]s", p->nome);
    scanf(" %d", &p->idade);
    printf("Nome: %s \nIdade: %d", p->nome, p->idade);

}