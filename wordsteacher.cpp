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
        ui->reactionButton->setText("Show answer");
        wordsMastered = false;;
    }
    else
    {
        revealAnswer();
        ui->reactionButton->setText("Next example");
        wordsMastered = true;
    }
}

void WordsTeacher::changePair()
{
    currentPair = pairPicker.pick();
    ui->field_eng->setText(QString::fromStdString(currentPair.first));
    ui->field_pl->setText("");
}

void WordsTeacher::revealAnswer()
{
    ui->field_pl->setText(QString::fromStdString(currentPair.second));
}

void WordsTeacher::connects()
{
    connect(ui->reactionButton, SIGNAL(released()), this, SLOT(buttonClicked()));
}
