#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Board{
	char owner[50];
	char board[9];
}Board;

typedef struct Car{
	char model[50];
	int chassis;
}Car;

typedef struct Infringement{
	char boardd[9];
	char description[50];
	float price;
}Infringement;

void menu(){
	printf("\n************ Opcoes ************");
	printf("\n1 - Cadastrar placa");
	printf("\n2 - Listar placas");
	printf("\n3 - Editar placas");
	printf("\n4 - Cadastrar carro");
	printf("\n5 - Listar carros");
	printf("\n6 - Multar carro");
	printf("\n7 - Listar multas\n");
	printf("\n********************************\n");
	printf("\nOpcao: ");
}

//abrir arquivo
FILE*openFile(char* nome){
	FILE* a = fopen(nome,"rb+");
	if (!a)
		a = fopen(nome,"wb+");
	if (!a)
		printf("Abertura do Arquivo negada!\n");
	return a;
}

void setBoard(FILE *board){
	Board set;
	fseek(board, 0, SEEK_END);
	printf("Digite o nome do proprietario: ");
	scanf(" %s", set.owner);
	printf("Digite a placa do veiculo: ");
	scanf(" %s", set.board);
	fwrite(&set, sizeof(Board), 1, board);
}

//Listar as placas
void getBoard(FILE *board){
	Board get;
	fseek(board, 0, SEEK_SET);
	while(fread(&get, sizeof(Board), 1, board)){
		if(strcmp(get.board, "\\0")!='0')
			printf("Placa:\t%s\tProprietario:\t%s\n", get.board, get.owner);
	}
}
//Editar placas
void editBoard(FILE *board){
	Board edit;
	char comp[9];
	while(1){
		int flag = 0;
		fseek(board, 0, SEEK_SET);
		printf("Digite a placa que deseja editar: ");
		scanf(" %[^\n]s", comp);
		while(fread(&edit, sizeof(Board), 1, board)){
			if(strcmp(comp, edit.board)==0){
				flag = 1;
				break;
			}
		}
		if(flag == 0){
			printf("Placa nao cadastrada!\n");	
		}else{
			break;
		}
	}
	printf("Editando a placa | Nova Placa: ");
	scanf(" %[^\n]s", edit.board);
	printf("Editando o nome do proprietario | Novo nome: ");
	scanf(" %[^\n]s", edit.owner);
	fseek(board, -sizeof(Board), SEEK_CUR);
	fwrite(&edit, sizeof(Board), 1, board);
}

//Cadastrar carro
void setCar(FILE *car){
	Car set;
	printf("Digite o modelo do veiculo: ");
	scanf(" %[^\n]s", set.model);
	printf("Digite o chassi do veiculo: ");
	scanf(" %d", &set.chassis);
	fwrite(&set, sizeof(Car), 1, car);
}

//Mostrar carros
void getCar(FILE *car){
	Car get;
	fseek(car, 0, SEEK_SET);
	while(fread(&get, sizeof(Car), 1, car)){
		printf("Modelo:\t%s\tChassi:\t%d\n", get.model, get.chassis);
	}
}

//Multar
void setFine(FILE *fine, FILE *car, FILE *board){
	Board x;
	Car y;
	Infringement set;
	char aux[9];
	int flag = 0;
	fseek(fine, 0, SEEK_SET);
	printf("\n***********Multar************\n");
	printf("\nPlacas cadastradas\n");
	getBoard(board);
	printf("\nChassis cadastrados\n");
	getCar(car);
	fseek(fine, 0, SEEK_SET);
	while(1){
		fseek(board, 0, SEEK_SET);
		printf("Placa do carro: ");
		scanf(" %[^\n]s", aux);
		while(fread(&x, sizeof(Board), 1, board)){
			if (strcmp(aux, x.board)==0){
				strcpy(set.boardd, aux);
				flag = 1;
				break;
			}
		}
		if(flag ==0)
			printf("Placa nao cadastrada\n");
		else break;		
	}

		printf("Modelo: ");
		scanf(" %[^\n]s", y.model);
		printf("Chassi do veiculo: ");
		scanf(" %d", &y.chassis);
		printf("Preco da multa: ");
		scanf(" %f", &set.price);
		printf("Descricao: ");
		scanf(" %[^\n]s", set.description);
		fwrite(&set, sizeof(Infringement), 1, fine);

}

//mostrar as multas
void getFine(FILE *fine, FILE *board, FILE* car){
	Infringement get;
	Board x;
	Car y;
	fseek(fine, 0, SEEK_SET);
	while(fread(&x, sizeof(Board), 1, board)){
		printf("\nNome do proprietario: %s\n", x.owner);
		printf("Placa: %s\n", x.board);
		}
	while(fread(&y, sizeof(Car), 1, car)){
		printf("Modelo: %s\n", y.model);
		printf("Chassi: %d\n", y.chassis);
		}
	while(fread(&get, sizeof(Infringement), 1, fine)){	
		printf("Motivo: %s\n" , get.description);
		printf("Preco: %2.f\n", get.price);
	}
}

int main(){
	FILE* board = openFile("board.txt");
	FILE* car = openFile("car.txt");
	FILE* fine = openFile("fine.txt");
	int option = -1;
	while(option != 0){
		menu();
		scanf(" %d", &option);
		switch(option){
			case 1:
				setBoard(board);
				break;
			case 2:
				getBoard(board);
				break;
			case 3:
				editBoard(board);
				break;
			case 4:
				setCar(car);
				break;
			case 5:
				getCar(car);
				break;
			case 6:
				setFine(fine, car, board);
				break;
			case 7:
				getFine(fine, car, board);
				break;
			default: return 0;
		}
	}
	fclose(board);
	
	return 0;
}
