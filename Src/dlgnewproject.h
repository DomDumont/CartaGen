#ifndef DLGNEWPROJECT_H
#define DLGNEWPROJECT_H

#include <QDialog>

namespace Ui {
class DlgNewProject;
}

class DlgNewProject : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewProject(QWidget *parent = 0);
    ~DlgNewProject();
    void AddCardType(QString newCard);

private:
    Ui::DlgNewProject *ui;
};

#endif // DLGNEWPROJECT_H
