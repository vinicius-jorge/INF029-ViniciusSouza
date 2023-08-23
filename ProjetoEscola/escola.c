#include <stdio.h>
#define TAM_ESTUDANTE 3

int main(void){

    int listaEstudante[TAM_ESTUDANTE];
    int opcao;
    int qtdEstudante = 0;
    int sair = 0; //Opção para sair do menu;

    while(!sair)
    {
      printf("Projeto Escola - Escolha o módulo desejado:\n");
      printf("0 - Sair\n");
      printf("1 - Estudante\n");
      printf("2 - Professor\n");
      printf("3 - Disciplina\n");
    
      scanf("%d", &opcao);
  
      switch (opcao){
  
        case 0:{
          sair = 1;
          break;
        }
        case 1:{
          printf("Módulo Estudante\n");
          
            int sairEstudante = 0;
            int opcaoEstudante;
            while(!sairEstudante){
            printf("0 - Voltar\n");
            printf("1 - Cadastrar Estudante\n");
            printf("2 - Listar Estudante\n");
            printf("3 - Atualizar Estudante\n");
            printf("4 - Excluir Estudante\n");
            
            scanf("%d, &opcaoEstudante");

            switch(opcaoEstudante){

              case 0:{
                sairEstudante = 1; //Opção para retornar ao menu geral dos módulos;
                break;
              }
              case 1:{
                printf("1 - Cadastrar Estudante\n");
                printf("1 - Digite a matrícula:\n");
                int matricula;
                scanf("%d", &matricula);
                if(matricula < 0){
                  printf("Matrícula inválida!\n");
                }else{
                  if(qtdEstudante == TAM_ESTUDANTE){
                    printf("Lista de estudantes cheia!\n");
                  }else{
                    listaEstudante[qtdEstudante] = matricula;
                    qtdEstudante++;
                  }
                }
                break;
              }              
              case 2:{
                printf("2 - Listar Estudante\n");
                break;
              }
              case 3:{
                printf("3 - Atualizar Estudante\n");
                break;
              }
              case 4:{
                printf("4 - Excluir Estudante\n");
                break;
              }
              default:{
                printf("Opção inválida!\n");
              }
              
            }
            
          }
          
          break;
        }
        case 2:{
          printf("Módulo Professor\n");
          break;
        }
        case 3:{
          printf("Módulo Disciplina\n");
          break;
        }
        default:{
          printf("Opção inválida!\n");
        }
  
        
      }
    
    }
  
  















  
  return 0;
}