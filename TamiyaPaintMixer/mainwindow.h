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
    void SetColour1(QString str);
    void SetColour2(QString str);
    void SetColour3(QString str);
    void SetColour4(QString str);
    void RecomputeMixedColor();


private:
    Ui::MainWindow *ui;

    ColorList       m_collist;
    QGraphicsScene  m_colToMixScene;
    QGraphicsScene  m_col1Scene;
    QGraphicsScene  m_col2Scene;
    QGraphicsScene  m_col3Scene;
    QGraphicsScene  m_col4Scene;
    QGraphicsScene  m_mixScene;
    QPen            m_colToMixPen;
    QBrush          m_colToMixBrush;

    QColor          m_col1;
    QColor          m_col2;
    QColor          m_col3;
    QColor          m_col4;

};
#endif // MAINWINDOW_H
