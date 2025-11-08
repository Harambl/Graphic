#include "text_command.h"
#include <QPainter>

Text_Command::Text_Command(QImage* image, QString text, QPoint pos, QColor color): tImage(image), Text(text), Pos(pos), Color(color), backup(image->copy()) {}

void Text_Command::execute(){
    QPainter painter(tImage);
    painter.setPen(Color);
    painter.setFont(QFont("Times", 12));
    painter.drawText(Pos, Text);
}

void Text_Command::undo(){
    *tImage = backup;
}
