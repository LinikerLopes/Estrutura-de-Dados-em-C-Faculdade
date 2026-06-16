#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIVROS 50
#define MAX_STRING 100
#define PROPRIETARIO "SAVA"
typedef struct {
	char nome[MAX_STRING];
	char autor[MAX_STRING];
	char editora[MAX_STRING];
	int edicao;
} Livro;

void limpabuffer(){
	int c;
	while((c = getchar()) != '\n' && c != EOF);
}

int main(){
	
	Livro biblioteca[MAX_LIVROS];
	int totalLivros = 0;
	int opcao;
	
	do{
		printf("Biblioteca do %s\n", PROPRIETARIO);
		printf("===============================\n");
		printf("1 - Cadastrar Livro\n");
		printf("2 - Listar Livros\n");
		printf("3 - Sair\n");
		printf("-------------------------------\n");
		printf("Escolha uma opcao: ");
		
		scanf("%d", &opcao);
		limpabuffer();
		
		switch(opcao){
			
			case 1:
				printf("Cadastrar novo livro\n");
				
				if(totalLivros < MAX_LIVROS){
					printf("Digite nome do livro: ");
					fgets(biblioteca[totalLivros].nome, MAX_STRING, stdin);
					
						printf("Digite autor do livro: ");
					fgets(biblioteca[totalLivros].autor, MAX_STRING, stdin);
					
						printf("Digite editora do livro: ");
					fgets(biblioteca[totalLivros].editora, MAX_STRING, stdin);
					
					biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome, "\n")] = '\0';
					biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor, "\n")] = '\0';
					biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora, "\n")] = '\0';
					
						printf("Digite edicao do livro: ");
						scanf("%d", &biblioteca[totalLivros].edicao);
						limpabuffer();
						
					totalLivros++;
				}else{
					printf("Lista de livros cheia.");
				}
				break;
				
			case 2:
				printf("Lista de livros\n");
				if(totalLivros == 0){
					printf("Nenhum livro cadastrado.");
				} else{
					for (int i = 0; i < totalLivros; i++){
						printf("--------------------------------- \n");
						printf("LIVRO %d\n", i+1);
						printf("Nome: %s\n", biblioteca[i].nome);
							printf("Autor: %s\n", biblioteca[i].autor);
								printf("Editora: %s\n", biblioteca[i].editora);
									printf("Edicao: %d\n", biblioteca[i].edicao);
						printf("--------------------------------- \n");
					}
					}
				break;
			
			case 3:
				printf("Obrigado pelo uso");
				opcao = 0;
				break;
				
			default:
				printf("Opcao selecionada invalida.");
				getchar();
				break;
				}
				}while(opcao != 0);
				
				return 0;
		}
 
