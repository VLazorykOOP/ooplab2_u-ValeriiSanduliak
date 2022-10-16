#include <iostream>
#include<fstream>
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
    
        char S[4][16], ch;
        char so[4][16];
        unsigned short sh_dat[64], sd2[64], r, w, bW;
        char str[16];
        ifstream fin("fread.txt");
        if (fin.fail()) exit(0);
        ofstream ofs("out.txt");
        ofstream ofsb("outb.txt", ios::out | ios::binary);

        for (int i = 0; i < 4; i++) {
            fin.get(S[i], 16, '\0');

        }
        for (int i = 0; i < 4; i++)
        {
            if (strlen(S[i]) < 16) {
                for (int f = strlen(S[i]); f < 16; f++)
                {
                    S[i][f] = ' ';
                }
                S[i][15] = '\0';
            }
        }

        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 16; j++)
            {
                cout << S[i][j];
            }
        cout << endl;
        unsigned char c;
        unsigned short i, j, l, b, k, t;
        j = 0;
        for (i = 0; i < 4; i++)
            for (l = 0; l < 16; l++) {
                r = 0;              // 0000 0000 0000 0000
                r = i;              // 0000 0000 0000 00__<-i
                c = S[i][j];
                t = c;
                r |= t << 2;       // oldest part

                b = 0; t = 1;
                for (k = 0; k < 6; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                w = 1 << 6;
                t = c;
                r |= t << 7;       //yong part
                w = l << 11;       //pos symbol in string
                r |= w;

                b = 0; t = 1;
                for (k = 7; k < 15; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                w = 1 << 15;
                if (r & 0x4000) r |= 0x8000;
                sh_dat[j] = r;
                j++;
                ofs << hex << r << ' ';
                cout << hex << r << endl;
            }

        ofsb.write((char*)sh_dat, 64 * sizeof(unsigned short));
        ofsb.close();
        fin.close();
        fin.open("outb.txt", ios::in | ios::binary);
        fin.read((char*)sd2, 64 * sizeof(unsigned short));
        short indi, indj;
        for (i = 0; i < 64; i++)
        {   
            r = sd2[i];
            indj = r & 0x0050;
            indj >>= 3;
            indi = r & 0x0003; 
            w >>= 7;
            ch = w;
            so[indi][indj] = ch;

        }
        
        for (i = 0; i < 8; i++) {
            for (l = 0; l < 16; l++)
                cout << so[i][l];

        }
        cout << endl;


    
}

/*
struct TextCode {
    unsigned short schkb : 2;
    unsigned short posrow : 4;
    unsigned short bitp1 : 1;
    unsigned short mchkb : 4;
    unsigned short poss : 4;
    unsigned short bitp2 : 1;
};
unsigned char pbit(unsigned char c)
{
    unsigned char t = 1, b = 0;
    for (int j = 0; j < 8; j++)         // обчислення біта парності
    {
        if (c & t) {
            if (b == 0) b = 1; else b = 0;
        }
        t <<= 1;
    }
    return b;
}
*/
void TaskT3()
{

   
}


void TaskT4()
{   // Задача із використання побітових операцій
    // The problem of using bitwise operations
    cout << " Data encryption using structures with bit fields \n";

}


