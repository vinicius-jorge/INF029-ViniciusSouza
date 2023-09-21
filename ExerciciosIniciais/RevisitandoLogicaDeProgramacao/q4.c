#include <stdio.h>

//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas sem utilizar variável auxiliar.

int main()
{
  int x, y;

  printf("Digite dois valores:\n");
  scanf("%d%d", &x, &y);

  printf("x: %d\ty: %d\n", x, y);
  
  x = x + y;
  y = x - y;
  x = x - y;

  printf("x: %d\ty: %d\n", x, y);

  return 0;
  
}