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

vector2 ra(){
    vector2 ra;
    if(random()%2==0){
        if(random()%2==0){
            ra=vector2(0, 1);
        }else{
            ra=vector2(0, -1);
        }
    }else{
        if(random()%2==0){
            ra=vector2(1, 0);
        }else{
            ra=vector2(-1, 0);
        }
    }
    return(ra);
}


void dawaj_texture(sf::RenderWindow *window, string path, int x=0, int y=0){
    sf::Sprite sprite;
    sf::Texture texture;
    sprite.setPosition(sf::Vector2f(y, x));
    if (!texture.loadFromFile(path)){
        // error...
        cout<<"ERROR\n";
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    window->draw(sprite);
}


int main(){
    
    srand(time(NULL));
    
    sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
    sf::RenderWindow window(desktop, "SOKOBAN", sf::Style::Fullscreen);//sf::VideoMode(1000, 1000)
    window.setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);
    level lvl_gracz(&window);//nom
    level lvl_bot(&window);
    
    if(vector2(2, 2)==vector2(2, 2)){//przyklad uzycia operatora ==
        cout<<"ruwne\n";
    }
    
    human jack;//sparrow
    bot barrbarossa;
    
    level *poziom;
    player *gracz;
    
    
    vector2 strzal;
    
    for(int i=0;i<2;i++){
        if(i%2==0){
            poziom=&lvl_bot;
            //cout<<"ee\n";//DEBGUG
            for(int i=0;i<1;i++){
                while((poziom->dodaj(new ponton(random()%10, random()%10, ra())))==false){};
                while((poziom->dodaj(new kuter(random()%10, random()%10, ra())))==false){};
                while((poziom->dodaj(new korweta(random()%10, random()%10, ra())))==false){};
            }
        }else{
            poziom=&lvl_gracz;
            gracz=&jack;
            for(int i=0;i<10;i++){
                do{//nie strzela
                    strzal=gracz->strzal();
                    quit_check(poziom);
                    poziom->render(true);
                    if(strzal.x!=-1){
                        //strzelamy
                        //cout<<"EEE\n";//DEBGU
                        poziom->dodaj(new kuter(strzal.x, strzal.y, ra()));
                    }
                }while(window.isOpen() && strzal.x==-1);//strzal.x!=-1
            }
        }
        /*
        for(int i=1;i<6;i++){
            poziom->dodaj(new ponton(random()%10, random()%10, ra()));
            poziom->dodaj(new kuter(random()%10, random()%10, ra()));
            poziom->dodaj(new korweta(random()%10, random()%10, ra()));
        }*/
    }
    
    for(int j=0;j<60 && window.isOpen();j++){
        quit_check(poziom);
        poziom->render(false);
    }
    
    
    for(int i=0;i<poziom->statki.size();i++){//tu uzywam operatora wow omg
        cout<<*(poziom->statki[i])<<"\n";
    }
    
    //cout<<"trafienia"<<poziom->trafienia<<"\n";//DEBUG
    while(window.isOpen() && poziom->trafienia<6){
        for(int i=0;i>=0 && window.isOpen() && poziom->trafienia<6;i++){
            if(i%2==0){
                poziom=&lvl_bot;
                gracz=&jack;
            }else{
                poziom=&lvl_gracz;
                gracz=&barrbarossa;
            }
            do{//nie strzela
                strzal=gracz->strzal();
                quit_check(poziom);
                poziom->render(i%2);
                if(strzal.x!=-1){
                    //strzelamy
                    poziom->strzal(strzal.x, strzal.y);
                }
            }while(window.isOpen() && strzal.x==-1);//strzal.x!=-1
            
            
            for(int j=0;j<20 && window.isOpen();j++){
                quit_check(poziom);
                poziom->render(i%2);
            }
            

        }
        

        if(true){//gracz wygral
            //cout<<"haha\n";//DEBUG
            while(window.isOpen()){
                quit_check(poziom);
                window.clear();
                dawaj_texture(&window, tex_p+"win.png");
                window.display();
            }
        }else{//przegrana
            
        }
        
    }
    
}
