#ifndef DIRECTORYGETTER_H
#define DIRECTORYGETTER_H

#include "types.h"

class DictionaryGetter
{
public:
    DictionaryGetter(const std::string & _filePath = "", const std::string & _delim = "|");

    Dictionary getDictionary();

private:
    Entry split(const std::string &line);
    void openFile(const std::string &filename, Dictionary &dictionary);

    std::string filePath;
    std::string delim;
};

#endif // DIRECTORYGETTER_H
