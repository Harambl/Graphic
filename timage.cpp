#include "timage.h"
#include "image_command.h"
#include <QFileDialog>

TImage::TImage(MainWindow* mainWin): MainWin(mainWin) {}

void TImage::mousePressEvent(QMouseEvent *event, paint_scene *scene) {
    QPoint pos = QPoint(event->pos());

    QString filePath = QFileDialog::getOpenFileName(
        MainWin,
        "Select Image",
        "",
        "Images (*.png *.jpg *.jpeg *.bmp *.gif)"
        );

    if (filePath.isEmpty()) return;

    QImage image(filePath);

    Image_Command* com = new Image_Command(const_cast<QImage*>(&scene->getImage()), image, pos);

    scene->executeCom(com);
}

