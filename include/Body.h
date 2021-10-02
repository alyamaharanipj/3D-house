#ifndef BODY_H
#define BODY_H

#include "Cube.h"

class Body : public Cube
{
    public:
        Body(point startPoint, point endPoint, tile objectTile, GLint texture, float _angle);
        void displayBody();

};

#endif // BODY_H
