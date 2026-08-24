#ifndef GAME_H
#define GAME_H

#define LARGURA 40
#define ALTURA 20
#define TAM_MAX 100
#define MAX_OBSTACULOS 50

typedef struct
{
    int x;
    int y;
} Posicao;

extern Posicao cobra[TAM_MAX];
extern Posicao comida;

extern int tamanhoCobra;
extern int pontuacao;
extern int vidas;
extern int dificuldade;

extern Posicao obstaculos[MAX_OBSTACULOS];
extern int numeroObstaculos;

void iniciarJogo();

void reposicionarComida();
void criarObstaculos(int quantidade);
void mostrarTabuleiro();
int verificarColisaoObstaculo();

#endif