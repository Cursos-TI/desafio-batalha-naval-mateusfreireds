#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define QTDE_NAVIO 3
#define TAMANHO_HABILIDADEX 5
#define TAMANHO_HABILIDADEY 3

// Definição dos tipos de habilidades
#define CONE 1
#define CRUZ 2
#define OCTAEDRO 3





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
            if (tabuleiro[navio[0]+i][navio[1]] == '3') {
                return 1;
            }
        }
    }
    else if (navio[2] == 2){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]][navio[1]+i] == '3') {
                return 1;
            }
        }
    }
    else if (navio[2] == 3){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]+i][navio[1]+i] == '3') {
                return 1;
            }
        }
    }
    else if (navio[2] == 4){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]-i][navio[1]+i] == '3') {
                return 1;
            }
        }
    }
    else if (navio[2] == 5){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]+i][navio[1]-i] == '3') {
                return 1;
            }
        }
    }
    else if (navio[2] == 6){
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[navio[0]-i][navio[1]-i] == '3') {
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
        printf("digite 1 para vertical , 2 para horizontal, 3 para diagonal para cima direita , 4 para diagonal para cima esquerda\n");
        printf("digite 5 para diagonal para baixo direita , 6 para diagonal para baixo esquerda\n");
        scanf("%d", &navio[2]);
        //posicionando navio no tabuleiro de acordo com sua orientação
        if(checarNavioTabuleiro(navio,tabuleiro) == 1){
            printf("Posição inválida, tente novamente\n");
            x--;
        }
        switch(navio[2]){ 
            case 1 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]+i][navio[1]] = '3';  
                
                    }
            break;

            }
            case 2 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]][navio[1]+i] = '3';  
            
                    }
            break;
            }
            case 3 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]+i][navio[1]+i] = '3';  
                }
              break;
            }
            case 4 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]-i][navio[1]+i] = '3';  
            
                    }
            break;
        }
            case 5 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]+i][navio[1]-i] = '3';  
            
                }
            break;
            }
            case 6 :{
                for (int i = 0; i < TAMANHO_NAVIO; i++) {
                    tabuleiro[navio[0]-i][navio[1]-i] = '3';  
            
                    }
            break;
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


//Função para habilidade em cone
void habilidadeCone(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Matriz que define o padrão do cone
    char padraoCone[3][5] = {
        {'0', '0', '5', '0', '0'},
        {'0', '5', '5', '5', '0'},
        {'5', '5', '5', '5', '5'}
    };
    
    // Aplicar o padrão do cone no tabuleiro
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 5; j++) {
            if(4 + i < TAMANHO_TABULEIRO && 4 + j < TAMANHO_TABULEIRO) {
                if(padraoCone[i][j] == '5') {
                    tabuleiro[4 + i][4 + j] = '5'; // Marca área afetada pela habilidade
                }
            }
        }
    }
}


void habilidadeCruz(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Matriz que define o padrão da cruz
    char padraoCruz[3][5] = {
        {'0', '0', '5', '0', '0'},
        {'5', '5', '5', '5', '5'},
        {'0', '0', '5', '0', '0'}
    };
    
    // Aplicar o padrão da cruz no tabuleiro
    for(int i2 = 0; i2 < 3; i2++) {
        for(int j2 = 0; j2 < 5; j2++) {
            if(4 + i2 < TAMANHO_TABULEIRO && 4 + j2 < TAMANHO_TABULEIRO) {
                if(padraoCruz[i2][j2] == '5') {
                    tabuleiro[6 + i2][1 + j2] = '5'; // Marca área afetada pela habilidade
                }
            }
        }
    }
}

void habilidadeOctaedro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Matriz que define o padrão do Octaedro
    char padraoCruz[3][5] = {
        {'0', '0', '5', '0', '0'},
        {'0', '5', '5', '5', '0'},
        {'0', '0', '5', '0', '0'}
    };
    
    // Aplicar o padrão do octaedro no tabuleiro
    for(int i2 = 0; i2 < 3; i2++) {
        for(int j2 = 0; j2 < 5; j2++) {
            if(4 + i2 < TAMANHO_TABULEIRO && 4 + j2 < TAMANHO_TABULEIRO) {
                if(padraoCruz[i2][j2] == '5') {
                    tabuleiro[2 + i2][5 + j2] = '5'; // Marca área afetada pela habilidade
                }
            }
        }
    }
}


int main() {
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    int navios = QTDE_NAVIO;
    // Posicionando os navios no tabuleiro
    posicionarNavio(tabuleiro);
    
    habilidadeCone(tabuleiro);
    habilidadeCruz(tabuleiro);
    habilidadeOctaedro(tabuleiro);
    // Exibindo o tabuleiro
    printf("Tabuleiro da Batalha Naval:\n");
    displayTabuleiro(tabuleiro);

    return 0;
}