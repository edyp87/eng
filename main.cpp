#include "pairpicker.h"
#include "directorygetter.h"
#include "textprinter.h"

int main()
{
    DictionaryGetter dictionaryGetter("../angielski/angielski.txt");
    PairPicker pairPicker(dictionaryGetter.getDictionary());

    while (true)
    {
        TextPrinter::ask(pairPicker);
        system("clear");
    }
}


