#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGlobal>
#include <QTimer>
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pTimerClass = new timerClass(this);
    player1Time = 0;
    player2Time = 0;
    player1StoppedTime = 0;
    player2StoppedTime = 0;
    currentPlayer = 0;
    gameTime = 0;
    result = 0;

    resetProgressBar();
    setGameInfoText("Select playtime and start game!", 100);
    connect(ui->TwoMin,SIGNAL(clicked(bool)),this,SLOT(handleTwoMin()));
    connect(ui->FiveMin,SIGNAL(clicked(bool)),this,SLOT(handleFiveMin()));
    connect(ui->Start,SIGNAL(clicked(bool)),this,SLOT(handleStart()));
    connect(ui->Stop,SIGNAL(clicked(bool)),this,SLOT(handleStop()));
    connect(ui->SwitchOne,SIGNAL(clicked(bool)),this,SLOT(handleSwitch()));
    connect(ui->SwitchTwo,SIGNAL(clicked(bool)),this,SLOT(handleSwitch()));
    connect(pTimerClass,SIGNAL(sendTimerUpdate()),this,SLOT(timeout()));
    connect(pTimerClass,SIGNAL(timeout()),this,SLOT(updateProgressBar()));



}

MainWindow::~MainWindow()
{
    delete ui;
    delete pTimerClass;
    pTimerClass = nullptr;

}

void MainWindow::timeout()
{
    if (currentPlayer == 0) {
        player1Time--;

        if (player1Time == 0) {
            setGameInfoText("Player 2 WON", 100);
            return;
        }
        updateProgressBar();
    }
    else if (currentPlayer == 1) {
        player2Time--;

        if (player2Time == 0) {
            setGameInfoText("Player 1 WON", 100);
            return;
        }
         updateProgressBar();
    }
}

void MainWindow::resetProgressBar()
{
    ui->progressBarLeft->setValue(100);
    ui->progressBarRight->setValue(100);
}

void MainWindow::updateProgressBar()
{
    if (currentPlayer == 0) {
        qDebug("result = %d", result);
        qDebug("player1Time = %d", player1Time);
        qDebug("gameTime = %d", gameTime);

        result = calculateResult(player1Time, gameTime);

        printf("result = %d", result);
        ui->progressBarLeft->setValue(result);
    }
    else if (currentPlayer == 1) {
        qDebug("result = %d", result);
        qDebug("player2Time = %d", player2Time);
        qDebug("gameTime = %d", gameTime);
        result = calculateResult(player2Time, gameTime);
        printf("result2 = %d", result);
        ui->progressBarRight->setValue(result);
    }

}

void MainWindow::setGameInfoText(QString t, short)
{
    ui->textbox->setText(t);
}

void MainWindow::handleStart()
{
    setGameInfoText("Game ongoing", 100);
    qDebug("gameTime: %d", gameTime);
}

void MainWindow::handleStop()
{
    resetProgressBar();
    player1Time=0;
    player2Time=0;
    setGameInfoText("New game via start button", 100);

}

void MainWindow::handleSwitch()
{
    if (currentPlayer == 1) {
        player1Time = player1StoppedTime;
        player2StoppedTime = player2Time;
        currentPlayer = 0;
        return;
    }
    else if (currentPlayer == 0) {
        player2Time = player2StoppedTime;
        player1StoppedTime = player1Time;
        currentPlayer = 1;
        return;
    }
}

void MainWindow::handleTwoMin()
{
    gameTime = 120;
    player1Time = 120;
    player2Time = 120;
    player1StoppedTime = 120;
    player2StoppedTime = 120;
    setGameInfoText("Ready to play", 100);
}


void MainWindow::handleFiveMin()
{
    gameTime = 300;
    player1Time = 300;
    player2Time = 300;
    player1StoppedTime = 300;
    player2StoppedTime = 300;
    setGameInfoText("Ready to play", 100);
}
double MainWindow::calculateResult(short pT, short gT) {
    return (double(pT)/gT)*100;
}

