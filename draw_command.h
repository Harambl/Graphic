#ifndef DRAW_COMMAND_H
#define DRAW_COMMAND_H
#pragma once

#include "command.h"
#include <QPoint>
#include <QImage>
#include <QPen>
#include <QPainter>
#include <QPainterPath>

class Draw_Command: public Command
{
public:
    Draw_Command(QImage *image, QPainterPath& Path, QPen& pen);

    void undo() override;
    void execute() override;

private:

    QImage *dImage;
    QPen Pen;
    QPainterPath Path;
    QImage Backup;

};

#endif // DRAW_COMMAND_H
