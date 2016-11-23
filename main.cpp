#include <iostream>
#include <map>
#include <fstream>

using namespace std;

pair<string, string> split(const string &line)
{
    size_t found = line.find("-");
    return { line.substr(0, found - 1), line.substr(found + 2) };
}

void openFile(const string &filename, map<string, string> &dictionary)
{
    ifstream infile(filename);
    string line {};

    while (getline(infile, line))
    {
        auto words = split(line);
        dictionary[words.first] = words.second;
    }
}

std::pair<string, string> getRandomFromMap(map<string, string> &dictionary)
{
    auto it = dictionary.begin();
    std::advance(it, rand() % dictionary.size());
    return *it;
}

void shuffle(std::pair<string, string> &words)
{
    int r = rand() % 2;

    if (r)
    {
        swap(words.first, words.second);
    }
}

void ask(std::pair<string, string> words)
{
    shuffle(words);

    cout << words.first;  getchar();
    cout << words.second; getchar();
}

int main()
{
    srand( time( NULL ) );
    map<string, string> dictionary {};
    openFile("../eng/angielski.txt", dictionary);

    while (true)
    {
        ask(getRandomFromMap(dictionary));
        system("clear");

    }

    return 0;
}
