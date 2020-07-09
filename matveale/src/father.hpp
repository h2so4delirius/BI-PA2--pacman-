#ifndef father_hpp
#define father_hpp
#include<vector>

using namespace std;
/**
 *@brief abstract class - father
 */
class father{
public:
    /**
    *@brief abstract method
    *@param[in] vector<vector<char>>&field   game field
    *@param[in] vector<vector<char>>&copy 
    *@return if player take some of bonuses else return 0
    */
    virtual int update(vector<vector<char>>&field,vector<vector<char>>&copy)=0;
    /**
    *@brief abstract method
    *@return return return position y
    */
    virtual unsigned int get_position_y()=0;
    /**
    *@brief abstract method
    *@return return return position x
    */
    virtual unsigned int get_position_x()=0;
    /**
    *@brief abstract method
    *@param[in] int direction  new direction
    */
    virtual void set_direction(int direction)=0;
    /**
    *@brief abstract method
    *@param[in] unsigned int x
    *@param[in] unsigned int y       
    */
    virtual void set_pacmen(unsigned int x,unsigned int y)=0;
    /**
    *@brief abstract method
    *@param[in] unsigned int x   position x
    *@param[in] unsigned int y   position y 
    */
    virtual void set_position(unsigned int x,unsigned int y)=0;
protected:
    struct pos{
        unsigned int x;
        unsigned int y;
        int preev_direction;
    };
    struct cest{
        unsigned int x;
        unsigned int y;
        int preev_direction;
        vector<pos>road;        
    };


};
#endif