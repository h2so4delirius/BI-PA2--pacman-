#include"player.hpp"

using namespace std;




void player::set_pacmen(unsigned int x,unsigned int y){
    return;
}

void player::set_position(unsigned int x,unsigned int y){
    this->position_x=x;
    this->position_y=y;  
}


player::player(int position_x,int position_y){
    this->position_x=position_x;
    this->position_y=position_y;
}

unsigned int player::get_position_x()
{
    return position_x;
}
unsigned int player::get_position_y()
{
    return position_y;
}
void player::set_direction(int direction)
{
    this->direction=direction;
}
//#  1 #
//2 -1 4
//#  3 #
int player::update(vector<vector<char>>&field,vector<vector<char>>&copy){
    int res=0;
    if(direction==1){
        if(position_y==0){
            main_direction=1;
        }
        else if(field[position_y-1][position_x]!='#'){
            main_direction=1;
        }
    }
    else if(direction==2){
        if(position_x==0){
            main_direction=2;
        }
        else if(field[position_y][position_x-1]!='#'){
            main_direction=2;
        }
    }
    else if(direction==3){
        if(position_y==field.size()-1){
            main_direction=3;
        }
        else if(field[position_y+1][position_x]!='#'){
            main_direction=3;
        }
    }
    else if(direction==4){
        if(position_x==field[0].size()-1){
            main_direction=4;
        }
        else if(field[position_y][position_x+1]!='#'){
            main_direction=4;
        }
    }


    if(main_direction==1){
        if(position_y==0){
            field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_y=field.size()-1;
            if(field[field.size()-1][position_x]=='.'){
                copy[field.size()-1][position_x]=' ';
                res=1;
            }
            else if(field[field.size()-1][position_x]=='B'){
                copy[field.size()-1][position_x]=' ';
                res=2;
            }
            else if(field[field.size()-1][position_x]=='L'){
                copy[field.size()-1][position_x]=' ';
                res=3;
            }
            field[field.size()-1][position_x]='p';
        }
        else if(field[position_y-1][position_x]!='#'){
             field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_y=position_y-1;
            if(field[position_y][position_x]=='.'){
                copy[position_y][position_x]=' ';
                res=1;
            }
            else if(field[position_y][position_x]=='B'){
                copy[position_y][position_x]=' ';
                res=2;
            }
            else if(field[position_y][position_x]=='L'){
                copy[position_y][position_x]=' ';
                res=3;
            }
            field[position_y][position_x]='p';           
        }
    }
    if(main_direction==2){
        if(position_x==0){
            field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_x=field[position_y].size()-1;
            if(field[position_y][field[0].size()-1]=='.'){
                copy[position_y][field[0].size()-1]=' ';
                res=1;
            }
            else if(field[position_y][field[0].size()-1]=='B'){
                copy[position_y][field[0].size()-1]=' ';
                res=2;
            }
            else if(field[position_y][field[0].size()-1]=='L'){
                copy[position_y][field[0].size()-1]=' ';
                res=3;
            }
            field[position_y][field[0].size()-1]='p';
        }
        else if(field[position_y][position_x-1]!='#'){
             field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_x=position_x-1;
            if(field[position_y][position_x]=='.'){
                copy[position_y][position_x]=' ';
                res=1;
            }
            else if(field[position_y][position_x]=='B'){
                copy[position_y][position_x]=' ';
                res=2;
            }
            else if(field[position_y][position_x]=='L'){
                copy[position_y][position_x]=' ';
                res=3;
            }
            field[position_y][position_x]='p';           
        }
    }
    if(main_direction==3){
        if(position_y==field.size()-1){
            field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_y=0;
            if(field[0][position_x]=='.'){
                copy[0][position_x]=' ';
                res=1;
            }
            else if(field[0][position_x]=='B'){
                copy[0][position_x]=' ';
                res=2;
            }
            else if(field[0][position_x]=='L'){
                copy[0][position_x]=' ';
                res=3;
            }
            field[0][position_x]='p';
        }
        else if(field[position_y+1][position_x]!='#'){
             field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_y=position_y+1;
            if(field[position_y][position_x]=='.'){
                copy[position_y][position_x]=' ';
                res=1;
            }
            else if(field[position_y][position_x]=='B'){
                copy[position_y][position_x]=' ';
                res=2;
            }
            else if(field[position_y][position_x]=='L'){
                copy[position_y][position_x]=' ';
                res=3;
            }
            field[position_y][position_x]='p';           
        }
    }
    if(main_direction==4){
        if(position_x==field[position_y].size()-1){
            field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_x=0;
            if(field[position_y][0]=='.'){
                copy[position_y][0]=' ';
                res=1;
            }
            else if(field[position_y][0]=='B'){
                copy[position_y][0]=' ';
                res=2;
            }
            else if(field[position_y][0]=='L'){
                copy[position_y][0]=' ';
                res=3;
            }
            field[position_y][0]='p';
        }
        else if(field[position_y][position_x+1]!='#'){
             field[position_y][position_x]=' ';
            if(copy[position_y][position_x]=='p'){
                copy[position_y][position_x]=' ';
            }
            position_x=position_x+1;
            if(field[position_y][position_x]=='.'){
                copy[position_y][position_x]=' ';
                res=1;
            }
            else if(field[position_y][position_x]=='B'){
                copy[position_y][position_x]=' ';
                res=2;
            }
            else if(field[position_y][position_x]=='L'){
                copy[position_y][position_x]=' ';
                res=3;
            }
            field[position_y][position_x]='p';           
        }
    }
    return res;
}