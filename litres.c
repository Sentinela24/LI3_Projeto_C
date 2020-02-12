#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRODSIZE 6
#define CLIENTESIZE 5
#define MAXBUFSIZE 128

typedef enum { false, true } bool;

bool validaCliente(char* cliente){
  int codigo = atoi(cliente+1);
  if(codigo < 1000 || codigo > 5000 || cliente[0] < 'A' || cliente [0] > 'Z' || cliente[5]) return false;
  else return true;
}
bool validaProduto(char* produto){
  int codigo = atoi(produto+2);
  if(produto[0] < 'A' || produto[1] < 'A' || produto[1] > 'Z' || produto[0] > 'Z' || codigo < 1000 || codigo > 9999 || produto[6]) return false;
  else return true;
}

int main(){
  char** clientes = (char**)malloc(sizeof(char*));
  char** produtos = (char**)malloc(sizeof(char*));

  char buffer[MAXBUFSIZE];
  int index = 0, clientes_val = 0, produtos_val = 0;
  //Clientes
  FILE* fp_clientes = fopen("Clientes.txt", "r");
  if(fp_clientes){
    while(fgets(buffer, MAXBUFSIZE, fp_clientes)){
      char* token = strtok(buffer, "\r\n");
      if(validaCliente(token) == true){
        clientes = (char**)realloc(clientes, (index+1) * sizeof(char*));
        clientes[index] = strdup(token);
        printf("%s\n", clientes[index]);
        index++;
        clientes_val++;
      }
    }
    fclose(fp_clientes);
  }
  //Produto
  FILE* fp_produtos = fopen("Produtos.txt", "r");
  if(fp_produtos){
    while(fgets(buffer, MAXBUFSIZE, fp_produtos)){
      char* token = strtok(buffer, "\r\n");
      if(validaProduto(token) == true){
        produtos = (char**)realloc(produtos, (index+1) * sizeof(char*));
        produtos[index] = strdup(token);
        printf("%s\n", produtos[index]);
        index++;
        produtos_val++;
      }
    }
    fclose(fp_produtos);
  }
  //Vendas

  printf("Vendas válidas: %d\n", vendas_val);
  printf("Produtos válidos: %d\n", produtos_val);
  printf("Clientes válidos: %d\n", clientes_val);
}
