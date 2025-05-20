#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string.h>
#include <vector>

using namespace std;

static vector<string> splitString(const string& str) {
    vector<string> words;
    istringstream stream(str);
    string word;
    while (stream >> word) {
        words.push_back(word);
    }

    return words;
}

static string makeVoid(const vector<string>& vec)
{
    string res;
    for (int i = 0; i < vec.size(); i++)
    {
        res += vec[i] + " ";
    }

    return res;
}

static void defen()
{
	cout << "Введите строку: ";
	string line;
	getline(cin >> ws, line);


    vector<string> words = splitString(line);
    int wordcount = 0;
    vector<string> realw;
    for (const auto& word : words)
    {
        if (word.size() % 2 == 0)
        {
            realw.push_back(word);
            wordcount++;
        }
    }

    cout << "Слова с четным числом букв: " << endl << makeVoid(realw) << endl;
    cout << "Количество слов: " << wordcount << endl;
}