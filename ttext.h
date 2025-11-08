#ifndef TTEXT_H
#define TTEXT_H
#pragma once

#include "tool.h"
#include "text_command.h"
#include "mainwindow.h"

class TText: public Tool
{
public:
    explicit TText(MainWindow* mainWin);

    void setColor(const QColor& color) override;

    void mousePressEvent(QMouseEvent *event, paint_scene *scene) override;

private:

    MainWindow* MainWin = nullptr;
    QColor Color;

};

#endif // TTEXT_H
