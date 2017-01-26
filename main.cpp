#include <iostream>
#include <map>
#include <fstream>

using namespace std;

class PairPicker
{
public:
    PairPicker(const map<string, string> & dictionary);

    std::pair<string, string> pick();

private:
    std::pair<string, string> getRandomFromMap();
    map<string, string> pairs;
};

class DictionaryGetter
{
public:
    DictionaryGetter(const std::string & filePath);

    map<string, string> getDictionary();

private:
    pair<string, string> split(const string &line);
    void openFile(const string &filename, map<string, string> &dictionary);

    std::string m_filePath;
};





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
    DictionaryGetter dictionaryGetter("../angielski/angielski.txt");
    PairPicker pairPicker(dictionaryGetter.getDictionary());

    while (true)
    {
        ask(pairPicker.pick());
        system("clear");
    }
}

PairPicker::PairPicker(const map<string, string> &dictionary) : pairs(dictionary) {}

std::pair<string, string> PairPicker::pick()
{
    return getRandomFromMap();
}

std::pair<string, string> PairPicker::getRandomFromMap()
{
    auto it = pairs.begin();
    std::advance(it, static_cast<unsigned long>(rand()) % pairs.size());
    return *it;
}

DictionaryGetter::DictionaryGetter(const string &filePath) : m_filePath(filePath)
{
    srand( static_cast<unsigned>(time( NULL )) );
}

map<string, string> DictionaryGetter::getDictionary()
{
    map<string, string> dictionary {};

    openFile(m_filePath, dictionary);

    return dictionary;
}

pair<string, string> DictionaryGetter::split(const string &line)
{
    size_t found = line.find("-");
    return { line.substr(0, found - 1), line.substr(found + 2) };
}

void DictionaryGetter::openFile(const string &filename, map<string, string> &dictionary)
{
    ifstream infile(filename);
    string line {};

    while (getline(infile, line))
    {
        auto words = split(line);
        dictionary[words.first] = words.second;
    }
}
