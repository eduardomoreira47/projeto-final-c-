#include <ncurses/ncurses.h>
#include "game.h"
#include "board.h"
#include "extras.h"

void mostrarTabuleiro()
{
    int linha;
    int coluna;
    int i;
    int temCobra;
    int temObstaculo;
    int alturaTerminal;
    int larguraTerminal;
    int inicioY;
    int inicioX;

    getmaxyx(stdscr, alturaTerminal, larguraTerminal);

    erase();

    if (alturaTerminal < ALTURA ||
        larguraTerminal < LARGURA)
    {
        mvprintw(0, 0, "Terminal demasiado pequeno!");
        mvprintw(1, 0, "Necessario: %dx%d", LARGURA, ALTURA);
        refresh();
        return;
    }

    inicioY = (alturaTerminal - ALTURA) / 2;
    inicioX = (larguraTerminal - LARGURA) / 2;

    if (dificuldade == 1)
    {
        mvprintw(0, inicioX,
                 "Pontuacao: %d    Recorde: %d    Vidas: %d    Facil",
                 pontuacao,
                 obterHighScore(),
                 vidas);
    }
    else if (dificuldade == 2)
    {
        mvprintw(0, inicioX,
                 "Pontuacao: %d    Recorde: %d    Vidas: %d    Medio",
                 pontuacao,
                 obterHighScore(),
                 vidas);
    }
    else
    {
        mvprintw(0, inicioX,
                 "Pontuacao: %d    Recorde: %d    Vidas: %d    Dificil",
                 pontuacao,
                 obterHighScore(),
                 vidas);
    }

    for (linha = 0; linha < ALTURA; linha++)
    {
        for (coluna = 0; coluna < LARGURA; coluna++)
        {
            temCobra = 0;
            temObstaculo = 0;

            for (i = 0; i < tamanhoCobra; i++)
            {
                if (cobra[i].x == coluna &&
                    cobra[i].y == linha)
                {
                    temCobra = 1;
                    break;
                }
            }

            for (i = 0; i < numeroObstaculos; i++)
            {
                if (obstaculos[i].x == coluna &&
                    obstaculos[i].y == linha)
                {
                    temObstaculo = 1;
                    break;
                }
            }

            if (linha == 0 ||
                linha == ALTURA - 1 ||
                coluna == 0 ||
                coluna == LARGURA - 1)
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        '#');
            }
            else if (temCobra)
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        'O');
            }
            else if (comida.x == coluna &&
                     comida.y == linha)
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        '*');
            }
            else if (temObstaculo)
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        'X');
            }
            else
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        ' ');
            }
        }
    }

    mvprintw(inicioY + ALTURA,
             inicioX,
             "W/A/S/D | P - Pausa | Q - Sair");

    refresh();
}