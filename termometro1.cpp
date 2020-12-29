#include "termometro1.h"
#include "ui_termometro1.h"
#include <QDebug>

Termometro1::Termometro1(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Termometro1)
{
    ui->setupUi(this);
    ui->dialFahr->setValue(32);
    ui->dialKelv->setValue(273);

    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Fahr(int)));
    connect(ui->dialCent, SIGNAL(valueChanged(int)),
            this, SLOT(cent2Kelvin(int)));

    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this, SLOT(fhar2Cent(int)));
    connect(ui->dialFahr,SIGNAL(valueChanged(int)),
            this, SLOT(fhar2Kelvin(int)));

    connect(ui->dialKelv,SIGNAL(valueChanged(int)),
            this, SLOT(kelvin2Cent(int)));
    connect(ui->dialKelv,SIGNAL(valueChanged(int)),
            this, SLOT(kelvin2Fahr(int)));

    //---------------------------------------------

    connect(ui->dialCent, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialFahr, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));
    connect(ui->dialKelv, SIGNAL(sliderPressed()),
            this, SLOT(dialPresionado()));


    connect(ui->dialCent, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    connect(ui->dialFahr, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));
    connect(ui->dialKelv, SIGNAL(sliderReleased()),
            this, SLOT(dialRelajado()));

}
//----------------------------------------------------
//----------------------------------------------------
Termometro1::~Termometro1()
{
    delete ui;
}
//----------------------------------------------------
//---Centigrados--------------------------------------
float Termometro1::cent2Fahr(int valor)
{
    if(ui->dialCent->hasFocus()){
        float f=(valor*9.0/5)+32;
        ui->dialFahr->setValue(f);
        return f;
    }
    return 0;
}
//----------------------------------------------------
float Termometro1::cent2Kelvin(int valor)
{
    if(ui->dialCent->hasFocus()){
        float k=valor + 273.15 ;
        ui->dialKelv->setValue(k);
        return k;
    }
    return 0;
}
//----------------------------------------------------
//---Fahrneheit---------------------------------------
float Termometro1::fhar2Cent(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float f=(valor-32)*5.0/9;
        ui->dialCent->setValue(f);
        return f;
    }
    return 0;
}
//----------------------------------------------------
float Termometro1::fhar2Kelvin(int valor)
{
    if(ui->dialFahr->hasFocus()){
        float f=(valor-32)*5.0/9+273.15;
        ui->dialKelv->setValue(f);
        return f;
    }
    return 0;
}
//----------------------------------------------------
//---Kelvin-------------------------------------------
float Termometro1::kelvin2Cent(int valor)
{
    if(ui->dialKelv->hasFocus()){
        float k=valor-273.15;
        ui->dialCent->setValue(k);
        return k;
    }
    return 0;
}
//----------------------------------------------------
float Termometro1::kelvin2Fahr(int valor)
{
    if(ui->dialKelv->hasFocus()){
        float k=(valor-273.15)*9/5+32;
        ui->dialFahr->setValue(k);
        return k;
    }
    return 0;
}
//----------------------------------------------------
//----------------------------------------------------
void Termometro1::dialPresionado()
{
    //if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::ClosedHandCursor);
    //}else{
        ui->dialFahr->setCursor(Qt::ClosedHandCursor);
    //}
        ui->dialKelv->setCursor(Qt::ClosedHandCursor);
}

void Termometro1::dialRelajado()
{
    //if(ui->dialCent->hasFocus()){
        ui->dialCent->setCursor(Qt::OpenHandCursor);
    //}else{
        ui->dialFahr->setCursor(Qt::OpenHandCursor);
    //}
        ui->dialKelv->setCursor(Qt::OpenHandCursor);
}

