 #include "Bacteria.h"

void prompt()
{
    string input;
    cin >> input;
    if (!cin)
        return;
}

int main()
{
    srand(time(NULL));              // set seed for RNG()
    Bacteria b(1, 2, 1, false);
    // Animal::print();
    // cout << endl << endl;
    // Animal::charVec[b.getY() - 1][b.getX() - 1] = '.';
    // b.setXY(2, 3);
    // int y = 2;
    // int x = 1;

    // while (x < 5)
    // {
    //     Bacteria c(x, y, 1, false);
    //     ++x;
    // }
    // while (y < 6)
    // {
    //     Bacteria c(x, y, 1, false);
    //     ++y;
    // }
    // while (x > 0)
    // {
    //     Bacteria c(x, y, 1, false);
    //     --x;
    // }
    
    // Animal::print();
    map<int,Bacteria> bacMapCopy = Bacteria::bacMap;
    map<int, Bacteria>::iterator bacIter;
    while (true)
    {
        prompt();
        bacMapCopy = Bacteria::bacMap;
        bacIter = bacMapCopy.begin();
        cout << "Start reproducing\n";
        while(bacIter != bacMapCopy.end())
        {
            bacIter->second.reproduce();
            ++bacIter;
        }
        Animal::print();
        cout << "Start moving\n";
        bacMapCopy = Bacteria::bacMap;
        bacIter = bacMapCopy.begin();
        while(bacIter != bacMapCopy.end())
        {
            bacIter->second.move();
            ++bacIter;
        }
        cout << "Elements in bacMap: " << Bacteria::bacMap.size() << endl;
        Animal::print();
    }

    // NOTE NOTE NOTE You need to be changing FIRST in every pair as you iterate. 
    
    return 0;
}
