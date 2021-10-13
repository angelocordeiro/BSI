#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <conio.h>
#include <time.h>

typedef struct{
    char nome[100];
    int num;
    float saldo;
}Pessoas;

typedef struct{
    char tipo[10];
    char descricao[100];
    int contaorigem;
    int contadestino;
    float valor;
}Conta;


//Cria o número da conta.
int setNum(){
        int num;
        num = 99 + (rand() % 999);
        while (num % 7 > 0){
            num = 99 + (rand() % 999);
        }
        while ((num > 999) || (num < 99)){
                num = 99 + (rand() % 999);
        }
    return num;
}

//Cadastro de contas.
Pessoas setPessoas(Pessoas* contas, int cont){
    Pessoas c;
    int verifica;
    int controll = 0;
    
    //Verifica se já existe uma conta com esse número.
    while(controll == 0){
        verifica = setNum();
        controll = 1;
        for(int i=0; i<cont; i++){
            if (verifica == contas[i].num)
                controll = 0;
        }
    }
	
    c.num = verifica;
    printf("\nO numero da sua conta eh: %i\n",c.num);
    printf("Nome do titular: ");
    scanf(" %[^\n]s",c.nome);
    c.saldo = 0;
    printf("Seu saldo eh de: R$%.2f\n",c.saldo);

    return c;
}

//Listando os dados das pessoas.
void getPessoas(Pessoas* contas, int cont){
	
	for (int i=0; i<cont; i++){
		printf("\n________________________________________________\n");
		printf("\nNome : %s\n",contas[i].nome);
		printf("Numero da conta : %d\n",contas[i].num);
		printf("O saldo da sua conta eh: R$%.2f\n",contas[i].saldo);
		printf("________________________________________________\n");
	}
}

//Deposito
Conta deposito(Conta* transacao,Pessoas* contas,int cont){
	Conta d;
	
		for (int i=0; i<cont; i++){
			if (d.valor > 0){
				if(d.contaorigem == 0)
					if(d.contadestino == contas[i].num)
						contas[i].saldo += d.valor;		
		} else { printf("Valor invalido!");
			break;
		}
	}
	return d;
}

//Saque.
Conta saque(Conta* transacao,Pessoas* contas,int cont){
	Conta d;
	
	for(int i=0; i<cont; i++){
		if ((d.valor > contas[i].saldo) || (d.valor > 0)){
			if (d.contaorigem)
				if (d.contadestino == 0)
					if (d.contaorigem == contas[i].num)
						 contas[i].saldo -= d.valor;
		} else { printf("\nVoce nao possui essa quantidade de dinheiro na conta ou o valor eh invalido!\n");
			break;
		}
	}
	return d;
}

//Transferencia
/*
Conta transferencia(Conta* transacao,Pessoas* contas,int cont){
	Conta d; float aux, aux2;

	for(int i=0; i<cont; i++){
		if ((d.valor > contas[i].saldo) || (d.valor > 0)){
			if (d.contaorigem)
				if (transacao[i].contaorigem == contas[i].num)	
					contas[i].saldo -= d.valor;
		printf("saldo: %f",contas[i].saldo);
			}			
	}
	for(int j=0; j<cont+1; j++){
			if (transacao[j].contaorigem == contas[j].num){
				aux2 = contas[j].saldo;
				printf("aux2: \t%f",aux2);	
				aux2 -= d.valor;
				contas[j].saldo = aux2;
			}
	}
	return d;
}*/

//Painel de valores.
void setPainel(Conta* transacao){
	Conta d;
	printf("\n================================================\n");
	printf("Qual eh o tipo da sua conta Credito ou Debito: ");
	scanf(" %[^\n]s", d.tipo);
	printf("Descricao: ");
	scanf(" %[^\n]s", d.descricao);
	printf("Valor: ");
	scanf(" %f",&d.valor);
	printf("Conta de origem: ");
	scanf(" %d", &d.contaorigem);
	printf("Conta de destino: ");
	scanf(" %d", &d.contadestino);
	printf("\n================================================\n");
}

//Painel de opcções.
int getOpcao(){
	printf("\n================================================\n");
	printf("(1) - Cadastro de conta\n");
	printf("(2) - Deposito\n");
	printf("(3) - Saque\n");
	printf("(4) - Transferencia entre contas.\n");
	printf("(5) - Registro geral de movimentacao.\n");
	printf("(6) - Relatorio de contas.\n");
	printf("(0) - Para encerrar o programa.\n");
	printf("================================================\n");
	printf("Opcao: ");
	int opcao;
	scanf("%d", &opcao);
	return opcao;
}

//Ordenando por saldo.
void setOrdem(Pessoas* contas, int cont){
    for (int i=0; i<cont; i++){
        for (int j=0; j<cont-1-i; j++){
            if (contas[j].saldo > contas[j+1].saldo){
                Pessoas troca = contas[j];
                contas[j] = contas[j+1];
                contas[j+1] = troca;
            }   
        }
    }
}

int main(){
	Conta transacao[100];
    Pessoas contas[100];
    int cont=0;
    
    srand(time(NULL));
    do{
		
		switch(getOpcao()){
			case 0: return 0;
				break;
			case 1: system("cls"); 
				contas[cont++] = setPessoas(contas, cont);				
				break;
			case 2: //system("cls");
				setPainel(transacao);
				deposito(transacao, contas, cont);
				break;
			case 3: //system("cls");
				setPainel(transacao);
				saque(transacao, contas, cont);
				break;
			case 4: //system("cls");
				setPainel(transacao);
				transferencia(transacao, contas, cont);				
				break;
			case 5: //system("cls");
				
				break;
			case 6: system("cls");
				setOrdem(contas, cont);
				getPessoas(contas, cont); 
				break;
		}
		
    }while(1);
}
