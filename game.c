#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

Posicao cobra[3] = {
    {20, 10},
    {19, 10},
    {18, 10}
};

Posicao comida;

void reposicionarComida()
{
    comida.x = rand() % (LARGURA - 2) + 1;
    comida.y = rand() % (ALTURA - 2) + 1;
}

void mostrarTabuleiro()
{
    int linha;
    int coluna;
    int i;
    int temCobra;

    for (linha = 0; linha < ALTURA; linha++)
    {
        for (coluna = 0; coluna < LARGURA; coluna++)
        {
            temCobra = 0;

            for (i = 0; i < 3; i++)
            {
                if (cobra[i].x == coluna && cobra[i].y == linha)
                {
                    temCobra = 1;
                }
            }

            if (linha == 0 || linha == ALTURA - 1 ||
                coluna == 0 || coluna == LARGURA - 1)
            {
                printf("#");
            }
            else if (temCobra == 1)
            {
                printf("O");
            }
            else if (comida.x == coluna && comida.y == linha)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }

        printf("\n");
    }
}

void iniciarJogo()
{
    int opcao;

    srand(time(NULL));
    reposicionarComida();

    printf("========================\n");
    printf("        C-SNAKE         \n");
    printf("========================\n");
    printf("\n");
    printf("1 - Jogar\n");
    printf("2 - Sair\n");
    printf("\n");
    printf("Escolha: ");

    scanf("%d", &opcao);

    switch(opcao)
    {
        case 1:
            printf("\n");
            mostrarTabuleiro();
            break;

        case 2:
            printf("\nA sair do C-Snake...\n");
            break;

        default:
            printf("\nOpcao invalida!\n");
    }
}