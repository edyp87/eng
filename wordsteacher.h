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
    void changeDictionary();

private:
    void changePair();
    void revealAnswer();
    void connects();
    void setReactionButtonText(const QString& text);
    void setFieldPl();
    void setFieldEng();
    void clearFieldPl();
    void clearFieldEng();
    void randomlyClearOneOfFields();
    void clearFieldsAccordingToDirectionPolicy();
    Entry pickPairAccodringToPolicy();
    void disableDueToEmptyDictionary();
    void enablePotentiallyDisabledUi();
    void toggleUi(bool isEnabled);
    void initializeWithNewDictionary();

    Ui::WordsTeacher *ui;
    PairPicker pairPicker;
    Entry currentPair;
    bool wordsMastered = false;
};

#endif // WORDSTEACHER_H
