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
	arq=fopen("texto.txt","ab");
	
	if(arq==NULL){
		printf("problemas com abertura do arquivo\n");
		exit(1);
	}
	for(int i=0;i<150;i++){
		if(fwrite(&vet[i],sizeof(vet[i]),1,arq)!=1){
			printf("ocorreu um erro de escrita no arquivo\n");
			exit(1);
		}
	}
	fclose(arq);
}
void ler_arq(int valor){
	FILE *arq;
	int num;
	int tam;
	arq=fopen("texto.txt","rb");
	if(arq==NULL){
		printf("problemas para abrir arquivo\n");
		exit(1);
	}
		if(fread(&num,sizeof(int),1,arq)!=1){
			printf("ocorreu um erro de escrita no arquivo\n");
			exit(1);
		} 
      	if (valor >= 0 && valor < 150) { 
        	fseek (arq, valor * sizeof (int), SEEK_SET); 
        	fread (&tam, sizeof (int), 1, arq);
			printf("Valor encontrado\n");
			return;

		}
}


void print(int vet[]){
	for(int i=0;i<150;i++){
		printf("%3.d\n",vet[i]);
	}
}


int main(){
	int vet[150];
	int valor;
	srand(time(NULL));
	for(int i=0;i<150;i++){
		vet[i]=gera();
		
	}
	print(vet);
	rb(vet,150);
	printf("\n---------------------pos ordenacao---------------------\n");
	print(vet);
	salvar_arq(vet);
	printf("digite um valor\n");
	scanf("%d",&valor);
	ler_arq(valor);
	
	return 0;
}