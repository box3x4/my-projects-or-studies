#include <iostream>

using std::cin;
using std::cout;

int main(){

	/*Mesmo inicio da lista encadeada simples*/

	typedef struct node{
		int num;
		node *prox;
	};

	node *inicio = NULL;
	node *fim = NULL;
	node *aux;
	node *ant;
	//declaração dos nós que serão utilizados

	int op, num, find, qnt,element; //Criação das variaveis
	do{
		cout<<"Menu \n";
		cout<<"1 - Insere no inicio\n";
		cout<<"2 - Insere no fim\n";
		cout<<"3 - Consultar lista toda de frente para tras\n";
		cout<<"4 - Remover da lista\n";
		cout<<"5 - Esvaziar a Lista \n";
		cout<<"6 - Sair\n";
		cout<<"Digite Opcao: ";
		cin>>op; //Criação do menu e leitura da opção

		if (op < 1 || op > 6)
			cout<<"opcao invalida\n"; //Checagem da opção

		if(op==1){ /*inserir numero no comeco*/
			cout<<"Numero a ser inserido: ";
			node *novo=new node();
			cin>>novo->num; //Le o numero a ser inserido e criar o nó que via receber esse numero
			
			if(inicio==NULL){
				inicio=novo;
				fim=novo;
				fim->prox=inicio;
			}//Caso lista vazia

			else{
				novo->prox=inicio;
				inicio=novo;
				fim->prox=inicio;
			}
			
			cout<<"Numero Inserido!\n";
		}
		
		if(op==2){ /*inserir numero no fim*/
			cout<<"Numero a ser inserido: ";
			node *novo=new node();
			cin>>novo->num; //Le o numero a ser inserido e cria o nó que vai receber esse numero
						
			if(inicio==NULL){
				inicio=novo;
				fim=novo;
			}//Caso lista vazia

			else{
				fim->prox=novo;
				fim=novo;
				fim->prox=inicio;
			}

			cout<<"Numero Inserido!\n";
		}
		
		if(op==3) /*listagem normal*/
		{
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			//Caso lista vazia
			else{
				aux=inicio;
				
				do{
					cout<<aux->num<<" ";
					aux=aux->prox;
				}while(aux!=inicio);
				
				cout<<"\n";
			}
		}
		
		if(op==4){/*retirar numero*/
			
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			
			else{
				cout<<"Numero a ser retirado: ";
				cin>>num;
				aux=inicio;
				ant=NULL;
				find=0;
				qnt=0;
				//Setup para começar a remoção
				
				do{
					qnt++;
					aux=aux->prox;
				}while(aux!=inicio);

				element=1;//Essa variavel sera usada como condição no (do) (while)

				do{
					if(inicio==fim && inicio->num==num){
						delete(inicio);
						inicio=NULL;
						find++;
					}//Caso lista com um só nó
					
					else{
						if(aux->num==num){
							find++;	
							if(aux==inicio){
								inicio=inicio->prox;
								fim->prox=inicio;
								delete(aux);
								aux=inicio;
							}//Caso num no inicio
							
							else{
								if(aux==fim){
									fim=ant;
									fim->prox=inicio;
									delete(aux);
									aux=NULL;
								}//Caso num no fim

								else{
									ant->prox=aux->prox;
									delete(aux);
									aux=ant->prox;
								}//Caso genérico
							}
						}

						else{
							ant=aux;
							aux=aux->prox;
						}

						element++;
					}
				}while(element<=qnt)

				if(find==0)
					cout<<"Numero nao encontrado!\n";
				
				else{
					if(find==1)
						cout<<"Numero encontrado 1 vez!\n";
					
					else
						cout<<"Numero encontrado "<<find<<" vezes!\n";
				}
			}
		}
		
		if(op==5){/*esvaziar lista*/
			if(inicio==NULL)//Caso lista vazia
				cout<<"Lista Vazia!\n";
			
			else{
				aux=inicio;
				
				do{
					inicio=inicio->prox;
					delete(aux);
					aux=inicio;
				}while(aux!=fim);

				delete(fim);
				inicio=NULL;
				cout<<"Lista esvaziada!\n";
			}
		}
	}while(op!=6);
	
	return 0;
}
