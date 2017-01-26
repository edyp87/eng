#ifndef WORDSTEACHER_H
#define WORDSTEACHER_H

#include <QMainWindow>

#include "pairpicker.h"

namespace Ui {
class WordsTeacher;
}

class WordsTeacher : public QMainWindow
{
    Q_OBJECT

public:
    explicit WordsTeacher(const PairPicker & _pairPicker, QWidget *parent = 0);
    ~WordsTeacher();

private slots:
    void buttonClicked();

private:
    void changePair();
    void revealAnswer();
    void connects();

    Ui::WordsTeacher *ui;
    PairPicker pairPicker;
    Entry currentPair;
    bool wordsMastered = false;
};

#endif // WORDSTEACHER_H
