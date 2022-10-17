
#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <unordered_map>



int main()
{
    setlocale(LC_ALL, "ru");

    std::string buf;
    std::unordered_map <char, int> mp;
    auto it = mp.begin();
    
    

    std::ifstream fin;
    fin.open("text.txt");
    if (!fin)
        std::cout << "Файл не открыт\n\n";
    else
        std::cout << "Файл открыт!\n\n";

    getline(fin, buf, '\0');
    for (int i = 0; i < buf.length(); ++i) {
        const auto result = mp.insert({buf[i], 1});
        if(!result.second){
            result.first->second += 1;
        }
        
        // if('a'<= mp.insert(std::make_pair(buf[i], 0)).first->first && mp.insert(std::make_pair(buf[i], 0)).first->first <= 'z')
        //     mp.insert(std::make_pair(buf[i], 0)).first->second++;
    }


    /*for (int i = 0; i < 33; it++, i++) {

        for (int j = 0; j < buf.length(); j++) {
            if (it->first == buf[j])
                mp[buf[j]]++;
            else if ('А' <= buf[j] && buf[j] <= 'Я') {
                buf[j] += 32;
                mp[buf[j]];


            }
        }
    }*/


    std::ofstream fout;
    fout.open("../table.txt");

    auto itt = mp.begin();
    for (int j = 0; itt != mp.end(); itt++, j++) {
       
            std::cout << "Letter " << itt->first << ", Frequency " << itt->second << std::endl;
    }


}

