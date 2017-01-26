#include "directorygetter.h"

#include <fstream>
#include <QFileDialog>

DictionaryGetter::DictionaryGetter(const std::string &_filePath, const std::string & _delim)
    : filePath(_filePath),
      delim(_delim)
{
    if (filePath.empty())
    {
        filePath =
                QFileDialog::getOpenFileName(0,
                                             "Select a dictionary file to open...",
                                             QDir::currentPath(),
                                             "Text files (*.txt)").toStdString();
    }
}

Dictionary DictionaryGetter::getDictionary()
{
    Dictionary dictionary {};

    openFile(filePath, dictionary);

    return dictionary;
}

Entry DictionaryGetter::split(const std::string &line)
{
    size_t found = line.find(delim);
    return { line.substr(0, found - 1), line.substr(found + 2) };
}

void DictionaryGetter::openFile(const std::string &filename, Dictionary &dictionary)
{
    std::ifstream infile(filename);
    std::string line {};

    while (getline(infile, line))
    {
        auto words = split(line);
        dictionary[words.first] = words.second;
    }
}
