#ifndef TIMERCLASS_H
#define TIMERCLASS_H
#include <QObject>
#include <QTimer>

class timerClass:public QObject // luokan täytyy periä QObject
{
    Q_OBJECT  //lisätään makro

public:
    timerClass(QObject* parent = nullptr);
    ~timerClass();

signals:
    void sendTimerUpdate();

public slots:
    void handleTimeOut(); //slotti on ihan normaali funktio

private:
    QTimer* pQTimer;

};

#endif // TIMERCLASS_H





