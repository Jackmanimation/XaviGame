/*
Name        :   utilities.cpp
Author      :   Denis Jackman
Date        :   27/06/2016
Version     :   1:00:00
Function    :   This is a catch all utility to play with sprites for XaviGame
Compile     :   make
                g++ ../../game/include/general.cpp ../../game/include/SDLEngine.cpp ../../game/include/gamefunction.cpp utility.cpp -w -std=gnu++0x -I/usr/local/include -L/usr/local/lib  -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer -o utility

Change History
Name        :   Date        :   Version :   Reason
D Jackman   :   27/06/2016  :   1:00:00 :   Original Version

*/

#include <iostream>
#include <string>
#include <vector>

// Game Library headers
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

// Custom Headers
#include "../../game/include/general.h"
#include "../../game/include/gamefunction.h"
#include "../../game/include/SDLEngine.h"

using namespace std;

SDL_Surface*    temp        =   NULL;
SDL_Texture*    source      =   NULL;
SDL_Texture*    dummy       =   NULL;

int main (int argc, char* args[] )
{
    SCREEN_WIDTH        = 640;
    SCREEN_HEIGHT       = 480;
    SCREEN_TITLE        = "XaviGame Utility";
    PROGRAM_TIMER       = 2000;
    VERSION             = "V1.00.00";
    NAME_PROGRAM        = "XaviGame Utility";
    MEDIAFILE           = "../assets/ballguy.png";
    int SPEED           = 25;
    int w;
    int h;
    bool utilLoop = true;
    SDL_Rect sourceRect;
    SDL_Rect screenRect;
    SDL_Rect dummyRect;
    SDL_Rect dummyDisplay;

    Print("Starting Utility Program ");
    if (GameInitialise() == false)
    {
        Print("Game failed to initialise !");
    }

    source = loadTexture(MEDIAFILE);
    dummy = source;
    SDL_QueryTexture(source, NULL, NULL, &w, &h);
    Print("Ballguy");
    Print("Width  : " + to_string(w));
    Print("Height : " + to_string(h));
    Print("Sprites: " + to_string(w/28));
    sourceRect.x = 0;
    sourceRect.y = 0;
    sourceRect.w = 16;
    sourceRect.h = h;

    screenRect.x = 0;
    screenRect.y = SCREEN_HEIGHT / 2 ;
    screenRect.w = 64;
    screenRect.h = h*4;


    dummyDisplay.x = SCREEN_WIDTH / 2;
    dummyDisplay.y = 50 ;
    dummyDisplay.w = 32;
    dummyDisplay.h = h*2;

    SDL_Event gameEvent;
    while(utilLoop)
    {
        Uint32 ticks = SDL_GetTicks();
        Uint32 sprite = (ticks / SPEED) % 16;

        sourceRect.x = sprite * 16 ;
        sourceRect.y = 0;
        sourceRect.w = 16;
        sourceRect.h = h;
        screenRect.x++;
        if (screenRect.x > (SCREEN_WIDTH-64))
        {
            screenRect.x = 0;
        }
        dummyRect.x = sourceRect.x ;
        dummyRect.y = sourceRect.y ;
        dummyRect.w = sourceRect.w ;
        dummyRect.h = sourceRect.h ;
        while ( SDL_PollEvent(&gameEvent ) != 0 )
		{


		    //User requests quit
			if ( gameEvent.type == SDL_QUIT)
			{
			    utilLoop = false;
		    }
		}
		//Clear screen
		ClearScreen(White);
		SDL_RenderCopy( gRenderer, source , &sourceRect, &screenRect );
		SDL_RenderCopy( gRenderer, dummy , &dummyRect, &dummyDisplay );
		//Render texture to screen
		SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );
		//Update screen
		SDL_RenderPresent( gRenderer );
    }
  	SDL_DestroyTexture( source );
	GameTerminate();
    Print("Finishing Utility Program ");
}