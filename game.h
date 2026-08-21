#ifndef GAME_H
#define GAME_H

#define ALTURA 20
#define LARGURA 40
#define TAM_MAX 100

typedef struct
{
    int x;
    int y;
} Posicao;

void iniciarJogo();
void mostrarTabuleiro();
void reposicionarComida();
void moverCobra(char direcao);
int verificarColisao();
int verificarColisaoCorpo();
int verificarComida();
void reiniciarCobra();
void mostrarMenu();

#endif