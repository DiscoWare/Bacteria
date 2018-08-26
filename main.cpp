 #include "Bacteria.h"

void prompt()
{
    string input;
    cin >> input;
}

int main()
{
    srand(time(NULL));              // set seed for RNG()
    Bacteria b(1, 2, 1, false);
    Animal::print();
    cout << endl << endl;
    Animal::charVec[b.getY() - 1][b.getX() - 1] = '.';
    b.setXY(2, 3);
    Animal::print();
    while (true)
    {
        prompt();
        b.move();
        Animal::print();
    }

    
    return 0;
}
