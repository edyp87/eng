#include "pairpicker.h"
#include "directorygetter.h"
#include "textprinter.h"

#include <QApplication>
#include "wordsteacher.h"

int main(int argc, char *argv[])
{
    DictionaryGetter dictionaryGetter("../angielski/angielski.txt");
    PairPicker pairPicker(dictionaryGetter.getDictionary());

    QApplication app(argc, argv);
    WordsTeacher window(pairPicker);
    window.show();
    return app.exec();
}


