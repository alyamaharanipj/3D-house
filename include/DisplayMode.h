#ifndef DISPLAYMODE_H
#define DISPLAYMODE_H

#include "../DataType.h"


class DisplayMode
{
    public:
        DisplayMode();
        DisplayMode(point startPoint, point endPoint, tile objectTile, GLint texture, float _angle);
        void displayFront();
        void displaySide();
        void displayBase();

    protected:
        GLint texture;
        tile objectTile;
        point startPoint;
        point endPoint;
        float _angle;

    private:
};

#endif // DISPLAYMODE_H
