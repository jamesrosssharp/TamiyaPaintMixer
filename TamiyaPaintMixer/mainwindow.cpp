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
        ui->colorToMixCombo->addItem(d.name);

    m_colToMixScene.addRect(0, 0, 300, 300, QPen(QColor(0,0,0)), QBrush(QColor(0, 0, 0)));
    ui->colorToMixView->setScene(&m_colToMixScene);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetColourToMix(QString str)
{
    std::cout << str.toStdString() << std::endl;

    QColor col = m_collist.colourOf(str);

/*    QPalette pal;
    pal.setColor(QPalette::Background, m_collist.colourOf(str));
    ui->colorToMixView->autoFillBackground();
    ui->colorToMixView->setPalette(pal);
    ui->colorToMixView->show();*/

    m_colToMixScene.addRect(0, 0, 300, 300, QPen(col), QBrush(col));

    int r,g,b;

    col.getRgb(&r, &g, &b);

    ui->colorToMixLabel->setText(QString("Colour to mix (#%1%2%3) ").arg(r, 2, 16, QLatin1Char('0')).arg(g, 2 ,16, QLatin1Char('0')).arg(b, 2, 16, QLatin1Char('0')) );

}
