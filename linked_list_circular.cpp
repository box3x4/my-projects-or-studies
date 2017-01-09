#include <iostream>

using std::cin;
using std::cout;

int main(){

	/*Mesmo inicio da lista encadeada simples*/

	struct node{
		int num;
		struct node *prox;
		struct node *ant;
	};

	struct node *inicio = NULL;
	struct node *fim = NULL;
	struct node *aux;
	//declaração dos nós que serão utilizados

	int op, num, find, qnt,element; //Criação das variaveis
	do{
		cout<<"Menu \n";
		cout<<"1 - Insere no inicio\n";
		cout<<"2 - Insere no fim\n";
		cout<<"3 - Consultar lista normalmente\n";
		cout<<"4 - Consultar lista ao contrario\n";
		cout<<"5 - Remover da lista\n";
		cout<<"6 - Esvaziar a Lista \n";
		cout<<"7 - Sair\n";
		cout<<"Digite Opcao: ";
		cin>>op; //Criação do menu e leitura da opção

		if (op < 1 || op > 7)
			cout<<"opcao invalida\n"; //Checagem da opção

		if(op==1){ /*inserir numero no comeco*/
			cout<<"Numero a ser inserido: ";
			node *novo=new node();
			cin>>novo->num; //Le o numero a ser inserido e criar o nó que via receber esse numero
			
			if(inicio==NULL){
				inicio=novo;
				fim=novo;
				novo->prox=inicio;
				novo->ant=inicio;
			}//Caso lista vazia

			else{
				novo->prox=inicio;
				inicio->ant=novo;
				inicio=novo;
				fim->prox=inicio;
				inicio->ant=fim;
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
				novo->prox=inicio;
				novo->ant=inicio;
			}//Caso lista vazia

			else{
				fim->prox=novo;
				novo->ant=fim;
				fim=novo;
				fim->prox=inicio;
				inicio->ant=fim;
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
		
		if(op==4){/*listar invertido*/
			if(inicio==NULL)
				cout<<"LIsta vazia!\n";
			else{
				aux=fim;
				
				do{
					cout<<aux->num<<" ";
					aux=aux->ant;
				}while(aux!=fim);

				cout<<"\n";
			}
		}
			
		if(op==5){//retirar numero
			if(inicio==NULL)
				cout<<"Lista Vazia!\n";
			
			else{
				cout<<"Numero a ser retirado: ";
				cin>>num;
				aux=inicio;
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
								inicio->ant=fim;
								fim->prox=inicio;
								delete(aux);
								aux=inicio;
							}//Caso num no inicio
							
							else{
								if(aux==fim){
									fim=aux->ant;
									fim->prox=inicio;
									inicio->ant=fim;
									delete(aux);
									aux=NULL;
								}//Caso num no fim

								else{
									aux->ant->prox=aux->prox;
									aux->prox->ant=aux->ant;
									node *aux2;
									aux2=aux;
									aux=aux->prox;
									delete(aux2);
								}//Caso genérico
							}
						}

						else{
							aux=aux->prox;
						}

						element++;
					}
				}while(element<=qnt);

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

		if(op==6){/*esvaziar lista*/
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
	}while(op!=7);
	
	return 0;
}
