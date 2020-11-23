#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include "../render.h"
#include <iostream>
#include <fstream>
#include <memory>
#include <sstream>
#include <unistd.h>

using namespace render;
using namespace std;
using namespace state;

StateLayer::StateLayer (state::State& state, sf::RenderWindow& window, std::string env) : window(window)
{
    font.loadFromFile("../res/text_textures/neo-latina-demo-FFP.ttf");

    std::unique_ptr<Tile> tileMapCell(new Tile(TileID::MAPCELL));
    
}

void StateLayer::initLayer(state::State &state, const int *level)
{
    //render::LoadLayer *layer;
    //layer->loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),level, 30, 30);
}


std::vector<std::unique_ptr<LoadLayer>> &StateLayer::getLayer()
{
    std::vector<std::unique_ptr<LoadLayer>> &refLayer = layer;
    return refLayer;
}


void StateLayer::draw(sf::RenderWindow &window)
{
    
    draw(window);
    window.display();
}
