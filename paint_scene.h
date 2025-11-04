#ifndef PAINT_SCENE_H
#define PAINT_SCENE_H

#include <QObject>
#include <QWidget>
#include <QList>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>
#include "command.h"

class paint_scene : public QWidget
{
    Q_OBJECT
public:

    explicit paint_scene(QWidget *parent = nullptr);

    void clear_scene();
    const QImage& getImage() const;
    void setImage(const QImage& image);

    void executeCom(Command *com);
    void undo();
    void redo();

private:

    void paintEvent(QPaintEvent *event) override;

    QList<Command*> UndoStack;
    QList<Command*> RedoStack;

    QImage Image;

signals:

};

#endif // PAINT_SCENE_H
