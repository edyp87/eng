#ifndef PAIRPICKER_H
#define PAIRPICKER_H

#include "types.h"

class PairPicker
{
public:
    PairPicker(const Dictionary & dictionary);

    Entry pickRandomly();
    Entry next();
    void resetIterator();

private:
    Entry getRandomFromMap();
    Entry getPair(unsigned index);
    Dictionary pairs;
    unsigned currentElem;
};

#endif // PAIRPICKER_H
