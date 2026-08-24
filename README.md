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

main.c
game.c
game.h
snake.c
snake.h
board.c
board.h
world.c
world.h
menu.c
menu.h
extras.c
extras.h
README.md
log.md
.gitignore
highscore.txt

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
