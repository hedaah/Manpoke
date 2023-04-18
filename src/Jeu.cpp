#include <iostream>

#include "Jeu.h"
using namespace std;

Jeu::Jeu(){
    afficherInit();

    im_Menu.loadFromFile("data/ecran_menu.jpg",renderer);

    dres.setNbPokeball(5);
    for (unsigned int i = 0; i< dres.getNbPokeball() ; i++)
    {
        dres.getTabPokeball()[i].im_pokeball.loadFromFile("data/pokeball.png", renderer);
    }
    dres.getImageSprite()[haut].loadFromFile("data/haut.png",renderer);
    dres.getImageSprite()[gauche].loadFromFile("data/gauche.png",renderer);
    dres.getImageSprite()[bas].loadFromFile("data/bas.png",renderer);
    dres.getImageSprite()[droite].loadFromFile("data/droite.png",renderer);

    ter.setImageTerrain(GRASS,"data/herbe.png",renderer);
    ter.setImageTerrain(WALL,"data/mur.png",renderer);
    ter.setImageTerrain(DOOR,"data/porte2.png",renderer);
    ter.setImageTerrain(STONE,"data/pierre.png",renderer);
}


void Jeu::actionClavier(const char touche){
    switch (touche){
    case 'z':
            dres.moveUp(ter);
            dres.LienPokD2();
            break;

    case 's':
            dres.moveDown(ter);
            dres.LienPokD2();
            break;
    
    case 'd':
            dres.moveRight(ter);
            dres.LienPokD2();
            break;

    
    case 'q':
            dres.moveLeft(ter);
            dres.LienPokD2();
            break;
    case 'a':
        dres.attaquer2();
        dres.LienPokD2();
        //     while(dres.getBol()){
            //dres.attaquer(0);
            //cout<<"position du pokemon ="<<dres.getPoke(0).y<<endl;
            //cout<<"la distance entre le pokemon et dresseur est ="<<dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())<<endl;
            //if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==200){
                        //dres.setBolF();
                        //cout<<"la valeur boolen "<<dres.getBol()<<endl;
                //}
            //if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==201){
                        //dres.setBolF();
                        //cout<<"la valeur boolen "<<dres.getBol()<<endl;
                //}
        //     }
        
            /*
            if(dres.getPoke(0).distance2(dres.getPoke(0),dres.getVect2D())==201){
                        dres.setBolF();
                        cout<<dres.getBol()<<endl;
                }
        */
            break;
    default:
        break;
    }
}

void Jeu::actionsMonstre(){
    for(int i=0;i<=10;i++){
        tab[i].deplacerAuto();
    }
}

const Terrain& Jeu::getConstTerrain() const {return ter;}
const Dresseur& Jeu::getConstDresseur() const {return dres;}

void Jeu::afficherInit()

{  
    
    // On initialise SDL 
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
            SDL_Quit();
            exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

    int dimX,dimY;
    dimX=ter.getDimX();
    dimY=ter.getDimY();
    dimX=dimX*37;
    dimY=dimY*40;
    cout<<"dimension de x ="<<dimX<<endl;
    cout<<"dimension de y="<<dimY<<endl;
    

    // On crée la fenetre

    window = SDL_CreateWindow("manPoke", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimX, dimY, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

     renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    
    

     // Fonts


     // Sons
     if(withSound){
        sound=Mix_LoadWAV("data/ecran.mp3");
        pas=Mix_LoadWAV("data/bruit_pas.wav");
        if(sound==nullptr){
            cout<<"Failed to load son d'ecran mp3"<<endl;
        }
        if(pas==nullptr){
            cout<<"Failed to load bruit pas wav"<<endl;
        }

     }
    
}

void Jeu::afficherDetruit()
{
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(1);

}

void Jeu::afficherBoucle()
{
    bool quit=false;
     
    Direction i=bas;
    int k=0;
    SDL_Event Event;

    unsigned int x,y;
    int restante=dres.GetnombreRestantesPokemon();

    

    //

    while(!quit)
    {
        while(SDL_PollEvent(&Event))
        {   
            if(Event.type == SDL_QUIT) quit=true;

            else if (Event.type == SDL_KEYDOWN) 
            { 

				switch (Event.key.keysym.scancode) 
                {   
                    case SDL_SCANCODE_RETURN:
                        k=1;
                        break;
                    
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
                    
                    case SDL_SCANCODE_UP:
                        i=haut;
                        actionClavier('s');
                        cout<<"position du dresseur en y = "<<dres.getPosY()<<endl;
                        cout<<"position du pokeball en y = "<<dres.getPosYSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;
                    
                    case SDL_SCANCODE_DOWN:
                        i=bas;
                        actionClavier('z');
                        cout<<"position du dresseur en y = "<<dres.getPosY()<<endl;
                        cout<<"position du pokeball en y = "<<dres.getPosYSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXP(),getConstDresseur().getPosYP(),10,10);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;

                    case SDL_SCANCODE_LEFT:
                        i=gauche;
                        actionClavier('d');
                        cout<<"position du dresseur en x = "<<dres.getPosX()<<endl;
                        cout<<"position du pokeball en x = "<<dres.getPosXSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);

                        //im_pokeball.draw(renderer,getConstDresseur().getPosXP(),getConstDresseur().getPosYP(),10,10);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;
                    
                    case SDL_SCANCODE_RIGHT:
                        i=droite;
                        actionClavier('q');
                        cout<<"position du dresseur en x = "<<dres.getPosX()<<endl;
                        cout<<"position du pokeball en x = "<<dres.getPosXSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXP(),getConstDresseur().getPosYP(),10,10);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;
                    
                    case SDL_SCANCODE_SPACE:
                        //cout<<" 1- valeur du boolen ="<<getConstDresseur().getBol()<<endl;
                        //while(dres().getBol()){
                            
                            actionClavier('a');
                            cout<<"position du pokemon en x = "<<dres.getPosXSPA()<<endl;
                            cout<<"position du pokemon en y = "<<dres.getPosYSPA()<<endl;
                            dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSPA()*37,dres.getPosYSPA()*40,18,20);
                            //im_pokeball.draw(renderer,getConstDresseur().getPosXSP(),getConstDresseur().getPosYSP(),20,20);


                            

                        //}
                        //getConstDresseur().setBolT();
                        //cout<<"2- valeur du boolen ="<<getConstDresseur().getBol()<<endl;
                        break;
                    
                    default: 
                    Mix_Pause(-2);
                    break;
				}
			}
        }
     SDL_SetRenderDrawColor(renderer,100,100,100,225);
     SDL_RenderClear(renderer);
     switch (k){
        case 0:im_Menu.draw(renderer,0,0,1000,600);
            Mix_PlayChannel(-1,sound,-1);
            break;
        case 1: 
            cout << "Nous sommes rentrée dans le draw de la map"  << endl;
            
            if (renderer == NULL) { cout << "Renderer nul lors du draw de map" << endl;}
            for(x=0;x<ter.getDimX();x++){
                for(y=0;y<ter.getDimY();y++)
                {
                    cout << "NOus sommes dans la boucle : x = " << x << " et y = " << y << endl;
                    cout << "SUr quel case on est : "<<(char)ter.getXY(x,y) << endl;
                    switch (ter.getXY(x,y))
                    {
                    case '#':
                        ter.getImageTerrain(WALL).draw(renderer,x*37,y*40,37,40);
                        cout << "Wall a bien été dessiné" << endl;
                        break;
                    case '.':
                        ter.getImageTerrain(GRASS).draw(renderer,x*37,y*40,37,40);
                        cout << "Grass a bien été dessiné" << endl;
                        break;
                    case 'A':
                        ter.getImageTerrain(STONE).draw(renderer,x*37,y*40,37,40);
                        cout << "Stone a bien été dessiné" << endl;
                        break;
                    //case 'D':
                    //   im_porte.draw(renderer,x*67,y*30,67,30);
                    
                    }
                    
                }
            }
            cout<<restante<<endl;
                dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSP()*37,dres.getPosYSP()*40,18,20);
                dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSPA()*37,dres.getPosYSPA()*40,18,20);
            
            dres.getImageSprite()[i].draw(renderer,dres.getPosX()*37,dres.getPosY()*40,37,40); 
            //Mix_Pause(-1);
            break;

     }
     SDL_RenderPresent(renderer);

    } 
    afficherDetruit();

}


void Jeu::afficher()
{
    afficherBoucle();
}