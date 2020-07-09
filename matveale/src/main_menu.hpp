
#ifndef main_menu_hpp
#define main_menu_hpp

#include<ncurses.h>
#include<string>
#include<fstream>
#include<vector>
//#include"prnt.hpp"
#include"game_start.hpp"
/**
 *@brief The central class that represents main menu - main_menu
 */
class main_menu{
    public:
        /**
        *@brief default constructor that initialising new main_manu
        */
        main_menu();
        /**
        *@brief main method of class
        */
        void start();
        /**
        *@brief start game
        */
        void start_lvl();
        /**
        *@brief main method of class that update all objects
        */
        void update();
        /**
        *@brief displays the menu
        */
        void prnt();
    private:
    char field[20][50];
    int position=0;
    //prnt p;
};
#endif