#ifndef TEXTURE
#define TEXTURE
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "SDL2Renderer.h"
#include "RGB.h"
class Texture
{
	public:
		Texture();
		~Texture();
		bool loadFromFile(std::string path, SDL2Renderer* renderer);
		void free();
		void setColor(uint8_t red, uint8_t green,uint8_t blue);
		void setBlendMode(SDL_BlendMode blending);
		void setAlpha(uint8_t alpha);
		void setClip(int x, int y, int width, int height);
		void setClip(SDL_Rect& rect);
		SDL_Rect* getClip() {return clipRect;}
		SDL_Texture* getTexture() {return texture;}
		bool generateTexture(std::string path, SDL2Renderer * renderer,
			SDL_BlendMode blendMode,
			SDL_Rect& clipRect);
	protected:
		SDL_Texture* texture;
		SDL_Rect* clipRect;
};


#endif
