#include "draw_command.h"

Draw_Command::Draw_Command(QImage *image, QPoint& start, QPoint& end, QPen& pen): dImage(image), Start(start), End(end), Pen(pen), Backup(image->copy()) {}

void Draw_Command::execute(){
    QPainter painter(dImage);
    painter.setPen(Pen);
    painter.drawLine(Start, End);
}

void Draw_Command::undo(){
    *dImage = Backup;
}
