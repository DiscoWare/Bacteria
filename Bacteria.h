#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
using namespace std;

class Animal
{
public:
    Animal();

    static vector< vector<char> > charVec;
    void setXY(int x, int y);
    void setAntigen(int antigen);

    int getX();
    int getY();
    int getAntigen();

    void static print();
private:
    unsigned int x_;
    unsigned int y_;
    unsigned int antigen_;
};

int RNG(int max);
