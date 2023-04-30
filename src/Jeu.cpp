#include <iostream>
#include <sstream>

#include "Jeu.h"
using namespace std;

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

Jeu::Jeu(){
    afficherInit();
    srand(time(NULL));

    im_Menu[0].loadFromFile("data/Menu/menu.png",renderer);
    im_Menu[1].loadFromFile("data/Menu/GameOver.png",renderer);

    Im_score.loadFromFile("data/Score/score.png",renderer);

    Im_Pr.loadFromFile("data/Score/Pokeball.png",renderer);

    dres.getTabImageVie()[0].loadFromFile("data/Score/vie/Vie125.png", renderer);
    dres.getTabImageVie()[1].loadFromFile("data/Score/vie/Vie100.png", renderer);
    dres.getTabImageVie()[2].loadFromFile("data/Score/vie/Vie75.png", renderer);
    dres.getTabImageVie()[3].loadFromFile("data/Score/vie/Vie50.png", renderer);
    dres.getTabImageVie()[4].loadFromFile("data/Score/vie/Vie25.png", renderer);
    dres.getTabImageVie()[5].loadFromFile("data/Score/vie/Vie0.png", renderer);


    int tmpDresPosX = static_cast<int>(dres.getPosX()*65.);
    int tmpDresPosY = static_cast<int>(dres.getPosY()*60.0);
    dres.getRectPos() = {tmpDresPosX,tmpDresPosY,200,200}; // On peut modifier directement depuis le getter car on récupère la 
                                                         //référence vers le rectpos de l'instance, on récupère la référence 
                                                         //car on en a besoin pour draw ensuite.

    for (unsigned int i = 0; i< dres.getNbPokeball() ; i++)
    {
        dres.getTabPokeball()[i].im_pokeball.loadFromFile("data/pokeball.png", renderer);
    }
    /*dres.getImageSprite()[haut].loadFromFile("data/haut.png",renderer);
    dres.getImageSprite()[gauche].loadFromFile("data/gauche.png",renderer);
    dres.getImageSprite()[bas].loadFromFile("data/bas.png",renderer);
    dres.getImageSprite()[droite].loadFromFile("data/droite.png",renderer);*/

    dres.getImageSprite().loadFromFile("data/trainer.png",renderer);
    
    USInt_level = 1; // On commence toujours au niveau 1.
    USInt_nbMonstre = 10; // Toujours 10 monstres par niveaux.

    ter.setImageTerrain(GRASS,"data/Map/herbe.png",renderer);
    ter.setImageTerrain(WALL,"data/Map/mur.png",renderer);
    ter.setImageTerrain(DOOR,"data/Map/porte2.png",renderer);
    ter.setImageTerrain(STONE,"data/Map/pierre.png",renderer);


    for (unsigned short int i =0;i< USInt_nbMonstre ; i++)
    {
        if (i < 6) // 6 petits monstres
        {
            Monstre tmp(8.0,2.0+i,petit);
            Monstre* tmp2 = new Monstre;
            tmp2->setPos(tmp.getPosX(),tmp.getPosY()); 
            tmp2->setVie(tmp.getVie());
            tab_monstres.push_back(tmp2);
            tab_monstres[i]->getImageSprite().loadFromFile("data/001.png",renderer);
            int tmpMonstrePosX = static_cast<int>(tab_monstres[i]->getPosX()*65.0);
            int tmpMonstrePosY = static_cast<int>(tab_monstres[i]->getPosY()*60.0);
            tab_monstres[i]->getRectPos() = {tmpMonstrePosX,tmpMonstrePosY,65,60};
        }
        else if (i >= 6 && i < 9) // 3 monstres moyens
        {
            Monstre tmp(10.0,2.0+i,moyen);
            Monstre* tmp2 = new Monstre;
            tmp2->setPos(tmp.getPosX(),tmp.getPosY());
            tmp2->setVie(tmp.getVie());
            tab_monstres.push_back(tmp2);
            tab_monstres[i]->getImageSprite().loadFromFile("data/002.png",renderer);
            int tmpMonstrePosX = static_cast<int>(tab_monstres[i]->getPosX()*65.0);
            int tmpMonstrePosY = static_cast<int>(tab_monstres[i]->getPosY()*60.0);
            tab_monstres[i]->getRectPos() = {tmpMonstrePosX,tmpMonstrePosY,65,60};
        }
        else if (i == 9) // 1 monstre grand
        {
            Monstre tmp(5.0,5.0,grand);
            Monstre* tmp2 = new Monstre;
            tmp2->setPos(tmp.getPosX(),tmp.getPosY());
            tmp2->setVie(tmp.getVie());
            tab_monstres.push_back(tmp2);
            tab_monstres[i]->getImageSprite().loadFromFile("data/003.png",renderer);
            int tmpMonstrePosX = static_cast<int>(tab_monstres[i]->getPosX()*65.0);
            int tmpMonstrePosY = static_cast<int>(tab_monstres[i]->getPosY()*60.0);
            tab_monstres[i]->getRectPos() = {tmpMonstrePosX,tmpMonstrePosY,65,60};
        }
    }

    font=TTF_OpenFont("DejaVuSansCondensed.ttf", 72 );

    point=0;
    score=dres.GetnombreRestantesPokemon();
    font_color.r = 255;font_color.g = 255;font_color.b = 255;


}

Jeu::~Jeu(){
    
}

void Jeu::actionClavier(const char touche){
    bool moving;
    unsigned short int movingState;
    dres.getMovingState(moving,movingState);
    //cout << "moving : " << moving << " movingState : " << movingState << " direction : " << dres.getDir() << endl; 
    if (moving == true) 
    {
        return; //Si le joueur est déjà en mouvement, on fait rien et on attend la fin de son déplacement actuel.
    }
    switch (touche){
    case 'z':
        if (moving == false) {
            dres.setDir(haut);
            dres.setMovingState(true,0);
            //dres.LienPokD2();
        }
        break;

    case 's':
        if (moving == false) {
            dres.setDir(bas);
            dres.setMovingState(true,0);
            //dres.LienPokD2();
        }
        break;
    case 'd':
        if (moving == false) {
            dres.setDir(droite);
            dres.setMovingState(true,0);
            //dres.LienPokD2();
        }
        break;
    case 'q':
        if (moving == false) {
            dres.setDir(gauche);
            dres.setMovingState(true,0);
            //dres.LienPokD2();
        }
        break;
    case 'a':
        dres.WORLVie(-25);
        /*dres.attaquer2();
        dres.LienPokD2();*/
        //cout << "(TOUCHE) Coordonnée dresseur x : " << dres.getPosX() << " coordonnée dresseur y :" << dres.getPosY() << endl;
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
    for(unsigned short int i=0;i<tab_monstres.size();i++){
        int tmp = rand() % 4;
        tab_monstres[i]->deplacerAuto(tmp);
    }
}

void Jeu::gestionDeplacement(Personne& p)
{
    bool moving;
    unsigned short int movingState;
    p.getMovingState(moving,movingState);
    //cout << "moving : " << moving << " movingState : " << movingState << " direction : " << dres.getDir() << endl; 
    if (movingState < 20 && moving == true) // On veut que le déplacement dure 20 frames, càd environ 1/3 secondes dans le cas où l'ordinateur rend bien à 60 images par secondes.
    {
        //cout << "On entre dans le déplacement" << endl;
        switch(p.getDir())
        {
            case haut:
            {
                if (p.moveUp(ter) == true)
                {
                    movingState+=1;
                    p.setMovingState(moving,movingState);
                    break;
                }
                else
                {
                    break;
                }
                //dres.LienPokD2();
            }
            case bas:
            {
                if (p.moveDown(ter) == true)
                {
                    movingState+=1;
                    p.setMovingState(moving,movingState);
                    break;
                }
                else
                {
                    break;
                }
                //dres.LienPokD2();
            }
            case droite:
            {
                if (p.moveRight(ter) == true)
                {
                    movingState+=1;
                    p.setMovingState(moving,movingState);
                    break;
                }
                else
                {
                    break;
                }
                //dres.LienPokD2();
            }
            case gauche:
            {
                if (p.moveLeft(ter) == true)
                {
                    movingState+=1;
                    p.setMovingState(moving,movingState);
                    break;
                }
                else
                {
                    break;
                }
                //dres.LienPokD2();
            }
            default : break;
        }
    }
    else if (movingState >= 20)
    {
        p.setMovingState(false,0);
    }
}

void Jeu::gestionRendue(Personne& p)
{
    int tmpPosX = static_cast<int>(p.getPosX()*65.0);
    int tmpPosY = static_cast<int>(p.getPosY()*60.0);
    p.getRectPos() = {tmpPosX,tmpPosY,65,60};

    if (p.getInternalMovingState() == 0)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[0],&p.getRectPos());
    }
    else if (p.getInternalMovingState() < 4)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[0],&p.getRectPos());
    }
    else if (p.getInternalMovingState() < 8 && p.getInternalMovingState() >=4)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[1],&p.getRectPos());
    }
    else if (p.getInternalMovingState() < 12 && p.getInternalMovingState() >=8)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[2],&p.getRectPos());
    }
    else if (p.getInternalMovingState() < 16 && p.getInternalMovingState() >=12)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[3],&p.getRectPos());
    }
    else if (p.getInternalMovingState() >= 16)
    {
        SDL_RenderCopy(renderer,p.getImageSprite().getTexture(),
            &p.getTabSpritesRect(p.getDir())[0],&p.getRectPos());
    }
}

const Terrain& Jeu::getConstTerrain() const {return ter;}
const Dresseur& Jeu::getConstDresseur() const {return dres;}

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
        case 0:im_Menu[0].draw(renderer,0,0,1755,1050);
           
            break;
        case 1:
            im_Menu[1].draw(renderer,0,0,1755,1050);
            break;

        case 2: 
            //cout << "Nous sommes rentrée dans le draw de la map"  << endl;
            
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


            switch (dres.getVie())
            {
                case 125:
                    dres.getTabImageVie()[0].draw(renderer,150,910,180,90);
                    break;

                case 100:
                    dres.getTabImageVie()[1].draw(renderer,150,910,180,90);
                    break;
                
                case 75:
                    dres.getTabImageVie()[2].draw(renderer,150,910,180,90);
                
                    break;
                
                case 50:
                    dres.getTabImageVie()[3].draw(renderer,150,910,180,90);
                    break;
                
                case 25:
                    dres.getTabImageVie()[4].draw(renderer,150,910,180,90);
                    break;

                case 0:
                    dres.getTabImageVie()[5].draw(renderer,150,910,180,90);
                    break;

                default:
                    break;
            } 

            Im_score.draw(renderer,1250,790,470,350);
            Im_Pr.draw(renderer,800,920,80,80);

            SDL_Rect Stock;
            Stock.x=725;
            Stock.y=925;
            Stock.w=70;
            Stock.h=70;

            SDL_Rect Score;
            Score.x=1000;
            Score.y=925;
            Score.h=140;
            Score.w=70;

            SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&Stock);
            SDL_RenderCopy(renderer,font_im.getTexture(),nullptr,&Score);

        


            //cout << dres.GetnombreRestantesPokemon() << endl;
                //dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSP()*64,dres.getPosYSP()*64,18,20);
                //dres.getTabPokeball()[0].im_pokeball.draw(renderer,dres.getPosXSPA()*64,dres.getPosYSPA()*64,18,20);

            
            //dres.getImageSprite()[dres.getDir()].draw(renderer,dres.getPosX()*37,dres.getPosY()*40,37,40);

            //Préparation du rendu du dresseur.
            gestionRendue(dres);

            //Préparation du rendu des monstres.
            actionsMonstre();
            for (unsigned short int i = 0; i<tab_monstres.size() ; i++)
            {
                gestionRendue(*tab_monstres[i]);
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
    int mouseX,mouseY;


    while(!quit)
    {
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
                            score--;
                            score_str=to_string(score);

                            point_str=to_string(point);

    
                            font_im.setSurface(TTF_RenderText_Blended(font,score_str.c_str(),font_color));
                            font_im.loadFromCurrentSurface(renderer);

                            

                        //}
                        //getConstDresseur().setBolT();
                        //cout<<"2- valeur du boolen ="<<getConstDresseur().getBol()<<endl;
                        break;
                    
                    default: 
                        if (Event.button.button==SDL_BUTTON_LEFT ){


                            switch (state){
                                case 0:
                                    if(mouseX>=212 && mouseX<=573 && mouseY>=411 && mouseY<=661){
                                        cout<<"bouton souris qui fonctionne"<<endl;
                                        state=2;
                                    }
                                    if(mouseX>= 590 && mouseX<=954 && mouseY>=411 && mouseY<=661){
                                        cout<<"Tu as Selectionné Reglage"<<endl;
                                        
                                    }
                                    if(mouseX>=212 && mouseX<=573 && mouseY>=681 && mouseY<=929){
                                        cout<<"Tu as selectionné Credit"<<endl;
                                        
                                    }
                                    if(mouseX>=590 && mouseX<=954 && mouseY>=681 && mouseY<=929){
                                        quit=true;  
                                    } 

                                break;

                                case 1:

                                    if(mouseX>=336 && mouseX<=859 && mouseY>=541 && mouseY<=649){
                                        quit=true;  
                                    } 
                                    break;


                            }

                        }
                    break;
				}
			}
            if(dres.getVie()==0) {
                cout<<"fin game"<<endl;
                state=1;
                cout<<state<<endl;
            }
        }
    // ################## Déplacement du joueur ################
    gestionDeplacement(dres);

    // ################## Déplacement des monstres ################
    for(unsigned short int i=0;i<tab_monstres.size();i++)
    {
        gestionDeplacement(*tab_monstres[i]);
    }



    SDL_SetRenderDrawColor(renderer,100,100,100,225);
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