#include "textprinter.h"
#include "pairpicker.h"

void TextPrinter::shuffle(Entry &words)
{
    int r = rand() % 2;

    if (r)
    {
        swap(words.first, words.second);
    }
}

void TextPrinter::ask(PairPicker & pairPicker)
{
    Entry words = pairPicker.pick();
    shuffle(words);

    std::cout << words.first;  getchar();
    std::cout << words.second; getchar();
}
