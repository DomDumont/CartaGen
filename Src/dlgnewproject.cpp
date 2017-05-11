#include "dlgnewproject.h"
#include "ui_dlgnewproject.h"
#include "utils.h"

DlgNewProject::DlgNewProject(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewProject)
{
    ui->setupUi(this);
}

DlgNewProject::~DlgNewProject()
{
    delete ui;
}


void DlgNewProject::AddCardTypes(QVector<CardType *> _supported)
{
    for (auto element : _supported)
        {
        this->ui->comboBoxCardType->addItem(element->name,QVariant::fromValue(element));
        }
    //this->ui->comboBoxCardType->addItem(newCard);
}

void DlgNewProject::on_comboBoxCardType_currentIndexChanged(int index)
{
    QVariant variant = this->ui->comboBoxCardType->itemData(index);
    CardType* cardType = variant.value<CardType*>();
    if (ui)
        {
        ui->lineEditWidth->setText(QString::number(cardType->width));
        ui->lineEditHeight->setText(QString::number(cardType->height));
        }
}

