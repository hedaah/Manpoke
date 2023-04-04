#include <iostream>
#include <time.h>
#include <cassert>
#include <stdlib.h>
#include "sdl_aff.h"

using namespace std;
// ============= CLASS IMAGE =============== //

Image::Image () : m_surface(nullptr), m_texture(nullptr), m_hasChanged(false) {
}

Image::~Image()
{
    SDL_FreeSurface(m_surface);
    SDL_DestroyTexture(m_texture);

    m_surface = nullptr;
    m_texture = nullptr;

    m_hasChanged = false;
}

void Image::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    m_surface = IMG_Load(filename);
    if (m_surface == nullptr) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        m_surface = IMG_Load(nfn.c_str());
        if (m_surface == nullptr) {
            nfn = string("../") + nfn;
            m_surface = IMG_Load(nfn.c_str());
        }
    }
    if (m_surface == nullptr) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(m_surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(m_surface);
    m_surface = surfaceCorrectPixelFormat;

    m_texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (m_texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::loadFromCurrentSurface (SDL_Renderer * renderer) {
    m_texture = SDL_CreateTextureFromSurface(renderer,m_surface);
    if (m_texture == nullptr) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Image::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?m_surface->w:w;
    r.h = (h<0)?m_surface->h:h;

    if (m_hasChanged) {
        ok = SDL_UpdateTexture(m_texture,nullptr,m_surface->pixels,m_surface->pitch);
        assert(ok == 0);
        m_hasChanged = false;
    }

    ok = SDL_RenderCopy(renderer,m_texture,nullptr,&r);
    assert(ok == 0);
}

SDL_Texture * Image::getTexture() const {return m_texture;}

void Image::setSurface(SDL_Surface * surf) {m_surface = surf;}


// ============= CLASS SDLJEU =============== //

jeu::jeu(){

}

void jeu:: afficherInit()

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

    
    

    // On crée la fenetre

    window = SDL_CreateWindow("manPoke", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

     renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

    


     // Image 
    im_Menu.loadFromFile("data/ecran_menu.jpg",renderer);
    im_dresseur[0].loadFromFile("data/bas.png",renderer);
    im_dresseur[1].loadFromFile("data/haut.png",renderer);
    im_dresseur[2].loadFromFile("data/gauche.png",renderer);
    im_dresseur[3].loadFromFile("data/droite.png",renderer);

     // Fonts


     // Sons
     if(withSound){
        sound=Mix_LoadWAV("data/ecran.mp3");
        if(sound==nullptr){
            cout<<"Failed to load son.mp d'ecran mp3"<<endl;
        }
     }
    
}

void jeu:: afficherDetruit()
{
    if (withSound) Mix_Quit();
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    exit(1);

}

void jeu:: afficherBoucle()
{
    bool quit=false;
     
    int i=0;
    int k=0;
    SDL_Event Event;

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
                        i=1;
                        break;
                    
                    case SDL_SCANCODE_DOWN:
                        i=0;
                        break;

                    case SDL_SCANCODE_LEFT:
                        i=2;
                        break;
                    
                    case SDL_SCANCODE_RIGHT:
                        i=3;
                        break;
                    
                    default: break;
				}
			}
        }
     SDL_SetRenderDrawColor(renderer,100,100,100,225);
     SDL_RenderClear(renderer);
     switch (k){
        case 0:im_Menu.draw(renderer,0,0,1000,600);
            Mix_PlayChannel(-1,sound,-1);
            break;
        case 1: im_dresseur[i].draw(renderer,game.getConstDresseur().getPosX(),game.getConstDresseur().getPosY(),50,50); 
            break;

     }
     SDL_RenderPresent(renderer);

    }
    afficherDetruit();

}

void jeu:: afficher()
{
    afficherInit();
    afficherBoucle();
}


