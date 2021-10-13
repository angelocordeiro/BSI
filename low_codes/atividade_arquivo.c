#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Placa{
    
}Placa;


char * letras(){
    srand(time(NULL));
        
    char letras, alfabeto[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','x','y','z'};
	letras=malloc(20*sizeof(char));
    for(int i=0; i<3; i++){
        int num;
        num = (rand() % 25);      
        letras[i] = alfabeto[num];
    }
    //printf("Letras: %s\n",letras);
    return letras;
}


int setPlaca(){
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


int main (){
    /*char* c[4] = letras();
    FILE* arq = openArq("fonte.txt");

    printf("%s",c);
*/


//    fclose(arq);
}
