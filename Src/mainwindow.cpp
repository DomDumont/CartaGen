#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dlgnewproject.h"

#include <QGraphicsTextItem>
#include <QtSvg>

#include "utils.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
     ui->setupUi(this);
     scene = new QGraphicsScene(this);
     ui->graphicsView->setScene(scene);

     //Test
     CardType *pTemp = new CardType("coucou",12, 13);

     supportedCardTypes.append(pTemp);
     pTemp = new CardType("coucou2",12, 13);
     supportedCardTypes.append(pTemp);

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

void MainWindow::on_actionInsertSVG_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,tr("Open SVG Image"), "", tr("SVG Image Files (*.svg)"));

    QSvgRenderer *renderer = new QSvgRenderer(fileName);
    QGraphicsSvgItem *svgItem = new QGraphicsSvgItem();
    svgItem->setSharedRenderer(renderer);
    //svgItem->setElementId(QStringLiteral("example"));
    svgItem->setPos(150,70);
    svgItem->setScale(1.0f);
    scene->addItem(svgItem);
}
