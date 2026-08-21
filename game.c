#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <ncurses/ncurses.h>
#include "game.h"

Posicao cobra[TAM_MAX] = {
    {20, 10},
    {19, 10},
    {18, 10}
};

Posicao comida;

int tamanhoCobra = 3;
int pontuacao = 0;
int vidas = 3;

void reposicionarComida()
{
    comida.x = rand() % (LARGURA - 2) + 1;
    comida.y = rand() % (ALTURA - 2) + 1;
}

void mostrarTabuleiro()
{
    int linha, coluna, i;
    int temCobra;
    int alturaTerminal, larguraTerminal;
    int inicioY, inicioX;

    getmaxyx(stdscr, alturaTerminal, larguraTerminal);

    clear();

    if (alturaTerminal < ALTURA || larguraTerminal < LARGURA)
    {
        mvprintw(0, 0, "Terminal demasiado pequeno!");
        mvprintw(1, 0, "Necessario: %dx%d", LARGURA, ALTURA);
        refresh();
        return;
    }

    inicioY = (alturaTerminal - ALTURA) / 2;
    inicioX = (larguraTerminal - LARGURA) / 2;

    mvprintw(0, inicioX, "Pontuacao: %d    Vidas: %d",
             pontuacao, vidas);

    for (linha = 0; linha < ALTURA; linha++)
    {
        for (coluna = 0; coluna < LARGURA; coluna++)
        {
            temCobra = 0;

            for (i = 0; i < tamanhoCobra; i++)
            {
                if (cobra[i].x == coluna &&
                    cobra[i].y == linha)
                {
                    temCobra = 1;
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
            else
            {
                mvaddch(inicioY + linha,
                        inicioX + coluna,
                        ' ');
            }
        }
    }

    if (inicioY + ALTURA + 1 < alturaTerminal)
    {
        mvprintw(inicioY + ALTURA,
                 inicioX,
                 "W/A/S/D | Q - Sair");
    }

    refresh();
}

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
        return 1;

    return 0;
}

int verificarColisaoCorpo()
{
    int i;

    for (i = 1; i < tamanhoCobra; i++)
    {
        if (cobra[0].x == cobra[i].x &&
            cobra[0].y == cobra[i].y)
            return 1;
    }

    return 0;
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

void mostrarMenu()
{
    clear();

    mvprintw(3, 10, "========================");
    mvprintw(4, 10, "        C-SNAKE");
    mvprintw(5, 10, "========================");

    mvprintw(8, 15, "1 - Jogar");
    mvprintw(9, 15, "2 - Sair");

    mvprintw(12, 10, "Escolha uma opcao:");

    refresh();
}

void iniciarJogo()
{
    int tecla;
    char direcao = 'd';
    int jogoAtivo = 1;

    srand(time(NULL));

    pontuacao = 0;
    vidas = 3;
    tamanhoCobra = 3;

    reiniciarCobra();
    reposicionarComida();

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
            break;

        if (tecla == '2' ||
            tecla == 'q' ||
            tecla == 'Q')
        {
            endwin();
            return;
        }
    }

    nodelay(stdscr, TRUE);

    while (jogoAtivo)
    {
        tecla = getch();

        if (tecla == 'w' ||
            tecla == 'W' ||
            tecla == KEY_UP)
            direcao = 'w';

        else if (tecla == 's' ||
                 tecla == 'S' ||
                 tecla == KEY_DOWN)
            direcao = 's';

        else if (tecla == 'a' ||
                 tecla == 'A' ||
                 tecla == KEY_LEFT)
            direcao = 'a';

        else if (tecla == 'd' ||
                 tecla == 'D' ||
                 tecla == KEY_RIGHT)
            direcao = 'd';

        else if (tecla == 'q' ||
                 tecla == 'Q')
        {
            jogoAtivo = 0;
            continue;
        }

        moverCobra(direcao);

        if (verificarColisao() ||
            verificarColisaoCorpo())
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
                mostrarTabuleiro();

                nodelay(stdscr, FALSE);

                mvprintw(ALTURA + 2, 0, "GAME OVER!");
                mvprintw(ALTURA + 3, 0,
                         "Pontuacao final: %d",
                         pontuacao);
                mvprintw(ALTURA + 5, 0,
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

        usleep(150000);
    }

    endwin();
}