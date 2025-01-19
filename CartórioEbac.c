#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>  // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar da string
int registro() // Fun��o resnpos�vel por cadastrar os usuarios no sistema.
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	// Inicio da cria��o das variaveis/strings.
	char ARQUIVO[40];
	char CPF[40];
	char NOME[40];
	char SOBRENOME[40];
	char CARGO [40];
	// Final da cria��o das variaveis/strings.
	
	printf("Digite o CPF que deseja cadastrar:"); // Coletando a informa��o do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	strcpy(ARQUIVO, CPF);	// Respons�vel por copiar os valores da string.
	
	FILE *file; // cria o arquivo
	file = fopen(ARQUIVO,"w"); // cria o arquivo "w" � de write
	fprintf(file, CPF); // salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ",");// separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado:"); // Coletando a informa��o do usuario.
	scanf("%s", NOME); // %s refere-se a string.
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, NOME); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o SOBRENOME a ser cadastrado:"); // Coletando a informa��o do usuario.
	scanf("%s", SOBRENOME); // %s refere-se a string.
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, SOBRENOME); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por "," 
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado:"); // Coletando a informa��o do usuario.
	scanf("%s", CARGO); // %s refere-se a string.
	
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, CARGO); // separa as variaveis por ","
	fclose(file); // fecha o arquivo
	
	file = fopen(ARQUIVO, "a"); // cria o arquivo "a" atualizar
	fprintf(file, ","); // separa as variaveis por ","
	fclose(file); // fecha o arquivo
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso n�o tenha volta direto ao menu inical.
	
	
}

int consulta() // Fun��o resnpos�vel por consultar os usuarios no sistema.
{
	setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	// Inicio da cria��o das variaveis/strings.
	char CPF[40];
	char CONTEUDO[100];
	// Final da cria��o das variaveis/strings.
	
	printf("Digite o CPF a ser consultado: "); // Coletando a informa��o do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	FILE *file; // cria o arquivo
	file = fopen(CPF,"r"); // cria o arquivo "r" de read.
	
	if(file == NULL) // Fun��o "if" que da op��o se tiver ou n�o o cpf cadastrado.
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!\n"); // Retorno ao usuario caso n�o seja encontrado.
	}
	
	while(fgets(CONTEUDO, 200, file) != NULL) // Fun��o "while" caso encontre o CPF digitado ela retorna o texto abaixo.
	
	{
		printf("\n Essas s�o as informa��es do usu�rio: "); // Retorno ao usuario caso seja encontrado.
		printf("%s", CONTEUDO);
		printf("\n\n"); // Espa�os
	}
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso n�o tenha volta direto ao menu inical.
	
		
}
int deletar() // Fun��o resnpos�vel por deletar os usuarios no sistema.
{
	// Inicio da cria��o das variaveis/strings.
	char CPF[40];
	char CONTEUDO[100];
	// Final da cria��o das variaveis/strings.
	
	printf("Digite o CPF a ser deletado: "); // Coletando a informa��o do usuario.
	scanf("%s", CPF); // %s refere-se a string.
	
	remove(CPF); // Fun��o para remover
	
	FILE *file; // cria o arquivo.
	file = fopen(CPF,"r"); // cria o arquivo "r" de read.
	
	if (file == NULL)
	{
		printf("O Usu�rio n�o se encontra no sistema! \n");
		system("pause");
		
	}
	
	while(fgets(CONTEUDO, 200, file) != NULL)
	
	{
		printf("\n Usu�rio deletado com sucesso! ");
		printf("%s", CONTEUDO);
		printf("\n\n");
	}
	
	system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso n�o tenha volta direto ao menu inical.
}


int main()
{
	int opcao=0; // definindo as vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	  system("cls"); // Limpa a tela
	  
	  setlocale(LC_ALL, "Portuguese"); // definindo a linguagem
	
	
	
	  printf(" ### Cart�rio da EBAC ###\n\n"); // Inicio do menu
	  printf("Escolha a op��o desejada no Menu: \n\n");
	  printf("\t 1 - Registrar nomes \n");
	  printf("\t 2 - Consultar nomes \n");
	  printf("\t 3 - Deletar nomes \n\n"); 
	  printf("\t 4 - Sair do sistema \n\n");
	  printf("Op��o: "); // Fim do menu
	
	  scanf("%d", &opcao); // Armazenando a escolha do usu�rio
	
      system("cls"); // Serve para limpa a tela p�s inser��o da resposta
	  
	  switch(opcao)
	  {
	  	case 1:
	  	    registro(); //chamada de fun��es
	  	    break;
	  	
	  	case 2:
	  		consulta(); //chamada de fun��es
	  		break;
	  		
	  	case 3:
	  	    deletar(); //chamada de fun��es
	  	    break;
	  	    
	  	case 4:
	  	    printf("Obrigado por usar o sistema!");
	  	    return 0;
			break;
		  		  		       
	  	default:
	  		printf("Esta op��o n�o est� disponivel! :)\n");
	  	    system("pause"); // faz o sistema pausar na resposta que volta ao cliente, caso n�o tenha volta direto ao menu inical.
	  	    break;
	  	
	  }
	  
	  
 }
 }
