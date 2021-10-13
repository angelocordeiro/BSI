#include <stdio.h>

int main(){
	int x, y, soma=0;

	do{
		printf("Insira dois numeros: \n");
		printf("x > ");
		scanf(" %i",&x);

		do{
			printf("y > ");
			scanf(" %i",&y);
		} while(y < x);
		
		soma = x + y;

		while (x < y){
			x++;
			y--;

			if (x != y)
				soma += x + y;
			else
				soma += x;
		}

		if (soma > 0)
			printf("%i\n", soma );

	} while(x > 0 && y > 0);
}
