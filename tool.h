#ifndef TOOL_H
#define TOOL_H
#include <qcolor.h>
#pragma once

#include <QMouseEvent>

class paint_scene;

class Tool
{
public:
    Tool();
    virtual ~Tool();
    virtual void mousePressEvent(QMouseEvent *event, paint_scene *scene) {}
    virtual void mouseMoveEvent(QMouseEvent *event, paint_scene *scene) {}
    virtual void mouseReleaseEvent(QMouseEvent *event, paint_scene *scene) {}
    virtual void setWidth(int width) {}
    virtual void setColor(const QColor& color) {}
    virtual QColor getColor() { return Qt::white; }

};

#endif // TOOL_H
