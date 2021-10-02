#include "Roof.h"

Roof::Roof(point startPoint, point endPoint, tile objectTile, float _angle)
{
    this->dStartPoint = startPoint;
    this->dEndPoint = endPoint;
    this->objectTile = objectTile;
    this->_angle = _angle;
}

void Roof::displayRoof(){
    texture = 3;
    drawFront();
    drawBack();
    drawLeft();
    drawRight();
    texture = 9;
    drawTop();
    drawBottom();
}

