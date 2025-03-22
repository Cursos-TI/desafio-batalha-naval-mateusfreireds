#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define QTDE_NAVIO 3



// Função para inicializar o tabuleiro
void inicializarTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '0';  // Água
        }
    }
}

// Função para checar se a posição do navio é válida
int checarNavioTabuleiro(int navio[3], char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]){
    if (navio[0] < 0 || navio[0] >= TAMANHO_TABULEIRO || navio[1] < 0 || navio[1] >= TAMANHO_TABULEIRO) {
        return 1;
    }
    if (navio[2] == 1){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]+i][navio[1]] == 'N') {
                return 1;
            }
        }
    }
    else if (navio[2] == 2){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]][navio[1]+i] == 'N') {
                return 1;
            }
        }
    }
    return 0;
}


// Função para posicionar um navio no tabuleiro
void posicionarNavio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    int navio[3];
    for(int x = 1; x<=3; x++){
        //Colhendo as informações do navio
        printf("Posicionando navio : Insira a coordenada inicial do navio %d : \n", x );      
        scanf("%d %d", &navio[0], &navio[1]);
        printf("digite 1 para vertical e 2 para horizontal\n");
        scanf("%d", &navio[2]);
        //posicionando navio no tabuleiro de acordo com sua orientação
        if(checarNavioTabuleiro(navio,tabuleiro) == 1){
            printf("Posição inválida, tente novamente\n");
            x--;
        }
        else 
            if (navio[2] == 1){
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]+i][navio[1]] = 'N';  
                    }

            }
            else if (navio[2] == 2){
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]][navio[1]+i] = 'N';  
                    }
        }
    }
}

// Função para exibir o tabuleiro
void displayTabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("  ");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%d ", j);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    int navios = QTDE_NAVIO;
    // Posicionando os navios no tabuleiro
    posicionarNavio(tabuleiro);
    

    // Exibindo o tabuleiro
    printf("Tabuleiro da Batalha Naval:\n");
    displayTabuleiro(tabuleiro);

    return 0;
}