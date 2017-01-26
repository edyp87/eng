#ifndef PAIRPICKER_H
#define PAIRPICKER_H

#include "types.h"

class PairPicker
{
public:
    PairPicker(const Dictionary & dictionary);

    Entry pick();

private:
    Entry getRandomFromMap();
    Dictionary pairs;
};

#endif // PAIRPICKER_H
