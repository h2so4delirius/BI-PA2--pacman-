#ifndef ghoust_1_hpp
#define ghoust_1_hpp
#include<vector>
#include"father.hpp"

using namespace std;
/**
 *@brief The class that represents child of father - ghoust_1
 */
class ghoust_1 :public father{
public:
    /**
    *@brief default constructor that initialising new ghost_1
    *@param[in] unsigned int x   position x
    *@param[in] unsigned int y   position y 
    */
    ghoust_1(int position_x,int position_y);
    /**
    *@brief update position of ghost
    *@param[in] vector<vector<char>>&field   game field
    *@param[in] vector<vector<char>>&copy 
    *@return always return 0
    */
    int update(vector<vector<char>>&field,vector<vector<char>>&copy);
    /**
    *@brief search for a path to the player
    *@param[in] vector<vector<char>>&field   game field
    */
    void bfs(vector<vector<char>>&field);
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
private:
    int position_x, position_y;
    int direction=-1;
    vector<pos>road_to_pakmen;
    unsigned int pacman_x=1;
    unsigned int pacman_y=1;
    bool ghost_is_aktive=false;
};
#endif