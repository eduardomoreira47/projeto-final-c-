# C-Snake

## Descrição

C-Snake é um jogo desenvolvido em linguagem C, baseado num jogo Snake que desenvolvi anteriormente no Scratch.

O objetivo é controlar a cobra, apanhar comida, aumentar a pontuação e evitar os limites do tabuleiro e os obstáculos.

## Funcionalidades

* 3 níveis de dificuldade
* Movimento e crescimento da cobra
* Comida aleatória
* Obstáculos
* Sistema de vidas
* Sistema de pontuação
* High Score
* Velocidade variável
* Pausa
* Menu principal

## Controlos

W - Cima
S - Baixo
A - Esquerda
D - Direita
P - Pausa
Q - Sair

## Estrutura

projeto-final-c/

Estrutura

main.c - inicia o programa
game.c / game.h - controla o jogo
snake.c / snake.h - controla a cobra
board.c / board.h - desenha o tabuleiro
world.c / world.h - gere comida e obstáculos
menu.c / menu.h - gere os menus
extras.c / extras.h - funcionalidades extra
README.md - documentação do projeto
log.md - registo do desenvolvimento
.gitignore - ficheiros ignorados pelo Git
highscore.txt - guarda o recorde

## Conceitos utilizados

Funções
Arrays
Matrizes
Struct
Ciclos for e while
if / else
switch
Ficheiros
Programação modular

## Compilação

gcc main.c game.c snake.c board.c world.c menu.c extras.c -o csnake.exe -lncursesw

## Execução

./csnake.exe
