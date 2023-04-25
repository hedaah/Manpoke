#include <iostream>

#include "Jeu.h"
using namespace std;

Jeu::Jeu(){
    afficherInit();

    im_Menu.loadFromFile("data/menu.png",renderer);

    dres.setNbPokeball(5);
    for (unsigned int i = 0; i< dres.getNbPokeball() ; i++)
    {
        dres.getTabPokeball()[i].im_pokeball.loadFromFile("data/pokeball.png", renderer);
    }
    /*dres.getImageSprite()[haut].loadFromFile("data/haut.png",renderer);
    dres.getImageSprite()[gauche].loadFromFile("data/gauche.png",renderer);
    dres.getImageSprite()[bas].loadFromFile("data/bas.png",renderer);
    dres.getImageSprite()[droite].loadFromFile("data/droite.png",renderer);*/

    dres.getImageSprite().loadFromFile("data/trainer.png",renderer);
    dres.getTabSpritesRect(haut)[0] = {0,192,64,64};
    dres.getTabSpritesRect(haut)[1] = {64,192,64,64};
    dres.getTabSpritesRect(haut)[2] = {128,192,64,64};
    dres.getTabSpritesRect(haut)[3] = {192,192,64,64};

    dres.getTabSpritesRect(bas)[0] = {0,0,64,64};
    dres.getTabSpritesRect(bas)[1] = {64,0,64,64};
    dres.getTabSpritesRect(bas)[2] = {128,0,64,64};
    dres.getTabSpritesRect(bas)[3] = {192,0,64,64};

    dres.getTabSpritesRect(gauche)[0] = {0,64,64,64};
    dres.getTabSpritesRect(gauche)[1] = {64,64,64,64};
    dres.getTabSpritesRect(gauche)[2] = {128,64,64,64};
    dres.getTabSpritesRect(gauche)[3] = {192,64,64,64};

    dres.getTabSpritesRect(droite)[0] = {0,128,64,64};
    dres.getTabSpritesRect(droite)[1] = {64,128,64,64};
    dres.getTabSpritesRect(droite)[2] = {128,128,64,64};
    dres.getTabSpritesRect(droite)[3] = {192,128,64,64};


    ter.setImageTerrain(GRASS,"data/herbe.png",renderer);
    ter.setImageTerrain(WALL,"data/mur.png",renderer);
    ter.setImageTerrain(DOOR,"data/porte2.png",renderer);
    ter.setImageTerrain(STONE,"data/pierre.png",renderer);
}


void Jeu::actionClavier(const char touche){
    bool moving;
    unsigned short int movingState;
    dres.getMovingState(moving,movingState);
    cout << "moving : " << moving << " movingState : " << movingState << " direction : " << dres.getDir() << endl; 
    if (moving == true) 
    {
        return; //Si le joueur est déjà en mouvement, on fait rien et on attend la fin de son déplacement actuel.
    }
    switch (touche){
    case 'z':
        if (moving == false) {
            dres.setMovingState(true,0);
            dres.setDir(haut);
            dres.LienPokD2();
        }
        break;

    case 's':
        if (moving == false) {
            dres.setMovingState(true,0);
            dres.setDir(bas);
            dres.LienPokD2();
        }
        break;
    case 'd':
        if (moving == false) {
            dres.setMovingState(true,0);
            dres.setDir(droite);
            dres.LienPokD2();
        }
        break;
    case 'q':
        if (moving == false) {
            dres.setMovingState(true,0);
            dres.setDir(gauche);
            dres.LienPokD2();
        }
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
    dimX=dimX*65;
    dimY=dimY*70;
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
        //sound=Mix_LoadWAV("data/ecn.mp3");
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

void Jeu::setupRenderer(int state)
{
     switch (state){
        case 0:im_Menu.draw(renderer,0,0,1755,1050);
            Mix_PlayChannel(-1,sound,-1);
            break;
        case 1: 
            //cout << "Nous sommes rentrée dans le draw de la map"  << endl;
            
            if (renderer == NULL) { cout << "Renderer nul lors du draw de map" << endl;}
            for(unsigned int x=0;x<ter.getDimX();x++){
                for(unsigned int y=0;y<ter.getDimY();y++)
                {
                    //cout << "NOus sommes dans la boucle : x = " << x << " et y = " << y << endl;
                    //cout << "SUr quel case on est : "<<(char)ter.getXY(x,y) << endl;
                    switch (ter.getXY(x,y))
                    {
                    case '#':
                        ter.getImageTerrain(WALL).draw(renderer,x*65,y*60,65,60);
                        //cout << "Wall a bien été dessiné" << endl;
                        break;
                    case '.':
                        ter.getImageTerrain(GRASS).draw(renderer,x*65,y*60,65,60);
                        //cout << "Grass a bien été dessiné" << endl;
                        break;
                    case 'A':
                        ter.getImageTerrain(STONE).draw(renderer,x*65,y*60,65,60);
                        //cout << "Stone a bien été dessiné" << endl;
                        break;
                    //case 'D':
                    //   im_porte.draw(renderer,x*67,y*30,67,30);
                    
                    }
                    
                }
            }
            //cout << dres.GetnombreRestantesPokemon() << endl;
                //dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSP()*64,dres.getPosYSP()*64,18,20);
                //dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSPA()*64,dres.getPosYSPA()*64,18,20);

            
            //dres.getImageSprite()[dres.getDir()].draw(renderer,dres.getPosX()*37,dres.getPosY()*40,37,40);
            SDL_Rect tmpTrainerRect = {dres.getPosX()*65,dres.getPosY()*60,65,60};

            if (dres.getInternalMovingState() == 0)
            {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[0],&tmpTrainerRect);
            }
           else if (dres.getInternalMovingState() < 4)
           {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[0],&tmpTrainerRect);
           }
           else if (dres.getInternalMovingState() < 8 && dres.getInternalMovingState() >=4)
           {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[1],&tmpTrainerRect);
           }
           else if (dres.getInternalMovingState() < 12 && dres.getInternalMovingState() >=8)
           {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[2],&tmpTrainerRect);
           }
           else if (dres.getInternalMovingState() < 16 && dres.getInternalMovingState() >=12)
           {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[3],&tmpTrainerRect);
           }
           else if (dres.getInternalMovingState() >= 16)
           {
                SDL_RenderCopy(renderer,dres.getImageSprite().getTexture(),
                    &dres.getTabSpritesRect(dres.getDir())[0],&tmpTrainerRect);
           }

            //Mix_Pause(-1);
            break;

     }
}

void Jeu::afficherBoucle()
{
    bool quit=false;
     
    int state=0;
    SDL_Event Event;

    //unsigned int x,y;
    //int restante=dres.GetnombreRestantesPokemon();

    

    

    //

    while(!quit)
    {
        
        int mouseX,mouseY;
        SDL_GetMouseState(&mouseX,&mouseY);
        unsigned int start = SDL_GetPerformanceCounter();
        while(SDL_PollEvent(&Event))
        {   
            if(Event.type == SDL_QUIT) quit=true;

            else if (Event.type == SDL_KEYDOWN || Event.type==SDL_MOUSEBUTTONDOWN) 
            { 

				switch (Event.key.keysym.scancode) 
                {   
                    
                    case SDL_SCANCODE_ESCAPE:
                        quit = true;
                        break;
                    
                    case SDL_SCANCODE_UP:
                        actionClavier('z');
                        cout<<"position du dresseur en y = "<<dres.getPosY()<<endl;
                        cout<<"position du pokeball en y = "<<dres.getPosYSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;
                    
                    case SDL_SCANCODE_DOWN:
                        actionClavier('s');
                        cout<<"position du dresseur en y = "<<dres.getPosY()<<endl;
                        cout<<"position du pokeball en y = "<<dres.getPosYSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXP(),getConstDresseur().getPosYP(),10,10);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;

                    case SDL_SCANCODE_LEFT:
                        actionClavier('q');
                        cout<<"position du dresseur en x = "<<dres.getPosX()<<endl;
                        cout<<"position du pokeball en x = "<<dres.getPosXSP()<<endl;
                        cout<<"la direction du dresseur = "<<dres.getDir()<<endl;
                        //im_pokeball.draw(renderer,getConstDresseur().getPosXSP()*37,getConstDresseur().getPosYSP()*40,18,20);

                        //im_pokeball.draw(renderer,getConstDresseur().getPosXP(),getConstDresseur().getPosYP(),10,10);
                        //Mix_PlayChannel(-2,pas,-2);
                        break;
                    
                    case SDL_SCANCODE_RIGHT:
                        actionClavier('d');
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
                        if (Event.button.button==SDL_BUTTON_LEFT){
                            if(mouseX>=212 && mouseX<=573 && mouseY>=411 && mouseY<=661){
                                cout<<"bouton souris qui fonctionne"<<endl;
                                state=1;
                            }
                            if(mouseX>= 590 && mouseX<=954 && mouseY>=411 && mouseY<=661){
                                cout<<"Tu as Selectionné Reglage"<<endl;
                                
                            }
                            if(mouseX>=212 && mouseX<=573 && mouseY>=681 && mouseY<=929){
                                cout<<"Tu as selectionné Credit"<<endl;
                                
                            }
                            if(mouseX>=590 && mouseX<=954 && mouseY>=681 && mouseY<=929){
                                cout<<"Tu as selectionné Quitter"<<endl;
                                quit=true;
                                
                            }

                            

                        }
                        break;
                        
                    Mix_Pause(-2);
                    break;
				}
			}
        }
    // ################## Déplacement du joueur ################

    bool moving;
    unsigned short int movingState;
    dres.getMovingState(moving,movingState);
    //cout << "moving : " << moving << " movingState : " << movingState << " direction : " << dres.getDir() << endl; 
    if (movingState < 20 && moving == true) // On veut que le déplacement dure 20 frames, càd environ 1/3 secondes dans le cas où l'ordinateur rend bien à 60 images par secondes.
    {
        cout << "On entre dans le déplacement" << endl;
        switch(dres.getDir())
        {
            case haut:
            {
                dres.moveUp(ter);
                //dres.LienPokD2();
                movingState+=1;
                dres.setMovingState(moving,movingState);
                break;
            }
            case bas:
            {
                dres.moveDown(ter);
                //dres.LienPokD2();
                movingState+=1;
                dres.setMovingState(moving,movingState);
                break;
            }
            case droite:
            {
                dres.moveRight(ter);
                //dres.LienPokD2();
                movingState+=1;
                dres.setMovingState(moving,movingState);
                break;
            }
            case gauche:
            {
                dres.moveLeft(ter);
                //dres.LienPokD2();
                movingState+=1;
                dres.setMovingState(moving,movingState);
                break;
            }
            default : break;
        }
    }
    else 
    {
        dres.setMovingState(false,0);
    }




    SDL_SetRenderDrawColor(renderer,255,255,100,225);
    SDL_RenderClear(renderer);
    setupRenderer(state);
    SDL_RenderPresent(renderer);

    unsigned int end = SDL_GetPerformanceCounter();
    float elapsedMS = (end - start) / SDL_GetPerformanceCounter() * 1000.f;
    SDL_Delay(floor((float)(100/6) - elapsedMS)); // limite 60 fps

    } 
    afficherDetruit();

}


void Jeu::afficher()
{
    afficherBoucle();
}