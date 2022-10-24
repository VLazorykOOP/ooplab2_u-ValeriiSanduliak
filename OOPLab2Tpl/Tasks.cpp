#include <iostream>
#include<fstream>
using namespace std;
#include "Tasks.h"
#include <string.h>
#include <string>
#include "Examples.h"
void MenuTask()
{
    cout << "     Menu Task   \n";
    cout << "    1.  Calculation of expressions using bitwise operations  \n";
    cout << "    2.  Data encryption using bitwise operations \n";
    cout << "    3.  Data encryption using structures with bit fields \n";
    cout << "    4.  Encode the input sequence using an XOR mask, which is selected depending on its size:" << endl<<"        in the case of an even size, use the mask '01010101',"<<endl <<"        in the case of an odd one - '10101010'. \n";
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
void outbin(unsigned short in)
{
    char out[17];
    int i,  ix, n = 0;
    for (i = 0; i < 16; i++)  out[i] = '0';
    double x;
    
    if (in != 0) {
        x = in;
        do {
            x = x / 2.;
            ix = (int)x;
            if ((x - ix) != 0) out[n] = '1';
            else out[n] = '0';
            n++;
            x = ix;
        } while (x >= 1);
    }
 
    for (i = 16 - 1; i >= 0; i--)
        cout << out[i];
}




void TaskT2()
{
    
        char S[4][17], ch;
        char so[4][17];
      
        unsigned short sh_dat[64], sd2[64], r, w;
        ifstream fin("fread.txt");
        if (fin.fail()) exit(0);
        ofstream ofs("out.dat");
        ofstream ofsb("outb.dat", ios::out | ios::binary);
        unsigned char c;
        unsigned short i, j, l, b, k, t;
        for (i = 0; i < 4; i++)
        {
            fin.get(S[i], 17, '\0'); 
            fin.get(ch);

            if (strlen(S[i]) < 16)
            {
                for (int f = strlen(S[i]); f < 16; f++)
                {
                    S[i][f] = ' ';
                }
                S[i][16]='\0';
            }
            
        }
     
     

          cout << endl << endl;
            for (int i = 0; i < 4; i++)
            {
                cout << strlen(S[i]) << endl;
            }

        for (int i = 0; i < 4; i++, cout << endl)
            for (int j = 0; j < 16; j++)
            {
                cout << S[i][j]; 
            }
            
        cout << endl;
       
      
        j = 0;
        for (i = 0; i < 4; i++)
            for (l = 0; l < 16; l++) {
              
                // position i;
                r = i;              // 0000 0000 0000 00__<-i

                c = S[i][l];
               
                t = c;
                t = t >> 4;       //  0000 1100 
                r |= t << 2;       // oldest part     0000 0000 00ss ssii
               
                b = 0; t = 1;
                for (k = 0; k < 6; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                w = 1 << 6;
                if (b) r |= w;      //0000 0000 0bss ssii
                
                //youger part
                t = c&0x000F;     //  0000 0000 1100 1011   0b0000000000001111;
                                  //  0000 0000 0000 1111
                r |= t << 7;       //  0000 0101 1000 0000
                                  //   0000 0mmm mbss ssii
                                  //   0ppp pmmm mbss ssii
               //position symbol j;
                w = l << 11;       //pos symbol in string
                r |= w;



                b = 0; t = 1<<7;
                for (k = 0; k < 8; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                w = 1 << 15;         //bppp pmmm mbss ssii
                if (b) r |= w;
                // 1000 0000 0000 0000   0x8000

                sh_dat[j] = r;
                j++;
                ofs << hex << r << ' ';
                cout << hex << r <<"\0";
               // outbin(r); cout << S[i][j] << endl;
            }

        ofsb.write((char*)sh_dat, 64 * sizeof(unsigned short));
        ofsb.close();
        fin.close();

        fin.open("outb.dat", ios::in | ios::binary);
        fin.read((char*)sd2, 64 * sizeof(unsigned short));
         short indi, indj;
        unsigned short ow,yw,bp1,bp2;
        char ch1='0';
        for (i = 0; i < 64; i++)
        {
            
                r = sd2[i];           // bppp pmmm mbss ssii
                //1000 0000 0000 0000
                //0000 0000 0100 0000

                bp1 = r & 0x8000 ? 1 : 0;
                t = 1 << 7;
                b = 0;
                for (k = 0; k < 8; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                if (b != bp1) {
                    cout << "ERRoR bp1";
                    exit(0);
                }


                indj = r & 0x7800;    //0111 1000 0000 0000 
                indj >>= 11;
                //cout << "index J : " << indj<<endl;

                yw = r & 0x0780;       //0000 0111 1000 0000 younger part   
                yw >>= 7;

                bp2 = r & 0x0040 ? 1 : 0;   // 0000 0000 0100 0000
                t = 1;
                b = 0;
                for (k = 0; k < 6; k++) // обчислення біта парності
                {
                    if (r & t) {
                        if (b == 0) b = 1; else b = 0;
                    }
                    t <<= 1;
                }
                if (b != bp2) {
                    cout << "ERRoR bp2";
                    exit(0);
                }

                ow = r & 0x003c;        //0000 0000 0011 1100 older part
                ow <<= 2;                //0000 0000 ssss 0000

                indi = r & 0x0003;     //0000 0000 0000 0011

               // cout << "index I : " << indi << endl;
               // cout << "ch = " << ch1 << endl;
                ch1 = ow | yw;
                so[indi][indj] = ch1;
          
        }
        cout << endl;
        for (i = 0; i < 4; i++)
        {
            for (l = 0; l < 16; l++)
                cout << so[i][l];
                 cout << endl;
        }
        cout << endl;
        

    
}


struct TextCode {
    unsigned short nr : 2;
    unsigned short op : 4;
    unsigned short btp1 : 1;
    unsigned short yp : 4;
    unsigned short ps : 4;
    unsigned short btp2 : 1;
};


unsigned char pbit1(unsigned char c)
{
    unsigned char t = 1, b = 0;
    for (int j = 0; j < 6; j++)         // обчислення біта парності
    {
        if (c & t) {
            if (b == 0) b = 1; else b = 0;
        }
        t <<= 1;
    }
    return b;
}
unsigned char pbit2(unsigned char c)
{
    unsigned char t = 1<<7, b = 0;
    for (int j = 0; j < 8; j++)         // обчислення біта парності
    {
        if (c & t) {
            if (b == 0) b = 1; else b = 0;
        }
        t <<= 1;
    }
    return b;
}
void TaskT3()
{
   
}

string EncryptDecrypt(string Encrypt) {
    char keyn[9] = { '1', '0', '1','0','1','0','1','0'};
    char keyp[9] = { '0', '1', '0','1','0','1','0','1'};
    string out = Encrypt;
    if (Encrypt.size() % 2) {
        for (int i = 0; i < Encrypt.size(); i++)
            out[i] = Encrypt[i] ^ keyn[i % (sizeof(keyn) / sizeof(char))];
    }
    else{
        for (int i = 0; i < Encrypt.size(); i++)
            out[i] = Encrypt[i] ^ keyp[i % (sizeof(keyp) / sizeof(char))];
    }

    return out;
}
void TaskT4()
{
    string s;
    cout << "Input S:";
    getline(cin, s);
    cout << s.size()<<endl;
    string encrypt = EncryptDecrypt(s);
    cout << "Encrypted:" << encrypt << "\n";

    string decrypt = EncryptDecrypt(encrypt);
    cout << "Decrypted:" << decrypt << "\n";
   

}


