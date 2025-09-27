// TEMA 1 - NÍVEL AVENTUREIRO DESENVOLVIDO POR JÚLIO CÉZAR
//PONTEIROS E ALOCAÇÃO DINAMICA DE MEMORIA E ATAQUE E DEFESA DAS TROPAS

#include <stdio.h> //INCLUINDO BIBLIOTECAS ESSENCIAIS
#include <stdlib.h>
#include <string.h>
#include <time.h>//BIBLIOTECA PARA ALEATORIO

int quantidade;
int ataque;
int defesa;

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
        printf("Agora a nova cor do exercito %s e %s e sua tropa é de %d",defensor->nome,defensor->cor,defensor->tropas);
    }
}

//FUNÇÃO LIBERAR MEMÓRIA
void liberarMemoria(struct Territorio*areas){
    free(areas);
    printf("\nMemória liberada com sucesso");
}

int main() { // CHAMADA PRINCIPAL DO PROGRAMA
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
    //MOSTRAR DADOS DOS TERRITORIOS CADASTRADOS
    printf("\n-------------LISTA DE TERRITORIOS-------------\n");//LOOP PARA MOSTRAR OS TERRITORIOS CADASTRADOS
    for (int i = 0; i< quantidade;i++){
        
        printf("\n---------TERRITORIOS CADASTRADO %d-------------\n", i);
        printf("TERRITORIO: %i \n", i);
        printf("NOME: %s ", areas[i].nome);
        printf("COR: %s ", areas[i].cor);
        printf("TROPAS: %i ", areas[i].tropas);
        
    }

    printf("\n-------------HORA DO ATAQUE-------------\n");//SELECIONANDO UM ATACANTE E DEFENSOR DOS CADASTRADOS
    printf("Selecione o territorio atacante");
    scanf("%i", &ataque);//%i REPRESENTA INTEIRO %s REPRESENTA STRING E %d INTEIRO OU DECIMAL
    limparBufferEntrada();

    printf("Selecione o territorio defensor");
    scanf("%i", &defesa);
    limparBufferEntrada();

    //VALIDAÇÃO DOS TERRITORIOS SELECIONADOS

    if (ataque==defesa){
        printf("SELECIONOU A MESMA TROPA OPÇÃO INVALIDA!\n");
    }
    else if(ataque<=quantidade && defesa<=quantidade){
        atacar(&areas[ataque],&areas[defesa]);//CHAMANDO A FUNÇÃO DE ATACAR UTILIZANDO PARAMETROS SE DER CERTO A SELEÇÃO DOS DADOS
    }else{
      printf("OPÇÃO INVALIDA!\n");  
    }

    liberarMemoria(areas);
}