#include "../include/statki.h"




void obj::render(level *lvl/*, float alpha, float angle*/){
    //cout<<"Fajny Jestem!\n";//DEBUG
    sf::Sprite sprite;
    sf::Texture texture;
    int scale=100;
    /*int scale=lvl->nice_scale;
    sprite.setScale(sf::Vector2f(0.01f*scale, 0.01f*scale));*/
    
    sprite.setColor(sf::Color(255, 255, 255, 255));
    
    sf::Transform transform;
    int angle=0;
    if(kierunek.x==-1){
        angle=2;
    }
    if(kierunek.y==-1){
        angle=1;
    }
    if(kierunek.y==1){
        angle=3;
    }
    transform.rotate(angle*90, (x+0.5)*scale, (y+0.5)*scale);
    
    sprite.setPosition(sf::Vector2f(scale*y, scale*x));//+lvl.offset
    //cout<<"scale: "<<scale<<"    x: "<<scale*x<<"    y: "<<scale*y;//DEBUG
    if (!texture.loadFromFile(texture_path())){
        // error...
        cout<<"ERROR\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    lvl->window->draw(sprite, transform);
    //lvl->window->draw(sprite);
    //cout<<"Bardzo Fajny!\n";//DEBUG
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
