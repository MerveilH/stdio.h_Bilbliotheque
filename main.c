#include <stdio.h>
#include <SDL2/SDL.h>
#include<stdlib.h>

/*
Paramètres de SDL_CreateRenderer pour l'affichage
   SDL_RENDERER_SOFTWARE :
   SDL_RENDERER_ACCELERATED : Accélération
   SDL_RENDERER_PRESENTVSYNC : Synchronisation matériel
   SDL_RENDERER_TARGETTEXTURE : Rendu texture

*/
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
void SDL_ExitWithError(const char *message);

int main(int argc, char *argv[]){
    
   SDL_Window *window = NULL;
   SDL_Renderer *renderer = NULL;
   
  
   if(SDL_Init(SDL_INIT_VIDEO) != 0)// Initialisation et vérication de l'initialisation de la SDL
     SDL_ExitWithError("Initialisation SDL");
     
//Création de fênetre + Rendu

if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) !=0)
   SDL_ExitWithError("Impossible de creer la fenetre et le rendu");

/*------------------------------------------------------------------*/
SDL_Surface *image = NULL;
SDL_Texture *texture = NULL;

 image = SDL_LoadBMP("tx.bmp");
 if(image == NULL)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de charger l'image");
  }
  
  texture = SDL_CreateTextureFromSurface(renderer, image);
  SDL_FreeSurface(image);
  
  if(image == NULL)
  {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de creer la texture");
  }
    SDL_Rect rectangle;
    if(SDL_QueryTexture(texture, NULL, NULL, &rectangle.w, &rectangle.h) != 0){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de charger la texture");
    
    }
    
    
    rectangle.x =0;// (WINDOW_WIDTH -rectangle.w)/2;
    rectangle.x = 0; // (WINDOW_HEIGHT -rectangle.h)/2;
    
    
    if(SDL_RenderCopy(renderer, texture, NULL, &rectangle) != 0 )
    {
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_ExitWithError("Impossible de charger la texture");
    
    }
    
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);//1000 vaut 1s
/*..................................................................*/
    
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

	return 0;

}


void SDL_ExitWithError(const char *message)
 {
   SDL_Log("ERREUR : %s > %s\n", message, SDL_GetError());
   SDL_Quit();
   exit(EXIT_FAILURE);
 }














