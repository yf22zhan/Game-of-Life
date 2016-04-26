#pragma once
#include "SFML/Graphics.hpp"

class FontProvider
{
public:
	enum FontType
	{
		Sansation, OpenSans
	};

	FontProvider();
	~FontProvider();
	sf::Font &getFont(FontType font_type) const;

private:
	sf::Font *sansation;
	sf::Font *openSans;
};