#include "Cube.h"

Cube::Cube(){}

void Cube::setCoordinate(){
    startPoint = dStartPoint;
    endPoint = dEndPoint;
}

void Cube::drawFront(){
    setCoordinate();
    endPoint.z = dStartPoint.z;
    displayFront();
}

void Cube::drawBack(){
    setCoordinate();
    startPoint.z = dEndPoint.z;
    displayFront();
}

void Cube::drawLeft(){
    setCoordinate();
    endPoint.x = dStartPoint.x;
    displaySide();
}

void Cube::drawRight(){
    setCoordinate();
    startPoint.x = dEndPoint.x;
    displaySide();
}

void Cube::drawTop(){
    setCoordinate();
    endPoint.y = dStartPoint.y;
    displayBase();
}

void Cube::drawBottom(){
    setCoordinate();
    startPoint.y = dEndPoint.y;
    displayBase();
}

