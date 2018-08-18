 #include "Bacteria.h"

int main()
{
    Bacteria b(1, 2, 1, false);
    Animal::print();
    cout << endl << endl;
    Animal::charVec[b.getY() - 1][b.getX() - 1] = '.';
    b.setXY(2, 3);
    Animal::print();
    return 0;
}
