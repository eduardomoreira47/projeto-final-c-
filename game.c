#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses/ncurses.h>

#include "game.h"
#include "extras.h"
#include "snake.h"
#include "board.h"
#include "world.h"
#include "menu.h"

Posicao cobra[TAM_MAX] = {
    {20, 10},
    {19, 10},
    {18, 10}
};

Posicao comida;

int tamanhoCobra = 3;
int pontuacao = 0;
int vidas = 3;
int dificuldade = 1;

Posicao obstaculos[MAX_OBSTACULOS];
int numeroObstaculos = 0;

void iniciarJogo()
{
    int tecla;
    char direcao = 'd';
    int jogoAtivo = 1;

    srand(time(NULL));

    carregarHighScore();

    pontuacao = 0;
    vidas = 3;
    tamanhoCobra = 3;
    numeroObstaculos = 0;

    reiniciarCobra();

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);

    nodelay(stdscr, FALSE);

    mostrarMenu();

    while (1)
    {
        tecla = getch();

        if (tecla == '1')
        {
            break;
        }

        if (tecla == '2')
        {
            clear();

            mvprintw(5, 10, "========================");
            mvprintw(6, 10, "        RECORDE");
            mvprintw(7, 10, "========================");

            mvprintw(10, 15,
                     "Recorde: %d",
                     obterHighScore());

            mvprintw(13, 10,
                     "Prima uma tecla para voltar.");

            refresh();

            getch();

            mostrarMenu();
        }

        if (tecla == '3' ||
            tecla == 'q' ||
            tecla == 'Q')
        {
            endwin();
            return;
        }
    }

    dificuldade = escolherDificuldade();

    if (dificuldade == 1)
    {
        criarObstaculos(0);
    }
    else if (dificuldade == 2)
    {
        criarObstaculos(10);
    }
    else
    {
        criarObstaculos(20);
    }

    reposicionarComida();

    nodelay(stdscr, TRUE);

    while (jogoAtivo)
    {
        tecla = getch();

        if (tecla == 'w' ||
            tecla == 'W' ||
            tecla == KEY_UP)
        {
            direcao = 'w';
        }
        else if (tecla == 's' ||
                 tecla == 'S' ||
                 tecla == KEY_DOWN)
        {
            direcao = 's';
        }
        else if (tecla == 'a' ||
                 tecla == 'A' ||
                 tecla == KEY_LEFT)
        {
            direcao = 'a';
        }
        else if (tecla == 'd' ||
                 tecla == 'D' ||
                 tecla == KEY_RIGHT)
        {
            direcao = 'd';
        }
        else if (tecla == 'p' ||
                 tecla == 'P')
        {
            if (mostrarPausa() == 0)
            {
                jogoAtivo = 0;
            }

            continue;
        }
        else if (tecla == 'q' ||
                 tecla == 'Q')
        {
            jogoAtivo = 0;
            continue;
        }

        moverCobra(direcao);

        if (verificarColisao() ||
            verificarColisaoCorpo() ||
            verificarColisaoObstaculo())
        {
            vidas--;

            if (vidas > 0)
            {
                reiniciarCobra();
                reposicionarComida();
                direcao = 'd';
            }
            else
            {
                atualizarHighScore(pontuacao);

                mostrarTabuleiro();

                nodelay(stdscr, FALSE);

                mvprintw(ALTURA + 2,
                         0,
                         "GAME OVER!");

                mvprintw(ALTURA + 3,
                         0,
                         "Pontuacao final: %d",
                         pontuacao);

                mvprintw(ALTURA + 4,
                         0,
                         "Recorde: %d",
                         obterHighScore());

                mvprintw(ALTURA + 6,
                         0,
                         "Prima uma tecla para sair.");

                refresh();
                getch();

                jogoAtivo = 0;
            }
        }
        else
        {
            verificarComida();
        }

        mostrarTabuleiro();

        if (dificuldade == 1)
        {
            napms(200);
        }
        else if (dificuldade == 2)
        {
            napms(150);
        }
        else
        {
            napms(100);
        }
    }

    endwin();
}