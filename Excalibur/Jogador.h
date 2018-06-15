#pragma once
#include <SFML\Graphics.hpp>
#include "Animacao.h"
#include "Colisor.h"
#include "Personagem.h"

class Jogador : public Personagem
{
public:
	Jogador(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed, int health, int attack, int id, float jumpHeight);
	~Jogador();

	void Update(float deltaTime);
	void Draw(sf::RenderWindow &window);
	void OnCollision(sf::Vector2f direcao);

	sf::Vector2f GetPosition() { return body.getPosition(); }
	Colisor GetCollider() { return Colisor(body); }

private:
	bool canJump;
	bool isJumping;
	float jumpHeight; //200.f


};

