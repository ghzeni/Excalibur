#pragma once
#include "Fase.h"


class Fase2 :
	public Fase
{
public:
	Fase2();
	~Fase2();
	int Executar(Jogador* player, Jogador** player2, sf::RenderWindow& window, sf::View& view, bool* twoplayers);
	void ResizeView(const sf::RenderWindow& window, sf::View& view);

private:
	bool *twoplayers;
	sf::Texture chaoTexture;
	sf::Texture esqueletoTexture;
	sf::Texture chefaoTexture;
	sf::Texture caixaTexture;
	sf::Texture espinhoTexture;

	std::vector<Plataforma> plataformas;
	std::vector<Plataforma> caixas;
	std::vector<Obstaculo> obstaculos;
	std::vector<Esqueleto> esqueletos;
	std::vector<Obstaculo> espinhos;

	int num_esqueletos;
	bool checkpoint_reached;
	sf::Event *evnt;

};

