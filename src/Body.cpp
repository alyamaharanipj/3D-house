#include "Body.h"

Body::Body(point startPoint, point endPoint, tile objectTile, GLint texture, float _angle)
{
    this->dStartPoint = startPoint;
    this->dEndPoint = endPoint;
    this->texture = texture;
    this->objectTile = objectTile;
    this->_angle = _angle;
}

void Body::displayBody(){
    drawFront();
    drawBack();
    drawLeft();
    drawRight();
    drawTop();
    drawBottom();
}


