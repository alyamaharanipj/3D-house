#include <stdlib.h>
#include <GL/glut.h>
#include "BmpLoader.h"
#include "DataType.h"
#include "DisplayMode.h"
#include "Roof.h"
#include "Body.h"
#include <iostream>

using namespace std;

char title[] = "Alya - 181511038";
int refreshMills = 15;
unsigned int ID;
float _angle = 0.0;
GLuint _textureFence2, _textureBricks, _textureDoor, _textureGrass,_textureRoof, _textureWindow, _textureSky, _textureFence, _textureWood, _textureWood2;

void Init();
void KeyboardHandler(int key, int x, int y);
void Reshape(GLsizei width, GLsizei height);
void Display();
void Timer(int value);
void front_display();
void side_display();
void base_display();
GLuint loadTexture(const char* filename);

int main(int argc, char **argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(50, 50);
	glutCreateWindow(title);
	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutSpecialFunc(KeyboardHandler);
	Init();
	glutMainLoop();
	return 0;
}

void drawGrass(){
    //Alas
    point startPoint = {-50, -1.5, 50};
    point endPoint = {50, -1.5, -50};
    tile objectTile = {70, 70};

    DisplayMode grass(startPoint, endPoint, objectTile, _textureGrass, _angle);
    grass.displayBase();

    //Alas Brick
    startPoint = {5.5, -1.49, 4};
    endPoint = {7.5, -1.49, -3.5};
    objectTile = {1, 1};

    DisplayMode grassBase(startPoint, endPoint, objectTile, _textureBricks, _angle);
    grassBase.displayBase();
}

void drawSky(){
    // Sky
    point startPoint = {-50, 50, 50};
    point endPoint = {50, -50, -50};
    tile objectTile = {1, 1};

    Body sky(startPoint, endPoint, objectTile, _textureSky, _angle);
    sky.displayBody();
}

void drawFirstFloor(){
    // Draw Brick for Left-Front Side
    point startPoint = {-3.5, 0.3, -1};
    point endPoint = {-3, -1.5, -3.5};
    tile objectTile = {1, 1};

    Body leftBrick(startPoint, endPoint, objectTile, _textureBricks, _angle);
    leftBrick.displayBody();

    // Draw Wood Wall
    startPoint = {-3, 0.3, -1.7};
    endPoint = {-2.2, -1.5, -1.7};
    objectTile = {1, 1};

    DisplayMode wood(startPoint,endPoint,objectTile,_textureWood,_angle);
    wood.displayFront();

    // Draw Window
    startPoint = {-2.2, 0.3, -1.7};
    endPoint = {2.5, -1.5, -1.7};
    objectTile = {1, 3};

    DisplayMode window(startPoint,endPoint,objectTile,_textureWindow,_angle);
    window.displayFront();

    // Draw Brick for Right-Front Side
    startPoint = {2.5, 0.3, -1.7};
    endPoint = {3.5, -1.5, -3.5};
    objectTile = {1, 1};

    Body rightBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    rightBrick.displayBody();

    // Draw Side Window
    startPoint = {3.51, 0.2, -2};
    endPoint = {3.51, 0, -3.3};
    objectTile = {1, 3};

    DisplayMode sideWindow(startPoint,endPoint,objectTile,_textureWindow,_angle);
    sideWindow.displaySide();

    // Draw Roof
    startPoint = {-3.5, 0.5, -0.7};
    endPoint = {3.8, 0.3, -3.5};
    objectTile = {1, 1};

    Roof firstRoof(startPoint,endPoint,objectTile,_angle);
    firstRoof.displayRoof();
}

void drawSecondFloor(){
    // Draw Left Side
    // Draw Glass + Brick for Left Side
    point startPoint = {-3.5, 1, -0.7};
    point endPoint = {-3.5, 0.5, -2};
    tile objectTile = {1, 1};

    DisplayMode glass(startPoint,endPoint,objectTile,_textureWindow,_angle);
    glass.displaySide();

    //Front glass
    startPoint = {-3.5, 1, -0.7};
    endPoint = {1.5, 0.5, -0.7};
    objectTile = {1, 1};

    DisplayMode glass2(startPoint,endPoint,objectTile,_textureWindow,_angle);
    glass2.displayFront();

    startPoint = {-3.5, 2.1, -2};
    endPoint = {-3.5, 0.5, -3.5};
    objectTile = {1, 1};

    DisplayMode leftSideBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    leftSideBrick.displaySide();

    // Draw Left Section
    // Draw Brick for Left-Front Side
    startPoint = {-2.5, 2.1, -2.2};
    endPoint = {-3.5, 0.5, -2.2};
    objectTile = {1, 1};

    DisplayMode leftSectionBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    leftSectionBrick.displayFront();

    // Splitter
    // Draw wood (lekuk)
    startPoint = {-2.5, 2.1, -2};
    endPoint = {-2.5, 0.5, -2.2};
    objectTile = {1, 1};

    DisplayMode sideWood(startPoint,endPoint,objectTile,_textureWood,_angle);
    sideWood.displaySide();


    // Draw Center Section
    // Draw wood to the front
    startPoint = {-1.5, 2.1, -2};
    endPoint = {-2.5, 0.5, -2};
    objectTile = {1, 1};

    DisplayMode centerSectionWood(startPoint,endPoint,objectTile,_textureWood,_angle);
    centerSectionWood.displayFront();

    //Draw 2 window beside wood
    startPoint = {-1.5, 2.1, -2};
    endPoint = {-0.8, 0.5, -2};
    objectTile = {1, 1};

    DisplayMode firstWindow(startPoint,endPoint,objectTile,_textureWindow,_angle);
    firstWindow.displayFront();

    startPoint = {-0.8, 2.1, -2};
    endPoint = {1.5, 0.5, -2};
    objectTile = {1, 1};

    DisplayMode secondWindow(startPoint,endPoint,objectTile,_textureWindow,_angle);
    secondWindow.displayFront();

    // Splitter
    // Draw Brick and Window for Right-Side Side
    // Brick
    startPoint = {1.5, 2.1, -2};
    endPoint = {1.5, 0.5, -2.8};
    objectTile = {1, 1};

    DisplayMode rightFrontBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    rightFrontBrick.displaySide();

    startPoint = {1.5, 1, -0.7};
    endPoint = {1.5, 0.5, -2};
    objectTile = {1, 1};

    DisplayMode rightSideBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    rightSideBrick.displaySide();

    //Window
    startPoint = {1.51, 1.9, -2.1};
    endPoint = {1.51, 1.6, -2.7};
    objectTile = {1, 1};

    DisplayMode sideWindow(startPoint,endPoint,objectTile,_textureWindow,_angle);
    sideWindow.displaySide();

    // Draw Right Section
    // Draw Brick for Right-Front Side (Setelah lekuk)
    startPoint = {1.5, 2.1, -2.8};
    endPoint = {3.5, 0.5, -3.5};
    objectTile = {1, 1};

    Body rightSectionBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    rightSectionBrick.displayBody();

    // Draw Wood
    startPoint = {2.15, 2.1, -2.79};
    endPoint = {2.85, 0.5, -2.79};
    objectTile = {1, 1};

    DisplayMode rightSectionWood(startPoint,endPoint,objectTile,_textureWood2,_angle);
    rightSectionWood.displayFront();

    // Draw Roof
    startPoint = {-3.5, 2.3, -0.7};
    endPoint = {1.7, 2.1, -3.5};
    objectTile = {1, 1};

    Roof firstRoof(startPoint,endPoint,objectTile,_angle);
    firstRoof.displayRoof();

    startPoint = {1.5, 2.2, -2};
    endPoint = {3.8, 2, -3.5};
    objectTile = {1, 1};

    Roof secondRoof(startPoint,endPoint,objectTile,_angle);
    secondRoof.displayRoof();

}

void drawBackBody(){
    // Draw Wood Body
    point startPoint = {-3.5, 4, -3.5};
    point endPoint = {3.8, -1.5, -9};
    tile objectTile = {1, 1};

    Body woodBody(startPoint, endPoint, objectTile, _textureWood, _angle);
    woodBody.displayBody();

    startPoint = {-1, 3, -9};
    endPoint = {3.8, -1.5, -12.5};
    objectTile = {1, 1};

    Body woodBody3(startPoint, endPoint, objectTile, _textureWood, _angle);
    woodBody3.displayBody();

    // Draw Back Door Wood Body
    startPoint = {3, 0.1, -12.51};
    endPoint = {2, -1.5, -12.5};
    objectTile = {1, 1};

    DisplayMode backDoor(startPoint, endPoint, objectTile, _textureDoor, _angle);
    backDoor.displayFront();

    // Draw Window on Back Side Wood Body
    startPoint = {-1.5, 3.3, -9.01};
    endPoint = {-3, 1.5, -9.01};
    objectTile = {1, 2};

    DisplayMode seventhWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    seventhWindow.displayFront();

    // Draw Window on Back Side Wood Body
    startPoint = {3.4, 2.3, -12.51};
    endPoint = {-0.5, 2, -12.51};
    objectTile = {1, 4};

    DisplayMode eigthWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    eigthWindow.displayFront();

    // Draw Window on Back Side Wood Body
    startPoint = {3.4, 3.7, -3.49};
    endPoint = {1.5, 3.5, -3.49};
    objectTile = {1, 2};

    DisplayMode ninthWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    ninthWindow.displayFront();

    // Draw Window on Right Side Wood Body
    startPoint = {3.81, 3.3, -4};
    endPoint = {3.8, 1.5, -4.5};
    objectTile = {2, 1};

    DisplayMode firstWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    firstWindow.displaySide();

    startPoint = {-3.51, 4, -3.5};
    endPoint = {-3.51, -1.5, -9};
    objectTile = {2, 2};

    DisplayMode sideBrick(startPoint,endPoint,objectTile,_textureBricks,_angle);
    sideBrick.displaySide();

    startPoint = {3.81, 0.5, -3.7};
    endPoint = {3.8, -1.5, -4.7};
    objectTile = {1, 1};

    DisplayMode secondWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    secondWindow.displaySide();

    //Roof Wood Body
    startPoint = {-3.5, 4.2, -3.5};
    endPoint = {3.8, 4, -9};
    objectTile = {1, 1};

    Roof firstRoof(startPoint,endPoint,objectTile,_angle);
    firstRoof.displayRoof();

    //Roof Wood Body
    startPoint = {-1.2, 3.2, -9};
    endPoint = {4.8, 3, -13};
    objectTile = {1, 1};

    Roof sixthRoof(startPoint,endPoint,objectTile,_angle);
    sixthRoof.displayRoof();

    // Draw Black Body
    startPoint = {3.8, 3.5, -5};
    endPoint = {5.5, -1.5, -7.5};
    objectTile = {1, 1};

    Body blackBody(startPoint, endPoint, objectTile, _textureRoof, _angle);
    blackBody.displayBody();

    // Draw Window on Black Body
    startPoint = {4, 0.5, -4.99};
    endPoint = {5.2, -1.5, -4.99};
    objectTile = {1, 1};

    DisplayMode thirdWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    thirdWindow.displayFront();

    startPoint = {4.5, 3, -4.99};
    endPoint = {5.5, 1, -4.99};
    objectTile = {1, 1};

    DisplayMode fourthWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    fourthWindow.displayFront();

    startPoint = {5.51, 3, -4.99};
    endPoint = {5.51, 1, -5.3};
    objectTile = {1, 1};

    DisplayMode fifthWindow(startPoint, endPoint, objectTile, _textureWindow, _angle);
    fifthWindow.displaySide();

    //Draw Brick Body
    startPoint = {5.5, 2.6, -5.5};
    endPoint = {7.5, -1.5, -7.5};
    objectTile = {1, 1};

    Body brickBody(startPoint, endPoint, objectTile, _textureBricks, _angle);
    brickBody.displayBody();

    //Roof Brick Body
    startPoint = {5.5, 2.8, -5.3};
    endPoint = {7.7, 2.6, -7.7};
    objectTile = {1, 1};

    Roof secondRoof(startPoint,endPoint,objectTile,_angle);
    secondRoof.displayRoof();

    //Wood Body for Door
    startPoint = {5.7, 0.3, -3.5};
    endPoint = {7.5, -1.5, -5.5};
    objectTile = {1, 1};

    Body woodDoorBody(startPoint, endPoint, objectTile, _textureWood, _angle);
    woodDoorBody.displayBody();

    //Roof Wood Body for Door
    startPoint = {5.5, 0.5, -2.5};
    endPoint = {7.7, 0.3, -5.5};
    objectTile = {1, 1};

    Roof thirdRoof(startPoint,endPoint,objectTile,_angle);
    thirdRoof.displayRoof();

    //Brick for left side o door
    startPoint = {5.5, 0.3, -2.5};
    endPoint = {5.7, -1.5, -5.5};
    objectTile = {1, 1};

    Body leftSideBrick(startPoint, endPoint, objectTile, _textureBricks, _angle);
    leftSideBrick.displayBody();

    //Door
    startPoint = {6, 0, -3.49};
    endPoint = {7, -1.5, -3.49};
    objectTile = {1, 1};

    DisplayMode door(startPoint, endPoint, objectTile, _textureDoor, _angle);
    door.displayFront();

    // Draw Brick Back Body
    startPoint = {3.8, 2.7, -7.5};
    endPoint = {5.5, 0.5, -10.5};
    objectTile = {1, 1};

    Body brickBackBodyTop(startPoint, endPoint, objectTile, _textureBricks, _angle);
    brickBackBodyTop.displayBody();

    //Window back brick
    startPoint = {6.4, 0.5, -7.51};
    endPoint = {7.1, -1.5, -7.51};
    objectTile = {1, 1};

    DisplayMode windowBrick(startPoint, endPoint, objectTile, _textureWindow, _angle);
    windowBrick.displayFront();

    startPoint = {3.8, 0.5, -7.5};
    endPoint = {6, -1.5, -11.5};
    objectTile = {1, 1};

    Body brickBackBodyBottom(startPoint, endPoint, objectTile, _textureBricks, _angle);
    brickBackBodyBottom.displayBody();

    //Window back brick

    //Top Door
    startPoint = {5.51, 2.7, -7.5};
    endPoint = {5.51, 0.5, -8.8};
    objectTile = {1, 1};

    DisplayMode topDoor(startPoint, endPoint, objectTile, _textureDoor, _angle);
    topDoor.displaySide();

    //Glass Pagar Top
    startPoint = {6, 1.2, -7.5};
    endPoint = {6, 0.5, -11.5};
    objectTile = {1, 1};

    DisplayMode sideGlass(startPoint, endPoint, objectTile, _textureWindow, _angle);
    sideGlass.displaySide();

    startPoint = {3.8, 1.2, -11.5};
    endPoint = {6, 0.5, -11.5};
    objectTile = {1, 1};

    DisplayMode backGlass(startPoint, endPoint, objectTile, _textureWindow, _angle);
    backGlass.displayFront();

    //Top
    startPoint = {5.51, 2.7, -9};
    endPoint = {5.51, 1.5, -10.5};
    objectTile = {1, 1};

    DisplayMode bottomWindowSideBrick(startPoint, endPoint, objectTile, _textureWindow, _angle);
    bottomWindowSideBrick.displaySide();

    //Back
    startPoint = {5, 2.7, -10.51};
    endPoint = {5.5, 1.5, -10.51};
    objectTile = {1, 1};

    DisplayMode backWindowSideBrick(startPoint, endPoint, objectTile, _textureWindow, _angle);
    backWindowSideBrick.displayFront();

    //Roof Wood Body for Door
    startPoint = {3.8, 3, -7.5};
    endPoint = {6, 2.7, -11.2};
    objectTile = {1, 1};

    Roof fourthRoof(startPoint,endPoint,objectTile,_angle);
    fourthRoof.displayRoof();
}
void drawFence(){
    //Front
    point startPoint = {-5, -0.5, 5};
    point endPoint = {5.5, -1.5, 5};
    tile objectTile = {1, 10};

    DisplayMode frontFence(startPoint, endPoint, objectTile, _textureFence, _angle);
    frontFence.displayFront();
    startPoint = {8, -0.5, 5};
    endPoint = {9, -1.5, -5};
    objectTile = {1, 1};

    DisplayMode littleFrontFence(startPoint, endPoint, objectTile, _textureFence, _angle);
    littleFrontFence.displayFront();

    //Back
    startPoint = {-5, -0.5, -14};
    endPoint = {9, -1.5, -14};
    objectTile = {1, 10};

    DisplayMode backFence(startPoint, endPoint, objectTile, _textureFence, _angle);
    backFence.displayFront();

    //Left
    startPoint = {-5, -0.5, 5};
    endPoint = {-5, -1.5, -14};
    objectTile = {1, 20};

    DisplayMode leftFence(startPoint, endPoint, objectTile, _textureFence, _angle);
    leftFence.displaySide();

    //Right
    startPoint = {9, -0.5, 5};
    endPoint = {9, -1.5, -14};
    objectTile = {1, 20};

    DisplayMode rightFence(startPoint, endPoint, objectTile, _textureFence, _angle);
    rightFence.displaySide();

    //Center
    startPoint = {5.5, 1, 5};
    endPoint = {8, -1.5, 5};
    objectTile = {1, 2};

    DisplayMode centerFence(startPoint, endPoint, objectTile, _textureFence2, _angle);
    centerFence.displayFront();

    //Gapura

    startPoint = {5.5, 2.1, 5.5};
    endPoint = {6, -1.5, 4.5};
    objectTile = {1, 1};

    Body left(startPoint, endPoint, objectTile, _textureBricks, _angle);
    left.displayBody();

    //right
    startPoint = {7.5, 2.1, 5.5};
    endPoint = {8, -1.5, 4.5};
    objectTile = {1, 1};

    Body right(startPoint, endPoint, objectTile, _textureBricks, _angle);
    right.displayBody();

    //top
    startPoint = {5, 2.3, 5.5};
    endPoint = {8.5, 2.1, 4.5};
    objectTile = {1, 1};

    Roof top(startPoint, endPoint, objectTile, _angle);
    top.displayRoof();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	drawGrass();
	drawSky();
	drawFirstFloor();
	drawSecondFloor();
	drawBackBody();
	drawFence();

	glutSwapBuffers();
}

void Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, Timer, 0);
}

void Init(){
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    _textureGrass = loadTexture("grass.bmp");
    _textureBricks = loadTexture("gray.bmp");
    _textureRoof = loadTexture("black.bmp");
    _textureDoor = loadTexture("pintu.bmp");
    _textureSky = loadTexture("sky.bmp");
    _textureFence = loadTexture("wall6.bmp");
    _textureFence2 = loadTexture("fence.bmp");
    _textureWindow = loadTexture("window.bmp");
    _textureWood = loadTexture("wood.bmp");
    _textureWood2 = loadTexture("wood2.bmp");
}

void Reshape(GLsizei width, GLsizei height) {
	const float ar = (float) width / (float) height;
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void KeyboardHandler(int key, int x, int y)
{

	// d dan f
	switch (key) {
	case GLUT_KEY_RIGHT:
		_angle += 1;
		if (_angle > 360) _angle = 0.0;
		break;
	case GLUT_KEY_LEFT:
        _angle -= 1;
        if (_angle > 360) _angle = 0.0;
	    break;
	default:
		break;
	}
	glutPostRedisplay();
}

GLuint loadTexture(const char* filename) {
	BmpLoader bl(filename);
	GLuint textureId;
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	glTexImage2D(GL_TEXTURE_2D,
				 0,
				 GL_RGB,
				 bl.iWidth, bl.iHeight,
				 0,
				 GL_RGB,
				 GL_UNSIGNED_BYTE,
				 bl.textureData);
	return textureId;
}
