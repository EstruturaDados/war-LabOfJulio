#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>
#include <time.h>//BIBLIOTECA PARA ALEATORIO

atribuirMissao(char* destino, char* missoes[], int totalMissoes) {
    srand(time(NULL)); // INICIA OS NUMEROS ALEATORIOS
    int indice = rand() % totalMissoes; // SORTEIA UMA MISSÃO VALIDA
    strcpy(destino, missoes[indice]);  //COPIA A MISSÃO PARA O DESTINO
}

void missao() { //FUNÇÃO PARA GUARDAR AS MISSÕES E INFORMAR QUAL SERÁ
    char* missoes[] = {
        "Destruir todos os territorios",
        "Conquistar 3 territorios",
        "Defender sua base por 2 rodadas",
        "Eliminar um exercito inimigo",
        "Controlar todos os territorios azuis"
    };
    int total = sizeof(missoes) / sizeof(missoes[0]);
    char missaoDoJogador[100]; //  MISSÃO QUE O JOGADOR IRÁ RECEBER
    atribuirMissao(missaoDoJogador, missoes, total);
    printf("MISSAO ATRIBUIDA: %s\n", missaoDoJogador);
    return 0;
}
