#pragma once

#include <math.h>
#include <map>
#include <string>
#include "GameEngine/Shader.h"
#include "GameEngine/TextRenderer.h"
#include "GameEngine/GameWindow.h"
#include "GameEngine/Texture.h"
#include "GL/glew.h"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define NUM_ELMS 361 * 3

class Renderer{
public:
	Renderer(GameWindow* win);
	virtual ~Renderer();

	void setColor(int r, int g, int b);
	void setColor(float r, float g, float b);

	void fillRect(int x, int y, int w, int h);
	void drawRect(int x, int y, int w, int h);
	void fillOval(int x, int y, int w, int h);
	void drawImage(std::string imageName, int x, int y, int w, int h);
	void drawText(std::string text, int x, int y, float scale);
	void setDimensions(float w, float h);	
	void loadImage(std::string textureName, std::string textureLoc, bool hasTransparency);
	void loadFont(std::string fontName, std::string fontLoc);
	void setFont(std::string font);	

	void setStrokeWidth(int w) { strokeWidth = w; }

	void setGameWidth(int w){ gameWidth = w; }
	void setGameHeight(int h){ gameHeight = h; }
	void setRotationRad(float r){ rotation = r; }
	void setRotationDeg(int d){ rotation = (float)d / 180.0f * 3.141592653589793; }

private:
	int gameWidth;
	int gameHeight;
	float rotation;

	GLuint sqVAO;
	GLuint sqVBO;
	GLuint crVAO;
	GLuint crVBO;

	GLuint texAttrib;

	GLuint transUniform;
	GLuint colorUniform;
	GLuint texTransUniform;

	Shader* shader;
	Shader* textureShader;

	std::map<std::string, Texture*> textures;	

	TextRenderer* textRenderer;

	GameWindow* window;

	glm::mat4 transform;

	static GLfloat crVerts[722];
	static GLuint crElmts[NUM_ELMS];

	void initCrVerts();
	void calcScale(int w, int h);
	void calcTranslate(int x, int y);
	void calcRotation();
	void loadUniforms();
	void initShaders();
	void initRectBuffer();
	void initEllipseBuffer();

	int strokeWidth;
	
	float r;
	float g;
	float b;
};
