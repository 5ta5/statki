#include "include/statki.h"

void quit_check(level *lvl){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)){
        lvl->window->close();
    }
    sf::Event event;
    while (lvl->window->pollEvent(event)){
        if (event.type == sf::Event::Closed){
            lvl->window->close();
        }
    }
}

int main(){
    
    sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
    sf::RenderWindow window(desktop, "SOKOBAN", sf::Style::Fullscreen);//sf::VideoMode(1000, 1000)
    //window->setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);
    level lvl(&window);//nom
    /*
    obj tmp;
    lvl.statki.push_back(&tmp);
    */
    //for...
    kuter czarna;//konkretny
    czarna.x=5;
    czarna.y=5;
    czarna.kierunek=vector2(-1, 0);
    lvl.dodaj(&czarna);//0, 0, 'D', 
    
    while(lvl.window->isOpen()){
        quit_check(&lvl);
        lvl.render();
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                lvl.strzal(i, j);
            }
        }
        //lvl.strzal(3, 5);
    }
    
}
