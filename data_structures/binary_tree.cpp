#include <stdio.h>
#include <iostream>

struct arvore{
	int info;
	arvore *dir,*esq;
};//estrutura da arvore

void posordem(arvore *aux){
	if(aux!=NULL){
		posordem(aux->esq);
		posordem(aux->dir);
		printf("%i ",aux->info);
	}
}//metodo de posordem

void emordem(arvore *aux){
	if(aux!=NULL){
		emordem(aux->esq);
		printf("%i ",aux->info);
		emordem(aux->dir);
	}
}//metodo de ordem

void preordem(arvore *aux){
	if(aux!=NULL){
		printf("%i ",aux->info);
		preordem(aux->esq);
		preordem(aux->dir);
	}
}//método de preordem

arvore *remover(arvore *aux,int numero){

	arvore *p,*p2;

	if(aux->info==numero){
		if(aux->esq==aux->dir){//sem filhos
			delete aux;
			return NULL;
		}
		else if(aux->esq==NULL){//tem filho a direita
			p=aux->dir;
			delete aux;
			return p;
		}
		else if(aux->dir==NULL){//tem filho a esquerda
			p=aux->esq;
			delete aux;
			return p;
		}
		else{//filhos em ambos lados
			p2=aux->dir;
			p=aux->dir;
			while(p->esq!=NULL){
				p=p->esq;
			}
			p->esq=aux->esq;
			//passa a subarvore a esquerda de aux para
			//o ultimo nó a esquerda da sub arvore
			//a direita de aux(que virará raiz)

			delete aux;
			return p2;
		}
	}
	else if(numero>aux->info)
		aux->dir=remover(aux->dir,numero);
	else
		aux->esq=remover(aux->esq,numero);

	return aux;
}//metodo de remover numero

arvore *insere(arvore *aux, int numero){
	if(aux==NULL){
		aux= new arvore();
		aux->info= numero;
		aux->esq=NULL;
		aux->dir=NULL;
	}//procura a folha da arvore
	else if(numero<aux->info)
		aux->esq=insere(aux->esq,numero);
	else
		aux->dir=insere(aux->dir,numero);

	return aux;
}//método insere numero

arvore *desalocar(arvore *aux){
	if(aux!=NULL){
		aux->esq=desalocar(aux->esq);
		aux->dir=desalocar(aux->dir);
		delete aux;
	}
	return NULL;
}//método para desalocar a arvore

int consultar(arvore *aux,int numero,int achou){
	if(aux!=NULL && achou==0){
		if(aux->info==numero){
			achou=1;
		}
		else if(numero < aux->info)
			achou=consultar(aux->esq,numero,achou);
		else
			achou=consultar(aux->dir,numero,achou);
	}
	return achou;
}//método de consulta na árvore

int main(void){
	arvore *raiz=NULL;

	int op,achou,num;

	do{
		printf("\nMENU");
		printf("\n1 - Insere na Arvore");
		printf("\n2 - Consultar um no da Arvore");
		printf("\n3 - Consultar toda Arvore em pre-ordem");
		printf("\n4 - Consultar toda Arvore em ordem");
		printf("\n5 - Consultar toda Arvore em pos-ordem");
		printf("\n6 - Excluir um no da Arvore");
		printf("\n7 - Esvaziar toda Arvore");
		printf("\n8 - Sair");
		printf("\nOpcao: ");
		scanf("%i",&op);

		if(op==1){
			
			printf("\nNumero a inserir na Arvore: ");
			scanf("%i",&num);
			raiz=insere(raiz,num);
			printf("\nNumero inserido!");
		}//opção insere

		if(op==2){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				printf("\nNumero a ser consultado: ");
				scanf("%i",&num);
				achou=0;
				achou=consultar(raiz,num,achou);

				if(achou==1)
					printf("\nNumero existente na Arvore!");
				else
					printf("\nNumero nao existente na Arvore!");
			}
		}//opção busca numero

		if(op==3){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				printf("\nListando em pre-ordem\n");
				preordem(raiz);
			}
		}//opçao listar preordem

		if(op==4){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				printf("\nListando em ordem\n");
				emordem(raiz);
			}
		}//opçao listar em ordem

		if(op==5){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				printf("\nListando em pos-ordem\n");
				posordem(raiz);
			}
		}//opçao listar pos ordem

		if(op==6){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				printf("\nInforme o numero a ser removido: ");
				scanf("%i",&num);
				achou=0;
				achou=consultar(raiz,num,achou);
				//verifica se o nó existe
				if(achou==0)
					printf("\nNumero nao existente na Arvore!");
				else{
					raiz=remover(raiz,num);
					printf("\nNumero removido!");
				}
			}
		}//opçao remoção

		if(op==7){

			if(raiz==NULL)
				printf("\nArvore vazia!");
			else{
				raiz=desalocar(raiz);
				printf("\nArvore desalocada!");
			}
		}//opçao desaloca

		printf("\n************************************************************\n");

		getc(stdin);
	}while(op>0 && op<9 && op!=8);

	return 0;
}