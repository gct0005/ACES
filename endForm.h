#ifndef ENDFORM_H
#define ENDFORM_H

#include <QWidget>

namespace Ui {
class EndForm;
}

class EndForm : public QWidget
{
    Q_OBJECT

public:
    explicit EndForm(QWidget *parent = nullptr);
    ~EndForm();

private:
    Ui::EndForm *ui;
};

#endif // ENDFORM_H
