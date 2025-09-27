#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>
#include <time.h>//BIBLIOTECA PARA ALEATORIO

int quantidade;
int ataque;
int defesa;
//FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limparBufferEntrada(){
    int c;
    while ((c=getchar()) !='\n' && c != EOF);
}
void cadastro_visualiza(){
    printf("-------BEM VINDO AO WAR-------\n");
    printf("===============================\n");
    printf("Quantas tropas iremos ter?\n");      
    scanf("%d", &quantidade);//QUANTIDADE DAS AREAS TAMBEM
    limparBufferEntrada();

    //O PONTEIRO APONTA PARA QUANTIDADE DE AREAS QUE O JOGO VAI TER ("MAPAS")
    struct Territorio*areas = (struct Territorio*) calloc(quantidade, sizeof(struct Territorio)); //USANDO PONTEIRO PARA DEFINIR A ALOCAÇÃO DINAMICA

    printf("----------------------------------\n");
    printf("BEM VINDO AO WAR\n");
    printf("----------------------------------\n");

    for (int i = 0; i< quantidade;i++){ //LOOP DE CADASTRO
        printf("--------CADASTRE AS TROPAS--------\n");
        printf("----------------------------------\n");
        printf("DIGITE O NOME DA TROPA %i : ", i + 1);
        fgets(areas[i].nome,30,stdin);

        printf("DIGITE A COR DA TROPA %i : ", i + 1);
        fgets(areas[i].cor,30,stdin);

        printf("DIGITE O NUMERO DE TROPAS DA TROPA %i : ", i + 1);
        scanf("%d", &areas[i].tropas);

        printf("TROPA %i CADASTRADA COM SUCESSO\n", i+1);

        limparBufferEntrada();

    }
}