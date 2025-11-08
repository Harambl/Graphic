#include "ttext.h"
#include "QInputDialog"

TText::TText(MainWindow* mainWin): MainWin(mainWin) {}

void TText::setColor(const QColor& color) { Color = color; }

void TText::mousePressEvent(QMouseEvent *event, paint_scene *scene){
    bool ok;
    QString text = QInputDialog::getText(MainWin,"Insert Text","Enter text:",QLineEdit::Normal,"",&ok);

    if (!ok || text.trimmed().isEmpty()) {
        return;
    }

    QPoint pos = QPoint(event->pos());

    Text_Command* com = new Text_Command(const_cast<QImage*>(&scene->getImage()), text, pos, Color);

    scene->executeCom(com);
}
