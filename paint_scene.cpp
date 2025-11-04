#include "paint_scene.h"

paint_scene::paint_scene(QWidget *parent): QWidget{parent} {
    Image = QImage(size(), QImage::Format_RGB32);
    Image.fill(Qt::white);
}

void paint_scene::setImage(const QImage& image){
    Image = image;
    update();
}

const QImage& paint_scene::getImage() const{
    return Image;
}

void paint_scene::clear_scene(){
    Image.fill(Qt::white);
    update();
}

void paint_scene::executeCom(Command *com){
    com->execute();
    UndoStack.push_back(com);
    RedoStack.clear();
}

void paint_scene::undo(){
    if (!UndoStack.isEmpty()){
        Command *com = UndoStack.takeLast();
        com->undo();
        RedoStack.push_back(com);
        update();
    }
}

void paint_scene::redo(){
    if (!RedoStack.isEmpty()){
        Command *com = RedoStack.takeLast();
        com->execute();
        UndoStack.push_back(com);
        update();
    }
}

void paint_scene::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawImage(event->rect(), Image, event->rect());
}
