#ifndef MEASUREMENTMODULE_H
#define MEASUREMENTMODULE_H

#include <QObject>
#include <QFile>
#include <QTextStream>
#include <QDateTime>

class MeasurementModule : public QObject
{
    Q_OBJECT
public:
    explicit MeasurementModule(QObject *parent = nullptr);
    ~MeasurementModule();

    void writeCSV(const QString& data);

public slots:
    void logEvent();
    void startCount();

signals:
    void gameStarted();

private:
    QFile logFile;
    QDateTime lastEventTime;

};

#endif // MEASUREMENTMODULE_H
