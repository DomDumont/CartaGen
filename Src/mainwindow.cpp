#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgnewproject.h"

#include <QGraphicsTextItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     scene = new QGraphicsScene(this);
     ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{

}

// Test
void MainWindow::on_action_AboutCartaGen_triggered()
{

}

void MainWindow::on_actionInsertText_triggered()
{
    QGraphicsTextItem * textItem = new QGraphicsTextItem;

    textItem ->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsFocusable | QGraphicsItem::ItemIsMovable);
    textItem ->setTextInteractionFlags(Qt::TextEditorInteraction);

    textItem->setPos(150,70);
    textItem->setPlainText("Test");

    scene->addItem(textItem);
}

void MainWindow::on_actionNew_Project_triggered()
{
    DlgNewProject dialog(this);
    if (dialog.exec() == QDialog::Accepted)
        {

        }
}
