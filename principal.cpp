#include "principal.h"
#include "ui_principal.h"
#include <QDebug>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    // Conectar el dial de Centigrados con el slot de ESTA clase
    connect(ui->inCent, SIGNAL(valueChanged(int)),
           this,SLOT(cent2fahr(int)));
    // Conectar el dial de Fahrenheith con el slot de ESTA clase
    connect(ui->inFahr, SIGNAL(valueChanged(int)),
           this,SLOT(fahr2cent(int)));
}

Principal::~Principal()
{
    delete ui;
}

void Principal::cent2fahr(int cent)
{
    if (ui->inCent->hasFocus()){
        int fahr = (cent * 9.0/5) + 32;
        ui->inFahr->setValue(fahr);
    }
}

void Principal::fahr2cent(int i)
{
    if (ui->inFahr->hasFocus()){
        int c = (i - 32) * 5.0/9;
        ui->inCent->setValue(c);
    }
}

