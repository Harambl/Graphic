#ifndef IMAGE_COMMAND_H
#define IMAGE_COMMAND_H
#pragma once

#include "command.h"
#include <QImage>

class Image_Command: public Command
{
public:
    Image_Command(QImage* image, const QImage& imageToIns, const QPoint& pos);

    void execute();
    void undo();

private:
    QImage* iImage;
    QImage InsertedImage;
    QPoint Pos;
    QImage backup;
};

#endif // IMAGE_COMMAND_H
