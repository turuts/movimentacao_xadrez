# ♟️ Simulador de Xadrez Avançado em C
Um programa educativo que simula movimentos complexos de peças de xadrez utilizando técnicas avançadas de programação como recursividade e loops aninhados.
## 🚀 Características
- Recursividade: Implementação de movimentos usando funções recursivas
- Loops Complexos: Controle preciso de fluxo com loops aninhados
- Movimentos Realistas: Simulação fiel dos movimentos das peças de xadrez
- Código Documentado: Comentários detalhados explicando cada funcionalidade

## 📋 Peças Implementadas

**♜ Torre**
- **Movimento**: Horizontal e vertical
- **Técnica**: Recursividade pura
- **Direções**: Direita, Esquerda, Cima, Baixo

**♝ Bispo**
- **Movimento**: Diagonal
- **Técnica**: Recursividade + Loops Aninhados
- **Loop Externo**: Controle vertical
- **Loop Interno**: Controle horizontal

**♞ Cavalo**
- **Movimento**: Em "L" (2 casas para cima + 1 para direita)
- **Técnica**: Loops aninhados complexos
- **Controle de Fluxo**: Uso de *break* e *continue*

**♛ Rainha**
- **Movimento**: Todas as direções
- **Técnica**: Recursividade com múltiplas direções
- **Flexibilidade**: Combina movimentos de Torre e Bispo

## 🛠️ Tecnologias Utilizadas
### Linguagem: C
**Conceitos Avançados**:
- Recursividade
- Loops aninhados
- Controle de fluxo (break, continue)
- Funções recursivas
- Variáveis e constantes

## 🎯 Como Executar
**Pré-requisitos**:
- Compilador C (GCC recomendado)
- Terminal ou prompt de comando

## 🎮 Compilação e Execução

```bash
# Compilar o programa
gcc -o xadrez xadrez.c
 
# Executar 
./xadrez
```
## 📊 Exemplo de Saída

```bash
=== SIMULADOR DE XADREZ AVANÇADO ===

TORRE - Movimento Recursivo:
Movendo 3 casas para a direita:
Direita
Direita
Direita

BISPO - Movimento Recursivo:
Movendo 2 casas na diagonal:
Cima-Direita
Cima-Direita

CAVALO - Movimento em L:
Cima Cima Direita
Cima Cima Direita

=== FIM DA SIMULAÇÃO ===
```
# 🎯 Batalha Naval com Habilidades Especiais
Um projeto em C que expande o clássico jogo de Batalha Naval com habilidades especiais estratégicas, implementando áreas de efeito distintas para adicionar profundidade tática ao gameplay.
## 🚀 Funcionalidades

### 🎮 Habilidades Especiais Implementadas
- **🔺 Cone**: Área em formato triangular que se expande do topo para a base
- **➕ Cruz**: Área em formato de cruz com centro no ponto de origem
- **💎 Octaedro**: Área em formato de losango (vista frontal do octaedro)

### 🎮 Elementos do Jogo
**Símbolos no Tabuleiro:**
- O símbolo ~ = Água
- O símbolo # = Navio
- O símbolo * = Área afetada por habilidade

**Coordenadas:**
- Linhas: 0-9 (vertical)
- Colunas: 0-9 (horizontal)

### 🏗️ Estrutura do Projeto
- **Tabuleiro 10x10**: Matriz principal do jogo
- **Matrizes de Habilidade 5x5**: Representam as áreas de efeito
- **Sistema de Visualização**: Exibição clara dos diferentes elementos
- **Gestão de Limites**: Verificação de bordas do tabuleiro

### 🛠️ Tecnologias Utilizadas
- **Linguagem:** C
- **Compilador:** Compatível com GCC.
- **Bibliotecas**: Standard C Library (stdio.h, stdlib.h)

### 🎯 Como Executar
**Pré-requisitos**:
- Compilador C (GCC recomendado)
- Terminal ou prompt de comando

### 🎮 Compilação e Execução
```bash
# Compilar o programa
gcc -o batalha_naval batalha_naval.c
# Executar
./batalha_naval
```
### 📊 Exemplo de Saída

```bash
=== TABULEIRO DE BATALHA NAVAL ===
Legenda: ~ = Agua, # = Navio, * = Area de Habilidade

    0  1  2  3  4  5  6  7  8  9 
  -------------------------------
 0| ~  ~  ~  ~  ~  ~  ~  ~  ~  ~ 
 1| ~  ~  ~  ~  *  ~  ~  ~  ~  ~ 
 2| ~  ~  ~  #  *  #  ~  ~  ~  ~ 
 3| ~  ~  ~  #  *  #  ~  ~  ~  ~ 
 4| ~  ~  ~  #  *  #  ~  ~  ~  ~ 
 5| ~  ~  ~  ~  *  ~  ~  #  ~  ~ 
 6| ~  ~  ~  ~  *  ~  *  #  *  ~ 
 7| ~  ~  ~  ~  ~  ~  *  *  *  ~ 
 8| ~  #  #  ~  ~  ~  *  *  *  * 
 9| ~  #  #  ~  ~  ~  ~  *  ~  ~ 
```
