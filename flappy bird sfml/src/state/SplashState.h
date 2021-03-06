#pragma once
#include <core/StateManager.h>

class SplashState : public IState
{
private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	float m_time;
public:
	// Inherited via IState
	virtual void init() override;
	virtual void handleInput() override;
	virtual void update(float deltaTime) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void onPushState() override;
	virtual void onPopState() override;
};

