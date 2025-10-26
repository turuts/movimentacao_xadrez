#include <stdio.h>

// Constantes para o número de movimento das peças
#define MOVIMENTOS_TORRE 3
#define MOVIMENTOS_BISPO 2
#define MOVIMENTOS_CAVALO 2
#define MOVIMENTOS_RAINHA 3

// Função recursiva para movimento da Torre
void moverTorre(int casas) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    printf("Direita\n");  // Torre movendo para a direita
    moverTorre(casas - 1);  // Chamada recursiva
}

// Função recursiva para movimento do Bispo
void moverBispoRecursivo(int casas) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    printf("Cima-Direita\n");  // Bispo movendo na diagonal
    moverBispoRecursivo(casas - 1);  // Chamada recursiva
}

// Função com loops aninhados para o Bispo
void moverBispoLoopsAninhados(int vertical, int horizontal) {
    printf("Bispo com loops aninhados:\n");
    
    // Loop externo para movimento vertical
    for (int v = 1; v <= vertical; v++) {
        printf("Vertical: %d - ", v);
        
        // Loop interno para movimento horizontal
        for (int h = 1; h <= horizontal; h++) {
            printf("Horizontal: %d | ", h);
        }
        printf("\n");
    }
}

// Função para movimento do Cavalo com loops complexos
void moverCavalo() {
    printf("Cavalo movendo em L (2 cima, 1 direita):\n");
    
    int movimentos_feitos = 0;
    int max_movimentos = MOVIMENTOS_CAVALO;
    
    // Loop externo para controle geral dos movimentos
    for (int ciclo = 1; ciclo <= 5; ciclo++) {
        if (movimentos_feitos >= max_movimentos) {
            break;  // Sai do loop quando atingir o número máximo de movimentos
        }
        
        printf("Ciclo %d: ", ciclo);
        
        // Loop para movimento vertical (2 casas para cima)
        for (int vertical = 1; vertical <= 2; vertical++) {
            if (movimentos_feitos >= max_movimentos) {
                continue;  // Pula para próxima iteração se já atingiu o máximo
            }
            
            printf("Cima ");
            
            // Loop para movimento horizontal (1 casa para direita)
            for (int horizontal = 1; horizontal <= 1; horizontal++) {
                if (vertical == 2) {  // Só move para direita na segunda casa vertical
                    printf("Direita ");
                    movimentos_feitos++;
                    
                    if (movimentos_feitos >= max_movimentos) {
                        break;  // Sai do loop interno
                    }
                }
            }
        }
        printf("\n");
        
        // Condição adicional para controle de fluxo
        if (ciclo > 3 && movimentos_feitos < 1) {
            printf("Movimento especial ativado!\n");
            printf("Cima Cima Direita\n");
            movimentos_feitos++;
        }
    }
}

// Função recursiva para movimento da Rainha
void moverRainha(int casas) {
    // Caso base: quando não há mais casas para mover
    if (casas <= 0) {
        return;
    }
    
    // A rainha pode se mover em todas as direções
    // Vamos simular movimentos alternados
    if (casas % 3 == 0) {
        printf("Rainha: Cima\n");
    } else if (casas % 3 == 1) {
        printf("Rainha: Direita\n");
    } else {
        printf("Rainha: Cima-Direita\n");
    }
    
    moverRainha(casas - 1);  // Chamada recursiva
}

// Função principal
int main() {
    printf("=== SIMULADOR DE XADREZ AVANÇADO ===\n\n");
    
    // Torre - Movimento com recursividade
    printf("TORRE - Movimento Recursivo:\n");
    printf("Movendo %d casas para a direita:\n", MOVIMENTOS_TORRE);
    moverTorre(MOVIMENTOS_TORRE);
    printf("\n");
    
    // Bispo - Movimento com recursividade
    printf("BISPO - Movimento Recursivo:\n");
    printf("Movendo %d casas na diagonal:\n", MOVIMENTOS_BISPO);
    moverBispoRecursivo(MOVIMENTOS_BISPO);
    printf("\n");
    
    // Bispo - Movimento com loops aninhados
    moverBispoLoopsAninhados(2, 3);
    printf("\n");
    
    // Cavalo - Movimento com loops complexos
    moverCavalo();
    printf("\n");
    
    // Rainha - Movimento com recursividade
    printf("RAINHA - Movimento Recursivo:\n");
    printf("Movendo %d casas em várias direções:\n", MOVIMENTOS_RAINHA);
    moverRainha(MOVIMENTOS_RAINHA);
    printf("\n");
    
    printf("=== FIM DA SIMULAÇÃO ===\n");
    
    return 0;
}