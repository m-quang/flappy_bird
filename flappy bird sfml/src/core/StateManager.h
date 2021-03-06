#pragma once
#include <list>
#include <memory>
#include <SFML/Graphics.hpp>
#include "IStates.h"
#include <state/GameState.h>

class GameState;
class StateManager
{
private:
	std::list<std::shared_ptr<IState>> m_state;
	static StateManager* s_instance;
	StateManager() {}
public:
	static StateManager& instance()
	{
		if (s_instance == nullptr) s_instance = new StateManager();
		return *s_instance;
	}

	void pushBack(const std::shared_ptr<IState>& state);
	void popBack();
	void popFront();
	std::shared_ptr<IState> getState();
	std::shared_ptr<IState> findState(std::shared_ptr<GameState> state);
	void update(float deltaTime);
	void draw(sf::RenderWindow& window);
	void handleInput();
};

