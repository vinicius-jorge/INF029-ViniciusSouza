#include <stdio.h>

//Faça um programa que leia a idade de uma pessoa e informe de ela é de maior ou menor.

int main()
{
  int idade;

  printf("Digite a idade:\n");
  scanf("%d", &idade);

  if(idade >= 18)
    printf("Pessoa maior de idade!\n");
  else
    printf("Pessoa menor de idade!\n");

  return 0;
  
}