#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//Cria��o de vari�veis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo("w" = escrever)
	fprintf(file, cpf); //salva o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //adiciona espa�amento entre os dados
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, nome); //adiciona o nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, ","); //adiciona espa�amento entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, sobrenome); //adiciona o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, ","); //adiciona espa�amento entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, cargo); //adiciona espa�amento entre os dados
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela
}

int consulta() //Fun��o de consulta dos usu�rios
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem(acentos)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //abre e l�/consulta o arquivo("r" = ler)
	
	if(file == NULL) //verifica se o arquivo existe
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto tiver conte�do dentro desse arquivo ele armazena dentro da vari�vel conte�do
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo); //traz o conte�do
		printf("\n\n");
	}
	
	system("pause"); //pausa a tela
}

int deletar() //Fun��o de deletar os usu�rios
{	
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deleta o arquivo selecionado
	
	FILE *file;
	file = fopen(cpf, "r"); //le o arquivo("r" = ler)
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0; //Definindo vari�veis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
		system("cls"); //respons�vel por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");
		
		printf("-=-= Cart�rio da EBAC =-=- \n\n"); //In�cio do menu
		printf("Escolha a op��o desejada no menu abaixo: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n"); 
		printf("\t4 - Sair do sistema \n");
		printf("Op��o: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usu�rio
		
		system("cls"); //respons�vel por limpar a tela
		
		//menu
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n");
			system("pause"); //pausa a tela
			break;
		}
	}
}

