#include "../include/statki.h"

void obj::render(level *lvl/*, float alpha, float angle*/, bool visible=false){
    //visible=true;//tmp
    if(!(visible==false && this->thype()=="statek" && hp>0)){
        if(this->thype()=="statek"){
            //cout<<"HP: "<<hp<<"\n";//DEBUG
        }
    
    
    //cout<<"Fajny Jestem!\n";//DEBUG
    sf::Sprite sprite;
    sf::Texture texture;
    int scale=100;
    /*int scale=lvl->nice_scale;
    sprite.setScale(sf::Vector2f(0.01f*scale, 0.01f*scale));*/
    
    sprite.setColor(sf::Color(255, 255, 255, 255));
    
    
    //sf::Transform transform;
    int angle=0;
    int anglex=0;
    int angley=0;
    if(kierunek.x==-1){
        angle=2;
        anglex=1;
        angley=1;
    }
    if(kierunek.y==-1){
        angle=1;
        angley=1;
    }
    if(kierunek.y==1){
        angle=3;
        anglex=1;
    }
    //transform.rotate(angle*90, (x+0.5)*scale, (y+0.5)*scale);
    
    
    
    //dawaj_texture(lvl, tex_p+"eee.png", (x+0.5)*scale, (y+0.5)*scale);
    
    sprite.setPosition(sf::Vector2f(scale*(y+angley), scale*(x+anglex)));//+lvl.offset
    sprite.setRotation(90*angle);
    //cout<<"scale: "<<scale<<"    x: "<<scale*x<<"    y: "<<scale*y;//DEBUG
    if (!texture.loadFromFile(texture_path())){
        // error...
        cout<<"ERROR\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    //lvl->window->draw(sprite, transform);
    lvl->window->draw(sprite);
    //cout<<"Bardzo Fajny!\n";//DEBUG
    //return(true);
    }
};


string trafienie::texture_path(){
    if(stan==true){
        return(tex_p+"kabum.png");
    }else{
        return(tex_p+"plum.png");
    }
}

string water::texture_path(){
    return(tex_p+"nie ma wody dla ciebie!");
}

ostream & operator <<( ostream & s, const obj & o )
{
    return s<<"[ X: "<<o.x<<",   Y: "<< o.y<<"]";
}


bool operator==(const vector2 & a, const vector2 & b){
    if(a.x==b.x && a.y==b.y){
        return(true);
    }
    return(false);
}
