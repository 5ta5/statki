//#pragma once
#include "libs.h"

class obj;
class level;


class vector2{
public:
    int x;
    int y;
    
    vector2(int inx=0, int iny=0){
        x=inx;
        y=iny;
    }
};

//VIRTUAL--------------------------------------------------------
class obj{
public:
    int x;
    int y;
    vector2 kierunek;
    //virtual string thype()=0;
    //virtual string texture_path()=0;
   
    //void draw(level *lvl, int x, int y, string tp, float alpha=1, float angle=0);
    virtual string texture_path()=0;
    void render(level *lvl/*, string tp, float alpha, float angle*/);
    virtual string thype()=0;
};

class trafienie: public obj{
public:
    bool stan=false;
    string texture_path();
    string thype(){return("traf");}
};



class water: public obj{
public:
    string texture_path();
    string thype(){return("empty");}
};


static inline const string tex_p="../textures/";

class statek: public obj{
public:
    bool trafienia[10];//to se zrob XD
    //virtual vector2 rozmiar()=0;
    virtual string texture_path()=0;
    virtual int rozmiar();
    string thype(){return("statek");}
};


class ponton: public statek{
public:
    string texture_path();
    int rozmiar(){return(1);};
};


class kuter: public statek{
public:
    string texture_path();
    int rozmiar(){return(2);};
};


class korweta: public statek{
public:
    string texture_path();
    int rozmiar(){return(3);};
};





/*
//REAL-----------------------------------------
class empty_space: public obj{
public:
    string thype(){return(" ");};
    string texture_path(){return(tex_p+"black.png");};
    void self_draw(level *lvl, int x, int y);
};
class kuter: public rigid{
public:
    string thype(){return(" ");};
    string texture_path(){return(tex_p+"black.png");};
    void self_draw(level *lvl, int x, int y);
};
*/

class level{
public:
    water woda;
    vector<obj*> statki;//obiekty
    void render();
    
    trafienie traf[108];
    int l_traf=0;
    
    obj *matrix[12][12];
    
    sf::RenderWindow *window;
    level(sf::RenderWindow *wd){
        window=wd;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matrix[i][j]=&woda;
            }
        }
    }
    
    bool dodaj(statek *perla);//statek  int x, int y, char k, int typ
    /*
    level(){
        //cout<<"Hello\n";//DEBUG
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                matrix[i][j]=&woda;
            }
        }
        //cout<<"wsk: "<<matrix[1][1]<<"\n";//DEBUG
    }*/
    
    bool strzal(int x, int y);
    
};


class player{
public:
    virtual vector2 strzal()=0;
};

class human: public player{
public:
    vector2 strzal();
};

class bot: public player{
public:
    vector2 strzal();
};

void dawaj_texture(level *lvl, string path, int x, int y);
