
#ifndef player_hpp
#define player_hpp


#include<vector>
#include"father.hpp"



using namespace std;

/**
 *@brief The class that represents child of father - player
 */
class player :public father{
public:
    /**
    *@brief default constructor that initialising new player
    *@param[in] unsigned int x   position x
    *@param[in] unsigned int y   position y 
    */
    player(int position_x,int position_y);
    /**
    *@brief return position y
    *@return return return position y
    */
    unsigned int get_position_y();
    /**
    *@brief return position x
    *@return return return position x
    */
    unsigned int get_position_x();
    /**
    *@brief set new position of player(pacman)
    *@param[in] unsigned int x   position x
    *@param[in] unsigned int y   position y 
    */
    void set_position(unsigned int x,unsigned int y);
    /**
    *@brief set new direction of player(pacman)
    *@param[in] int direction  new direction
    */
    void set_direction(int direction);
    /**
    *@brief update position of player(pacman)
    *@param[in] vector<vector<char>>&field   game field
    *@param[in] vector<vector<char>>&copy 
    *@return if player take some of bonuses else return 0
    */
    int update(vector<vector<char>>&field,vector<vector<char>>&copy);
    /**
    *@brief empty method
    *@param[in] unsigned int x
    *@param[in] unsigned int y       
    */
    void set_pacmen(unsigned int x,unsigned int y);
private:
    unsigned int position_x,position_y;
    int direction=-1;
    int main_direction=-1;

};
#endif