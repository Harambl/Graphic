#include "draw_command.h"

Draw_Command::Draw_Command(QImage *image, QPainterPath& path, QPen& pen): dImage(image), Path(path), Pen(pen), Backup(image->copy()) {}

void Draw_Command::execute(){
    QPainter painter(dImage);
    painter.setPen(Pen);
    painter.drawPath(Path);
}

void Draw_Command::undo(){
    *dImage = Backup;
}
