#ifndef TEXTPRINTER_H
#define TEXTPRINTER_H

#include "types.h"
#include <iostream>

class PairPicker;

class TextPrinter
{
public:
    static void shuffle(Entry &words);
    static void ask(PairPicker & pairPicker);
};

#endif // TEXTPRINTER_H
