#include <stdio.h>
#include <ncurses/ncurses.h>
#include "game.h"
#include "extras.h"

int highScore = 0;

int mostrarPausa()
{
    int tecla;

    nodelay(stdscr, FALSE);

    clear();

    mvprintw(5, 10, "========================");
    mvprintw(6, 10, "       JOGO PAUSADO");
    mvprintw(7, 10, "========================");

    mvprintw(10, 15, "P - Continuar");
    mvprintw(11, 15, "Q - Sair");

    refresh();

    while (1)
    {
        tecla = getch();

        if (tecla == 'p' || tecla == 'P')
        {
            nodelay(stdscr, TRUE);
            return 1;
        }

        if (tecla == 'q' || tecla == 'Q')
        {
            nodelay(stdscr, TRUE);
            return 0;
        }
    }
}

void carregarHighScore()
{
    FILE *ficheiro;

    ficheiro = fopen("highscore.txt", "r");

    if (ficheiro != NULL)
    {
        fscanf(ficheiro, "%d", &highScore);
        fclose(ficheiro);
    }
    else
    {
        highScore = 0;
    }
}

void guardarHighScore()
{
    FILE *ficheiro;

    ficheiro = fopen("highscore.txt", "w");

    if (ficheiro != NULL)
    {
        fprintf(ficheiro, "%d", highScore);
        fclose(ficheiro);
    }
}

int obterHighScore()
{
    return highScore;
}

void atualizarHighScore(int pontuacao)
{
    if (pontuacao > highScore)
    {
        highScore = pontuacao;
        guardarHighScore();
    }
}