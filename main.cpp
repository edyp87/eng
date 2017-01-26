#include "pairpicker.h"
#include "directorygetter.h"
#include "textprinter.h"

#include <QApplication>
#include "wordsteacher.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    DictionaryGetter dictionaryGetter("../angielski/ai.txt");
    PairPicker pairPicker(dictionaryGetter.getDictionary());

    WordsTeacher window(pairPicker);
    window.setFixedSize(507, 292);
    window.show();
    return app.exec();
}


