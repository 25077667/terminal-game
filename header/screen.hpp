#ifndef SCREEN_HPP
#define SCREEN_HPP

#include <sys/ioctl.h>
#include <unistd.h>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>

typedef struct {
    int row, column;

} screenInfo;

// fullMap size is the currnet window size -1, because the lase line will be the wall.

void printFullMap(char** fullMap, screenInfo screenArgs) {
    int i;
    for (int i = 0; i < screenArgs.column - 1; i++) {
        int j;
        for (j = 0; j < screenArgs.row - 1; j++) {
            mvaddch(i, j, fullMap[i][j]);
            //maybe other contents
        }
        mvaddch(i, j, '|');
        mvaddch(i, j, '\n');
    }
    for (int j = 0; j < screenArgs.row; j++) {
        mvaddch(i, j, '-');
    }
    mvaddch(i, j, '\n');
}

screenInfo initScreenInfo() {
    struct winsize ws;
    ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);
    screenInfo info;
    info.row = ws.ws_row;
    info.column = ws.ws_col;
    // maybe add more args
    return info;
}

char* genRow(int size) {}

void mapShift(char** fullMap, screenInfo screenArgs) {
    for (int i = screenArgs.column - 1; i > 1; i--) {
        memcpy(fullMap[i], fullMap[i - 1], sizeof(char) * screenArgs.row - 1);
    }
    char* newGenRow = genRow(screenArgs.row - 1);
    memcpy(fullMap[0], newGenRow, sizeof(char) * screenArgs.row - 1);
}

bool printStringXY(int _x, int _y, std::string _string) {
}

#endif