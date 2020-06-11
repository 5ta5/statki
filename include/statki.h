#pragma once
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

//inline bool operator==(const vector2 & lhs, const vector2 & rhs){ return !(lhs == rhs); }
bool operator==(const vector2 & a, const vector2 & b);


//VIRTUAL--------------------------------------------------------
class obj{
public:
    int x;
    int y;
    vector2 kierunek;
    int hp;
    //virtual string thype()=0;
    //virtual string texture_path()=0;
   
    //void draw(level *lvl, int x, int y, string tp, float alpha=1, float angle=0);
    virtual string texture_path()=0;
    void render(level *lvl/*, string tp, float alpha, float angle*/, bool visible);
    virtual string thype()=0;
    
    obj(){};
    
    obj(int inx, int iny, vector2 k){
        x=inx;
        y=iny;
        kierunek=k;
    };
    
};

ostream & operator <<( ostream & s, const obj & o );

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
    //bool trafienia[10];//to se zrob XD
    //virtual vector2 rozmiar()=0;
    virtual string texture_path()=0;
    virtual int rozmiar();
    string thype(){return("statek");}
    
    /*
    public void dmg(int inx, int iny){
        int dyst=
        trafienia[dyst]=true;
    }
    public void dmg(){
        
    }
    */
    
};


class ponton: public statek{
public:
    string texture_path();
    int rozmiar(){return(1);};
    
    ponton(){
        hp=1;
    };
    ponton(int inx, int iny, vector2 k){
        hp=1;
        x=inx;
        y=iny;
        kierunek=k;
    };
};


class kuter: public statek{
public:
    string texture_path();
    int rozmiar(){return(2);};
    
    kuter(){
        hp=2;
    };
    kuter(int inx, int iny, vector2 k){
        hp=2;
        x=inx;
        y=iny;
        kierunek=k;
    };
};


class korweta: public statek{
public:
    string texture_path();
    int rozmiar(){return(3);};
    
    korweta(){
        hp=3;
    };
    korweta(int inx, int iny, vector2 k){
        hp=3;
        x=inx;
        y=iny;
        kierunek=k;
    };
};




class level{
public:
    water woda;
    vector<obj*> statki;//obiekty
    void render(bool visible);
    
    obj *hover;
    //void rehover();
    
    trafienie traf[108];
    int l_traf=0;
    int trafienia=0;
    
    obj *matrix[12][12];
    
    sf::RenderWindow *window;
    level(sf::RenderWindow *wd){
        window=wd;
        hover=&woda;
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
    bool lmousedown=false;
    vector2 strzal();
};

class bot: public player{
public:
    vector2 strzal();
};

void dawaj_texture(level *lvl, string path, int x, int y);

void send_to_mouse_position(obj *o);
