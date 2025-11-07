#include "tbrush.h"
#include "draw_command.h"
#include "paint_scene.h"

TBrush::TBrush(const QColor &color, int width): Color(color), pen_width(width) {}

void TBrush::setColor(const QColor &color) { Color = color; }
void TBrush::setWidth(int width) { pen_width = width; }

void TBrush::mousePressEvent(QMouseEvent *event, paint_scene *scene)
{
    if (event->button() == Qt::LeftButton) {
        lastPoint = event->pos();
        drawing = true;
    }
}

void TBrush::mouseMoveEvent(QMouseEvent *event, paint_scene *scene)
{
    if ((event->buttons() & Qt::LeftButton) && drawing) {
        QPoint current = event->pos();

        QPen pen(Color, pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        QPen upen(Qt::white, pen_width, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        Draw_Command *cmd = new Draw_Command(
            const_cast<QImage*>(&scene->getImage()),
            lastPoint,
            current,
            pen,
            upen
            );

        scene->executeCom(cmd);

        lastPoint = current;
        //delete cmd;
    }
}

void TBrush::mouseReleaseEvent(QMouseEvent *event, paint_scene *scene)
{
    if (drawing && event->button() == Qt::LeftButton) {
        drawing = false;
    }
}
