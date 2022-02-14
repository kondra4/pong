#include <stdio.h>

void display();

char ver = '-';
char hor = '|';
char space = ' ';
char pl_1 = ']';
char pl_2 = '[';
char ball = '*';
int pl1_x = 1;
int pl1_y = 12;
int pl2_x = 78;
int pl2_y = 12;
int ball_x = 39;
int ball_y = 12;
int score1, score2;
char code;

int main() {
    int pl1_move = 1;
    int pl2_move = -1;
    int ball_naprx = 1;
    int ball_napry = 0;
    display();
    while (score1 < 21 && score2 < 21) {
    code = getchar();
// Переход хода при нажатии на пробел
        if (code == ' ') {
            pl1_move = pl1_move * (-1);
            pl2_move = pl2_move * (-1);
            display();
            }
        // Движение первого игрока
        if (pl1_move == 1) {
            if (code == 'z' && pl1_y < 22) {
                pl1_y++;
                pl1_move = pl1_move * (-1);
                pl2_move = pl2_move * (-1);
                display();
                }
            if (code == 'a' && pl1_y > 2) {
                pl1_y--;
                pl1_move = pl1_move * (-1);
                pl2_move = pl2_move * (-1);
                display();
                }
        }
        // Движение второго игрока
        if (pl2_move == 1) {
            if (code == 'm' && pl2_y < 22) {
                pl2_y++;
                pl1_move = pl1_move * (-1);
                pl2_move = pl2_move * (-1);
                display();
                }
            if (code == 'k' && pl2_y > 2) {
                pl2_y--;
                pl1_move = pl1_move * (-1);
                pl2_move = pl2_move * (-1);
                display();
                }
        }
// Проверка на столкновение
// 1. С ракетками
// С серединой ракетки правого (х изменяется а у не меняется)
            if (ball_x + 1 == pl2_x && ball_y == pl2_y) {
            ball_naprx = - 1;
            ball_napry = 0;
        }
// С серединой ракетки левого
            if (ball_x - 1 == pl1_x && ball_y == pl1_y) {
            ball_naprx = + 1;
            ball_napry = 0;
        }
// С нижней частью ракетки правого
            if (ball_x + 1 == pl2_x && ball_y == pl2_y - 1) {
            ball_naprx = - 1;
            ball_napry = - 1;
        }
// C нижней частью ракетки левого
            if (ball_x - 1 == pl1_x && ball_y == pl1_y - 1) {
            ball_naprx = + 1;
            ball_napry = - 1;
        }
// C верхней частью ракетки правого
            if (ball_x + 1 == pl2_x && ball_y == pl2_y + 1) {
            ball_naprx = - 1;
            ball_napry = + 1;
        }
// C верхней частью ракетки левого
            if (ball_x - 1 == pl1_x && ball_y == pl1_y + 1) {
            ball_naprx = + 1;
            ball_napry = + 1;
        }
// 2. Столкновение со стенкой
            if (ball_y + 1 == 24) {
            ball_napry = - 1;
        }
            if (ball_y - 1 == 0) {
            ball_napry = + 1;
        }
// 3. Гол
            if (ball_x +1 == 79) {
                score1++;
                pl1_x = 1;
                pl1_y = 12;
                pl2_x = 78;
                pl2_y = 12;
                ball_x = 3;
                ball_y = 12;
                ball_naprx = + 1;
                ball_napry = 0;
                }
            if (ball_x -1 == 0) {
                score2++;
                pl1_x = 1;
                pl1_y = 12;
                pl2_x = 78;
                pl2_y = 12;
                ball_x = 77;
                ball_y = 12;
                ball_naprx = - 1;
                ball_napry = 0;
                }
        // Движение мяча
            ball_x += ball_naprx;
            ball_y += ball_napry;
        display();
                }
            if (score1 == 21) {
                printf("\nКонец игры, поздравляю игрока слева!\n");
            }
            if (score2 == 21) {
                printf("\nКонец игры, поздравляю игрока справа!\n");
            }
}

void display() {
    for (int y = 0; y <= 24; y++) {
        for (int x = 0; x <= 80; x++) {
        if (x == 0 || x == 80)
        printf("%c", hor);
        if ((y == 0 && x > 1 && x < 80) || (y == 24 && x > 1 && x < 80))
    printf("%c", ver);

// ОТРИСОВЫВАЕМ ПУСТОЕ ПОЛЕ
        if (y != 0 && y != 24 && x != 0 && x < 79) {
        if ((x != pl1_x || y != pl1_y) &&
        (x != pl1_x || y - 1 != pl1_y) &&
        (x != pl1_x || y + 1 != pl1_y) &&
        (x != pl2_x || y != pl2_y) &&
        (x != pl2_x || y - 1 != pl2_y) &&
        (x != pl2_x || y + 1 != pl2_y)&&
        (x != ball_x || y != ball_y))
        printf("%c", space);
        }
// ОТРИСОВКА ИГРОКА 1
        if ((x == pl1_x && y == pl1_y) || (x == pl1_x && y - 1 == pl1_y) || (x == pl1_x && y + 1 == pl1_y))
            printf("%c", pl_1);
// ОТРИСОВКА ИГРОКА 2
        if ((x == pl2_x && y == pl2_y) || (x == pl2_x && y - 1 == pl2_y) || (x == pl2_x && y + 1 == pl2_y))
            printf("%c", pl_2);
// //ОТРИСОВКА МЯЧА
        if (x == ball_x && y == ball_y)
            printf("%c", ball);
// ПЕРЕХОД НА НОВУЮ СТРОКУ
            if (x == 80)
            printf("\n");
            }
            }
    printf("\t\t\tPLAYER 1: %d\tPLAYER 2: %d\n", score1, score2);
}
