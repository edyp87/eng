#include "wordsteacher.h"
#include "directorygetter.h"
#include "ui_wordsteacher.h"
#include <QDebug>
#include <QTime>

WordsTeacher::WordsTeacher(const PairPicker & _pairPicker, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordsTeacher),
    pairPicker(_pairPicker)
{
    qsrand(static_cast<unsigned>(QTime::currentTime().msec()));

    ui->setupUi(this);
    ui->reactionButton->setFocus();

    connects();

    initializeWithNewDictionary();
}



WordsTeacher::~WordsTeacher()
{
    delete ui;
}

void WordsTeacher::buttonClicked()
{
    if (wordsMastered)
    {
        changePair();
    }
    else
    {
        revealAnswer();
    }
}

void WordsTeacher::changeDictionary()
{
    DictionaryGetter dictionaryGetter;
    pairPicker.resetDictionary(dictionaryGetter.getDictionary());
    initializeWithNewDictionary();
}

void WordsTeacher::changePair()
{
    currentPair = pickPairAccodringToPolicy();
    setFieldEng();
    setFieldPl();
    clearFieldsAccordingToDirectionPolicy();
    setReactionButtonText("Show answer");
    wordsMastered = false;
}

void WordsTeacher::revealAnswer()
{
    setFieldPl();
    setFieldEng();
    setReactionButtonText("Next example");
    wordsMastered = true;
}

void WordsTeacher::connects()
{
    connect(ui->reactionButton, SIGNAL(released()), this, SLOT(buttonClicked()));
    connect(ui->readNewFileButton, SIGNAL(released()), this, SLOT(changeDictionary()));
}

void WordsTeacher::setReactionButtonText(const QString &text)
{
    ui->reactionButton->setText(text);
}

void WordsTeacher::setFieldPl()
{
    ui->field_pl->setText(QString::fromStdString(currentPair.second));
}

void WordsTeacher::setFieldEng()
{
    ui->field_eng->setText(QString::fromStdString(currentPair.first));
}

void WordsTeacher::clearFieldPl()
{
    ui->field_pl->setText("");
}

void WordsTeacher::clearFieldEng()
{
    ui->field_eng->setText("");
}

void WordsTeacher::randomlyClearOneOfFields()
{
    int r = rand() % 2;

    if (r)
    {
        clearFieldPl();
    }
    else
    {
        clearFieldEng();
    }
}

void WordsTeacher::clearFieldsAccordingToDirectionPolicy()
{
    if (ui->randomDirection->isChecked())
    {
        randomlyClearOneOfFields();
    }
    else if (ui->engToPl->isChecked())
    {
        clearFieldPl();
    }
    else
    {
        clearFieldEng();
    }
}

Entry WordsTeacher::pickPairAccodringToPolicy()
{
    if (ui->randomOrder->isChecked())
    {
        return pairPicker.pickRandomly();
    }
    else
    {
        return pairPicker.next();
    }
}

void WordsTeacher::disableDueToEmptyDictionary()
{
    toggleUi(false);
    ui->field_eng->setText("");
    ui->field_pl->setText("");
    ui->reactionButton->setText("Empty dictionary. Please read new one.");
}

void WordsTeacher::enablePotentiallyDisabledUi()
{
    toggleUi(true);
}

void WordsTeacher::toggleUi(bool isEnabled)
{
    ui->field_eng->setEnabled(isEnabled);
    ui->field_pl->setEnabled(isEnabled);
    ui->reactionButton->setEnabled(isEnabled);
}

void WordsTeacher::initializeWithNewDictionary()
{
    if (pairPicker.isEmpty())
    {
        disableDueToEmptyDictionary();
    }
    else
    {
        enablePotentiallyDisabledUi();
        changePair();
    }
}
