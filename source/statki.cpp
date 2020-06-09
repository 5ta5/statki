#include "../include/statki.h"

int statek::rozmiar(){
    return(3);
}

/*
string statek::texture_path(){
    return(tex_p+"ponton.png");
}*/


string ponton::texture_path(){
    string my_p="";
    if(hp==0){
        my_p="wrak_";
    }
    return(tex_p+my_p+"ponton.png");
}

string kuter::texture_path(){
    string my_p="";
    if(hp==0){
        my_p="wrak_";
    }
    return(tex_p+my_p+"kuter.png");
}

string korweta::texture_path(){
    string my_p="";
    if(hp==0){
        my_p="wrak_";
    }
    return(tex_p+my_p+"korweta.png");
}
