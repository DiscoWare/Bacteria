#include "Bacteria.h"

vector< vector<char> > Animal::charVec(2500);

Animal::Animal()
{
    x_ = 0;
    y_ = 0;
    antigen_ = 0;
}

void Animal::setXY(int x, int y)
{
    x_ = x;
}

void Animal::setAntigen(int antigen)
{
    antigen_ = antigen;
}

int Animal::getX()
{
    return x_;
}

int Animal::getY()
{
    return y_;
}

int Animal::getAntigen()
{
    return antigen_;
}