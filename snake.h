#ifndef SNAKE_H
#define SNAKE_H

void moverCobra(char direcao);
int verificarColisao();
int verificarColisaoCorpo();
int verificarColisaoCorpoRecursiva(int indice);
int verificarComida();
void reiniciarCobra();

#endif
