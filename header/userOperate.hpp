#ifndef USER_OPERATE
#define USER_OPERATE

#include <curses.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <thread>
#include "screen.hpp"

void arrowUp();
void arrowDown();
void arrowLeft();
void arrowRight();
static bool isPause = false;

/* ref: 
* http://www.csie.ntnu.edu.tw/~ghhwang/course_slices/OS/Curses_Usage.txt
* https://linux.die.net/man/3/keypad
*/

void listenKeyBoard(int* keyValue) {
    std::ifstream keyBoard("/dev/input/event4");
    if (keyBoard.fail()) {
        perror("Cannot read keyBoard: ");
        exit(1);
    }

    /* must only be called once in each program, clean screen */
    initscr();

    /* The echo and noecho routines control whether characters typed by the user are echoed by getch as they are typed. */
    noecho();

    // read all key event expect "Crtl, Delete"
    cbreak();

    /*
    * The keypad option enables the keypad of the user's terminal. 
    * If enabled (bf is TRUE), the user can press a function key (such as an arrow key) and wgetch returns a single value representing the function key, 
    * as in KEY_LEFT. If disabled (bf is FALSE), curses does not treat function keys specially and the program has to interpret the escape sequences itself. 
    * If the keypad in the terminal can be turned on (made to transmit) and off (made to work locally),
    * turning on this option causes the terminal keypad to be turned on when wgetch is called. The default value for keypad is false.  
    */
    keypad(stdscr, true);
    nodelay(stdscr, true);
    refresh();

    while (true) {
        usleep(10);
        (*keyValue) = getch();

        if ((*keyValue) == KEY_UP) {
            arrowUp();
        } else if ((*keyValue) == KEY_DOWN) {
            arrowDown();
        } else if ((*keyValue) == KEY_LEFT) {
            arrowLeft();
        } else if ((*keyValue) == KEY_RIGHT) {
            arrowRight();
        } else if (isalnum((*keyValue))) {
            //addch(char(*keyValue));
        } else if ((*keyValue) == ' ') {
            // pause/resume
            isPause = !isPause;
        } else
            continue;

        /*  mvaddch(y, x, ch);
                在 (x,y) 上顯示某個字元
                相當於呼叫 move(y,x);addch(ch);
                如何在螢幕上顯示字元 @ http://www.csie.ntnu.edu.tw/~ghhwang/course_slices/OS/Curses_Usage.txt
        */
    }
    endwin();
}

//move the Object, dont move the map!
void arrowUp() {
    if (!isPause) {
    }
}
void arrowDown() {
    if (!isPause) {
    }
}
void arrowLeft() {
    if (!isPause) {
    }
}
void arrowRight() {
    if (!isPause) {
    }
}

#endif