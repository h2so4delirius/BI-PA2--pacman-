#ifndef game_start_hpp
#define game_start_hpp


#include<vector>
#include<ncurses.h>
#include<unistd.h>
#include<string>
#include <memory>
#include"player.hpp"
#include"ghoust_1.hpp"
#include"ghoust_2.hpp"
#include"ghoust_3.hpp"
#include"father.hpp"

using namespace std;
/**
 *@brief class responsible for the game mechanics - game_start
 */
class game_start{
    public:
    /**
    *@brief default constructor that initialising - game_start
    *@param[in] vector<vector<char>>field   game field
    *@param[in] int pointes   pointes in game
    *@param[in] int complexity  complexity of game 
    *@param[in] int sec   game speed 
    *@param[in] int Berserk   the duration of invulnerability
    */
    game_start(vector<vector<char>>field,int pointes,int complexity,int sec,int Berserk);
    /**
    *@brief main method
    */
    void start();
    /**
    *@brief displays the game
    */
    void prnt(int lifes,bool berserk,int time);
    /**
    *@brief displays lose if you lose
    */
    void prnt_v();
    /**
    *@brief displays win if you win
    */
    void prnt_l();
    /**
    *@brief update all bonus 
    *@param[in] vector<shared_ptr<father>>&pac   vector of ghost and player
    *@param[in] int &lifes  lifes of player
    *@return true if player win
    */    
    bool update_bonus(vector<shared_ptr<father>>&pac,int &lifes);
    /**
    *@brief update ghost and player 
    *@param[in] vector<shared_ptr<father>>&pac   vector of ghost and player
    *@param[in] int &lifes  lifes of player
    *@param[in] bool&end_game  is the player alive
    *@param[in] int &complexity_s Ghost movement if complexity == complexity_s
    *@param[in] int &wathe loop counter in the game
    *@param[in] shared_ptr<player>&pl class player
    *@return true if player lose
    */
    bool update(vector<shared_ptr<father>>&pac,int &lifes,bool&end_game,int &complexity_s,int &wathe,shared_ptr<player>&pl);
    private:
    int complexity=0;
    int pointes;
    vector<vector<char>>field;
    vector<vector<char>>copy;
    vector<vector<char>>prev_copy;
    vector<shared_ptr<father>>pac;
    bool berserk;
    int time=0;
    int Berserk;
    int sec;
};
#endif