#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>


typedef struct Team {
    char nome[100];
    int id;

    struct Team *prox, *ant;
    
} Team;


int painel() {
    int menu;
    printf("========================================\n");
    printf("(1) - Para cadastrar time\n");
    printf("(2) - Para deletar um dado\n");
    printf("(3) - Para listar os dados\n");
    printf("(0) - Para cancelar o programa\n");
    printf("========================================\n");
    printf("Opcao: ");
    scanf(" %d", &menu);

    return menu;
}


void getTeam(Team *lista) {
    Team *aux = lista;

    if (aux == NULL) {
        printf("LISTA VAZIA\n");
     }else {
        do {
            printf("%s\t%d\n", aux->nome, aux->id);
            aux = aux->prox;
        } while (aux);
        
    }   
}


Team *setTeam(Team *lista) {

    Team *nv = (Team*) malloc(sizeof(Team));

    printf("Digite o nome do Time: ");
    scanf(" %[^\n]s", nv->nome);

    if (lista==NULL) {
        nv->ant = NULL;
        nv->prox = NULL;
        nv->id = 1;
        lista = nv;
    }
    else {

        Team *aux = lista;
        while (aux->prox != NULL)
        {
            aux = aux->prox;
        }

        nv->prox = NULL;
        nv->ant = aux;
        aux->prox = nv;
        nv->id = aux->id + 1;
    }
    
    return lista;
}


Team *delTeam(Team *lista, int id) {
    Team *aux = lista;
    while (aux) {
        if (aux->id == id) {
            if (aux->ant) {
                if (aux->prox) {
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                    break;
                }
                else {
                    aux->ant->prox = NULL;
                    break;
                }
            }
            else {
                if (aux->prox) {
                    aux->prox->ant = NULL;
                    lista = aux->prox;
                    break;
                }
                else {
                    lista = NULL;
                    break;
                }               
            }
        }
        else {
            aux = aux->prox;
        }   
    }

    return lista;
}


int main() {

    Team *lista = NULL;
    int menu = -1, id;

    while (menu != 0)
    {
        menu = painel();
        switch(menu)
        {
            case(1):
                system("clear");
                lista = setTeam(lista);
                system("clear");
                break;
            case(2):
                system("clear");
                printf("QUAL TIME DESEJA DELETAR? ");
                scanf(" %d", &id);
                lista = delTeam(lista, id);
                system("clear");
                break;
            case(3):
                system("clear");
                getTeam(lista);
                break;
        }
    }   
}