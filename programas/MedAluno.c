#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

main() {
	setlocale(LC_ALL, "Portuguese");
    float nota1, nota2, nota3, nota4; 
    float media;
    
    printf("Digite a nota1: ");
    scanf ("%f", &nota1); 
    printf("Digite a nota2: ");
    scanf ("%f", &nota2);
    printf("Digite a nota3: ");
    scanf ("%f", &nota3);
    printf("Digite a nota4: ");
    scanf ("%f", &nota4);
    printf("\n");
  
    media = (nota1+nota2+nota3+nota4) / 4;
    printf("A média do aluno foi: %.1f \n", media);
  
  if (media < 4.5) {
      printf("O aluno foi Reprovado");
  }  
  else if (media  >=4.5 && media < 6) {
  	  printf("O aluno vai pra Exame");
  }
  else {
    printf("O aluno está Aprovado");
  }
	printf("\n\n");
	system ("pause");
}

