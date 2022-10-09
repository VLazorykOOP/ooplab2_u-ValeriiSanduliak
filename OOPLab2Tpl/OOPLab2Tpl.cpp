// OOPLab2Tpl.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
#include "Tasks.h"
//#include "Examples.h"


 //@brief 
/// @return 
int main()
{ 
    cout << "OOP. Template for laboratory work #2.\n";

    char ch = '5';
    do {
        system("cls");
        MenuTask();
        cout << " >>> ";
        ch = cin.get();
        
        cin.get();

        switch (ch) {
        case '1': TaskT1();  break;
        case '2': cout << "...[loading]"<<endl;  break;
        case '3': cout << "...[loading]"<<endl;  break;
        case '4': cout << "...[loading]"<<endl;  break;
		case '5': return 0;
	    }
        cout << " Press any key and enter\n";
        ch = cin.get();
    } while (ch != '5');
   
 
    return 0;
}

