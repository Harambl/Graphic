#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "paint_scene.h"
#include "tbrush.h"
#include <QActionGroup>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new paint_scene(this);
    //setCentralWidget(scene);
    ui->PaintLayout->addWidget(scene);

    brush = new TBrush(Qt::black, 3);
    scene->setTool(brush);

    auto* toolbar = addToolBar("Tools");

    auto* brushAction = toolbar->addAction("Pen");
    brushAction->setCheckable(true);
    brushAction->setChecked(true);

    toolGroup = new QActionGroup(this);
    toolGroup->addAction(brushAction);

    connect(toolGroup, &QActionGroup::triggered, this, &MainWindow::onToolChanged);

    auto* editMenu = menuBar()->addMenu("Edit");
    auto* undoAction = editMenu->addAction("Undo");
    auto* redoAction = editMenu->addAction("Redo");

    connect(undoAction, &QAction::triggered, this, &MainWindow::onUndo);
    connect(redoAction, &QAction::triggered, this, &MainWindow::onRedo);
}

void MainWindow::onUndo() {
    scene->undo();
}

void MainWindow::onRedo() {
    scene->redo();
}

void MainWindow::onToolChanged(QAction* action) {
    if (action->text() == "Pen")
        scene->setTool(brush);
    //else if (action->text() == "Text")
        //scene->setTool(m_textTool);
    //else if (action->text() == "Image")
        //scene->setTool(m_imageTool);
}

MainWindow::~MainWindow()
{
    delete ui;
}

