#pragma once
#include <SFML/Graphics.hpp>
#include "Gosma.h"
#include "Morcego.h"
#include "Esqueleto.h"
#include "Chefao.h"
#include "Item.h"
#include "Jogador.h"
#include <iostream>
#include <vector>
#include <time.h>
#include "Plataforma.h"
#include "Obstaculo.h"
#include "Checkpoint.h"
#include "Arma.h"

using namespace std;

class Fase
{
public:
	Fase();
	~Fase();
	virtual int Executar(Jogador* player, Jogador *player2, sf::RenderWindow& window, sf::View& view, bool* twoplayers) = 0;
	void ResizeView(const sf::RenderWindow& window, sf::View& view); //verificar

protected:
	sf::Sprite background;
	sf::Texture plataforma;
	sf::Texture backgroundTexture;
	sf::Texture background2Texture;
	sf::Texture plataformaTexture;
	sf::Vector2f direcao; //passada pra OnCollision e pra player OnCollision

	Jogador* player;
	Jogador* player2;
	
};

