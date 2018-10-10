#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int gera(){
	return rand()%199;
}


void rb(int vet[], int n)
{
    if(n == 0) 
        return;

    int i, aux;
    for (i = 0; i < n - 1; i++) {
        if ( vet[i] > vet[i + 1]){
            aux = vet[i + 1];

        vet[i + 1] = vet[i];
        vet[i] = aux;
    	}
	}
    rb(vet, n - 1);
}


void salvar_arq(int vet[150]){
	FILE *arq;
	arq=fopen("texto.txt","wb");
	
	if(arq==NULL){
		printf("problemas com abertura do arquivo");
		exit(1);
	}
	for(int i=0;i<150;i++){
		if(fwrite(&vet[i],1,sizeof(vet[i]),arq)!=1){
			printf("erro na escrita do arquivo");
			exit(1);
		}
	
	}
	fclose(arq);
}


void print(int vet[]){
	for(int i=0;i<150;i++){
		printf("%3.d\n",vet[i]);
	}
}


int main(){
	int vet[150];
	int cont=0; 
	srand(time(NULL));
	for(int i=0;i<150;i++){
		vet[i]=gera();
		
	}
	print(vet);
	printf("%d\n", cont);
	rb(vet,150);
	printf("\n---------------------pos ordenacao---------------------\n");
	print(vet);
	salvar_arq(vet);
	return 0;
}
