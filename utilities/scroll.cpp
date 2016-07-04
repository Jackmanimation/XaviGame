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
#include<ctime>
#include<cstdlib>

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

int main (int argc, char* args[] )
{
    SCREEN_WIDTH        = 640;
    SCREEN_HEIGHT       = 480;
    SCREEN_TITLE        = "Scroll";
    PROGRAM_TIMER       = 2000;
    VERSION             = "V1.00.00";
    NAME_PROGRAM        = "Scroll";
    MEDIAFILE           = "../files/parallax/Sky_back_layer.png";

    bool utilLoop = true;

    SDL_Surface*    temp            =   NULL;

    SDL_Texture*    back            =   NULL;
    SDL_Texture*    middle          =   NULL;
    SDL_Texture*    front           =   NULL;

    SDL_Rect        middle_rect1;
    SDL_Rect        middle_rect2;
    SDL_Rect        front_rect1;
    SDL_Rect        front_rect2;
    SDL_Rect        display_middle_rect1;
    SDL_Rect        display_middle_rect2;
    SDL_Rect        display_front_rect1;
    SDL_Rect        display_front_rect2;

    int             middle_scroll_width    =   0;
    int             front_scroll_width     =   0;

    middle_rect1.x = 0;
    middle_rect1.y = 0;
    middle_rect1.w = SCREEN_WIDTH;
    middle_rect1.h = SCREEN_HEIGHT;

    middle_rect2.x = 0;
    middle_rect2.y = 0;
    middle_rect2.w = SCREEN_WIDTH;
    middle_rect2.h = SCREEN_HEIGHT;

    display_middle_rect1.x = 0;
    display_middle_rect1.y = 0;
    display_middle_rect1.w = SCREEN_WIDTH;
    display_middle_rect1.h = SCREEN_HEIGHT;

    display_middle_rect2.x = 0;
    display_middle_rect2.y = 0;
    display_middle_rect2.w = SCREEN_WIDTH;
    display_middle_rect2.h = SCREEN_HEIGHT;
    
    front_rect1.x = 0;
    front_rect1.y = 0;
    front_rect1.w = SCREEN_WIDTH;
    front_rect1.h = SCREEN_HEIGHT;

    front_rect2.x = 0;
    front_rect2.y = 0;
    front_rect2.w = SCREEN_WIDTH;
    front_rect2.h = SCREEN_HEIGHT;

    display_front_rect1.x = 0;
    display_front_rect1.y = 0;
    display_front_rect1.w = SCREEN_WIDTH;
    display_front_rect1.h = SCREEN_HEIGHT;

    display_front_rect2.x = 0;
    display_front_rect2.y = 0;
    display_front_rect2.w = SCREEN_WIDTH;
    display_front_rect2.h = SCREEN_HEIGHT;

    SDL_Event       gameEvent;

    Print("Starting "+string(NAME_PROGRAM)+" Program ");
    if (GameInitialise() == false)
    {
        Print("Game failed to initialise !");
    }

    back = loadTexture(MEDIAFILE);
    middle = loadTexture("../files/parallax/Vegetation_middle_layer.png");
    front = loadTexture("../files/parallax/Ground_front_layer.png");

    while(utilLoop)
    {

        middle_scroll_width += 1;
        if (middle_scroll_width > SCREEN_WIDTH)
        {
            middle_scroll_width = 0;
        }
        middle_rect1.x = 0;
        middle_rect1.w = middle_scroll_width;

        display_middle_rect1.x = SCREEN_WIDTH - middle_scroll_width;
        display_middle_rect1.w = middle_scroll_width;

        middle_rect2.x = middle_scroll_width;
        middle_rect2.w = SCREEN_WIDTH - middle_scroll_width;

        display_middle_rect2.x = 0;
        display_middle_rect2.w = SCREEN_WIDTH - middle_scroll_width;

        front_scroll_width += 2;
        if (front_scroll_width > SCREEN_WIDTH)
        {
            front_scroll_width = 0;
        }
        front_rect1.x = 0;
        front_rect1.w = front_scroll_width;

        display_front_rect1.x = SCREEN_WIDTH - front_scroll_width;
        display_front_rect1.w = front_scroll_width;

        front_rect2.x = front_scroll_width;
        front_rect2.w = SCREEN_WIDTH - front_scroll_width;

        display_front_rect2.x = 0;
        display_front_rect2.w = SCREEN_WIDTH - front_scroll_width;

        // Get input from the keyboard
        while ( SDL_PollEvent(&gameEvent ) != 0 )
		{

		    //User requests quit
			if ( gameEvent.type == SDL_QUIT)
			{
			    utilLoop = false;
		    }
		}

        // render the textures to the screen
		// Clear screen
		ClearScreen(White);

        // Background
        // Layer 1 (Background)
        SDL_RenderCopy( gRenderer, back, NULL, NULL);
        // Layer 2 (Middle)
        SDL_RenderCopy( gRenderer, middle, &middle_rect1, &display_middle_rect1);
        SDL_RenderCopy( gRenderer, middle, &middle_rect2, &display_middle_rect2);
        // Layer 3 (Front)
        SDL_RenderCopy( gRenderer, front, &front_rect1, &display_front_rect1);
        SDL_RenderCopy( gRenderer, front, &front_rect2, &display_front_rect2);

        // NPC Objects
        // Not implemented yet
        // TODO: Implement NPC Rendering
        // SDL_RenderCopy( gRenderer, npc, &npc_rect, &display_npc_rect);

        // Player Objects
        // Not implemented yet
        // TODO: Implement Player Object Rendering
        // SDL_RenderCopy( gRenderer, player, &player_rect, &display_player_rect);

		//Update screen
		SDL_RenderPresent( gRenderer );
    }

    // tidy up when finished
	SDL_DestroyTexture( front );
	front = NULL;
	SDL_DestroyTexture( middle );
	middle = NULL;
	SDL_DestroyTexture( back );
	back  = NULL;
    TTF_Quit();
	GameTerminate();
    Print("Finishing "+string(NAME_PROGRAM)+" Utility Program ");
}