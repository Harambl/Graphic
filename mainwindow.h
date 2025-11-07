#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "paint_scene.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void onUndo();
    void onRedo();
    void onToolChanged(QAction* action);

private:

    Ui::MainWindow *ui;
    paint_scene* scene;
    Tool* brush;

    QActionGroup* toolGroup;
};
#endif // MAINWINDOW_H
