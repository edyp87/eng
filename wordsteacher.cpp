#include "wordsteacher.h"
#include "ui_wordsteacher.h"
#include <QDebug>

WordsTeacher::WordsTeacher(const PairPicker & _pairPicker, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::WordsTeacher),
    pairPicker(_pairPicker)
{
    ui->setupUi(this);
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
    currentPair = pairPicker.pick();
    setFieldEng();
    clearFieldPl();
    setReactionButtonText("Show answer");
    wordsMastered = false;
}

void WordsTeacher::revealAnswer()
{
    setFieldPl();
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
