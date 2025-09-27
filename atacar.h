#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>
#include <time.h>//BIBLIOTECA PARA ALEATORIO

void atacar(struct Territorio*atacante,struct Territorio*defensor){
    srand(time(NULL));// ALEATORIO
    int aleatorio_ataque = 1 + (rand() % 6); //ATAQUE OU DEFESA DE UM A SEIS
    int aleatorio_defesa = 1 + (rand() % 6); //ATAQUE OU DEFESA DE UM A SEIS
    printf("=================ATAQUE!===================\n");
    printf("\nAtaque de-> %s \nContra-> %s\n", atacante->nome, defensor->nome);
    printf("Dado atacante: %d | Dado defensor: %d\n", aleatorio_ataque, aleatorio_defesa);

    if(aleatorio_ataque<aleatorio_defesa){//VALIDAR QUEM GANHOU
        printf("A defesa foi bem sucedida! ");
        atacante->tropas-=1;
        printf("Tropa atacante perdeu -1 ficando com: %d", atacante->tropas);
    }else{
        printf("O ataque foi realizado! ");
        strcpy(defensor->cor, atacante->cor);//TRANSEFERIR A COR ONDE A COR DO DEFENSOR SE TORNA A PARTIR DA COR DO ATACANTE
        defensor->tropas = atacante->tropas / 2; // METADE DAS TROPAS PARA O TERRITORIO DEFENSOR
        printf("Agora a nova cor do exercito %s e %s e sua tropa e de %d",defensor->nome,defensor->cor,defensor->tropas);
    }
}
//FUNÇÃO LIBERAR MEMÓRIA
void liberarMemoria(struct Territorio*areas){
    free(areas);
    printf("\nMemoria liberada com sucesso");
}