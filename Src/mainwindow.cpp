#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_action_AboutCartaGen_triggered()
{

}

void MainWindow::on_actionInsertText_triggered()
{
    QGraphicsTextItem * io = new QGraphicsTextItem;
    io->setPos(150,70);
    io->setPlainText("Test");

    scene->addItem(io);
}
