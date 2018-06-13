// Excalibur.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Animacao.h"
#include "Jogador.h"
#include "Objeto.h"


static const float VIEW_HEIGHT = 512.0f;

void ResizeView(const sf::RenderWindow& window, sf::View& view)
{
	float aspectRatio = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(VIEW_HEIGHT * aspectRatio, VIEW_HEIGHT);
}

int main()
{
	
	sf::RenderWindow window(sf::VideoMode(512, 512), "NomeJanela", sf::Style::Close | sf::Style::Resize);
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(VIEW_HEIGHT, VIEW_HEIGHT));
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");

	Jogador player(&playerTexture, sf::Vector2u(3, 9), 0.3f, 100.0f, 200.f);

	std::vector<Objeto> plataformas;

	plataformas.push_back(Objeto(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f)));
	plataformas.push_back(Objeto(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f)));
	plataformas.push_back(Objeto(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f))); //caso queira múltiplas plataformas
	//plataforma que possa mover: 




	Objeto platform1(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 200.0f));
	Objeto platform2(nullptr, sf::Vector2f(400.0f, 200.0f), sf::Vector2f(500.0f, 0.0f));
	Objeto platform3(nullptr, sf::Vector2f(1000.0f, 200.0f), sf::Vector2f(500.0f, 500.0f));


	float deltaTime = 0.0f;
	sf::Clock clock;


	while (window.isOpen())
	{
		deltaTime = clock.restart().asSeconds();
		if (deltaTime > 1.0f / 20.0f)
			deltaTime = 1.0f / 20.0f;

		sf::Event evnt;

		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::Resized:
				ResizeView(window, view);
				break;


			}

		}

		/*
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
		sf::Vector2i mousePos = sf::Mouse::getPosition(window);
		player.setPosition((float)mousePos.x, static_cast<float>(mousePos.y));
		}
		*/


		player.Update(deltaTime);

		sf::Vector2f direcao; //passada pra OnCollision e pra player OnCollision

		
		/**for (int i = 0; i < plataformas.size(); i++)
		{
			Objeto& plataforma = plataformas[i];
		}**/

		for (Objeto& plataforma : plataformas)
		{
			if (plataforma.GetCollider().CheckCollision(&(player.GetCollider()), direcao, 1.0f))
				player.OnCollision(direcao);
		}



		view.setCenter(player.GetPosition()); //depois de update sempre
		


		window.clear(sf::Color(150,150,150));
		window.setView(view);
		player.Draw(window);
		platform1.Draw(window);
		platform2.Draw(window);

		for (Objeto& plataforma : plataformas)
			plataforma.Draw(window);

		window.display();
		

	}

	return 0;
}

