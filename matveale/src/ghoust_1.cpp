#include"ghoust_1.hpp"
using namespace std;



void ghoust_1::set_pacmen(unsigned int x,unsigned int y){
    this->pacman_x=x;
    this->pacman_y=y;
    return;
}

ghoust_1::ghoust_1(int position_x,int position_y){
    this->position_x=position_x;
    this->position_y=position_y;
}

void ghoust_1::set_position(unsigned int x,unsigned int y){
    this->position_x=x;
    this->position_y=y;  
}



int ghoust_1::update(vector<vector<char>>&field,vector<vector<char>>&copy){


    bfs(field);
    direction=road_to_pakmen[0].preev_direction;
    road_to_pakmen.erase(road_to_pakmen.begin());
    
    if(copy[position_y][position_x]==' '){
        field[position_y][position_x]=' ';
    }
    else{
        field[position_y][position_x]=copy[position_y][position_x];
    }
    
    position_y=road_to_pakmen[0].y;
    position_x=road_to_pakmen[0].x;
    field[position_y][position_x]='0';
    return 1;
}

void ghoust_1::bfs(vector<vector<char>>&field){

    vector<pos>used;
    vector<cest>road;
    cest pop;
    pop.y=position_y;
    pop.x=position_x;
    pop.preev_direction=direction;
    road.push_back(pop);
    while(road.size()!=0){
        bool is_used=false;
        if(road[0].x==pacman_x&&road[0].y==pacman_y){
                    pos k;
                    k.x=road[0].x;
                    k.y=road[0].y;
                    road[0].road.push_back(k);
                    road_to_pakmen=road[0].road;
                    return;           
        }


        for(auto i:used){
            if(i.x==road[0].x&&i.y==road[0].y){
                is_used=true;
            }
        }

        if(is_used){
            road.erase(road.begin());
        }
        else{
            if(road[0].preev_direction!=1){
                if(road[0].y==0){

                    if(field[field.size()-1][road[0].x]!='#'){
                        cest p;
                        p.y=field.size()-1;
                        p.x=road[0].x;
                        p.preev_direction=3;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=3;
                        p.road.push_back(k);
                        road.push_back(p);
                    }
                }
                else if(field[road[0].y-1][road[0].x]!='#'){
                        cest p;
                        p.y=road[0].y-1;
                        p.x=road[0].x;
                        p.preev_direction=3;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=3;
                        p.road.push_back(k);
                        road.push_back(p); 
                }
            }
            if(road[0].preev_direction!=2){
                if(road[0].x==0){

                    if(field[road[0].y][field[0].size()-1]!='#'){
                        cest p;
                        p.y=road[0].y;
                        p.x=field[0].size()-1;
                        p.preev_direction=4;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=4;
                        p.road.push_back(k);
                        road.push_back(p);
                    }
                }
                else if(field[road[0].y][road[0].x-1]!='#'){
                        cest p;
                        p.y=road[0].y;
                        p.x=road[0].x-1;
                        p.preev_direction=4;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=4;
                        p.road.push_back(k);
                        road.push_back(p); 
                }
            }
            if(road[0].preev_direction!=3){
                if(road[0].y==field.size()-1){

                    if(field[0][road[0].x]!='#'){
                        cest p;
                        p.y=0;
                        p.x=road[0].x;
                        p.preev_direction=1;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=1;
                        p.road.push_back(k);
                        road.push_back(p);
                    }
                }
                else if(field[road[0].y+1][road[0].x]!='#'){
                        cest p;
                        p.y=road[0].y+1;
                        p.x=road[0].x;
                        p.preev_direction=1;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=1;
                        p.road.push_back(k);
                        road.push_back(p); 
                }
            }
            if(road[0].preev_direction!=4){
                if(road[0].x==field[0].size()-1){

                    if(field[road[0].y][0]!='#'){
                        cest p;
                        p.y=road[0].y;
                        p.x=0;
                        p.preev_direction=2;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=2;
                        p.road.push_back(k);
                        road.push_back(p);
                    }
                }
                else if(field[road[0].y][road[0].x+1]!='#'){
                        cest p;
                        p.y=road[0].y;
                        p.x=road[0].x+1;
                        p.preev_direction=2;
                        p.road=road[0].road;
                        pos k;
                        k.x=road[0].x;
                        k.y=road[0].y;
                        k.preev_direction=2;
                        p.road.push_back(k);
                        road.push_back(p); 
                }
            }
            if(!is_used){
                pos k;
                k.x=road[0].x;
                k.y=road[0].y;
                used.push_back(k);
                road.erase(road.begin());
            }
    }
    }
    return;
}




unsigned int ghoust_1::get_position_y(){
    return position_y;
}
unsigned int ghoust_1::get_position_x(){
    return position_x;
}
void ghoust_1::set_direction(int direction){
    return;
}
