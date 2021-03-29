#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "colorlist.h"

#include <QGraphicsScene>
#include <QPen>
#include <QBrush>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void SetColourToMix(QString str);

private:
    Ui::MainWindow *ui;

    ColorList       m_collist;
    QGraphicsScene  m_colToMixScene;
    QPen            m_colToMixPen;
    QBrush          m_colToMixBrush;


};
#endif // MAINWINDOW_H
