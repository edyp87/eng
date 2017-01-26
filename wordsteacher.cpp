#include "wordsteacher.h"
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
    changePair();
    connects();
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
