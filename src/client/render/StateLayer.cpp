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

    
}

void StateLayer::initLayer(state::State &state)
{
    LoadLayer layer_1, layer_2,layer_3, layer_ui;
    
    layer.clear();
    layer_1.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_1(), 30, 30);
    layer.push_back(layer_1);
    layer_2.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_2(), 30, 30);
    layer.push_back(layer_2);
    layer_ui.loadTextures(state,"../res/ui_textures/ui.png", sf::Vector2u(16, 16),LoadLayer::MakeLayer_UI(), 30, 30);
    layer.push_back(layer_ui);
    layer_3.loadTextures(state,"../res/snow-expansion.png", sf::Vector2u(16, 16),state.cMap, 30, 30);
    layer.push_back(layer_3);


}


std::vector<LoadLayer> &StateLayer::getLayer()
{
    std::vector<LoadLayer> &refLayer = layer;
    return refLayer;
}


void StateLayer::draw(sf::RenderWindow &window)
{
    window.clear();
    for(size_t k=0;k<layer.size();k++){
        window.draw(layer[k]);
    }
    window.display();
}
