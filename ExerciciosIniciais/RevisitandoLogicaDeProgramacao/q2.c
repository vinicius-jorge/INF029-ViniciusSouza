#include <stdio.h>

//Faça um programa que leia a idade de duas pessoas e imprima a soma das idades.

void main()
{
  int idade1, idade2;
  printf("Digite a idade da primeira pessoa:\n");
  scanf("%d", &idade1);
  printf("Digite a idade da segunda pessoa:\n");
  scanf("%d", &idade2);
  int soma = idade1 + idade2;
  printf("A soma das idades é: %d\n", soma);

}