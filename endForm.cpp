#include "endForm.h"
#include "ui_endForm.h"

EndForm::EndForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EndForm)
{
    ui->setupUi(this);
}

EndForm::~EndForm()
{
    delete ui;
}
