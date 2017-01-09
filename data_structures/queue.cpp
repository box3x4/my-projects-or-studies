#include <iostream>
#include <stdio.h>
//inclusão bibliotecas

using std::cin;

int main()
{
	struct fila{
		int num;
		fila *prox;
	};

	struct fila *inicio=NULL;
	struct fila *fim=NULL;
	struct fila *aux;
	//aloca os ponteiros do inicio, fim e auxiliar

	int op;
	//variavel q identifica a operação

	do
	{
		printf("\nMenu de opcoes\n");
		printf("\n1-Inserir na fila");
		printf("\n2-Consultar a fila");
		printf("\n3-Remover da fila");
		printf("\n4-Esvaziar a fila");
		printf("\n5-Sair\n");
		//opçoes a serem realizadas

		cin>>op;
		//entra com a opção

		if(op<1 || op>5)
			printf("Opcao invalida!");

		if(op==1){

			printf("Digite o numero a ser inserido: ");
			struct fila *novo=new fila();
			cin>>novo->num;
			novo->prox=NULL;
			//le o numero a inserir, ja atribuindo ao novo ponteiro "novo"

			if(inicio==NULL){
				inicio=novo;
				fim=novo;
			}
			else{
				fim->prox=novo;
				fim=novo;
			}
			//faz as operações de inserção para os dois casos

			printf("Numero inserido!");
		}

		if(op==2){
			
			if(inicio==NULL)
				printf("Fila Vazia!");
			else{

				aux=inicio;
				//ponteiro para percorrer a fila

				while(aux!=NULL){
					printf("%i ",aux->num);
					aux=aux->prox;
				}//printa os auxs
			}
		}

		if(op==3){

			if(inicio==NULL)
				printf("\nFila Vazia!");
			else{
				aux=inicio;
				inicio=inicio->prox;
				delete(aux);
			}//remove o nó da fila
		}

		if(op==4){

			if(inicio==NULL)
				printf("\nFila Vazia!");
			else{

				aux=inicio;
				while(inicio!=NULL){
					inicio=inicio->prox;
					delete(aux);
					aux=inicio;
				}//faz a operação de esvaziar. mesma de remoção, porém até o final

				printf("\nFila esvaziada!");
			}
		}
		
	}while(op!=5);

	return 0;
}//fim main()