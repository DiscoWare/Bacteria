#include "Bacteria.h"

vector< vector<char> > Animal::charVec( 50, vector<char>(50, '.') );
vector< vector<int> > Animal::antigenVec( 50, vector<int>(50, 0) );
map<int, Bacteria> Bacteria::bacMap;

void Animal::setXY(int x, int y)
{
    x_ = x - 1;
    y_ = y - 1;
}

void Animal::setAntigen(int antigen)
{
    antigen_ = antigen;
}

int Animal::getX()
{
    return x_ + 1;
}

int Animal::getY()
{
    return y_ + 1;
}

int Animal::getAntigen()
{
    return antigen_;
}

void Animal::setVectors()
{
    cerr << "ERROR: ANIMAL SETVECTOR\n";
}

int Animal::getIntFromPos(int x, int y)
{
    return (y - 1) * 50 + x;
}

void Animal::print()
{
    cout << "PRINT" << endl;
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

Bacteria::Bacteria(int x, int y, int antigen, bool infected)
{
    setAntigen(antigen);
    infected_ = infected;
    setXY(x, y);
    pair<int, Bacteria> insertThis(getIntFromPos(x, y), *this);
    bacMap.insert(insertThis);
}

void Bacteria::setXY(int x, int y)
{
    Animal::setXY(x, y);
    setVectors();
}

void Bacteria::setVectors()
{
    char bacChar = 'O';
    if (infected_)
    {
        bacChar = '@';
    }
    charVec[getY() - 1][getX() - 1] = bacChar;
}

void Bacteria::move()
{
    int x;
    int y;
    returnPosition(x, y);
    if (x != getX() || y != getY())
    {
        charVec[getY() - 1][getX() - 1] = '.';
        Bacteria newBac = Bacteria(x, y, getAntigen(), infected_);
        Bacteria::bacMap.erase(getIntFromPos(getX(), getY()));
    }
    cout << "Bacteria at position: " << getX() << ", " << getY() 
        << " moving to " << x << ", " << y << endl;
}

void Bacteria::reproduce()
{
    int x;
    int y;
    returnPosition(x, y);
    if (x != getX() || y != getY())
    {
        Bacteria newBac(x, y, getAntigen(), false);
    }
    cout << "Bacteria at position: " << getX() << ", " << getY()
        << " reproduced to " << x << ", " << y << endl;
}

void Bacteria::returnPosition(int &x, int &y)
{
    y = getY();
    x = getX();
    vector<char> directions = {'u', 'r', 'd', 'l'};
    int numberOfElements = 4;
    while (directions.size() > 0)
    {
        int randIndex = RNG(numberOfElements);
        if (isAvailable(directions[randIndex]) == 't')
        {
            if (directions[randIndex] == 'u')
            {
                --y;
            }
            else if (directions[randIndex] == 'r')
            {
                ++x;
            }
            else if (directions[randIndex] == 'd')
            {
                ++y;
            }
            else
            {
                --x;
            }
            directions.clear();
        }
        else
        {
            directions.erase(directions.begin() + randIndex);
            --numberOfElements;
        }
    }

}

char Bacteria::isAvailable(char dir)
{
    pair<int, int> pos(getY(), getX());
    bool notEdge;
    if (dir == 'u')
    {
        if (getY() != 1)
        {
            notEdge = true;
            --pos.first;
        }
    }
    else if (dir == 'r')
    {
        if (getX() != 50)
        {
            notEdge = true;
            ++pos.second;
        }
    }
    else if (dir == 'd')
    {
        if (getY() != 50)
        {
            notEdge = true;
            ++pos.first;
        }
    }
    else
    {
        if (getX() != 1)
        {
            notEdge = true;
            --pos.second;
        }
    }

    if (notEdge)
    {
        if (charVec[pos.first - 1][pos.second -1] == 'O'||
            charVec[pos.first - 1][pos.second -1] == '@')
        {
            return 'f';
        }

        else if (charVec[pos.first - 1][pos.second -1] == '*')
        {
            return 'v';
        }

        else 
        {
            return 't';
        }
    }

    return 'f';
}

int RNG(int max)
{
    return rand() % max;
}
