// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI
//
// OK, LET'S DO IT!
//        HUMAN

#include <stdio.h>
#include <stdlib.h>

void u_dial();
int play_g();
int table(int x_rock1, int x_rock2, int x_ball);
void borders();
int ball_x(int x_ball, int vec);
int ball_y(int y_ball, int vec);
int score(int first, int second);
void navigation();


int main() {
    u_dial();
    return 0;
}

// USER'S DIALOGUE
void u_dial() {
    char quest, entr;
    char quest1 = 'y';
    int game_status;
    printf("Wazzup! Wanna play? (y/n): ");
    scanf("%c%c", &quest, &entr);
    while (quest == 'y' && quest1 == 'y' && entr == '\n') {
        game_status = play_g();
        if (game_status == 0) {
            printf("\nIT WAS A GREAT GAME! RESTART? (y/n)\n");
            scanf("%c", &quest1);
            } else if (game_status == 1) {
                printf("\nPLAYER 1 WINS! CONGRATS!\n");
                quest1 = 'f';
            } else if (game_status == 2) {
                printf("\nPLAYER 2 WINS! CONGRATS!\n");
                quest1 = 'f';
            } else if (game_status == 3) {
                printf("\nSOO.. YOU PRESSED ESC.\nMAYBE IT WAS AN ACCIDENT? (y/n): ");
                scanf("%c%c", &quest1, &entr);
            } else if (game_status == 4) {
                    play_g();
            }
        if (quest1 == 'f' && entr == '\n') {
            printf("RESTART? (y/n): ");
            scanf("%c", &quest1);
            }
        if (quest1 == 'n' && entr == '\n')
        printf("Ok, see you!\n");
    }
     if (quest == 'n' && entr == '\n')
         printf("Ok, see you!\n");
     else if (!((quest == 'n' || quest == 'y') && entr == '\n'))
         printf("Incorrect input. Try again..\n");
}

// START GAME FUNCTION
int play_g() {
    int x_rock1 = 1, x_rock2 = 80, x_ball = 40,
        y_rock1 = 14, y_rock2 = 14, y_ball = 14;  // Инициализация координат
    char in_put, ent;  // Кнопка выхода из цикла и char для Enter
    int fst_cnt = 0, sec_cnt = 0;
    int game_status = 0;  // Если 1 то выиграл первый игрок, если 2, то второй, если 3, то нажали отмену
    int vec = 1;
    ent = '\n';
    in_put = '+';
    while (in_put != 27 && in_put != 'r' && in_put != 'R' && game_status == 0) {
        printf("\n");
        switch (in_put) {
            case 'a' : {
                if (y_rock1 > 2) y_rock1--;
                break;}
            case 'A' : {
                if (y_rock1 > 2) y_rock1--;
                break;}
            case 'z' : {
                if (y_rock1 < 24) y_rock1++;
                break;}
            case 'Z' : {
                if (y_rock1 < 24) y_rock1++;
                break;}
            case 'k' : {
                if (y_rock2 > 2) y_rock2--;
                break;}
            case 'K' : {
                if (y_rock2 > 2) y_rock2--;
                break;}
            case 'm' : {
                if (y_rock2 < 24) y_rock2++;
                break;}
            case 'M' : {
                if (y_rock2 < 24) y_rock2++;
                break;}
        }
        if (in_put == 'a' || in_put == 'A' || in_put == 'z' || in_put == 'Z' || in_put == 'k' ||
            in_put == 'K' || in_put == 'm' || in_put == 'M' || in_put == ' ') {
            if (y_ball == 2 || y_ball == 26) {
                switch (vec) {
                    case 1 : vec = 4; break;
                    case 2 : vec = 3; break;
                    case 3 : vec = 2; break;
                    case 4 : vec = 1; break;
                }
            } else if ((x_ball == 2 || x_ball == 79) && (y_ball == y_rock1 ||
                        y_ball == y_rock1 + 1 || y_ball == y_rock1 + 2 || y_ball == y_rock2 ||
                        y_ball == y_rock2 + 1 || y_ball == y_rock2 + 2)) {
                switch (vec) {
                    case 1 : vec = 2; break;
                    case 2 : vec = 1; break;
                    case 3 : vec = 4; break;
                    case 4 : vec = 3; break;
                }
            } else if (x_ball == 1 || x_ball == 80) {
                if (x_ball == 1) {
                    x_ball = x_rock2 - 1;
                    y_ball = y_rock2 + 1;
                    sec_cnt++;
                } else if (x_ball == 80) {
                    x_ball = x_rock1 + 1;
                    y_ball = y_rock1 + 1;
                    fst_cnt++;
                }
            }
            x_ball = ball_x(x_ball, vec);
            y_ball = ball_y(y_ball, vec);
        }
        for (int i = 1; i <= 27; i++) {
            if (i == 1 || i == 27) {
                borders();
            } else {
                table((i < y_rock1) || (i >= y_rock1 + 3) ? 0 : x_rock1, (i < y_rock2) ||
                (i >= y_rock2 + 3) ? 0 : x_rock2, y_ball == i ? x_ball : 0);
        }
        }
        printf("\n");
        game_status = score(fst_cnt, sec_cnt);
        navigation();
        system("stty raw");  // Отключение буфериз. ввода через stdlib
        in_put = getchar();  // Ввод
        system("stty sane");  // Включение буфериз. ввода через stdlib
        printf("\033[d\033[J");  // Очистка экрана
    }
    if (in_put == 27)
        game_status = 3;
    if (in_put == 'r' || in_put == 'R')
        game_status = 4;
    return game_status;
}

// FUNCTION FOR LINES
int table(int x_rock1, int x_rock2, int x_ball) {
    char rkt = '|';
    char ball = '*';
    for (int i = 1; i <= 80; i++) {
        if (i == x_rock1 || i == x_rock2)
            printf("%c", rkt);
        else if (i == x_ball)
            printf("%c", ball);
        else
            printf(" ");
    }
    printf("\n");
    return 0;
}

// FUNCTION FOR HORISONTAL BORDERS
void borders() {
    for (int i = 1; i <= 80; i++) {
            printf("=");
    }
    printf("\n");
}

// FUNCTION FOR X AXIS MOVING OF THE BALL
int ball_x(int x_ball, int vec) {
    int x;
    if (vec == 1 || vec == 4)
        x = 0;
    else
        x = 1;
    switch (x) {
        case 0 : x_ball--; break;
        case 1 : x_ball++; break;
    }
    return x_ball;
}

// FUNCTION FOR Y AXIS MOVING OF THE BALL
int ball_y(int y_ball, int vec) {
    int y;
    if (vec == 1 || vec == 2)
        y = 0;
    else
        y = 1;
    switch (y) {
        case 0 : y_ball--; break;
        case 1 : y_ball++; break;
    }
    return y_ball;
}

// FUNCTION FOR SCORE POINTS
int score(int first, int second) {
    int indicator = 0;
    for (int i = 1; i <= 80; i++) {
        printf("+");
    }
    printf("\nPLAYER 1");
    for (int i = 1; i <= 24; i++) {
        printf(" ");
    }
    printf("| %d | -  - | %d |", first, second);
    for (int i = 1; i <= 24; i++) {
        printf(" ");
    }
    printf("PLAYER 2\n");
    for (int i = 1; i <= 80; i++) {
        printf("+");
    }
    printf("\n");
    if (first == 21)
        indicator = 1;
    else if (second == 21)
        indicator = 2;
    return indicator;
}

// FUNCTION FOR NAV INFO
void navigation() {
    printf("ESC for exit    R for restart\n");
}
