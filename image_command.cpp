#include "image_command.h"
#include <QPainter>

Image_Command::Image_Command(QImage* image, const QImage& imgToInsert, const QPoint& pos): iImage(image), InsertedImage(imgToInsert), Pos(pos), backup(image->copy()) {}

void Image_Command::execute() {
    QPainter painter(iImage);
    painter.drawImage(Pos, InsertedImage);
}

void Image_Command::undo() {
    *iImage = backup;
}
