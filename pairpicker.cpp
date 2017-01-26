#include "pairpicker.h"

PairPicker::PairPicker(const Dictionary &dictionary) : pairs(dictionary) {}

Entry PairPicker::pick()
{
    return getRandomFromMap();
}

Entry PairPicker::getRandomFromMap()
{
    auto it = pairs.begin();
    std::advance(it, static_cast<unsigned long>(rand()) % pairs.size());
    return *it;
}
