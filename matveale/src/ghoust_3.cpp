#include"ghoust_3.hpp"
using namespace std;
//# 1 #
//2-1 4
//# 3 #




void ghoust_3::set_position(unsigned int x,unsigned int y){
    this->position_x=x;
    this->position_y=y;  
}

void ghoust_3::set_pacmen(unsigned int x,unsigned int y){
    this->pacman_x=x;
    this->pacman_y=y;
    return;
}

unsigned int ghoust_3::get_position_y(){
    return position_y;
}


unsigned int ghoust_3::get_position_x(){
    return position_x;
}
void ghoust_3::set_direction(int direction){
    return;
}


ghoust_3::ghoust_3(unsigned int position_x,unsigned int position_y){
    this->position_x=position_x;
    this->position_y=position_y;
}
int ghoust_3::update(vector<vector<char>>&field,vector<vector<char>>&copy){
    unsigned int max=10000;
    int new_direction=-1;
    if(direction!=3){
        if(position_y==0){
            if(vec(position_x,field.size()-1,pacman_x,pacman_y)<max){
                max=vec(position_x,field.size()-1,pacman_x,pacman_y);
                new_direction=1;
            }
        }
        else if(field[position_y-1][position_x]!='#'){
            if(vec(position_x,position_y-1,pacman_x,pacman_y)<max){
                max=vec(position_x,position_y,pacman_x,pacman_y);
                new_direction=1;
            }   
        }
    }
    if(direction!=4){
        if(position_x==0){
            if(vec(field[0].size()-1,position_y,pacman_x,pacman_y)<max){
                max=vec(field[0].size()-1,position_y,pacman_x,pacman_y);
                new_direction=2;
            }
        }
        else if(field[position_y][position_x-1]!='#'){
            if(vec(position_x-1,position_y,pacman_x,pacman_y)<max){
                max=vec(position_x-1,position_y,pacman_x,pacman_y);
                new_direction=2;
            }   
        }
    }
    if(direction!=1){
        if(position_y==field.size()-1){
            if(vec(position_x,0,pacman_x,pacman_y)<max){
                max=vec(position_x,0,pacman_x,pacman_y);
                new_direction=3;
            }
        }
        else if(field[position_y+1][position_x]!='#'){
            if(vec(position_x,position_y+1,pacman_x,pacman_y)<max){
                max=vec(position_x,position_y+1,pacman_x,pacman_y);
                new_direction=3;
            }   
        }
    }
    if(direction!=2){
        if(position_x==field[0].size()-1){
            if(vec(0,position_y,pacman_x,pacman_y)<max){
                max=vec(0,position_y,pacman_x,pacman_y);
                new_direction=4;
            }
        }
        else if(field[position_y][position_x+1]!='#'){
            if(vec(position_x+1,position_y,pacman_x,pacman_y)<max){
                max=vec(position_x+1,position_y,pacman_x,pacman_y);
                new_direction=4;
            }   
        }
    }
    direction=new_direction;
    move(field,copy);
    return 0;
}



void ghoust_3::move(vector<vector<char>>&field,vector<vector<char>>&copy){
    if(direction==1){
        if(position_y==0){
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=field.size()-1;
            field[position_y][position_x]='&';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=position_y-1;
            field[position_y][position_x]='&';    
        }
    }
    else if(direction==2){
         if(position_x==0){
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=field[0].size()-1;
            field[position_y][position_x]='&';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=position_x-1;
            field[position_y][position_x]='&';       
        } 
    }
    else if(direction==3){
         if(position_y==field.size()-1){
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=0;
            field[position_y][position_x]='&';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=position_y+1;
            field[position_y][position_x]='&';       
        }  
    }
    else if(direction==4){
           if(position_x==field[0].size()-1){
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=0;
            field[position_y][position_x]='&';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=position_x+1;
            field[position_y][position_x]='&';       
        }    
    }

return;
}


unsigned int ghoust_3::vec(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2){
    unsigned int res_1;
    unsigned int res_2;
    if(x1>x2){
        res_1=x1-x2;
    }
    else{
       res_1=x2-x1; 
    }
    if(y1>y2){
        res_2=y1-y2;
    }
    else{
       res_2=y2-y1; 
    }
    unsigned int res=res_1+res_2;
    return res;
}

