 #include "Bacteria.h"

int main()
{
    srand(time(NULL));              // set seed for RNG()
    Bacteria b(1, 2, 1, false);
    Animal::print();
    cout << endl << endl;
    Animal::charVec[b.getY() - 1][b.getX() - 1] = '.';
    b.setXY(2, 3);
    Animal::print();
    cout << "Before move: " << b.getX() << " " << b.getY() << endl;
    b.move();
    cout << "After move: " << b.getX() << " " << b.getY() << endl;
    Animal::print();
    cout << "TEST GIT STASH\n";
    cout << "Test version control\n";
    return 0;
}
