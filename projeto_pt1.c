#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int vet[150];

int gera(){
	return rand()%199;
}

void rb(int n)
{
   int i, aux;
   while(n>=0)
    for (i = 0; i < n - 1; i++) {
        if (vet[i]>vet[i + 1] ){
            aux = vet[i + 1];
			vet[i + 1] = vet[i];
        	vet[i] = aux;
    	}
	}
	n - 1;
}

void print(){
	for(int i=0;i<150;i++){
		printf("%3.d\n",vet[i]);
	}
}
int main(){
	int cont=0; 
	srand(time(NULL));
	for(int i=0;i<150;i++){
		vet[i]=gera();
		cont++;
	}
	print();
	printf("%d\n", cont);
	rb(150);
	printf("\n---------------------pos ordenacao---------------------\n");
	print();

	return 0;
}
