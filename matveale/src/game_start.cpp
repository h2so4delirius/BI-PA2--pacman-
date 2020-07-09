#include"game_start.hpp"

using namespace std;
game_start::game_start(vector<vector<char>>field,int pointes,int complexity,int sec,int Berserk){
    berserk=false;
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    noecho();
    this->pointes=pointes-1;
    this->sec=sec;
    this->Berserk=Berserk;
    this->complexity=complexity;
    this->field=field;
    this->copy=field;
}

void game_start::start(){
    int complexity_s=0;
    shared_ptr<player> pl=make_shared<player>(1,1);
    shared_ptr<ghoust_1> gh_1=make_shared<ghoust_1>(12,9);
    shared_ptr<ghoust_2> gh_2=make_shared<ghoust_2>(12,9);
    shared_ptr<ghoust_3> gh_3=make_shared<ghoust_3>(12,9);
    pac.push_back(pl);
    
    for(unsigned int i=0;i<field.size();i++){
        vector<char>p;
        for(unsigned int j=0;j<field[0].size();j++){
            p.push_back('9');
        }
        prev_copy.push_back(p);
        p.clear();
        
    }
    int lifes=2;
    char c;
    int wathe=0;
    prnt(lifes,false,0);

    while(1){
        bool end_game=false;
        prev_copy=field;
        if(wathe==0){
            field[11][12]=' ';
            pac.push_back(gh_2);
        }
        if(wathe==40){
            field[11][11]=' ';
            pac.push_back(gh_1);
        }
        if(wathe==80){
            field[11][13]=' ';
            pac.push_back(gh_3);
        }   
        if((c=getch())>0){
            if(c=='t')
            {
                prnt_l();
                break;
            }
            else if(c=='w'){
                pac[0]->set_direction(1);
            }
            else if(c=='a'){
                pac[0]->set_direction(2);
            }
            else if(c=='s'){
                pac[0]->set_direction(3);
            }
            else if(c=='d'){
                pac[0]->set_direction(4);
            }
            else{
                pac[0]->set_direction(-1);
            }
        }
        if(update_bonus(pac,lifes)){
            prnt_v();
            break;
        }
        if(update(pac,lifes,end_game,complexity_s,wathe,pl)){
            prnt_l();
            break;
        }

        
    }
    getch();
    keypad(stdscr, FALSE);
    nodelay(stdscr, FALSE);
    return;
}



bool game_start::update(vector<shared_ptr<father>>&pac,int &lifes,bool&end_game,int &complexity_s,int &wathe,shared_ptr<player>&pl){
        for(unsigned int i=1;i<pac.size();i++){
            if(pac[0]->get_position_y()==pac[i]->get_position_y()&&pac[0]->get_position_x()==pac[i]->get_position_x()&&!berserk){
                    end_game=true;
            }
            if(pac[0]->get_position_y()==pac[i]->get_position_y()&&pac[0]->get_position_x()==pac[i]->get_position_x()&&berserk){
                pac[i]->set_position(12,9);
            }
        }
        if(complexity_s==complexity){
            for(unsigned int i=1;i<pac.size();i++){
                pac[i]->set_pacmen(pac[0]->get_position_x(),pac[0]->get_position_y());
            }
            for(unsigned int i=1;i<pac.size();i++){
                pac[i]->update(field,copy);
            }
                complexity_s=0;
        }
        else{
            complexity_s++;
        }
        for(unsigned int i=1;i<pac.size();i++){
            if(pac[0]->get_position_y()==pac[i]->get_position_y()&&pac[0]->get_position_x()==pac[i]->get_position_x()&&!berserk){
                end_game=true;
            }
            if(pac[0]->get_position_y()==pac[i]->get_position_y()&&pac[0]->get_position_x()==pac[i]->get_position_x()&&berserk){
                pac[i]->set_position(12,9);
            }
        }
        if(end_game){
            if(lifes==0){
                return true;
            }
            else{
                lifes--;
                pac[0]->set_position(1,1);
                field=copy;
                field[1][1]='p';
                for(unsigned int i=1;i<pac.size();i++){
                    pac[i]->set_position(12,9);
                }
                pac.clear();
                pac.push_back(pl);
                wathe=-1;
            }
        }
        wathe++;
        prnt(lifes,berserk,time);
        usleep(sec);  
        return false;  
}




bool game_start::update_bonus(vector<shared_ptr<father>>&pac,int &lifes){
    int end=pac[0]->update(field,copy);
    if(pointes==0)
    return true;
    if(end==1){
        pointes--;
        }
    else if(end==2){
        berserk=true;
        time=Berserk;
    }
    else if(end==3){
        lifes++;
    }
    if(time>0){
        time--;
    }
    else{
        berserk=false;
    }   
    return false;
}






void game_start::prnt(int lifes,bool berserk,int time){
    init_pair(1, COLOR_WHITE, COLOR_YELLOW);
    init_pair(6, COLOR_WHITE, COLOR_BLUE);
    init_pair(8, COLOR_MAGENTA,COLOR_RED);
    unsigned int ii=0;    
    for(auto i:field){
        unsigned int jj=0;
        for(auto j:i){
            if(ii<prev_copy.size()&&jj<prev_copy[0].size()&&j!=prev_copy[ii][jj]){
                    if(j=='#'){
                        attron(COLOR_PAIR(8));
                        mvwprintw(stdscr,ii,jj, "#");
                        attroff(COLOR_PAIR(8));
                    }
                    else if(j=='@'){
                        attron(COLOR_PAIR(6));
                        mvwprintw(stdscr,ii,jj, "@");
                        attroff(COLOR_PAIR(6));
                    }
                    else if(j=='0'){
                        attron(COLOR_PAIR(6));
                        mvwprintw(stdscr,ii,jj, "0");
                        attroff(COLOR_PAIR(6));
                    }
                    else if(j=='&'){
                        attron(COLOR_PAIR(6));
                        mvwprintw(stdscr,ii,jj, "&");
                        attroff(COLOR_PAIR(6));
                    }
                    else if(j=='p'){
                        attron(COLOR_PAIR(1));
                        mvwprintw(stdscr,ii,jj, "p");
                        attroff(COLOR_PAIR(1));
                    }
                    else{
                        mvwprintw(stdscr,ii,jj,"%c",j);
                    }
            }
              jj++;      
            }
            ii++;
        }
     
    string str="lifes:";
    unsigned int go_str;
    for(go_str=0;go_str<str.size();go_str++){
        mvwprintw(stdscr,ii,go_str,"%c",str[go_str]);
    }
    mvwprintw(stdscr,ii,go_str,"%d",lifes);
    ii++;
    str="points for victory:";
    for(go_str=0;go_str<str.size();go_str++){
        mvwprintw(stdscr,ii,go_str,"%c",str[go_str]);
    }
     mvwprintw(stdscr,ii,go_str,"%d",pointes);
    str="berserk:";
    ii++;
    for(go_str=0;go_str<str.size();go_str++){
        mvwprintw(stdscr,ii,go_str,"%c",str[go_str]);
    }
    if(berserk){
        mvwprintw(stdscr,ii,go_str,"%d",time);
    }
    refresh();
    return;
}





void game_start::prnt_v(){
clear();
printw("\n");
printw("\n");
printw("\n");
printw("\n");
printw("       _      _\n");                 
printw("      (_)    | | \n");                 
printw("__   ___  ___| |_ ___  _ __ _   _\n"); 
printw("\\ \\ / / |/ __| __/ _ \\| '__| | | |\n");
printw(" \\ V /| | (__| || (_) | |  | |_| |\n");
printw("  \\_/ |_|\\___|\\__\\___/|_|   \\__, |\n");
printw("                             __/ |\n");
printw("                            |___/ \n");
refresh();
usleep(5000000);

return;
}
void game_start::prnt_l(){
clear();
printw("\n");
printw("\n");
printw("\n");
printw("\n");

printw(" _ \n");                    
printw("| | \n");                   
printw("| | ___  ___  ___ _ __ \n");
printw("| |/ _ \\/ __|/ _ \\ '__|\n");
printw("| | (_) \\__ \\  __/ |   \n");
printw("|_|\\___/|___/\\___|_|   \n");



refresh();
usleep(5000000);
    return;
}