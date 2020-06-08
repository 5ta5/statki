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
    
    srand(time(NULL));
    
    sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
    sf::RenderWindow window(desktop, "SOKOBAN", sf::Style::Fullscreen);//sf::VideoMode(1000, 1000)
    window.setFramerateLimit(60);
    //window->setVerticalSyncEnabled(true);
    level lvl_gracz(&window);//nom
    level lvl_bot(&window);
    /*
    obj tmp;
    lvl.statki.push_back(&tmp);
    */
    //for...
    /*
    kuter czarna;//konkretny
    czarna.x=5;
    czarna.y=5;
    czarna.kierunek=vector2(-1, 0);
    lvl_bot.dodaj(&czarna);//0, 0, 'D', 
    */
    
    human jack;//sparrow
    bot barrbarossa;
    
    level *poziom;
    player *gracz;
    
    
    ponton pontony[100];
    kuter kutry[100];
    korweta korwety[100];
    
    for(int i=0;i<1;i++){
        if(i%2==0){
            poziom=&lvl_bot;
            //cout<<"ee\n";//DEBGUG
        }else{
            poziom=&lvl_gracz;
        }
        for(int i=1;i<4;i++){
            /*
            korwety[i].x=rand() % 10 + 0;
            korwety[i].y=rand() % 10 + 0;
            int randek=rand()%4;
            */
            /*if(randek==0){
                korwety[i].kierunek=vector2(-1, 0);
            }
            if(randek==1){
                korwety[i].kierunek=vector2(1, 0);
            }
            if(randek==2){
                korwety[i].kierunek=vector2(0, -1);
            }
            if(randek==3){
                korwety[i].kierunek=vector2(0, 1);
            }*/
            korwety[i].x=5+i;
            korwety[i].y=5;
            korwety[i].kierunek=vector2(0, 1);
            
            poziom->dodaj(&korwety[i]);
            
        }
    }
    
    
    
    
    vector2 strzal;
    
    while(window.isOpen()){
        for(int i=0;i>=0;i++){
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
                poziom->render();
                if(strzal.x!=-1){
                    //strzelamy
                    poziom->strzal(strzal.x, strzal.y);
                }
            }while(window.isOpen() && strzal.x==-1);//strzal.x!=-1
            
            /*
            for(int i=0;i<60 && window.isOpen();i++){
                quit_check(poziom);
                poziom->render();
            }
            */

        }
        
        //cout<<"EEE\n";
        /*
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                lvl.strzal(i, j);
            }
        }
        */
        //lvl.strzal(3, 5);
    }
    
}
