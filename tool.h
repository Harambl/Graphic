#ifndef TOOL_H
#define TOOL_H

#include <QMouseEvent>

class paint_scene;

class Tool
{
public:
    Tool();
    virtual ~Tool();
    virtual void mousePressEvent(QMouseEvent *event, paint_scene *scene) = 0;
    virtual void mouseMoveEvent(QMouseEvent *event, paint_scene *scene) = 0;
    virtual void mouseReleaseEvent(QMouseEvent *event, paint_scene *scene) = 0;

};

#endif // TOOL_H
