#include "../include/statki.h"

void dawaj_texture(level *lvl, string path, int x=0, int y=0){
    sf::Sprite sprite;
    sf::Texture texture;
    sprite.setPosition(sf::Vector2f(y, x));
    if (!texture.loadFromFile(path)){
        // error...
        cout<<"ERROR\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    lvl->window->draw(sprite);
}


void level::render(){
    window->clear();
    
    dawaj_texture(this, tex_p+"moze.png");
    
    
    int istart=0;
    //if
    for(int i=istart;i<statki.size();i++){
        statki[i]->render(this);
    }
    //if(win){win}
    //print_lvl_info();
    
    window->display();
}


void level::dodaj(statek *perla){//int x, int y, char k, 
    
    //statek *perla;
    /*
    if(true){//typ
        perla=&czarna;
    }
    */
    /*
    cout<<"x: "<<x<<"   y: "<<y<<"\n";
    perla->x=x;
    perla->y=y;
    perla->kierunek=k;
    */
    //cout<<"x: "<<perla->x<<"   y: "<<perla->y<<"\n";
    statki.push_back(perla);
    for(int i=0;i<perla->rozmiar();i++){
        int xx=(perla->x)+(perla->kierunek.x*i);
        int yy=(perla->y)+(perla->kierunek.y*i);
        matrix[xx][yy]=perla;
    }
    
}

bool level::strzal(int x, int y){
    
    //cout<<"x: "<<x<<"   y: "<<y<<"\n";//DEBUG
    //cout<<matrix[x][y]->thype()<<"\n";//DEBUG
    
    //cout<<matrix[x][y]<<"\n";//DEBUG
    
    
    if(matrix[x][y]->thype()=="statek"){
        
        traf[l_traf].stan=true;
        traf[l_traf].x=x;
        traf[l_traf].y=y;
        matrix[x][y]=&traf[l_traf];
        statki.push_back(&traf[l_traf]);
        l_traf++;
        return(true);
    }else{
        if(matrix[x][y]->thype()=="empty"){
            traf[l_traf].x=x;
            traf[l_traf].y=y;
            matrix[x][y]=&traf[l_traf];
            statki.push_back(&traf[l_traf]);
            l_traf++;
        }
        return(false);
    }
    
    
}
