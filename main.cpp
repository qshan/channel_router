#include "renderer.h"
#include "logic.h"

#include <SDL.h>


int main( int argc, char* args[] )
{

	ZRender renderer("ChannelRouter");
	ZChannelRouter router;
	ZInterLayer il(renderer,router);

	//il.draw_terms();
	//router.route();
	//il.draw_routed_segments();

    
        unsigned int lastTime = 0, currentTime;
        //SDL_RenderSetScale(gRenderer,6.0,6.0);

	SDL_Event e;
	bool quit = false;
        while( !quit )
        {
                currentTime = SDL_GetTicks();
                if (currentTime > lastTime + 100) {

		    while( SDL_PollEvent( &e ) != 0 )
		    {
			    if ( e.type == SDL_QUIT ) quit = true;
			    //if ( e.type == SDL_MOUSEBUTTONDOWN ) renderer.draw_line(0,0,10,10);
			    //if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {

			    //for dbg
			    //if ( e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_u) {
				//j->undo_permute();
			    //}
		    } 
		    
		    il.draw();
		    //renderer.draw_line(0,0,10,10);
		    lastTime = currentTime;  
		}
        }

        renderer.close();
        return 0;
}