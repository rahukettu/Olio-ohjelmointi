#include "timerclass.h"

timerClass::timerClass(QObject *parent)
{
    pQTimer = new QTimer(this);
    connect(pQTimer,SIGNAL(timeout()),this,SLOT(handleTimeOut())); //käynnistä ajastin näillä kahdella rivillä
    pQTimer->start(1000);

}

timerClass::~timerClass()
{
    delete pQTimer;
    pQTimer = nullptr;
}

void timerClass::handleTimeOut()
{
    emit sendTimerUpdate();
}
