#ifndef TERMOMETRO1_H
#define TERMOMETRO1_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Termometro1; }
QT_END_NAMESPACE

class Termometro1 : public QMainWindow
{
    Q_OBJECT

public:
    Termometro1(QWidget *parent = nullptr);
    ~Termometro1();

public slots:
    float cent2Fahr(int);
    float cent2Kelvin(int);
    //---------------------
    float fhar2Cent(int);
    float fhar2Kelvin(int);
    //---------------------
    float kelvin2Cent(int);
    float kelvin2Fahr(int);
    //---------------------
    void dialPresionado();
    void dialRelajado();

private:
    Ui::Termometro1 *ui;
};
#endif // TERMOMETRO1_H
