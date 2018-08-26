#include <iostream>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include <map>
#include <string>
#include <utility>
using namespace std;

class Animal
{
public:
    static vector< vector<char> > charVec;
    static vector< vector<int> > antigenVec;
    virtual void setXY(int x, int y);
    void setAntigen(int antigen);
    virtual void setVectors();
    int getIntFromPos(int x, int y);    // Get a single integer b/w 1 and 2500 from X and Y Coordinates

    int getX();
    int getY();
    int getAntigen();

    void static print();
private:
    unsigned int x_;
    unsigned int y_;
    unsigned int antigen_;
};

class Bacteria : public Animal
{
public:
    static map<int, Bacteria> bacMap;

    Bacteria(int x, int y, int antigen, bool infected);

    void setXY(int x, int y);
    void setVectors();
    void move();
    void returnPosition(int &x, int &y);

    char isAvailable(char dir);

private:
    bool infected_;
};

int RNG(int max);
