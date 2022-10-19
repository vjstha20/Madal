#include<SDL.h>
#include<SDL_mixer.h>
#include<SDL_image.h>
#include<iostream>
using namespace std;

class Image{
	private:
		SDL_Surface * image = NULL;
	public:
		Image(const char file[] = NULL)
		{
			image = SDL_LoadBMP(file);
		}
		void draw(SDL_Surface *destination)
		{
			SDL_BlitSurface(image,NULL,destination,NULL);
		}
		void destruct()
		{
			SDL_FreeSurface(image);
			image = NULL;
		}
};

class Audio{
	private:
		Mix_Chunk *sound = NULL;
	public:
		Audio(const char filename[] = NULL)
		{
			sound = Mix_LoadWAV(filename);
		}
		void play()
		{
			Mix_PlayChannel(-1,sound,0);	
		}
		void destroy()
		{
			Mix_FreeChunk(sound);
			sound = NULL;
		}
};


int main(int argc, char *argv[] )
{
	SDL_Window *window = NULL;
	SDL_Surface *windowSurface = NULL;
	
	const Uint8 *press;
	
	SDL_Init(SDL_INIT_EVERYTHING);
	
	window = SDL_CreateWindow("MADAL",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,706,474, SDL_WINDOW_SHOWN);
	windowSurface = SDL_GetWindowSurface(window);
	
	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,2,2048)<0)
	cout<<"ERROR PLAYING AUDIO ):"<<Mix_GetError()<<endl;

	
	Audio dhing("dhing.wav"),taang("taang.wav"),taak("taak.wav"),khaa("khaa.wav"),dhaang("dhaang.wav");
	
	Image back("back.bmp"), forg("forg.bmp"),forf("forf.bmp"),forh("forh.bmp"),forj("forj.bmp"),forspace("forspace.bmp");
	back.draw(windowSurface);
	
	
	bool running = true;
	SDL_Event ev ;
	while(running)
	{
		while(SDL_PollEvent(&ev)!=0)
		{
			if(ev.type == SDL_QUIT)
			running = false;
			
			if(ev.type==SDL_MOUSEBUTTONDOWN)
			{
				int x,y;
				SDL_GetMouseState(&x,&y);
				if(x>164&& x<249 && y>157&& y<246)
				{
					
					dhing.play();
					
				}
				else if(x>419&& x<506 && y>157&& y<246)
				{
					
				taang.play();
					
				}
				else if(x>294&& x<382 && y>210&& y<300)
				{
					
				dhaang.play();	
				
				}
				else if(x>164&& x<253 && y>331&& y<424)
				{
						
				khaa.play();
				
				}
				else if(x>420&& x<509 && y>333&& y<423)
				{
				
				taak.play();
					
				}
			}
			else if(ev.type == SDL_KEYDOWN)
			{
				switch(ev.key.keysym.sym)
				{
				case SDLK_f:
					dhing.play();
					break;
					case SDLK_g:
						taang.play();
						break;
						case SDLK_h:
							taak.play();
							break ;
							case SDLK_j:
								khaa.play();
								break;
								case SDLK_SPACE:
									dhaang.play();
									break;
			}
			}
			
		}
	
		press = SDL_GetKeyboardState(NULL);
		int x,y;
		SDL_GetMouseState(&x,&y);
		
		if(press[SDL_SCANCODE_F] || (x>164&& x<249 && y>157&& y<246) && SDL_BUTTON(1) )
		{
			forf.draw(windowSurface);
			
		}
		else if(press[SDL_SCANCODE_G] || (x>419&& x<506 && y>157&& y<246) && SDL_BUTTON(1))
		{
			forg.draw(windowSurface);
		}
		else if(press[SDL_SCANCODE_H] || (x>420&& x<509 && y>333&& y<423) && SDL_BUTTON(1))
		{
			forh.draw(windowSurface);
		}
		else if(press[SDL_SCANCODE_J] || (x>164&& x<253 && y>331&& y<424) && SDL_BUTTON(1))
		{
			forj.draw(windowSurface);
		}
		else if(press[SDL_SCANCODE_SPACE] || (x>294&& x<382 && y>210&& y<300) && SDL_BUTTON(1))
		{
			forspace.draw(windowSurface);
		}
		else
		{
			back.draw(windowSurface);
		}
		
		
		
		SDL_UpdateWindowSurface(window);
	}
	
	SDL_DestroyWindow(window);
	dhing.destroy();
	taak.destroy();
	taang.destroy();
	khaa.destroy();
	dhaang.destroy();
	
	back.destruct();
	forf.destruct();
	forg.destruct();
	forh.destruct();
	forj.destruct();
	forspace.destruct();
	
	window = NULL;
	
	Mix_Quit();
	SDL_Quit();
	return 0;
		
}
