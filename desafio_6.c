#include <stdio.h>
#include <math.h>
int is_prime(int );
int main()
{   
	 int n,i;  
	 scanf("%d",&n);  
	 for(i=2;i<n/2;i++)   
	     {        
	     	if(is_prime(i)==1&&is_prime(n-i)==1) break;   
	     }   	
	printf("%d = %d + %d",n,i,n-i);
    	return 0;
}
int is_prime(a)
{  
	 int i;    
	 if(a==2)   
	 return 1;   	
  	 if(a<=1)   
	 return 0;   
	 for(i=2;i<=sqrt(a);i++)   
	 {        
	      if(a%i==0)
	       return 0;   
	 }    
	 return 1; 
 }
