#include "directorygetter.h"

#include <fstream>
#include <QFileDialog>

DictionaryGetter::DictionaryGetter(const std::string &filePath) : m_filePath(filePath)
{
    srand( static_cast<unsigned>(time( NULL )) );

    if (m_filePath.empty())
    {
        m_filePath =
                QFileDialog::getOpenFileName(0,
                                             "Select a dictionary file to open...",
                                             QDir::currentPath()).toStdString();
    }
}

Dictionary DictionaryGetter::getDictionary()
{
    Dictionary dictionary {};

    openFile(m_filePath, dictionary);

    return dictionary;
}

Entry DictionaryGetter::split(const std::string &line)
{
    size_t found = line.find("-");
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
