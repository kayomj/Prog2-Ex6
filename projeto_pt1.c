#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int gera(){
	return rand()%199;
}

void ordenar(int vet){
	
}


int main(){
	int vet[150];
	srand(time(NULL));
	for(int i=0;i<150;i++){
		vet[i]=gera();
	}
	
}
