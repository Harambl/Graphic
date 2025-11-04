#ifndef TBRUSH_H
#define TBRUSH_H

#include "tool.h"
#include <QPoint>
#include <QColor>
#include <QPen>


class TBrush: public Tool
{
public:
    TBrush(const QColor &color = Qt::black, int width = 3);

    void setColor(const QColor &color);
    void setWidth(int width);

    void mousePressEvent(QMouseEvent *event, paint_scene *scene) override;
    void mouseMoveEvent(QMouseEvent *event, paint_scene *scene) override;
    void mouseReleaseEvent(QMouseEvent *event, paint_scene *scene) override;

private:

    QColor Color;
    int pen_width;
    bool drawing = false;
    QPoint lastPoint;

};

#endif // TBRUSH_H
