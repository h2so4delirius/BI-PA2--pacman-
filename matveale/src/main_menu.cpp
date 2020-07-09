#include"main_menu.hpp"

using namespace std;

main_menu::main_menu(){
    for(unsigned int i=0;i<20;i++){
        for(unsigned int j=0;j<50;j++){
        field[i][j]=' ';
        }
    }
        string m_1="<<new game>>";
        string m_2="   exit     ";
        for(unsigned int i=0;i<m_1.size();i++){
            field[12][20+i]=m_1[i];
        }
        for(unsigned int i=0;i<m_2.size();i++){
            field[14][20+i]=m_2[i];
        }

}
void main_menu::start(){
    
    clear();
    char get;
    //p.get_wind(&field);
    prnt();
    while(true){
        get=getch();
        if(get=='w'){
            position--;
        }
        else if(get=='s'){
            position++;
        }
        if(position<0){position=1;}
        else if(position>1){position=0;}
        if(get=='\n'&&position==1){return;}
        else if(get=='\n'&&position==0){start_lvl();}
        this->update();
        prnt();
    }
    return;
}

void main_menu::update(){
    if(position==1){
        string m_1="  new game  ";
        string m_2="<< exit   >>";
        for(unsigned int i=0;i<m_1.size();i++){
            field[12][20+i]=m_1[i];
        }
        for(unsigned int i=0;i<m_2.size();i++){
            field[14][20+i]=m_2[i];
        }
    }
    else{
        string m_1="<<new game>>";
        string m_2="   exit     ";
        for(unsigned int i=0;i<m_1.size();i++){
            field[12][20+i]=m_1[i];
        }
        for(unsigned int i=0;i<m_2.size();i++){
            field[14][20+i]=m_2[i];
        }
    }
    return;
}


void main_menu::start_lvl(){

    vector<vector<char>>pop;
    
    char p;
    ifstream fin("./src/lvl/1.txt");
    ifstream start("./src/lvl/start.txt");
    int complexity;
    int berserk;
    int time;
    start>>complexity;
    start>>berserk;
    start>>time;
    clear();
    int i=0;
    vector<char>k;
    int point=0;
    pop.push_back(k);
    while(fin>>p){
        
        if(p=='!'){
            pop.push_back(k);
            i++;
        }
        else if(p=='o'){
            pop[i].push_back('.');
            point++;
        }
        else{
            pop[i].push_back(p);
        }
    }
    fin.close();
    start.close();
    game_start go(pop,point,complexity,time,berserk);
    go.start();
}


void main_menu::prnt(){
    clear();
    for(unsigned int i=0;i<20;i++){
        for(unsigned int j=0;j<50;j++){
            printw("%c",field[i][j]);
        }
    printw("\n");
    }
}



