#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários no sistema
{
	//Criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a strings
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo("w" = escrever)
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file, ","); //adiciona espaçamento entre os dados
	fclose(file); // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, nome); //adiciona o nome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, ","); //adiciona espaçamento entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, sobrenome); //adiciona o sobrenome no arquivo
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, ","); //adiciona espaçamento entre os dados
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo("a" = atualizar)
	fprintf(file, cargo); //adiciona espaçamento entre os dados
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a tela
}

int consulta() //Função de consulta dos usuários
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem(acentos)
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file; //consulta o arquivo
	file = fopen(cpf, "r"); //abre e lê/consulta o arquivo("r" = ler)
	
	if(file == NULL) //verifica se o arquivo existe
	{
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) //enquanto tiver conteúdo dentro desse arquivo ele armazena dentro da variável conteúdo
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo); //traz o conteúdo
		printf("\n\n");
	}
	
	system("pause"); //pausa a tela
}

int deletar() //Função de deletar os usuários
{	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf); //deleta o arquivo selecionado
	
	FILE *file;
	file = fopen(cpf, "r"); //le o arquivo("r" = ler)
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	
}

int main()
{
	int opcao = 0; //Definindo variáveis
	int laco = 1;
	
	for(laco = 1; laco = 1;)
	{
		system("cls"); //responsável por limpar a tela
	
		setlocale(LC_ALL, "Portuguese");
		
		printf("-=-= Cartório da EBAC =-=- \n\n"); //Início do menu
		printf("Escolha a opção desejada no menu abaixo: \n\n");
		printf("\t1 - Registrar nomes \n");
		printf("\t2 - Consultar nomes \n");
		printf("\t3 - Deletar nomes \n"); 
		printf("\t4 - Sair do sistema \n");
		printf("Opção: "); //Fim do menu
		
		scanf("%d", &opcao); //Armazenando a escolha do usuário
		
		system("cls"); //responsável por limpar a tela
		
		//menu
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
			printf("Obrigado por utilizar o sistema!\n");
			return 0;
			break;
			
			default:
			printf("Essa opção não está disponível!\n");
			system("pause"); //pausa a tela
			break;
		}
	}
}

