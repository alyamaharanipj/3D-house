#ifndef ROOF_H
#define ROOF_H

#include "Cube.h"

class Roof : public Cube
{
    public:
        Roof(point startPoint, point endPoint, tile objectTile, float _angle);
        void displayRoof();

};

#endif // ROOF_H
