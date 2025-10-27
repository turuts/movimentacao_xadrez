#include <stdio.h>
#include <stdlib.h>

// Constantes para o tamanho do tabuleiro e habilidades
#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Constantes para representar os elementos no tabuleiro
#define AGUA 0
#define NAVIO 3
#define HABILIDADE_EFEITO 5

// Função para inicializar o tabuleiro com água
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para criar a matriz de habilidade em formato de Cone
void criarHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para criar formato de cone apontando para baixo
            // O cone se expande da ponta superior para a base inferior
            if (i == 0 && j == TAM_HABILIDADE/2) {
                // Topo do cone (ponto de origem)
                habilidade[i][j] = 1;
            } else if (i == 1 && j >= 1 && j <= 3) {
                // Segunda linha do cone
                habilidade[i][j] = 1;
            } else if (i == 2 && j >= 0 && j < TAM_HABILIDADE) {
                // Base do cone (linha mais larga)
                habilidade[i][j] = 1;
            } else if (i == 3 && j >= 1 && j <= 3) {
                // Quarta linha (começa a diminuir)
                habilidade[i][j] = 1;
            } else if (i == 4 && j == TAM_HABILIDADE/2) {
                // Ponta inferior
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em formato de Cruz
void criarHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para criar formato de cruz
            // Centro da matriz é o ponto de origem
            int centro = TAM_HABILIDADE / 2;
            
            // Linha horizontal central e coluna vertical central
            if (i == centro || j == centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para criar a matriz de habilidade em formato de Octaedro (losango)
void criarHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Lógica para criar formato de losango (vista frontal do octaedro)
            int centro = TAM_HABILIDADE / 2;
            int distancia = abs(i - centro) + abs(j - centro);
            
            // Cria formato de losango baseado na distância Manhattan do centro
            if (distancia <= centro) {
                habilidade[i][j] = 1;
            } else {
                habilidade[i][j] = 0;
            }
        }
    }
}

// Função para posicionar navios no tabuleiro (para demonstração)
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    // Posiciona alguns navios para demonstração
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    
    tabuleiro[8][1] = NAVIO;
    tabuleiro[8][2] = NAVIO;
    tabuleiro[9][1] = NAVIO;
    tabuleiro[9][2] = NAVIO;
}

// Função para aplicar uma habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], 
                      int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], 
                      int linha_origem, int coluna_origem) {
    
    // Calcula o deslocamento para centralizar a habilidade no ponto de origem
    int deslocamento = TAM_HABILIDADE / 2;
    
    // Aplica a habilidade ao tabuleiro
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            // Calcula as coordenadas no tabuleiro
            int linha_tab = linha_origem - deslocamento + i;
            int coluna_tab = coluna_origem - deslocamento + j;
            
            // Verifica se a posição está dentro dos limites do tabuleiro
            if (linha_tab >= 0 && linha_tab < TAM_TABULEIRO && 
                coluna_tab >= 0 && coluna_tab < TAM_TABULEIRO) {
                
                // Se a posição na matriz de habilidade for 1, marca no tabuleiro
                if (habilidade[i][j] == 1) {
                    tabuleiro[linha_tab][coluna_tab] = HABILIDADE_EFEITO;
                }
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    printf("\n=== TABULEIRO DE BATALHA NAVAL ===\n");
    printf("Legenda: ~ = Agua, # = Navio, * = Area de Habilidade\n\n");
    
    // Cabeçalho com números das colunas
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Linha separadora
    printf("   ");
    for (int j = 0; j < TAM_TABULEIRO; j++) {
        printf("---");
    }
    printf("\n");
    
    // Conteúdo do tabuleiro
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        printf("%2d|", i); // Número da linha
        
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            switch (tabuleiro[i][j]) {
                case AGUA:
                    printf(" ~ ");
                    break;
                case NAVIO:
                    printf(" # ");
                    break;
                case HABILIDADE_EFEITO:
                    printf(" * ");
                    break;
                default:
                    printf(" ? ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Função para exibir uma matriz de habilidade (para debug/demonstração)
void exibirHabilidade(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], const char* nome) {
    printf("\n=== MATRIZ DE HABILIDADE: %s ===\n", nome);
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            printf("%d ", habilidade[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Declaração do tabuleiro principal
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    
    // Declaração das matrizes de habilidades
    int habilidadeCone[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeCruz[TAM_HABILIDADE][TAM_HABILIDADE];
    int habilidadeOctaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    
    printf("=== BATALHA NAVAL COM HABILIDADES ESPECIAIS ===\n");
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona navios para demonstração
    posicionarNavios(tabuleiro);
    
    // Cria as matrizes de habilidades
    criarHabilidadeCone(habilidadeCone);
    criarHabilidadeCruz(habilidadeCruz);
    criarHabilidadeOctaedro(habilidadeOctaedro);
    
    // Exibe as matrizes de habilidades (opcional, para visualização)
    exibirHabilidade(habilidadeCone, "CONE");
    exibirHabilidade(habilidadeCruz, "CRUZ");
    exibirHabilidade(habilidadeOctaedro, "OCTAEDRO");
    
    // Aplica as habilidades ao tabuleiro em posições específicas
    printf("\nAplicando habilidades ao tabuleiro...\n");
    
    // Habilidade Cone na posição (3, 4)
    aplicarHabilidade(tabuleiro, habilidadeCone, 3, 4);
    
    // Habilidade Cruz na posição (6, 6)
    aplicarHabilidade(tabuleiro, habilidadeCruz, 6, 6);
    
    // Habilidade Octaedro na posição (8, 8)
    aplicarHabilidade(tabuleiro, habilidadeOctaedro, 8, 8);
    
    // Exibe o tabuleiro final com todas as habilidades aplicadas
    exibirTabuleiro(tabuleiro);
    
    printf("=== FIM DO PROGRAMA ===\n");
    
    return 0;
}