#include "Bacteria.h"

vector< vector<char> > Animal::charVec( 50, vector<char>(50, '.') );

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

void Animal::print()
{
    unsigned int end = Animal::charVec.size();
    unsigned int endOfRow;
    for (unsigned int i = 0; i < end; ++i)
    {
        endOfRow = Animal::charVec[i].size();
        for (unsigned int e = 0; e < endOfRow; ++e)
        {
            cout << Animal::charVec[i][e] << ' ';   
        } 
        cout << endl;
    }
}

int RNG(int max)
{
    return rand() % max + 1;
}
