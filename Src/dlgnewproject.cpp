#include "dlgnewproject.h"
#include "ui_dlgnewproject.h"

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


void DlgNewProject::AddCardType(QString newCard)
{
    this->ui->comboBoxCardType->addItem(newCard);
}
