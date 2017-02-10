#ifndef CPUGAMER_H
#define CPUGAMER_H

#include <QObject>

class CPUGamer : public QObject
{
    Q_OBJECT
public:
    explicit CPUGamer(QObject *parent = 0);

signals:

public slots:
};

#endif // CPUGAMER_H
