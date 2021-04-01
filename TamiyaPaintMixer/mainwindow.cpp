#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "colorlist.h"

#include <QBrush>
#include <QPalette>

#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /* Load color selection combos */

    for (const ColorDat& d : m_collist.colourTable())
    {
        ui->colorToMixCombo->addItem(d.name);
        ui->mixColor1ComboBox->addItem(d.name);
        ui->mixColor2ComboBox->addItem(d.name);
        ui->mixColor3ComboBox->addItem(d.name);
        ui->mixColor4ComboBox->addItem(d.name);
    }

    m_colToMixScene.addRect(0, 0, 300, 300, QPen(QColor(0,0,0)), QBrush(QColor(0, 0, 0)));
    ui->colorToMixView->setScene(&m_colToMixScene);

    ui->mixColor1View->setScene(&m_col1Scene);
    ui->mixColor2View->setScene(&m_col2Scene);
    ui->mixColor3View->setScene(&m_col3Scene);
    ui->mixColor4View->setScene(&m_col4Scene);

    ui->mixedColorView->setScene(&m_mixScene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetColourToMix(QString str)
{
    std::cout << str.toStdString() << std::endl;

    QColor col = m_collist.colourOf(str);

    m_colToMixScene.addRect(0, 0, 300, 300, QPen(col), QBrush(col));

    int r,g,b;

    col.getRgb(&r, &g, &b);

    ui->colorToMixLabel->setText(QString("Colour to mix (#%1%2%3) ").arg(r, 2, 16, QLatin1Char('0')).arg(g, 2 ,16, QLatin1Char('0')).arg(b, 2, 16, QLatin1Char('0')) );

}

#define SETCOL(x) void MainWindow::SetColour##x(QString str)\
{\
    std::cout << str.toStdString() << std::endl;\
    m_col##x = m_collist.colourOf(str);\
    m_col##x##Scene.addRect(0, 0, 300, 300, QPen(m_col##x), QBrush(m_col##x));\
    int r,g,b;\
    m_col##x.getRgb(&r, &g, &b);\
    ui->mixColor##x##Label->setText(QString("Mix colour 1 (#%1%2%3) ").arg(r, 2, 16,\
    QLatin1Char('0')).arg(g, 2 ,16, QLatin1Char('0')).arg(b, 2, 16, QLatin1Char('0')) );\
    RecomputeMixedColor();\
}

SETCOL(1)
SETCOL(2)
SETCOL(3)
SETCOL(4)

void MainWindow::RecomputeMixedColor()
{
    int r = 0, g = 0, b = 0;
    int r_accu = 0, g_accu = 0, b_accu = 0;
    int i = 0;

    std::vector<std::pair<QColor, QSlider*>> v = {{m_col1, ui->mixColor1Slider},
                                                  {m_col2, ui->mixColor2Slider},
                                                  {m_col3, ui->mixColor3Slider},
                                                  {m_col4, ui->mixColor4Slider},
                                                };

    int value = 0;
    for (const auto & a : v)
        if ((value = a.second->value()) > 0)
        {
            printf("Value: %d\n", value);
            fflush(0);
            a.first.getRgb(&r, &g, &b);
            r_accu += r*value;
            g_accu += g*value;
            b_accu += b*value;
            i+= value;
        }

    if (i > 1)
    {
        r_accu /= i;
        g_accu /= i;
        b_accu /= i;
    }

    QColor col(r_accu, g_accu, b_accu);

    m_mixScene.addRect(0, 0, 300, 300, QPen(col), QBrush(col));

    ui->mixedColorLabel->setText(QString("Result (#%1%2%3) ").arg(r_accu, 2, 16,\
    QLatin1Char('0')).arg(g_accu, 2 ,16, QLatin1Char('0')).arg(b_accu, 2, 16, QLatin1Char('0')) );

}
