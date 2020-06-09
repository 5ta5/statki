#include "../include/statki.h"


vector2 human::strzal(){
    vector2 odp;
    odp.x=2;
    odp.y=2;
    //cin>>odp.x>>odp.y;
    //cout<<"x: "<<sf::Mouse::getPosition().x<<"y: "<<sf::Mouse::getPosition().y<<"\n";
    odp.x=sf::Mouse::getPosition().y/100;
    odp.x=odp.x%10;
    odp.y=sf::Mouse::getPosition().x/100;
    odp.y=odp.y%10;
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left)==true){
        if(lmousedown==false){
            lmousedown=true;//click
        }else{
            odp.x=-1;
            odp.y=-1;
        }
    }else{
        lmousedown=false;
        odp.x=-1;
        odp.y=-1;
    }
    
    return(odp);
}

vector2 bot::strzal(){
    vector2 odp;
    odp.x= rand() % 10 + 0;
    odp.y= rand() % 10 + 0;
    return(odp);    
}
