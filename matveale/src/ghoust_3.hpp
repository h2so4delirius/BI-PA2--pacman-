#ifndef ghoust_3_hpp
#define ghoust_3_hpp
#include<vector>
#include"father.hpp"

using namespace std;

/**
 *@brief The class that represents child of father - ghoust_3
 */
class ghoust_3 :public father{
public:
    /**
    *@brief default constructor that initialising new ghost_3
    *@param[in] unsigned int x   position x
    *@param[in] unsigned int y   position y 
    */
    ghoust_3(unsigned int position_x,unsigned int position_y);
    /**
    *@brief find new position of ghost
    *@param[in] vector<vector<char>>&field   game field
    *@param[in] vector<vector<char>>&copy 
    *@return always return 0
    */
    int update(vector<vector<char>>&field,vector<vector<char>>&copy);
    /**
    *@brief update position of ghost
    *@param[in] vector<vector<char>>&field   game field
    *@param[in] vector<vector<char>>&copy 
    *@return always return 0
    */
    void move(vector<vector<char>>&field,vector<vector<char>>&copy);
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
    *@brief set new direction of ghost
    *@param[in] int direction  new direction
    */
    void set_direction(int direction);
    /**
    *@brief set position of pacman
    *@param[in] unsigned int x
    *@param[in] unsigned int y       
    */
    void set_pacmen(unsigned int x,unsigned int y);
    /**
    *@brief set new position of ghost
    *@param[in] unsigned int x
    *@param[in] unsigned int y       
    */
    void set_position(unsigned int x,unsigned int y);
    /**
    *@brief find the distance to the player
    *@param[in] unsigned int x1 x of ghost
    *@param[in] unsigned int y1 x of ghost
    *@param[in] unsigned int x2 x of player
    *@param[in] unsigned int y2 x of player
    *@return the distance to the player     
    */
    unsigned int vec(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
private:
    unsigned int position_x, position_y;
    int direction=-1;
    unsigned int pacman_x=1;
    unsigned int pacman_y=1;
};
#endif