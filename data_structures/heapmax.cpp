#include <iostream>
#include <stdio.h>

int pai(int x){
	return x/2;
}

void heap_fica(int *vet,int i,int qtd){

	int f_esq,f_dir,maior,aux;
	maior=i;
	if(2*i <= qtd){
		f_esq=2*i;
		f_dir=(2*i)+1;

		if(vet[f_esq] >= vet[f_dir] && vet[f_esq] > vet[i]){
			maior=2*i;
		}
		else if(vet[f_dir] > vet[f_esq] && vet[f_dir] > vet[i]){
			maior=2*i+1;
		} 
	}
	else if((2*i)+1 <= qtd){
		f_dir=(2*i)+1;
		if(vet[f_dir] > vet[i])
			maior=(2*i)+1;
	}
	if(maior!=i){
		aux=vet[i];
		vet[i]=vet[maior];
		vet[maior]=aux;
		heap_fica(vet,maior,qtd);
	}
}

int main(void){
	int vet[11];
	int tam,op,ind,num;
	tam=0;

	do{
		printf("\nMENU");
		printf("\n1 - Insere na Lista");
		printf("\n2 - Consultar elemento de maior prioridade: ");
		printf("\n3 - Remover elemento: ");
		printf("\n4 - Listar todos os elementos: ");
		printf("\n5 - Sair");
		printf("\nOpcao: ");
		scanf("%i",&op);

		if(op==1){//insere
			if(tam<10){
				tam++;
				printf("Elemento a inserir: ");
				scanf("%i",&num);
				ind=tam;
				while(ind>1 && vet[pai(ind)]<num){
					vet[ind]=vet[pai(ind)];
					ind=pai(ind);
				}
				vet[ind]=num;
				printf("\nNumero inserido!");
			}
		}

		if(op==2){//elemento de maior prioridade
			if(tam==0)
				printf("\nLista vazia!");
			else
				printf("\nElemento de maior prioridade: %i",vet[1]);
		}

		if(op==3){//remover
			if(tam==0)
				printf("\nLista vazia");
			else{
				int maior_prio=vet[1];
				vet[1]=vet[tam];
				tam--;
				heap_fica(vet,1,tam);
				printf("\nElemento removido: %i",maior_prio);
			}
		}

		if(op==4){//printa lista toda
			if(tam==0)
				printf("\nLista vazia!");
			else{
				printf("\nLista inteira: ");
				for(int i=1;i<=tam;i++){
					printf("%i ",vet[i]);
				}
				printf("\n");
			}
		}
	}while(op>0 && op<5);

	return 0;
}