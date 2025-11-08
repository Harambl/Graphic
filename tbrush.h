#ifndef TBRUSH_H
#define TBRUSH_H
#pragma once

#include "tool.h"
#include <QPoint>
#include <QColor>
#include <QPen>
#include <QPainterPath>


class TBrush: public Tool
{

public:
    TBrush(const QColor &color = Qt::black, int width = 3);

    void setColor(const QColor &color) override;
    void setWidth(int width) override;
    QColor getColor() override;

    void mousePressEvent(QMouseEvent *event, paint_scene *scene) override;
    void mouseMoveEvent(QMouseEvent *event, paint_scene *scene) override;
    void mouseReleaseEvent(QMouseEvent *event, paint_scene *scene) override;

private:

    QColor Color;
    int pen_width;
    bool drawing = false;
    QPainterPath path;

};

#endif // TBRUSH_H
