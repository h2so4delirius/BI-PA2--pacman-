#include"ghoust_2.hpp"
using namespace std;
//# 1 #
//2-1 4
//# 3 #



void ghoust_2::set_position(unsigned int x,unsigned int y){
    this->position_x=x;
    this->position_y=y;  
}

void ghoust_2::set_pacmen(unsigned int x,unsigned int y){
    return;
}

unsigned int ghoust_2::get_position_y(){
    return position_y;
}


unsigned int ghoust_2::get_position_x(){
    return position_x;
}
void ghoust_2::set_direction(int direction){
    return;
}



ghoust_2::ghoust_2(int position_x,int position_y){
    this->position_x=position_x;
    this->position_y=position_y;
}
int ghoust_2::update(vector<vector<char>>&field,vector<vector<char>>&copy){
    vector<int>posit;
    if(position_y==0){
        if(direction!=3)
        posit.push_back(1);
    }
    else if(field[position_y-1][position_x]!='#'){
        if(direction!=3)
        posit.push_back(1);      
    }
    if(position_x==0){
        if(direction!=4)
        posit.push_back(2);
    }
    else if(field[position_y][position_x-1]!='#'){
        if(direction!=4)
        posit.push_back(2);      
    }
    if(position_y==field.size()-1){
        if(direction!=1)
        posit.push_back(3);
    }
    else if(field[position_y+1][position_x]!='#'){
        if(direction!=1)
        posit.push_back(3);      
    }
    if(position_x==field[0].size()-1){
        if(direction!=2)
        posit.push_back(4);
    }
    else if(field[position_y][position_x+1]!='#'){
        if(direction!=2)
        posit.push_back(4);      
    }
    if(posit.size()!=0){
        direction= posit[rand()%posit.size()];
    }


    if(direction==1){
        if(position_y==0){
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=field.size()-1;
            field[position_y][position_x]='@';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=position_y-1;
            field[position_y][position_x]='@';       
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
            field[position_y][position_x]='@';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=position_x-1;
            field[position_y][position_x]='@';       
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
            field[position_y][position_x]='@';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_y=position_y+1;
            field[position_y][position_x]='@';       
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
            field[position_y][position_x]='@';
        }
        else{
            if(copy[position_y][position_x]==' '){
                field[position_y][position_x]=' ';
            }
            else{
                field[position_y][position_x]=copy[position_y][position_x];
            }
            position_x=position_x+1;
            field[position_y][position_x]='@';       
        }    
    }



    return 0;
}

