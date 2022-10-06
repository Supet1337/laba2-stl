
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
    map <char, int> mp = {{'а', 0}, {'б', 0}, { 'в', 0 }, { 'г', 0 }, { 'д', 0 }, { 'е', 0 }, { 'Є', 0 }, { 'ж', 0 }, { 'з', 0 }, { 'и', 0 }, { 'й', 0 }, { 'к', 0 }, { 'л', 0 }, { 'м', 0 }, { 'н', 0 }, { 'о', 0 }, { 'п', 0 }, { 'р', 0 }, { 'с', 0 }, { 'т', 0 }, { 'у', 0 }, { 'ф', 0 }, { 'х', 0 }, { 'ц', 0 }, { 'ч', 0 }, { 'ш', 0 }, { 'щ', 0 }, { 'ъ', 0 }, { 'ы', 0 }, { 'ь', 0 }, { 'э', 0 }, { 'ю', 0 }, { '€', 0 }};
    auto it = mp.begin();

    ifstream fin;
    fin.open("../text.txt");
    if (!fin)
        cout << "‘айл не открыт\n\n";
    else
        cout << "‘айл открыт!\n\n";

    getline(fin, buf, '\0');

    for (int i = 0; i < 33; it++, i++) {

        for (int j = 0; j < buf.length(); j++) {
            if (it->first  == buf[j])
                mp[buf[j]]++;
            else if('ј' <=  buf[j] && buf[j] <= 'я'){
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