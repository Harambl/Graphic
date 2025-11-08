#ifndef TEXT_COMMAND_H
#define TEXT_COMMAND_H
#pragma once

#include "command.h"
#include <QImage>

class Text_Command: public Command
{
public:
    Text_Command(QImage* image, QString text, QPoint pos, QColor color);

    void execute();
    void undo();

private:

    QImage* tImage;
    QString Text;
    QPoint Pos;
    QColor Color;
    QImage backup;

};

#endif // TEXT_COMMAND_H
