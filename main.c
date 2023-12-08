#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 1000

struct Usuario {
  int id;
  char nome[50];
  char email[50];
  char sexo[15];
  char endereco[100];
  double altura;
  int vacina;
};


void preencherUsuario(struct Usuario *usuario) {
  usuario->id = rand() % 100000;
  printf("\n Nome completo: ");
  scanf(" %[^\n]s", usuario->nome);
  printf("\n Email: ");
  scanf(" %s", usuario->email);
  printf("\n Sexo (Feminino/Masculino/Indiferente): ");
  scanf(" %s", usuario->sexo);
  printf("\n Endereco: ");
  scanf(" %[^\n]s", usuario->endereco);
  printf("\n Altura (entre 1 e 2 metros): \n");
  scanf("%lf", &usuario->altura);
  printf("\n Vacina (1 - sim / 0 - nao): \n");
  scanf("%d", &usuario->vacina);
}

void editarUsuario(struct Usuario *usuario) {
  printf("\n Nome completo: \n");
  scanf(" %[^\n]s", usuario->nome);
  printf("\n Endereco: \n");
  scanf(" %[^\n]s", usuario->endereco);
  printf("\n Altura (entre 1 e 2 metros): \n");
  scanf("%lf", &usuario->altura);
  printf("\n Vacina (1 para sim, 0 para não): \n");
  scanf("%d", &usuario->vacina);
}

struct Usuario *buscarUsuarioPorEmail(struct Usuario usuarios[],
                                      int totalUsuarios, const char *email) {
  for (int i = 0; i < totalUsuarios; i++) {
    if (strcmp(usuarios[i].email, email) == 0) {
      return &usuarios[i];
    }
  }
  return NULL;
}

void imprimirUsuarios(struct Usuario usuarios[], int totalUsuarios) {
  printf("\n Lista de Usuarios: \n");
  for (int i = 0; i < totalUsuarios; i++) {
    printf("\n ID: %d", usuarios[i].id);
    printf("\n Nome: %s", usuarios[i].nome);
    printf("\n Email: %s", usuarios[i].email);
    printf("\n Sexo: %s", usuarios[i].sexo);
    printf("\n Endereco: %s", usuarios[i].endereco);
    printf("\n Altura: %.2lf", usuarios[i].altura);
    printf("\n Vacina: %s", usuarios[i].vacina ? "Sim" : "Nao");
  }
}

int main() {
  struct Usuario usuarios[MAX_USERS];
  int totalUsuarios = 0;

  char opcao;
  do {
    printf("\n Opçoes:");
    printf("\n 1 - Incluir usuario");
    printf("\n 2 - Editar usuario");
    printf("\n 3 - Excluir usuario");
    printf("\n 4 - Buscar usuario por email");
    printf("\n 5 - Imprimir todos os usuarios");
    printf("\n 6 - Sair \n");

    printf("\n Escolha uma opcao: \n");
    scanf(" %c", &opcao);

    switch (opcao) {
    case '1':
      if (totalUsuarios < MAX_USERS) {
        preencherUsuario(&usuarios[totalUsuarios]);
        totalUsuarios++;
      } else {
        printf("\n Limite de usuarios atingido \n");
      }
      break;
    case '2':
      printf("Digite o ID do usuario a ser editado: ");
      int idEditar;
      scanf("%d", &idEditar);
      for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idEditar) {
          editarUsuario(&usuarios[i]);
          printf("\n Usuario editado com sucesso");
          break;
        }
        if (i == totalUsuarios - 1) {
          printf("\n ID do usuario não encontrado");
        }
      }
      break;
    case '3':
      printf("\n Digite o ID do usuario a ser excluido: ");
      int idExcluir;
      scanf("%d", &idExcluir);
      for (int i = 0; i < totalUsuarios; i++) {
        if (usuarios[i].id == idExcluir) {
          for (int j = i; j < totalUsuarios - 1; j++) {
            usuarios[j] = usuarios[j + 1];
          }
          totalUsuarios--;
          printf("\n Usuario excluido com sucesso");
          break;
        }
        if (i == totalUsuarios - 1) {
          printf("\n ID do usuario nao encontrado");
        }
      }
    break;
      
    case '4':
      printf("\n Digite o email do usuario a ser buscado: ");
      char emailBuscar[50];
      scanf(" %s", emailBuscar);
      struct Usuario *usuarioEncontrado =
          buscarUsuarioPorEmail(usuarios, totalUsuarios, emailBuscar);
      if (usuarioEncontrado != NULL) {
        printf("\n Usuario encontrado: \n");
        printf("\n ID: %d", usuarioEncontrado->id);
        printf("\n Nome: %s", usuarioEncontrado->nome);
        printf("\n Email: %s", usuarioEncontrado->email);
        printf("\n Sexo: %s", usuarioEncontrado->sexo);
        printf("\n Endereco: %s", usuarioEncontrado->endereco);
        printf("\n Altura: %.2lf", usuarioEncontrado->altura);
        printf("\n Vacina: %s", usuarioEncontrado->vacina ? "Sim" : "Nao");
      } else {
        printf("\n Usuario nao encontrado");
      }
    break;
      
    case '5':
      imprimirUsuarios(usuarios, totalUsuarios);
    break;
      
    case '6':
      printf("\n");
    break;
      
    default:
      printf("\n Opcao invalida");
    }
  } while (opcao != '6');

  return 0;
}
