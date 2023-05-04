#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int incluir() //Fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio cria��o de vari�veis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informa��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string(armazenamento)
	
	strcpy(arquivo,cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //salvo  o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	


}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");//Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)  !=NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser exclu�do?: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!\n");
    	system("pause");
    	
	}


	
}


int main()
{
	int opcao=0; //Definindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
		 
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("$$$ Cart�rio da EBAC $$$\n\n"); //inicio do menu
	    printf("Favor escolha a op��o desejada:\n\n");
	    printf("\t1 - Incluir Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Excluir Nomes\n\n");
	    printf("Op��o: ");	//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	    system("cls"); //respons�vel por limpar a tela
	    
	    switch(opcao) //in�cio da sele��o do menu
	    {
	    	case 1:
	    	incluir();	//chamada de fun��es
	    	break;
	    	
	    	case 2:
	    	consultar();
			break;
			
			case 3:
			excluir();
			break;
		
		
			default: 
			printf("Essa op��o n�o est� disponivel!\n");
		    system("pause");	
	    	break;	
	    		
		}
	
	   
	
	
	
	
    }
}
