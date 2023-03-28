#include "sdl_jeu.h"
#include <iostream>

using namespace std;

void jeu:: afficherInit()

{   
    m_surface =nullptr;
    m_texture=nullptr;
    m_hasChanged=false;

 
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    m_window = SDL_CreateWindow("manPoke", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1000, 800, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (m_window == nullptr) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

     m_renderer = SDL_CreateRenderer(m_window,-1,SDL_RENDERER_ACCELERATED);
    
}

void jeu:: afficherDetruit()
{
    SDL_DestroyWindow(m_window);
    SDL_DestroyRenderer(m_renderer);
    SDL_Quit();
    exit(1);

}

void jeu:: afficherBoucle()
{
     bool quit=false;
     

    SDL_Event windowEvent;

    while(!quit)
    {
        while(SDL_PollEvent(&windowEvent))
        {
        if(windowEvent.type == SDL_QUIT){quit=true;}
        }
    

     SDL_SetRenderDrawColor(m_renderer,100,100,100,225);
     SDL_RenderClear(m_renderer);
}

 afficherDetruit();

}

void jeu:: afficher()
{
    afficherInit();
    afficherBoucle();
}


