#include "tbrush.h"
#include "draw_command.h"
#include "paint_scene.h"
#include <QPainterPath>

TBrush::TBrush(const QColor &color, int width): Color(color), pen_width(width) {}

void TBrush::setColor(const QColor &color) { Color = color; }
void TBrush::setWidth(int width) { pen_width = width; }
QColor TBrush::getColor(){ return Color; }

void TBrush::mousePressEvent(QMouseEvent *event, paint_scene *scene)
{
    if (event->button() == Qt::LeftButton) {
        path = QPainterPath(event->pos());
        drawing = true;
        scene->setTempPath(path, QPen(Qt::gray, pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    }
}

void TBrush::mouseMoveEvent(QMouseEvent *event, paint_scene *scene)
{
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        path.lineTo(event->pos());
        scene->setTempPath(path, QPen(Color, pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
        scene->update();
    }
}

void TBrush::mouseReleaseEvent(QMouseEvent *event, paint_scene *scene)
{
    if (drawing && event->button() == Qt::LeftButton) {
        QPen pen(Color, pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        Draw_Command* com = new Draw_Command(const_cast<QImage*>(&scene->getImage()), path, pen);

        scene->executeCom(com);
        scene->clearTempPath();

        drawing = false;
        path = QPainterPath();
    }
}
