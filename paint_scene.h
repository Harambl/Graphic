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
#include "tool.h"

class paint_scene : public QWidget
{
    Q_OBJECT
public:

    explicit paint_scene(QWidget *parent = nullptr);

    void clear_scene();
    void setTool(Tool* tool);

    const QImage& getImage() const;
    void setImage(const QImage& image);

    void executeCom(Command *com);
    void undo();
    void redo();
protected:

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;


private:

    //void paintEvent(QPaintEvent *event) override;

    QList<Command*> UndoStack;
    QList<Command*> RedoStack;
    static const int MaxDo = 50;

    QImage Image;
    Tool* currentTool = nullptr;

signals:

};

#endif // PAINT_SCENE_H
