#pragma once

#include "GameEngine/GameObject.h"

class CollisionBox: public GameObject{
	public:
		CollisionBox(int x, int y, int w, int h);

		virtual void update();
		virtual void update(int x, int y, int w, int h);
		virtual void draw(Renderer* r);
		virtual void checkCollision(GameObject o);
	
		bool isColliding(){ return collision; }

	private:
		bool collision;

		virtual void init();

};
