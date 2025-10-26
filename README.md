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

