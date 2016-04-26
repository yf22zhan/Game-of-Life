#include "FontProvider.h"
#include <assert.h>

FontProvider::FontProvider()
{
	sansation = new sf::Font();
	assert(sansation->loadFromFile("font/Sansation-Regular.ttf"));

	openSans = new sf::Font();
	assert(openSans->loadFromFile("font/OpenSans-Semibold.ttf"));
}

FontProvider::~FontProvider()
{
	delete sansation;
	delete openSans;
}

sf::Font &FontProvider::getFont(FontType font_type) const
{
	switch (font_type)
	{
		case FontProvider::FontType::Sansation:
			return *sansation;
			break;

		case FontProvider::FontType::OpenSans:
			return *openSans;
			break;

		default:
			return *openSans;
			break;
	}
}