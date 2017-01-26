#ifndef DIRECTORYGETTER_H
#define DIRECTORYGETTER_H

#include "types.h"

class DictionaryGetter
{
public:
    DictionaryGetter(const std::string & filePath = "");

    Dictionary getDictionary();

private:
    Entry split(const std::string &line);
    void openFile(const std::string &filename, Dictionary &dictionary);

    std::string m_filePath;
};

#endif // DIRECTORYGETTER_H
