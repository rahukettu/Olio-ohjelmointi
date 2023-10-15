#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "timerclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    short player1Time;
    short player2Time;
    void resetProgressBar();
    void updateProgressBar();
    void setGameInfoText(QString,short);
    double calculateResult(short, short);

public slots:
    void timeout();
    void handleStart();
    void handleStop();
    void handleSwitch();
    void handleTwoMin();
    void handleFiveMin();


private:
    Ui::MainWindow *ui;
    short currentPlayer;
    short gameTime;
    short player1StoppedTime;
    short player2StoppedTime;
    int result;
    timerClass* pTimerClass;


};
#endif // MAINWINDOW_H
