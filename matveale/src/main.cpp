#include<iostream>
#include<ncurses.h>
#include"main_menu.hpp"
using namespace std;

int main(){
    initscr();
    curs_set(0);
    start_color();
    keypad(stdscr, TRUE);
    printw("up->w\ndown->s\nleft->a\nright->d\n\n\npress f to continue");
    getch();
    main_menu m;
    m.start();
    endwin();
  return 0;
}