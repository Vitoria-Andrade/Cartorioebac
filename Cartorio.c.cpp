#include <stdio.h> //Biblioteca de comunicação com o usuário 
#include <stdlib.h> //Biblioteca de alocação de espaço em memória 
#include <locale.h>//Biblioteca de Alocações de texto por região 
#include <string.h>//Biblioteca responsavel por cuidar das string

int registro()//Funçao responsavel por cadastrar os usuarios no sistema

{
    //Inicio da criaçao das variaveis/strigs
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
     //Final da criaçao das variaveis/strings
     printf("Digite o seu cpf: ");//coletando informaçoes do usuario
     scanf("%s", cpf);//"%s" refere-se as strings
    
     strcpy(arquivo, cpf);//Responsavel por copiar os valores das strings
    
     FILE *file;//cria o arquivo
     file = fopen(arquivo, "w");//cria o arquivo
     fprintf(file, cpf);//salva o valor do arquivo
     fclose(file);//fecha o arquivo
    
     file = fopen(arquivo, "a");//"a" significa atualizacao
     fprintf(file, ",");
     fclose(file);
    
     printf("Digite o seu nome: ");
     scanf ("%s", nome); 
    
     file = fopen(arquivo, "a");
     fprintf(file, nome);
     fclose(file);
    
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
    
     printf("Digite o seu sobronome: ");
     scanf("%s", sobrenome);
    
     file = fopen(arquivo, "a");
     fprintf(file, sobrenome);
     fclose(file);
    
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
    
     printf("Digite o cargo a ser cadastrado: ");
     scanf ("%s", cargo);
    
     file = fopen(arquivo, "a");
     fprintf(file, cargo);
     fclose(file);
    
     file = fopen(arquivo, "a");
     fprintf(file, ",");
     fclose(file);
    
     system("pause");
     
}

int consultar()
{
	setlocale(LC_ALL, "Portuguese");
	
    char cpf [40];
    char conteudo [200];
    
     printf("Digite o cpf a ser consultado: ");
     scanf("%s", cpf);
     
     FILE *file;
     file = fopen(cpf, "r"); //Ler o arquivo
	 
	 if(file ==NULL) 
	 {
	   printf("Nao foi possivel abrir o arquivo, nao localizado!. \n" );	
	 }
     while (fgets(conteudo, 200, file)!= NULL)
     {
       printf("\nEssas são as informações de usuario: ");
       printf("%s", conteudo);
       printf("\n\n");
       
        system("pause");
	 }
}
     
     
int deletar ()

{
	char cpf[40];
	
	printf("Qual o cpf do usuario a ser deletado? ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file ==NULL)
	{
		printf("O usuario não se encontra em nosso sistema!. \n");
	    system("pause");
	}
	
}
	
	
int main()
{ 
    int opcao=0;
    int x=1;
    
    for(x=1; x=1;)
    {
        system("cls");
        setlocale(LC_ALL, "Portuguese");
       
        printf("### Cartório da EBAC ###\n\n");
        printf("Escolha a opção desejada no menu: \n\n");
        printf("\t1- Registrar nomes \n");
        printf("\t2- Consultar nomes \n");
        printf("\t3- Deletar nomes \n\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        system("cls");//Responsavel por limpar a tela
        
        switch(opcao)//Inicio da seleçao do menu
        {
        	case 1:
        		registro();//chamada de funçao
	        	break;
	        
	        case 2:
	           consultar();	
	        	break;
	        
	        case 3:
	        	deletar();
	        	break;
	    
	    
		
	        default:
	        	printf("Esta opcao nao esta disponivel!\n");
		    	system("pause");
	            break;
		}
	
	}
}//fim do menu
