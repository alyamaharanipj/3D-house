#ifndef CUBE_H
#define CUBE_H

#include "DisplayMode.h"

class Cube : public DisplayMode
{
    public:
        Cube();

    protected:
        point dStartPoint;
        point dEndPoint;
        void setCoordinate();
        void drawFront();
        void drawBack();
        void drawLeft();
        void drawRight();
        void drawTop();
        void drawBottom();

    private:

};

#endif // CUBE_H
