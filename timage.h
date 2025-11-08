#ifndef TIMAGE_H
#define TIMAGE_H

#include "tool.h"
#include <QImage>
#include "mainwindow.h"

class TImage: public Tool
{
public:
    explicit TImage(MainWindow* mainWin);

    void mousePressEvent(QMouseEvent *event, paint_scene *scene) override;

private:

    MainWindow* MainWin = nullptr;

};

#endif // TIMAGE_H
