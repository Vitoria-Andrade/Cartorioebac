#include <stdio.h> //Biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //Biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h>//Biblioteca de Aloca��es de texto por regi�o 
#include <string.h>//Biblioteca responsavel por cuidar das string

int registro()//Fun�ao responsavel por cadastrar os usuarios no sistema

{
    //Inicio da cria�ao das variaveis/strigs
    char arquivo [40];
    char cpf [40];
    char nome [40];
    char sobrenome [40];
    char cargo [40];
     //Final da cria�ao das variaveis/strings
     printf("Digite o seu cpf: ");//coletando informa�oes do usuario
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
       printf("\nEssas s�o as informa��es de usuario: ");
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
		printf("O usuario n�o se encontra em nosso sistema!. \n");
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
       
        printf("### Cart�rio da EBAC ###\n\n");
        printf("Escolha a op��o desejada no menu: \n\n");
        printf("\t1- Registrar nomes \n");
        printf("\t2- Consultar nomes \n");
        printf("\t3- Deletar nomes \n\n");
        printf("Op��o: ");
        scanf("%d", &opcao);
        system("cls");//Responsavel por limpar a tela
        
        switch(opcao)//Inicio da sele�ao do menu
        {
        	case 1:
        		registro();//chamada de fun�ao
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
