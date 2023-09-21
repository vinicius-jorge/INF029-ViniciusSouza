#include <stdio.h>

//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou de menor.
//O programa deve repetir essa ação até que uma idade negativa seja informada.

int main()
{
  int idade;

    while(idade>=0)
    {
        printf("Digite a idade:\n");
        scanf("%d", &idade);

        if(idade < 0)
          printf("Valor inválido!\n");
        else if(idade >= 18)
          printf("Pessoa maior de idade!\n");
        else
          printf("Pessoa menor de idade!\n");
    }
  
  return 0;
  
}