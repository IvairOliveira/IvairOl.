// Criar um programa completo: Fun��es fopen, fwrite, fread, fclose, feof

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>
/*====TIPOS PR�-DEFINIDOS====*/
typedef  struct
{
    char   agencia [7];
    char   conta[8];
    char   nome [20];
    int    valor;
}
reg_cliente;
/*====FUN��ES====*/
void grava (reg_cliente  registro)
{
    FILE  *        arq;
    arq = fopen ("CLIENTES.DAT" , "a" );
    fwrite ( &registro, sizeof(registro), 1, arq );
    fclose(arq);
}
void cadastra (void)
{
    reg_cliente     r;
    char           op;

    memset( r.agencia,     '\0', sizeof(r.agencia) );
    memset( r.conta,           '\0', sizeof(r.conta)       );
    memset( r.nome, '\0', sizeof(r.nome) );
    r.valor = 0;
    /* Solicita os dados para o cadastro */
    system("cls");
    printf ("\n====== INCLUSAO DE DADOS =====");
    printf ("\nAgencia    : "); fflush(stdin); gets(r.agencia);
    printf ("\nConta          : "); fflush(stdin); gets(r.conta);
    printf ("\nNome          : "); fflush(stdin); gets(r.nome);
    printf ("\nValor        : "); fflush(stdin); scanf("%d", &r.valor);
    /* Confirma a grava��o ou n�o*/
    do
    {
       printf ("\nGrava os dados? [s,S]=sim [n,N]=nao ");
       fflush(stdin);  op = getche();
       op = toupper(op);
    }
    while ( op != 'S' && op != 'N');
    if ( op == 'S' )
       grava(r);
}

void relatorio (void)
{
   /* Vari�veis locais */
   FILE *         arq;
   FILE *         rel;
   reg_cliente      r;

   arq = fopen ("CLIENTES.DAT" , "r" );
   if ( arq == NULL )
   {
        system("cls");
        printf ("Imposs�vel gerar relat�rio");
        getch();
   }
   else
   {
      rel = fopen ("RELCLIENTES.TXT" , "w" );
      fprintf(rel,"\n+-------------------------------------------------------------+");
      fprintf(rel,"\n|                 CLIENTES     CADASTRADOS                    |");
      fprintf(rel,"\n+-------------------------------------------------------------+");
      fprintf(rel,"\n| AGENCIA  | CONTA   | NOME                 | VALOR DEPOSITADO|");
      fprintf(rel,"\n+-------------------------------------------------------------+");
      do
      {
         fread ( &r, sizeof(r), 1, arq );
         if ( !feof(arq) )
            fprintf (rel,"\n|%s       | %s |%s | %5.2f    |",
			r.agencia, r.conta, r.nome, r.valor);
      }
      while ( !feof(arq) );
      fclose(arq);
      fprintf(rel,"\n+-------------------------------------------------------------+");
      fclose (rel);
      system ("notepad   RELCLIENTES.TXT");
      getch();
   }
}

void menu (void)
{
   setlocale(LC_ALL, "Portuguese");
   /* Vari�veis locais */
   char    op;
   do
   {
      system ("cls");
      printf ("===========================\n");
      printf ("   1-incluir               \n");
      printf ("   2-relat�rio             \n");
      printf ("   s-sair                  \n");
      printf ("===========================\n");
      printf ("Digite sua op��o:    \n");
      fflush(stdin);
      op = getche();
      op = toupper(op);
      switch ( op )
      {
         case '1' : cadastra();       break;
         case '2' : relatorio();      break;
         case 'S' : printf ("sair");  break;
         default  : {
                      system ("cls");
                      printf ("Erro : op��o inv�lida");
                      getch();
                    }
      }
   }
   while ( op != 'S' );
}

/*====CORPO DO PROGRAMA=====*/
main()
{
    menu();
}

