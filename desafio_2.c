#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,n100,n50,n20,n10,n5,n2,n1;
    printf("Entre com o valor da cedula: ");
    scanf(" %d",&n);
    for (int i = 1; i < n; i++){
        if (n > 100){
            n100 += 1;
            n = n - 100;
        }
        if (n > 50){
            n50 += 1;
            n = n - 50;
        }
        if (n > 20){
            n20 += 1;
            n = n - 20;
        }
        if (n > 10){
            n10 += 1;
            n = n - 10;
        }
        if (n > 5){
            n5 += 1;
            n = n - 5;
        }
        if (n > 2){
            n2 += 1;
            n = n - 2;
        }
        if (n > 1){
            n1 += 1;
            n = n - 1;
        }
    }
    printf("%d nota(s) de R$ 100,00\n",n100);
    printf("%d nota(s) de R$ 50,00\n",n50);
    printf("%d nota(s) de R$ 20,00\n",n20);
    printf("%d nota(s) de R$ 10,00\n",n10);
    printf("%d nota(s) de R$ 5,00\n",n5);
    printf("%d nota(s) de R$ 2,00\n",n2);
    printf("%d nota(s) de R$ 1,00\n",n1);
    
    
    
}
