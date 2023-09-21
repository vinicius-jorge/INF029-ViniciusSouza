#include <stdio.h>

//Faça um programa que leia dois valores informados pelo usuário e inverta os valores nas variáveis lidas.

int main()
{
  int aux, x, y;

  printf("Digite dois valores:\n");
  scanf("%d%d", &x, &y);

  printf("x: %d\ty: %d\n", x, y);
  
  aux = y;
  y = x;
  x = aux;

  printf("x: %d\ty: %d\n", x, y);
  
}