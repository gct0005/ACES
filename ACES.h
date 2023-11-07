#ifndef ACES_H
#define ACES_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class ACES; }
QT_END_NAMESPACE

class ACES : public QWidget
{
    Q_OBJECT

public:
    ACES(QWidget *parent = nullptr);
    ~ACES();

private:
    Ui::ACES *ui;
};
#endif // ACES_H
