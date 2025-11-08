#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "paint_scene.h"
#include "tbrush.h"
#include "timage.h"
#include "ttext.h"
#include <QActionGroup>
#include <QToolBar>
#include <QSlider>
#include <QLabel>
#include <QToolButton>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new paint_scene(this);
    ui->PaintLayout->addWidget(scene);

    brush = new TBrush(Qt::black, 3);
    scene->setTool(brush);

    image = new TImage(this);
    text = new TText(this);

    auto* toolbar = addToolBar("Tools");

    auto* brushAction = toolbar->addAction("Brush");
    brushAction->setCheckable(true);
    brushAction->setChecked(true);

    auto* imageAction = toolbar->addAction("Add Image");
    imageAction->setCheckable(true);

    auto* textAction = toolbar->addAction("Add Text");
    textAction->setCheckable(true);

    toolGroup = new QActionGroup(this);
    toolGroup->addAction(brushAction);
    toolGroup->addAction(imageAction);
    toolGroup->addAction(textAction);

    auto* editMenu = menuBar()->addMenu("Edit");
    auto* undoAction = editMenu->addAction("Undo");
    auto* redoAction = editMenu->addAction("Redo");

    connect(toolGroup, &QActionGroup::triggered, this, &MainWindow::onToolChanged);

    connect(undoAction, &QAction::triggered, this, &MainWindow::onUndo);
    connect(redoAction, &QAction::triggered, this, &MainWindow::onRedo);

    QSlider* brushSizeSlider = new QSlider(Qt::Horizontal);
    brushSizeSlider->setRange(1, 50);
    brushSizeSlider->setValue(3);
    brushSizeSlider->setFixedWidth(100);


    QToolButton* colorButton = new QToolButton();
    colorButton->setText("Color");
    colorButton->setFixedSize(60, 30);
    colorButton->setStyleSheet("background-color: black; color: white;");


    connect(brushSizeSlider, &QSlider::valueChanged, this, [this](int size) {
        brush->setWidth(size);
    });

    connect(colorButton, &QToolButton::clicked, this, [this, colorButton]() {
        QColor newColor = QColorDialog::getColor(brush->getColor(), this, "Choose color");
        if (newColor.isValid()) {
            brush->setColor(newColor);
            text->setColor(newColor);
            QString style = QString("background-color: %1; color: %2;").arg(newColor.name(), newColor.lightness() > 150 ? "black" : "white");
            colorButton->setStyleSheet(style);
            colorButton->setText("");
        }
    });

    toolbar->addWidget(new QLabel("Size:"));
    toolbar->addWidget(brushSizeSlider);
    toolbar->addWidget(new QLabel("Color:"));
    toolbar->addWidget(colorButton);

}

void MainWindow::onUndo() {
    scene->undo();
}

void MainWindow::onRedo() {
    scene->redo();
}

void MainWindow::onToolChanged(QAction* action) {
    if (action->text() == "Brush")
        scene->setTool(brush);
    else if (action->text() == "Add Text")
        scene->setTool(text);
    else if (action->text() == "Add Image")
        scene->setTool(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

