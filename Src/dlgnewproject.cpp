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


