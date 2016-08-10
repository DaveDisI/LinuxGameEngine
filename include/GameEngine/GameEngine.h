#pragma once

#include <iostream>
#include "SDL2/SDL.h"
#include "GL/glew.h"
#include "GameEngine/Renderer.h"
#include "GameEngine/GameWindow.h"

class GameEngine{
public:
	virtual ~GameEngine();

	static GameEngine* getInstance();
	void startGame();
	void stopGame();
	
	const Uint8* getKeyState();

	const static int UP_KEY;
	const static int DOWN_KEY;
	const static int LEFT_KEY;
	const static int RIGHT_KEY;

private:
	GameEngine();

	Renderer* renderer;
	GameWindow* window;

	static GameEngine* gameEngineInstance;
	Uint8* keyState;	
};
