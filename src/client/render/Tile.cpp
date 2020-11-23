#include <string>
#include "../render.h"

using namespace render;

Tile::Tile(TileID newID)
{

	id = newID;

	//if (id == TileID::HUD)
	//{
	//	cellWidth = 32;
	//	cellHeight = 32;
	//	resourceFile = "../../res/snow-expansion.png";
	//}

	//else if (id == TileSetID::CHARACTER)
	//{
	//	cellWidth = 32;
	//	cellHeight = 32;
	//	resourceFile = "res/characters.png";
	//}

	if (id == TileID::MAPCELL)
	{
		cellWidth = 32;
		cellHeight = 32;
		resourceFile = "./../../dell/res/snow-expansion.png";
	}


	textureTileset.loadFromFile(resourceFile);
}

const int Tile::getTileID()
{
	return id;
}

const int Tile::getCellWidth()
{
	return cellWidth;
}

const int Tile::getCellHeight()
{
	return cellHeight;
}

//const std::string Tile::getImageFile()
//{
//	return resourceFile;
//}

//sf::Texture &Tile::getTexture()
//{
//	sf::Texture &refTexture = textureTileset;
//	return refTexture;
//}
