#include "measurementModule.h"

MeasurementModule::MeasurementModule(QObject *parent)
    : QObject{parent}
{
    logFile.setFileName("event_log.csv");
    logFile.open(QIODevice::WriteOnly | QIODevice::Text);

    writeCSV("TimeStamp, TimeSinceLastEvent (ms), TotalTime (ms)");

    connect(this, &MeasurementModule::gameStarted, this, &MeasurementModule::startCount);
}

MeasurementModule::~MeasurementModule()
{
    // Close the logfile
    logFile.close();
}

void MeasurementModule::logEvent()
{
    // Calculate the time since the last event
    QDateTime currentTime = QDateTime::currentDateTime();
    qint64 timeSinceLastEvent = lastEventTime.msecsTo(currentTime);

    // Update the last event time
    lastEventTime = currentTime;

    // Calculate the total time since the start of the game
    qint64 totalTime = gameStartTime.msecsTo(currentTime);
    QString currentTimeString = currentTime.toString("hh:mm:ss.zzz");


    // Write the time since the last event to the CSV file
    writeCSV(currentTimeString + ", " + QString::number(timeSinceLastEvent) + ", " + QString::number(totalTime));
}

void MeasurementModule::startCount()
{
    lastEventTime = QDateTime::currentDateTime();
    gameStartTime = QDateTime::currentDateTime();
    writeCSV("\n");
}

void MeasurementModule::writeCSV(const QString& data)
{
    QTextStream stream(&logFile);
    stream << data << "\n";
}
