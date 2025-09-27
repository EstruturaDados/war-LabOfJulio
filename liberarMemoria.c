#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>
#include <time.h>//BIBLIOTECA PARA ALEATORIO

//FUNÇÃO LIBERAR MEMÓRIA
void liberarMemoria(struct Territorio*areas){
    free(areas);
    printf("\nMemoria liberada com sucesso");
}