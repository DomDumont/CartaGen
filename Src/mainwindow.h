#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


namespace Ui {
class MainWindow;
}

class QGraphicsScene;
class CardType;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public:
    QVector<CardType *> supportedCardTypes;

private slots:
    void on_action_AboutCartaGen_triggered();

    void on_actionInsertText_triggered();

    void on_actionNew_Project_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
