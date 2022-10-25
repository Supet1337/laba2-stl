
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <windows.h>
#include <unordered_map>

 

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string buf;
    std::unordered_map <char, int> mp;

    std::ifstream fin;
    fin.open("../text.txt");
    if (!fin)
        std::cout << "Файл не открыт\n\n";
    else
        std::cout << "Файл открыт!\n\n";

    getline(fin, buf, '\0');
    for (int i = 0; i < buf.length(); ++i) {
        std::string s(1, buf[i]);

        if ("А" <= s && s <= "Я" || "а" <= s && s <= "я") {
            const auto result = mp.insert({std::tolower(buf[i]), 1});
            if (!result.second)
                result.first->second += 1;
        }
    }


    std::ofstream fout;
    fout.open("../table.txt");

    auto itt = mp.begin();
    for (int j = 0; itt != mp.end(); itt++, j++) {

        fout << "Letter " << itt->first << ", Frequency " << itt->second << std::endl;
    }


}
