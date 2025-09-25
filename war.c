// TEMA 1 - NÍVEL NOVATO DESENVOLVIDO POR JÚLIO CÉZAR
//CONSTRUÇÃO DE TERRITÓRIOS

#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>

#define MAX_TROPAS 5 //DEFININDO UMA VARIAVEL GLOBAL COM O MAXIMO DE 5 TROPAS

struct Territorio { // CRIANDO A ESTRUTURA DE DADOS DO TERRITORIOS SENDO NOME COR E TROPA
    char nome[30];
    char cor[10];
    int tropas;
};

//FUNÇÃO PARA LIMPAR O BUFFER DE ENTRADA
void limparBufferEntrada(){
    int c;
    while ((c=getchar()) !='\n' && c != EOF);
}

int main() { // CHAMADA PRINCIPAL DO PROGRAMA
    
    struct Territorio areas[MAX_TROPAS]; //AQUI EU CRIEI UMA ESTRUTURA DE DADOS ONDE LISTA UM VETOR DE 5 POCISÕES
    printf("----------------------------------\n");
    printf("BEM VINDO AO WAR\n");
    printf("----------------------------------\n");

    for (int i = 0; i< 5;i++){ //LOOP DE CADASTRO
        printf("--------CADASTRE AS TROPAS--------\n");
        printf("----------------------------------\n");
        printf("DIGITE O NOME DA TROPA %d : ", i + 1);
        fgets(areas[i].nome,30,stdin);

        printf("DIGITE A COR DA TROPA %d : ", i + 1);
        fgets(areas[i].cor,30,stdin);

        printf("DIGITE O NUMERO DE TROPAS DA TROPA %d : ", i + 1);
        scanf("%d", &areas[i].tropas);

        printf("TROPA %d CADASTRADA COM SUCESSO\n", i+1);

        limparBufferEntrada();

    }
    //MOSTRAR DADOS DOS TERRITORIOS CADASTRADOS
    printf("\n---------LISTA DE TERRITORIOS-------------\n");//LOOP PARA MOSTRAR OS TERRITORIOS CADASTRADOS
    for (int i = 0; i< 5;i++){
        
        printf("\n---------TERRITORIO CADASTRADO %d-------------\n", i + 1);
        
        printf("NOME: %s ", areas[i].nome);
        printf("COR: %s ", areas[i].cor);
        printf("TROPAS: %d ", areas[i].tropas);
        
    }
}