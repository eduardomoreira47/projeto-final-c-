#include <stdlib.h>
#include "game.h"
#include "world.h"

void reposicionarComida()
{
    int valido;

    do
    {
        valido = 1;

        comida.x = rand() % (LARGURA - 2) + 1;
        comida.y = rand() % (ALTURA - 2) + 1;

        for (int i = 0; i < tamanhoCobra; i++)
        {
            if (comida.x == cobra[i].x &&
                comida.y == cobra[i].y)
            {
                valido = 0;
                break;
            }
        }

        for (int i = 0; i < numeroObstaculos; i++)
        {
            if (comida.x == obstaculos[i].x &&
                comida.y == obstaculos[i].y)
            {
                valido = 0;
                break;
            }
        }

    } while (!valido);
}

void criarObstaculos(int quantidade)
{
    int i;
    int j;
    int valido;

    numeroObstaculos = 0;

    for (i = 0; i < quantidade; i++)
    {
        do
        {
            valido = 1;

            obstaculos[i].x = rand() % (LARGURA - 2) + 1;
            obstaculos[i].y = rand() % (ALTURA - 2) + 1;

            for (j = 0; j < tamanhoCobra; j++)
            {
                if (obstaculos[i].x == cobra[j].x &&
                    obstaculos[i].y == cobra[j].y)
                {
                    valido = 0;
                    break;
                }
            }

            for (j = 0; j < numeroObstaculos; j++)
            {
                if (obstaculos[i].x == obstaculos[j].x &&
                    obstaculos[i].y == obstaculos[j].y)
                {
                    valido = 0;
                    break;
                }
            }

        } while (!valido);

        numeroObstaculos++;
    }
}

int verificarColisaoObstaculo()
{
    int i;

    for (i = 0; i < numeroObstaculos; i++)
    {
        if (cobra[0].x == obstaculos[i].x &&
            cobra[0].y == obstaculos[i].y)
        {
            return 1;
        }
    }

    return 0;
}