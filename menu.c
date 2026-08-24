#include <ncurses/ncurses.h>
#include "menu.h"

void mostrarMenu()
{
    clear();

    mvprintw(3, 10, "========================");
    mvprintw(4, 10, "        C-SNAKE");
    mvprintw(5, 10, "========================");

    mvprintw(8, 15, "1 - Jogar");
    mvprintw(9, 15, "2 - Recorde");
    mvprintw(10, 15, "3 - Sair");

    mvprintw(13, 10, "Escolha uma opcao:");

    refresh();
}

int escolherDificuldade()
{
    int tecla;

    clear();

    mvprintw(3, 10, "========================");
    mvprintw(4, 10, "      DIFICULDADE");
    mvprintw(5, 10, "========================");

    mvprintw(8, 15, "1 - Facil");
    mvprintw(9, 15, "2 - Medio");
    mvprintw(10, 15, "3 - Dificil");

    mvprintw(13, 10, "Escolha uma opcao:");

    refresh();

    while (1)
    {
        tecla = getch();

        if (tecla == '1')
            return 1;

        if (tecla == '2')
            return 2;

        if (tecla == '3')
            return 3;
    }
}