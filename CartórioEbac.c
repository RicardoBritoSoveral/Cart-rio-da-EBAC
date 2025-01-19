#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h>  // biblioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável por cuidar da string
int registro() // Função resnposável por cadastrar os usuarios no sistema.
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	// Inicio da criação das variaveis/strings.
	char ARQUIVO[40];
	char CPF[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO [40];
	// Final da criação das variaveis/strings.
	
	printf("Digite o CPF que deseja cadastrar:"); // Coletando a informação do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	strcpy(ARQUIVO, CPF);	// Responsável por copiar os valores da string.
	
	FILE *file; // cria o arquivo
	file = fopen(ARQUIVO,"w"); // cria o arquivo "w" é de write
	fprintf(file, CPF); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ",");// separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado:"); // Coletando a informação do usuario.
	scanf("%s", NOME); // %s refere-se a string.
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, NOME); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado:"); // Coletando a informação do usuario.
	scanf("%s", SOBRENOME); // %s refere-se a string.
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, SOBRENOME); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); // Coletando a informação do usuario.
	scanf("%s", CARGO); // %s refere-se a string.
	
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, CARGO); // separa as variaveis por ","
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por ","
	fclose(file); // fecha o arquivo
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso não tenha volta direto ao menu inical.
	
	
}

int consulta() // Função resnposável por consultar os usuarios no sistema.
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	// Inicio da criação das variaveis/strings.
	char CPF[40];
	char CONTEUDO[100];
	// Final da criação das variaveis/strings.
	
	printf("Digite o CPF a ser consultado: "); // Coletando a informação do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	FILE *file; // cria o arquivo
	file = fopen(CPF,"r"); // cria o arquivo "r" de read.
	
	if(file == NULL) // Função "if" que da opção se tiver ou não o cpf cadastrado.
	{
		printf("Não foi possivel abrir o arquivo, não localizado!\n"); // Retorno ao usuario caso não seja encontrado.
	}
	
	while(fgets(CONTEUDO, 200, file) != NULL) // Função "while" caso encontre o CPF digitado ela retorna o texto abaixo.
	
	{
		printf("\n Essas são as informações do usuário: "); // Retorno ao usuario caso seja encontrado.
		printf("%s", CONTEUDO);
		printf("\n\n"); // Espaços
	}
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso não tenha volta direto ao menu inical.
	
		
}
int deletar() // Função resnposável por deletar os usuarios no sistema.
{
	// Inicio da criação das variaveis/strings.
	char CPF[40];
	char CONTEUDO[100];
	// Final da criação das variaveis/strings.
	
	printf("Digite o CPF a ser deletado: "); // Coletando a informação do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	remove(CPF); // Função para remover
	
	FILE *file; // cria o arquivo.
	file = fopen(CPF,"r"); // cria o arquivo "r" de read.
	
	if (file == NULL)
	{
		printf("O Usuário não se encontra no sistema! \n");
		system("pause");
		
	}
	
	while(fgets(CONTEUDO, 200, file) != NULL)
	
	{
		printf("\n Usuário deletado com sucesso! ");
		printf("%s", CONTEUDO);
		printf("\n\n");
	}
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso não tenha volta direto ao menu inical.
}


int main()
{
	int opcao=0; // definindo as variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls"); // Limpa a tela
	  
	  setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	
	
	  printf(" ### Cartório da EBAC ###\n\n"); // Inicio do menu
	  printf("Escolha a opção desejada no Menu: \n\n");
	  printf("\t 1 - Registrar nomes \n");
	  printf("\t 2 - Consultar nomes \n");
	  printf("\t 3 - Deletar nomes \n\n"); 
	  printf("\t 4 - Sair do sistema \n\n");
	  printf("Opção: "); // Fim do menu
	
	  scanf("%d", &opcao); // Armazenando a escolha do usuário
	
      system("cls"); // Serve para limpa a tela pós inserção da resposta
	  
	  switch(opcao)
	  {
	  	case 1:
	  	    registro(); //chamada de funções
	  	    break;
	  	
	  	case 2:
	  		consulta(); //chamada de funções
	  		break;
	  		
	  	case 3:
	  	    deletar(); //chamada de funções
	  	    break;
	  	    
	  	case 4:
	  	    printf("Obrigado por usar o sistema!");
	  	    return 0;
			break;
		  		  		       
	  	default:
	  		printf("Esta opção não está disponivel! :)\n");
	  	    system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso não tenha volta direto ao menu inical.
	  	    break;
	  	
	  }
	  
	  
 }
 }
