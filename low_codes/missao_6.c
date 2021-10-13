#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct{
    float valor;
    char nome[100];
    int codBarras;
    char validade[100];
    int estoque;
}Produto;

typedef struct{
    int produtosVendidos[1000];
    int contProdutos;
    float totalVendas;
}Venda;

int main(){

    Produto p[1000];
    Venda vendidos;
    char resposta;
    int opcao;
    int cont=0;
    int qtd=0;
    int indvendido=0;
    //loop principal
    while(1){  
        printf("================================================\n");
        printf("(1) - Para cadastrar um produto\n");
        printf("(2) - Para ler um produto.\n");
        printf("(3) - Para ver produtos cadastrados.\n");
        printf("(4) - Para fechar o pedido.\n");
        printf("================================================\n");
        printf("Opcao: ");
        scanf(" %d",&opcao);
        //if para o cadastro de produto
        if(opcao == 1){
			system("cls");
            printf("\n=====CADASTRO DE PRODUTO=====\n\n");
            while(1){
                printf("INFORME O CODIGO DE BARRAS: ");
                scanf(" %d", &p[cont].codBarras);
                printf("INFORME O NOME DO PRODUTO: ");
                scanf(" %[^\n]s", p[cont].nome);
                printf("INFORME O VALOR DO PRODUTO: ");
                scanf(" %f", &p[cont].valor);
                printf("INFORME A VALIDADE DO PRODUTO: ");
                scanf(" %[^\n]s", p[cont].validade);
                printf("INFORME A QUANTIDADE EM ESTOQUE: ");
                scanf(" %d", &p[cont].estoque);
                cont++;
                printf("\nDeseja cadastrar outro produto? (S/N) ");
                scanf(" %s", &resposta);
                system("cls");
                if ((resposta != 's') && (resposta != 'S')){
                    break;
                }
            }
        }
        //ordenando
        for (int i = 0; i < cont; i++){
            for (int j = 0; j < i; j++){
                if (p[j].codBarras > p[j+1].codBarras){
                    Produto troca = p[j];
                    p[j] = p[j+1];
                    p[j+1] = troca;
                }
            }
        }
        //if para ler os produtos que vai ser vendidos
        if (opcao == 2){
			//system("cls");
            printf("\n=====LEITURA DE PRODUTOS=====\n\n");
            while(1){
                int verificar=1;
                int codigo;
                printf("\nENTRE COM O CODIGO DE BARRAS DO PRODUTO");
                printf("\nCODIGO MENOR OU IGUAL A 0 EH UM 'CODIGO NULO'!\n");
                printf("\nCODIGO: ");
                scanf(" %d", &codigo);
                //verificando se o produto está cadastrado, se estiver permite a leitura
                for(int i=0; i < cont; i++){
                    if(codigo == p[i].codBarras){                        
                        if(p[i].estoque > 0){
                            printf("QUANTOS ITENS DESEJA LEVAR? ");
                            scanf(" %d",&qtd);
                            if(!(qtd > p[i].estoque)){
								vendidos.produtosVendidos[indvendido] = p[i].codBarras;
								indvendido++;
								vendidos.contProdutos = indvendido;
								vendidos.totalVendas += p[i].valor;
								p[i].estoque -= qtd;							
								printf("\nCodigo de Barras: %d \t Nome: %s \t Valor: %.2f \t Validade: %s \t Estoque: %d\n",
                                p[i].codBarras, p[i].nome, p[i].valor, p[i].validade, p[i].estoque); 
							}else printf("\n===PRODUTO FORA DE ESTOQUE===\n"); 
                        }else printf("\n===PRODUTO FORA DE ESTOQUE===\n");
                        verificar = 0;
                        break;  
                    }       
                }
                if (verificar)
                    printf("\n===PRODUTO NAO CADASTRADO===\n");       
                if (codigo <= 0){
                    system("cls");
                    printf("\n===CODIGO NULO===\n");
                    break;
				}				
            }       
        }
        //ver os produtos cadastrados
        if (opcao == 3){
			system("cls");
            printf("\n=====PRODUTOS CADASTRADOS====\n");
            for(int j=0; j < cont; j++){
                printf("\nCodigo de Barras: %d \t Nome: %s \t Valor: %.2f \t Validade: %s \t Estoque: %d\n\n",
                                        p[j].codBarras, p[j].nome, p[j].valor, p[j].validade, p[j].estoque); 
            }
        }
        //fechar o caixa
        if(opcao == 4){
			system("cls");
            for(int i=0; i < vendidos.contProdutos; i++){
                for(int j=0; j < cont; j++){
                    if(p[j].codBarras == vendidos.produtosVendidos[i]){
                        printf("\n*******************************\n");
                        printf("Codigo de barras: %d\n",p[j].codBarras);
                        printf("Item: %s\n",p[j].nome);
                        printf("Valor unitario: %.2f\n",p[j].valor);
                        printf("\n*******************************\n");
                    }
                }
            }
            printf("Quantidade de itens: %.d\n", vendidos.contProdutos);
            printf("Total R$%.2f\n", vendidos.totalVendas);
            break;
        }  
    }             
}
