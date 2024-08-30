#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 2048
#define MAX_PC 500
#define MAX 50

enum tipo_de_pc
{
  desktop,
  portatil,
  servidor
};

struct TData
{
  int dia, mes, ano;
};

struct TInventario
{
  enum tipo_de_pc tipo;
  struct TData data_nascimento;
  int numeroRegisto;
  int disco;
  int ram;
  float preco;
  char numeroSerie[MAX];
  char marca[MAX];
  char processador[MAX];
  char modelo[MAX];
  char grafica[MAX];
};

void InserePC(struct TInventario dados[], int counter)
{
  for (int i = 0; i < counter; i++)
  {
    dados[counter].numeroRegisto = i + 1;
  }

  fseek(stdin, 0, SEEK_END);
  printf("\033[1m -Marca: \033[0m");
  gets(dados[counter].marca);
  printf("\033[1m -Modelo (Pressionar ENTER para utilizar o valor por defeito 'Desconhecido'): \033[0m");
  gets(dados[counter].modelo);

  if (strlen(dados[counter].modelo) == 0)
  {
    strcpy(dados[counter].modelo, "Desconhecido");
  }

  printf("\033[1m -GPU(Placa Grafica, Pressionar ENTER para utilizar o valor por defeito 'GPU Integrada'): \033[0m");
  gets(dados[counter].grafica);

  if (strlen(dados[counter].grafica) == 0)
  {
    strcpy(dados[counter].grafica, "GPU Integrada");
  }

  printf("\033[1m -CPU(Processador): \033[0m");
  gets(dados[counter].processador);
  printf("\033[1m -Numero de Serie (Pressionar ENTER para utilizar o valor por defeito 'Desconhecido'): \033[0m");
  gets(dados[counter].numeroSerie);

  if (strlen(dados[counter].numeroSerie) == 0)
  {
    strcpy(dados[counter].numeroSerie, "Desconhecido");
  }

  printf("\033[1m -Data de Compra [DD/MM/AAAA]: \033[0m");
  scanf("%d/%d/%d", &dados[counter].data_nascimento.dia, &dados[counter].data_nascimento.mes, &dados[counter].data_nascimento.ano);
  printf("\033[1m -RAM: \033[0m");
  scanf("%d", &dados[counter].ram);
  printf("\033[1m -Espaco no Disco [gb]: \033[0m");
  scanf("%d", &dados[counter].disco);
  printf("\033[1m -Preco [EUR]: \033[0m");
  scanf("%f", &dados[counter].preco);

  printf("\033[1m [Tipo de PC]\n");
  printf("\033[1m 1 - Desktop \033[0m\n");
  printf("\033[1m 2 - Portatil \033[0m\n");
  printf("\033[1m 3 - Servidor \033[0m\n");
  printf("Introduza o tipo do produto (1-3): ");

  int op;
  scanf("%d", &op);

  if (op == 1)
  {
    dados[counter].tipo = desktop;
  }
  else if (op == 2)
  {
    dados[counter].tipo = portatil;
  }
  else if (op == 3)
  {
    dados[counter].tipo = servidor;
  }
  counter++;
}

void GravarPC(struct TInventario dados[], int counter, char *nomeficheiro)
{

  FILE *fp;
  fp = fopen(nomeficheiro, "wb");

  if (fp != NULL)
  {
    fprintf(fp, "\t\t|----------------------------|\n");
    fprintf(fp, "\t\t| NUMERO DE PRODUTOS: %d      |\n", counter);
    fprintf(fp, "\t\t|----------------------------|\n");
    fprintf(fp, "\n");
    for (int i = 0; i < counter; i++)
    {
      fprintf(fp, "#############[ Numero de Registo [%d] ]#############\n", dados[i].numeroRegisto);
      fprintf(fp, "| Numero de Serie: %s \n| Marca: %s \n| Modelo: %s \n| GPU(Placa Grafica): %s \n| CPU(Processador): %s \n| RAM: %d \n| Disco: %d \n| Preco: %0.2f euros \n| Data de Compra: %02d/%02d/%04d \n", dados[i].numeroSerie, dados[i].marca, dados[i].modelo, dados[i].grafica, dados[i].processador, dados[i].ram, dados[i].disco, dados[i].preco, dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);

      if (dados[i].tipo == desktop)
      {
        fprintf(fp, "| Tipo de Produto: Desktop \n");
      }
      else if (dados[i].tipo == portatil)
      {
        fprintf(fp, "| Tipo de Produto: Portatil \n");
      }
      else if (dados[i].tipo == servidor)
      {
        fprintf(fp, "| Tipo de Produto: Servidor \n");
      }
      fprintf(fp, "###################################################\n");
      fprintf(fp, "\n");
    }
    printf("\nGuardado com sucesso!\n");
    fclose(fp);
  }
  else if (fp == NULL)
  {
    printf("ERRO: Falha ao guardar o ficheiro!\n");
  }
}

int LerPCs(struct TInventario dados[], char *nomeficheiro)
{

  FILE *fp;
  fp = fopen(nomeficheiro, "rb");

  if (fp == NULL)
  {
    printf("Erro na abertura do ficheiro!");
    return 1;
  }

  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
  {
    printf("%s", buffer);
  }

  fclose(fp);
  return 0;
}

void MostrarPC(struct TInventario dados[], int counter)
{

  printf("\t\t|----------------------------|\n");
  printf("\t\t| NUMERO DE PRODUTOS: %d      |\n", counter);
  printf("\t\t|----------------------------|\n");

  for (int i = 0; i < counter; i++)
  {
    printf("\n");
    printf("\033[1m#################[ Numero de Registo [%d] ]#################\033[0m\n", dados[i].numeroRegisto);
    printf("| \033[1m-Numero de Serie:\033[0m %s \n", dados[i].numeroSerie);
    printf("| \033[1m-Marca:\033[0m %s \n", dados[i].marca);
    printf("| \033[1m-Modelo:\033[0m %s \n", dados[i].modelo);
    printf("| \033[1m-GPU(Placa Grafica):\033[0m %s \n", dados[i].grafica);
    printf("| \033[1m-CPU(Processador):\033[0m %s \n", dados[i].processador);
    printf("| \033[1m-RAM:\033[0m %d \n", dados[i].ram);
    printf("| \033[1m-Disco[GB]:\033[0m %d \n", dados[i].disco);
    printf("| \033[1m-Preco:\033[0m %0.2f euros \n", dados[i].preco);
    printf("| \033[1m-Data de Compra:\033[0m %02d/%02d/%04d \n", dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);

    if (dados[i].tipo == desktop)
    {
      printf("| \033[1m-Tipo de Produto:\033[0m Desktop \n");
    }
    else if (dados[i].tipo == portatil)
    {
      printf("| \033[1m-Tipo de Produto:\033[0m Portatil \n");
    }
    else if (dados[i].tipo == servidor)
    {
      printf("| \033[1m-Tipo de Produto:\033[0m Servidor \n");
    }
  }
  printf("\033[1m###########################################################\033[0m\n");
  printf("\n");
}

void MostrarCategoria(struct TInventario dados[], int counter)
{

  int op;
  printf("\n");
  printf("\033[1m################[ CATEGORIAS ]################\033[0m\n");
  printf("| \033[1m[1] Desktop\033[0m                                |\n");
  printf("| \033[1m[2] Portatil\033[0m                               |\n");
  printf("| \033[1m[3] Servidor\033[0m                               |\n");
  printf("| \033[1m[0] Sair\033[0m                                   |\n");
  printf("\033[1m##############################################\033[0m\n");
  printf("Insira que categoria pretende listar (0-3): ");
  scanf("%d", &op);
  printf("\n");

  if (op == 1)
  {
    for (int i = 0; i < counter; i++)
    {
      if (dados[i].tipo == desktop)
      {
        printf("\n");
        printf("\033[1m#################[ PRODUTO NUMERO [%d] ]#################\033[0m\n", dados[i].numeroRegisto);
        printf("| \033[1m-Numero de Serie:\033[0m %s \n", dados[i].numeroSerie);
        printf("| \033[1m-Marca:\033[0m %s \n", dados[i].marca);
        printf("| \033[1m-Modelo:\033[0m %s \n", dados[i].modelo);
        printf("| \033[1m-GPU(Placa Grafica):\033[0m %s \n", dados[i].grafica);
        printf("| \033[1m-CPU(Processador):\033[0m %s \n", dados[i].processador);
        printf("| \033[1m-RAM:\033[0m %d \n", dados[i].ram);
        printf("| \033[1m-Disco[GB]:\033[0m %d \n", dados[i].disco);
        printf("| \033[1m-Preco[EUR]:\033[0m %0.2f euros \n", dados[i].preco);
        printf("| \033[1m-Data de Compra:\033[0m %02d/%02d/%04d \n", dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);
        printf("| \033[1m-Tipo: Desktop\033[0m \n");
      }
    }
  }
  else if (op == 2)
  {
    for (int i = 0; i < counter; i++)
    {
      if (dados[i].tipo == portatil)
      {
        printf("\n");
        printf("\033[1m#################[ PRODUTO NUMERO [%d] ]#################\033[0m\n", dados[i].numeroRegisto);
        printf("| \033[1m-Numero de Serie:\033[0m %s \n", dados[i].numeroSerie);
        printf("| \033[1m-Marca:\033[0m %s \n", dados[i].marca);
        printf("| \033[1m-Modelo:\033[0m %s \n", dados[i].modelo);
        printf("| \033[1m-GPU(Placa Grafica):\033[0m %s \n", dados[i].grafica);
        printf("| \033[1m-CPU(Processador):\033[0m %s \n", dados[i].processador);
        printf("| \033[1m-RAM:\033[0m %d \n", dados[i].ram);
        printf("| \033[1m-Disco[GB]:\033[0m %d \n", dados[i].disco);
        printf("| \033[1m-Preco[EUR]:\033[0m %0.2f euros \n", dados[i].preco);
        printf("| \033[1m-Data de Compra:\033[0m %02d/%02d/%04d \n", dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);
        printf("| \033[1m-Tipo: Portatil\033[0m \n");
      }
    }
  }
  else if (op == 3)
  {
    for (int i = 0; i < counter; i++)
    {
      if (dados[i].tipo == servidor)
      {
        printf("\n");
        printf("\033[1m#################[ PRODUTO NUMERO [%d] ]#################\033[0m\n", dados[i].numeroRegisto);
        printf("| \033[1m-Numero de Serie:\033[0m %s \n", dados[i].numeroSerie);
        printf("| \033[1m-Marca:\033[0m %s \n", dados[i].marca);
        printf("| \033[1m-Modelo:\033[0m %s \n", dados[i].modelo);
        printf("| \033[1m-GPU(Placa Grafica):\033[0m %s \n", dados[i].grafica);
        printf("| \033[1m-CPU(Processador):\033[0m %s \n", dados[i].processador);
        printf("| \033[1m-RAM:\033[0m %d \n", dados[i].ram);
        printf("| \033[1m-Disco[GB]:\033[0m %d \n", dados[i].disco);
        printf("| \033[1m-Preco [EUR]:\033[0m %0.2f euros \n", dados[i].preco);
        printf("| \033[1m-Data de Compra:\033[0m %02d/%02d/%04d \n", dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);
        printf("| \033[1m-Tipo: Servidor\033[0m \n");
      }
    }
  }
  printf("\n");
}

void RemoverPC(struct TInventario dados[], int *counter)
{
  int numRegisto;
  printf("Introduza o numero de registo do PC a remover: ");
  scanf("%d", &numRegisto);
  int index = -1;
  for (int i = 0; i < *counter; i++)
  {
    if (dados[i].numeroRegisto == numRegisto)
    {
      index = i;
      break;
    }
  }
  if (index == -1)
  {
    printf("Não foi encontrado nenhum PC com esse numero de registo.\n");
    return;
  }
  for (int i = index; i < *counter - 1; i++)
  {
    dados[i] = dados[i + 1];
  }
  (*counter)--;
  printf("PC com numero de registo %d foi removido com sucesso.\n", numRegisto);
}

void OrdenarPCs(struct TInventario dados[], int counter)
{

  printf("\033[1m Escolha a ordem de ordenacao (1-Crescente 2-Decrescente): \033[0m");
  int op;
  scanf("%d", &op);

  int crescente = (op == 1);

  int comparator(const void *a, const void *b)
  {
    struct TInventario *pa = (struct TInventario *)a;
    struct TInventario *pb = (struct TInventario *)b;
    int resultado = pa->data_nascimento.ano - pb->data_nascimento.ano;
    if (resultado == 0)
    {
      resultado = pa->data_nascimento.mes - pb->data_nascimento.mes;
    }
    if (resultado == 0)
    {
      resultado = pa->data_nascimento.dia - pb->data_nascimento.dia;
    }
    if (!crescente)
    {
      resultado *= -1;
    }
    return resultado;
  }

  qsort(dados, counter, sizeof(struct TInventario), comparator);

  GravarPC(dados, counter, "pc.bin");
  printf("\n");
  LerPCs(dados, "pc.bin");
}

void valorTotal(struct TInventario dados[], int counter)
{

  float total = 0.0;

  for (int i = 0; i < counter; i++)
  {
    total += dados[i].preco;
  }
  printf("\033[1mValor Estimado Total: %0.2f euros\033[0m\n", total);
}

void procurarProduto(struct TInventario dados[], int counter)
{
  int numero;
  printf("Introduza o Numero de Registo do Produto que Pretende Encontrar: ");
  scanf("%d", &numero);
  int found = 0;

  for (int i = 0; i < counter; i++)
  {
    if (dados[i].numeroRegisto == numero)
    {
      found = 1;
      printf("- Numero de Registo: %d\n", dados[i].numeroRegisto);
      printf("- Marca: %s\n", dados[i].marca);
      printf("- Modelo: %s\n", dados[i].modelo);
      printf("- GPU(Placa Grafica): %s\n", dados[i].grafica);
      printf("- CPU(Processador): %s\n", dados[i].processador);
      printf("- Numero de Serie: %s\n", dados[i].numeroSerie);
      printf("- Data de Compra: %d/%d/%d\n", dados[i].data_nascimento.dia, dados[i].data_nascimento.mes, dados[i].data_nascimento.ano);
      printf("- RAM: %d\n", dados[i].ram);
      printf("- Espaco no Disco: %d\n", dados[i].disco);
      printf("- Preco: %f\n", dados[i].preco);

      if (dados[i].tipo == desktop)
      {
        printf("- Tipo de Produto:\033[0m Desktop \n");
      }
      else if (dados[i].tipo == portatil)
      {
        printf("- Tipo de Produto:\033[0m Portatil \n");
      }
      else if (dados[i].tipo == servidor)
      {
        printf("- Tipo de Produto:\033[0m Servidor \n");
      }
      printf("\n");
    }
  }
  if (!found)
  {
    printf("Produto com o numero de registo %d nao existe.\n", numero);
  }
}

/*
void ListarPCs(struct TInventario dados[], int counter, char *nomeficheiro)
{

  int indices[counter];
  for (int i = 0; i < counter; i++)
  {
    indices[i] = i;
  }
  for (int i = 0; i < counter; i++)
  {
    for (int j = i + 1; j < counter; j++)
    {
      if (dados[indices[i]].data_nascimento.ano > dados[indices[j]].data_nascimento.ano)
      {
        int temp = indices[i];
        indices[i] = indices[j];
        indices[j] = temp;
      }
    }
  }

  for (int i = 0; i < counter; i++)
  {
    int indice = indices[i];
    printf("\033[1mPRODUTO NUMERO [%d]\033[0m\n", dados[indice].numeroRegisto);
    printf("\033[1mNumero de serie:\033[0m %s\n", dados[indice].numeroSerie);
    printf("\033[1mMarca:\033[0m %s\n", dados[indice].marca);
    printf("\033[1mProcessador:\033[0m %s\n", dados[indice].processador);
    printf("\033[1mRAM:\033[0m %d GB\n", dados[indice].ram);
    printf("\033[1mDico[GB]:\033[0m %d \n", dados[indice].disco);
    printf("\033[1mPreco:\033[0m %0.2f euros\n", dados[indice].preco);
    printf("\033[1mData:\033[0m %d/%d/%d\n", dados[indice].data_nascimento.dia, dados[indice].data_nascimento.mes, dados[indice].data_nascimento.ano);
    printf("\033[1mTipo: ");
    switch (dados[indice].tipo)
    {
    case desktop:
      printf("Desktop\n");
      break;
    case portatil:
      printf("Portatil\n");
      break;
    case servidor:
      printf("Servidor\n");
      break;
    }
    printf("\n");
  }
}
*/

int menu()
{

  printf("\n");
  printf("\033[1m###########################################[ MENU ]###########################################\033[0m\n");
  printf("| \033[1m-[1] Inserir Informacao dos PCs da organizacao\033[0m                                             |\n");
  printf("| \033[1m-[2] Listar todos os Registos de PCs inseridos\033[0m                                             |\n");
  printf("| \033[1m-[3] Listar PCs por Categoria\033[0m                                                              |\n");
  printf("| \033[1m-[4] Remover PCs por Numero de Registo\033[0m                                                     |\n");
  printf("| \033[1m-[5] Gravar Registos de PCs no Ficheiro\033[0m                                                    |\n");
  printf("| \033[1m-[6] Ler Registos do Ficheiro e Mostrar\033[0m                                                    |\n");
  printf("| \033[1m-[7] Ler do Ficheiro, Ordenar (Crescente ou Decrescente (Data de Compra)), Gravar e Mostrar\033[0m|\n");
  printf("| \033[1m-[8] Calcular o Valor Estimado Total de todos os PCs registados\033[0m                            |\n");
  printf("| \033[1m-[9] Procurar Produto por Numero de Registo\033[0m                                                |\n");
  /* printf("| \033[1m-[10] Ordenar por Ordem Crescente do Ano de Compra os Produtos Inseridos no Ficheiro\033[0m |\n"); */ // REMOVI ESTA OPÇÃO PORQUE A OPÇÃO 7 FAZ O MESMO MAS PEDE SE O UTILIZADOR  QUER ORDENAR POR ORDEM CRESCENTE OU DECRESCENTE, A FUNÇÃO LISTARPCs ESTÁ PRESENTE NO CODIGO SO QUE ESTÁ COMENTADA *LINHA 409*
  printf("| \033[1m-[0] Sair\033[0m                                                                                  |\n");
  printf("\033[1m##############################################################################################\033[0m\n");
  printf("\033[1m- Insira a opcao que pretender (0-8): \033[0m");

  int op;
  scanf("%d", &op);
  printf("\n");
  return op;
}

int main()
{

  struct TInventario dados[MAX_PC];
  int counter = 0;
  int op;
  op = menu();

  while (op != 0)
  {
    if (op == 1)
    {
      InserePC(dados, counter);
      counter++;
    }
    else if (op == 2)
    {
      MostrarPC(dados, counter);
    }
    else if (op == 3)
    {
      MostrarCategoria(dados, counter);
    }
    else if (op == 4)
    {
      RemoverPC(dados, &counter);
    }
    else if (op == 5)
    {
      GravarPC(dados, counter, "pc.bin");
    }
    else if (op == 6)
    {
      LerPCs(dados, "pc.bin");
    }
    else if (op == 7)
    {
      OrdenarPCs(dados, counter);
    }
    else if (op == 8)
    {
      valorTotal(dados, counter);
    }
    else if (op == 9)
    {
      procurarProduto(dados, counter);
    }
    /*else if (op == 10)
    {
      ListarPCs(dados, counter, "pc.bin"); //
    }*/
    op = menu();
  }
}
