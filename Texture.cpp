#include "Texture.h"
Texture::Texture()
{
	texture = NULL;
	clipRect = NULL;
}

Texture::~Texture()
{
	delete clipRect;
	free();
}

bool Texture::loadFromFile(std::string path, SDL2Renderer* renderer)
{
	free();

	if(renderer != NULL)
	{
		SDL_Texture* newTexture = NULL;
		SDL_Surface* loadedSurface = IMG_Load(path.c_str());
		if(loadedSurface != NULL)
		{
//			if(chromakey != NULL)
//			{
//				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, chromakey->red, chromakey->green, chromakey->blue));
//				//{
////					printf("ERROR Setting Color key SDL_ERROR: %s\n", SDL_GetError());
//	//			}
//			}
//			else
//			{
//				SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));
//			}
			newTexture = renderer->createTextureFromSurface(loadedSurface);
/*			if(newTexture != NULL)
			{
				width = loadedSurface->w;
				height = loadedSurface->h;
			}*/
			SDL_FreeSurface(loadedSurface);
		}

		texture = newTexture;

		return texture != NULL;
	}
	return false;
}

void Texture::free()
{
	if(texture != NULL)
	{
		SDL_DestroyTexture(texture);
		texture = NULL;
	}
}

void Texture::setBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(texture, blending);
}

void Texture::setAlpha(uint8_t alpha)
{
	SDL_SetTextureAlphaMod(texture, alpha);
}

void Texture::setColor(uint8_t red, uint8_t green,uint8_t blue)
{
	SDL_SetTextureColorMod(texture, red, green, blue);
}

void Texture::setClip(int x, int y, int width, int height)
{
	clipRect = new SDL_Rect();
	clipRect->x = x;
	clipRect->y = y;
	clipRect->w = width;
	clipRect->h = height;
}

void Texture::setClip(SDL_Rect& clipRect)
{
	this->clipRect = new SDL_Rect(clipRect);
}

bool Texture::generateTexture(std::string path, SDL2Renderer * renderer,
						SDL_BlendMode blendMode,
						SDL_Rect& clipRect)
{
	bool success = true;
	if(loadFromFile(path,renderer))
	{
		setBlendMode(blendMode);
		setClip(clipRect);
	}
	else
	{
		success = false;
	}
	return success;
}
