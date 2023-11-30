#include "measurementModule.h"

MeasurementModule::MeasurementModule(QObject *parent)
    : QObject{parent}
{
    logFile.setFileName("event_log.csv");
    logFile.open(QIODevice::WriteOnly | QIODevice::Text);

    writeCSV("TimeSinceLastEvent (ms)");

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

    // Write the time since the last event to the CSV file
    writeCSV(QString::number(timeSinceLastEvent));
}

void MeasurementModule::startCount()
{
    lastEventTime = QDateTime::currentDateTime();
    writeCSV("\n");
}

void MeasurementModule::writeCSV(const QString& data)
{
    QTextStream stream(&logFile);
    stream << data << "\n";
}
