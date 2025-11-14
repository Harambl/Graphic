#include "paint_scene.h"


paint_scene::paint_scene(QWidget *parent): QWidget{parent} {
    Image = QImage(1343, 850, QImage::Format_RGB32);
    Image.fill(Qt::white);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void paint_scene::setImage(const QImage& image){
    Image = image;
    update();
}

const QImage& paint_scene::getImage() const{
    return Image;
}

void paint_scene::saveImage(){
    QString fnCount = QString::number(Image_count);
    QString fnName = Image_name + fnCount + ".png";
    Image.save(fnName);
    Image_count += 1;
}

void paint_scene::setTool(Tool* tool){
    currentTool = tool;
}
void paint_scene::clear_scene(){
    Image.fill(Qt::white);

    for (Command* com : UndoStack) {
        delete com;
        }

    UndoStack.clear();

    for (Command* com : RedoStack){
        delete com;
        }

    RedoStack.clear();

    update();
}

void paint_scene::executeCom(Command *com){
    com->execute();
    UndoStack.push_back(com);
    if (UndoStack.size() > MaxDo) {
        delete UndoStack.takeFirst();
    }

    for (Command* com : RedoStack){
        delete com;
    }

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

    if (hasTempPath){
        painter.setPen(tempPen);
        painter.drawPath(tempPath);
    }
}

void paint_scene::setTempPath(const QPainterPath& path, const QPen& pen) {
    tempPath = path;
    tempPen = pen;
    hasTempPath = true;
    update();
}

void paint_scene::clearTempPath() {
    hasTempPath = false;
    update();
}

void paint_scene::mousePressEvent(QMouseEvent* event) {
    if (currentTool)
        currentTool->mousePressEvent(event, this);
    update();
}

void paint_scene::mouseMoveEvent(QMouseEvent* event) {
    if (currentTool)
        currentTool->mouseMoveEvent(event, this);
    update();
}

void paint_scene::mouseReleaseEvent(QMouseEvent* event) {
    if (currentTool)
        currentTool->mouseReleaseEvent(event, this);
    update();
}
