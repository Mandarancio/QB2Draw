#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <box2d/box2d.h>
#include <QPainter>

#include "qb2draw.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private:
    b2World *world;//The world
    QB2Draw *draw;//The drawer
protected:
    void paintEvent(QPaintEvent *);//Paint event)
};

#endif // MAINWINDOW_H
