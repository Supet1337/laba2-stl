
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <windows.h>
using namespace std;


int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string buf;
    map <char, int> mp = {{'�', 0}, {'�', 0}, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }, { '�', 0 }};
    auto it = mp.begin();

    ifstream fin;
    fin.open("../text.txt");
    if (!fin)
        cout << "���� �� ������\n\n";
    else
        cout << "���� ������!\n\n";

    getline(fin, buf, '\0');

    for (int i = 0; i < 33; it++, i++) {

        for (int j = 0; j < buf.length(); j++) {
            if (it->first  == buf[j])
                mp[buf[j]]++;
            else if('�' <=  buf[j] && buf[j] <= '�'){
                buf[j] += 32;
                mp[buf[j]];


            }
        }
    }


    ofstream fout;
    fout.open("../table.txt");

    auto itt = mp.begin();
    for (int j = 0; itt != mp.end(); itt++, j++) {
        fout << j << ") Letter " << itt->first << ", Frequency " << itt->second << endl;
    }

}