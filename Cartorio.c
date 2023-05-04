#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int incluir() //Função responsável por cadastrar os usuários no sistema
{
	//início criação de variáveis/string
	char arquivo[40];
    char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/string
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string(armazenamento)
	
	strcpy(arquivo,cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo na pasta e o "w" significa escrever
	fprintf(file,cpf); //salvo  o valor da variável
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
		printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	while(fgets(conteudo, 200, file)  !=NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser excluído?: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
    {
    	printf("O usuário não se encontra no sistema!\n");
    	system("pause");
    	
	}


	
}


int main()
{
	int opcao=0; //Definindo variáveis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	    system("cls");
		 
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("$$$ Cartório da EBAC $$$\n\n"); //inicio do menu
	    printf("Favor escolha a opção desejada:\n\n");
	    printf("\t1 - Incluir Nomes\n");
	    printf("\t2 - Consultar Nomes\n");
	    printf("\t3 - Excluir Nomes\n\n");
	    printf("Opção: ");	//fim do menu
	
	    scanf("%d", &opcao); //armazenando a escolha do usuário
	
	    system("cls"); //responsável por limpar a tela
	    
	    switch(opcao) //início da seleção do menu
	    {
	    	case 1:
	    	incluir();	//chamada de funções
	    	break;
	    	
	    	case 2:
	    	consultar();
			break;
			
			case 3:
			excluir();
			break;
		
		
			default: 
			printf("Essa opção não está disponivel!\n");
		    system("pause");	
	    	break;	
	    		
		}
	
	   
	
	
	
	
    }
}
