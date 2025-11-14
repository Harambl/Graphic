#ifndef PAINT_SCENE_H
#define PAINT_SCENE_H
#pragma once

#include <QObject>
#include <QWidget>
#include <QList>
#include <QImage>
#include <QPoint>
#include <QColor>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
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
    void saveImage();

    void executeCom(Command *com);
    void undo();
    void redo();

    void setTempPath(const QPainterPath& path, const QPen& pen);
    void clearTempPath();

    void paintEvent(QPaintEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;

private:

    QList<Command*> UndoStack;
    QList<Command*> RedoStack;
    static const int MaxDo = 50;

    QImage Image;
    int Image_count = 0;
    QString Image_name = "image";

    Tool* currentTool = nullptr;

    QPainterPath tempPath;
    QPen tempPen;
    bool hasTempPath = false;

signals:

};

#endif // PAINT_SCENE_H
