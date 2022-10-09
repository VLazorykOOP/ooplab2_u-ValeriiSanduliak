#include <iostream>
using namespace std;
#include "Tasks.h"
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  The problem of using bitwise operations \n";
    cout << "    5.  Exit \n";
}
void TaskT1()
{
    int a, b, d, c, x, y;
    cout << "Calculating an expression using only bitwise operations.\n";
    cout << "Expression : x= 34*b + ((d*15+12*a)/1024)-8365*c+14*d. \n";
    cout << " Input :"<<endl;
    cout << "a:";
    cin >> a;
    cout << "b:";
    cin >> b;
    cout << "c:";
    cin >> c;
    cout << "d:";
    cin >> d;
    auto st = cin.rdstate();
    if (st != cin.goodbit) { cin.clear(); cout << " error \n"; cin.get(); cin.get(); return; }
    x = (b << 5) + (b << 1) + (((d << 4) - d + (a << 4) - (a << 2)) >> 10) - (c << 13) - (c << 7) - (c << 5) - (c << 3) - (c << 2) - c + (d << 4) - (d << 1);
    y = 34 * b + ((d * 15 + 12 * a) / 1024) - 8365 * c + 14 * d;
    cout << "Result :" << endl;
    cout << "  x=" << x << "  y=" << y << " a="<< a << " b=" << b << "  c=" << c << "  d=" << d << endl;
    cin.get();
    return;
}

void TaskT2()
{
    // Шифрування даних з використання побітових операцій 
    // Data encryption using bitwise operations
    cout << " Data encryption using bitwise operations  \n";

}

void TaskT3()
{
    // Шифрування даних з використання стуктур з бітовими полями 
    // Data encryption using structures with bit fields
    cout << "  Data encryption using structures with bit fields \n";
}


void TaskT4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


