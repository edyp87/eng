#include "pairpicker.h"
#include <QTime>

PairPicker::PairPicker(const Dictionary &dictionary) : pairs(dictionary)
{
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
}

Entry PairPicker::pick()
{
    return getRandomFromMap();
}

Entry PairPicker::getRandomFromMap()
{
    auto it = pairs.begin();
    std::advance(it, static_cast<unsigned long>(qrand()) % pairs.size());
    return *it;
}
