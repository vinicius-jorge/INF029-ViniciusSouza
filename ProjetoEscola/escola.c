#include <stdio.h>

#define TAM_ESTUDANTE 3
#define CAD_ESTUDANTE_SUCESSO -1
#define MATRICULA_INVALIDA -2
#define LISTA_CHEIA -3
#define ATUALIZACAO_ESTUDANTE_SUCESSO -4
#define MATRICULA_INEXISTENTE -5

typedef struct est{
  int matricula;
  //char nome;
  char sexo;
  //char dataNascimento;
  //char CPF;
  int status;
}Estudante;


// Protótipo das funções
int menuGeral();
int menuEstudante();
int cadastrarEstudante(listaEstudante[], qtdEstudante);
void listarEstudante(listaEstudante[], qtdEstudante);
int atualizarEstudante(listaEstudante[], qtdEstudante);


// Modularização;
// Utilizar um gerador automático de matrícula;
// validações necessárias (data de nascimento e CPF);
// inserção de novos atributos na struct Estudante;
// leitura dos novos atributos;


int main(void){

    Estudante listaEstudante[TAM_ESTUDANTE];
    int opcao;
    int qtdEstudante = 0;
    int sair = 0; //Opção para sair do menu;

    while(!sair)
    {
      opcao = menuGeral();
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
            
            opcaoEstudante = menuEstudante();
            scanf("%d", &opcaoEstudante);

            switch(opcaoEstudante){

              case 0:{
                sairEstudante = 1; //Opção para retornar ao menu geral dos módulos;
                break;
              }
              case 1:{      
                int retorno = cadastrarEstudante(listaEstudante, qtdEstudante);
                if(retorno == LISTA_CHEIA){
                  printf("Lista de estudantes cheia!\n");
                }else if(retorno == MATRICULA_INVALIDA){
                  printf("Matrícula inválida!\n");
                }else{
                  printf("Cadastro realizado com sucesso!\n");
                  qtdEstudante++;
                }
                break;
                          
              }case 2:{
                listarEstudante(listaEstudante, qtdEstudante);
                break;
              }
              case 3:{
                  
                  int retorno = atualizarEstudante(listaEstudante, qtdEstudante);

                  switch (retorno){
                    case MATRICULA_INVALIDA:{
                      printf("Matricula inválida!\n");
                      break;
                    }
                    case MATRICULA_INEXISTENTE:{
                      printf("Matricula inexistente!\n");
                      break;
                    }
                    case ATUALIZACAO_ESTUDANTE_SUCESSO:{
                      printf("Atualização realizada com sucesso!\n");
                      break;
                    }
                  }
                
                }                
                break;
              }
              case 4:{
                printf("4 - Excluir Estudante\n");
                printf("1 - Digite a matrícula:\n");
                int matricula;
                int encontrado = 0;
                scanf("%d", &matricula);
                if(matricula < 0){
                  printf("Matrícula inválida!\n");
                }else{
                  for(int i = 0; i < qtdEstudante; i++)
                  {
                    if(matricula == listaEstudante[i].matricula){
                      //exclusão lógica
                      listaEstudante[i].status = -1;
                      //shift
                      for(int j = i; j < qtdEstudante - 1; j++){
                        listaEstudante[j].matricula = listaEstudante[j+1].matricula;
                        listaEstudante[j].sexo = listaEstudante[j+1].sexo;
                        listaEstudante[j].status = listaEstudante[j+1].status;
                      }
                      qtdEstudante--;
                      encontrado = 1;
                      break;
                    }
                  }
                  if(encontrado){
                    printf("Estudante excluído com sucesso!\n");
                  }else{
                    printf("Matricula inexistente!\n");
                  }
                }
                
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

  return 0;
}

  

int menuGeral(){
  int opcao;
  printf("Projeto Escola\n");
  printf("Escolha o módulo desejado:\n");
  printf("0 - Sair\n");
  printf("1 - Estudante\n");
  printf("2 - Professor\n");
  printf("3 - Disciplina\n");
  scanf("%d", &opcao);
  return opcao;
}

int menuEstudante(){
  int opcao;
  printf("0 - Voltar\n");
  printf("1 - Cadastrar Estudante\n");
  printf("2 - Listar Estudante\n");
  printf("3 - Atualizar Estudante\n");
  printf("4 - Excluir Estudante\n");
  scanf("%d", &opcao);
  return opcao;
}

int cadastrarEstudante(listaEstudante[], qtdEstudante){
  printf("1 - Cadastrar Estudante\n");
  if(qtdEstudante == TAM_ESTUDANTE){
      return LISTA_CHEIA;
    }else{
      printf("1 - Digite a matrícula:\n");
      int matricula;
      scanf("%d", &matricula);
      if(matricula < 0){
        return MATRICULA_INVALIDA;
      }
      listaEstudante[qtdEstudante].matricula = matricula;
      listaEstudante[qtdEstudante].status = 1;
      return CAD_ESTUDANTE_SUCESSO;              
    }
}

void listarEstudante(listaEstudante[], qtdEstudante){
  printf("2 - Listar Estudante\n");
  if(qtdEstudante == 0){
    printf("2 - Lista Estudante vazia!\n");
  }else{
    for(int i = 0; i < qtdEstudante; i++)
    {
      if(listaEstudante[i].status){
        printf("Matricula: %d\n", listaEstudante[i].matricula);
      }
    }
  }
  
}

int atualizarEstudante(listaEstudante[], qtdEstudante){
  printf("3 - Atualizar Estudante\n");
  printf("1 - Digite a matrícula:\n");
  int matricula;
  int encontrado = 0;
  scanf("%d", &matricula);
  if(matricula < 0){
    return MATRICULA_INVALIDA;
  }else{
  for(int i = 0; i < qtdEstudante; i++)
  {
    if(matricula == listaEstudante[i].matricula && listaEstudante[i].status){
      //atualizacao
      printf("1 - Digite a nova matrícula:\n");
      int novaMatricula;
      scanf("%d", &novaMatricula);
      if(novaMatricula < 0){
        printf("Nova matrícula inválida!\n");
      }else{
        listaEstudante[i].matricula = novaMatricula;
        //listaEstudante[j].sexo = sexo;
        //listaEstudante[j].status = status;
        encontrado = 1;
        break;
      }
      
    }
  }
    if(encontrado){
      return ATUALIZACAO_ESTUDANTE_SUCESSO;
    }else{
      return MATRICULA_INEXISTENTE;
    }
    
  }
  
}