#include "../render.h"
#include <iostream>
#include <fstream>
#include <sstream>

#include <cstdlib>
using namespace std;
using namespace sf;
using namespace state;
using namespace render;



bool LoadLayer::loadTextures(state::State& state, const std::string& tileset, sf::Vector2u tileSize, std::vector<int> tiles, unsigned int width, unsigned int height)
{
    

    // on charge la texture du tileset
    if (!m_tileset.loadFromFile(tileset))
        return false;
    // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(width * height * 4);

    // on remplit le tableau de vertex, avec un quad par tuile
    for (unsigned int i = 0; i < width; ++i)
        for (unsigned int j = 0; j < height; ++j)
        {
            // on récupère le numéro de tuile courant
            int tileNumber = tiles[i + j * width];

            // on en déduit sa position dans la texture du tileset
            int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
            int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

            // on récupère un pointeur vers le quad à définir dans le tableau de vertex
            sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

            // on définit ses quatre coins
            quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
            quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
            quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
            quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

            // on définit ses quatre coordonnées de texture
            quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
        }

    return true;
}

void LoadLayer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
    

    
}

std::vector<int> LoadLayer::MakeLayer_1 (){

    int a;
    std::vector<int> layer_1;
    ifstream monFlux("../res/map1.txt");  //Ouverture d'un fichier en lecture

    if(monFlux)
    {
        for(int i=0;i<900;i++) {
        monFlux >> a;
        layer_1.push_back(a);
    }
    }

    monFlux.close();


    return layer_1;

}

std::vector<int> LoadLayer::MakeLayer_2 (){

    int a;
    std::vector<int> layer_2;
    ifstream monFlux("../res/map2.txt");  //Ouverture d'un fichier en lecture

    if(monFlux)
    {
        for(int i=0;i<900;i++) {
        monFlux >> a;
        layer_2.push_back(a);
    }
    }
    monFlux.close();


    return layer_2;

}

std::vector<int> LoadLayer::MakeLayer_UI (){

    int a;
    std::vector<int> layer_ui;
    ifstream monFlux("../res/ui.txt");  //Ouverture d'un fichier en lecture

    if(monFlux)
    {
        for(int i=0;i<900;i++) {
        monFlux >> a;
        layer_ui.push_back(a);
    }
    }
    monFlux.close();


    return layer_ui;

}
