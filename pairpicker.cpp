#include "pairpicker.h"
#include <QTime>

PairPicker::PairPicker(const Dictionary &dictionary)
    : pairs(dictionary),
      currentElem(0)
{
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));
}

Entry PairPicker::pickRandomly()
{
    return getRandomFromMap();
}

Entry PairPicker::next()
{
    if (pairs.empty())
    {
        return { "", "" };
    }

    auto pair = getPair(currentElem);

    if (currentElem + 1 == pairs.size())
    {
        resetIterator();
    }
    else
    {
        currentElem++;
    }

    return pair;
}


void PairPicker::resetIterator()
{
    currentElem = 0;
}

Entry PairPicker::getRandomFromMap()
{
    if (pairs.empty())
    {
        return { "", "" };
    }

    return getPair(static_cast<unsigned>(qrand()) % pairs.size());
}

Entry PairPicker::getPair(unsigned index)
{
    auto it = pairs.begin();
    std::advance(it, index);
    return *it;
}
