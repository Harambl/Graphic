#ifndef TOOL_H
#define TOOL_H

#include <QMouseEvent>
#include "paint_scene.h"

class Tool
{
public:
    Tool();
    virtual ~Tool() = default;
    virtual void mousePressEvent(QMouseEvent *event, paint_scene *scene);
    virtual void mouseMoveEvent(QMouseEvent *event, paint_scene *scene);
    virtual void mouseReleaseEvent(QMouseEvent *event, paint_scene *scene);

};

#endif // TOOL_H
