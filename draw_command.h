#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H

#include "command.h"
#include <QPoint>
#include <QImage>
#include <QPen>
#include <QPainter>

class Draw_Command: public Command
{
public:
    Draw_Command(QImage *image, QPoint& start, QPoint& end, QPen& pen, QPen& Upen);

    void undo() override;
    void execute() override;

private:

    QImage *dImage;
    QPen Pen;
    QPen UPen;
    QPoint Start, End;
    QImage Backup;

};

#endif // DRAW_COMMAND_H
