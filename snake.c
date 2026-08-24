#include <stdio.h>
#include "game.h"
#include "snake.h"

void moverCobra(char direcao)
{
int i;

for (i = tamanhoCobra - 1; i > 0; i--)
    cobra[i] = cobra[i - 1];

switch (direcao)
{
    case 'w':
        cobra[0].y--;
        break;

    case 's':
        cobra[0].y++;
        break;

    case 'a':
        cobra[0].x--;
        break;

    case 'd':
        cobra[0].x++;
        break;
}

}

int verificarColisao()
{
if (cobra[0].x <= 0 ||
cobra[0].x >= LARGURA - 1 ||
cobra[0].y <= 0 ||
cobra[0].y >= ALTURA - 1)
{
return 1;
}

return 0;

}

int verificarColisaoCorpoRecursiva(int indice)
{
if (indice >= tamanhoCobra)
return 0;

if (cobra[0].x == cobra[indice].x &&
    cobra[0].y == cobra[indice].y)
    return 1;

return verificarColisaoCorpoRecursiva(indice + 1);

}

int verificarColisaoCorpo()
{
return verificarColisaoCorpoRecursiva(1);
}

int verificarComida()
{
if (cobra[0].x == comida.x &&
cobra[0].y == comida.y)
{
if (tamanhoCobra < TAM_MAX)
tamanhoCobra++;

    pontuacao += 10;
    reposicionarComida();

    return 1;
}

return 0;

}

void reiniciarCobra()
{
cobra[0].x = 20;
cobra[0].y = 10;

cobra[1].x = 19;
cobra[1].y = 10;

cobra[2].x = 18;
cobra[2].y = 10;

tamanhoCobra = 3;

}
