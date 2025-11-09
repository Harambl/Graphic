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
#include <QShortcut>

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new paint_scene(this);
    ui->PaintLayout->addWidget(scene);

    brush = new TBrush(Qt::black, 3);
    scene->setTool(brush);

    eraser = new TBrush(Qt::white, 3);

    image = new TImage(this);
    text = new TText(this);

    auto* toolbar = addToolBar("Tools");

    auto* brushAction = toolbar->addAction("Brush");
    brushAction->setCheckable(true);
    brushAction->setChecked(true);

    auto* eraseAction = toolbar->addAction("Eraser");
    eraseAction->setCheckable(true);

    auto* imageAction = toolbar->addAction("Add Image");
    imageAction->setCheckable(true);

    auto* textAction = toolbar->addAction("Add Text");
    textAction->setCheckable(true);

    toolGroup = new QActionGroup(this);
    toolGroup->addAction(brushAction);
    toolGroup->addAction(eraseAction);
    toolGroup->addAction(imageAction);
    toolGroup->addAction(textAction);

    QShortcut* ushortcut = new QShortcut(QKeySequence("Ctrl+Z"), this);
    QShortcut* rshortcut = new QShortcut(QKeySequence("Ctrl+Y"), this);

    connect(toolGroup, &QActionGroup::triggered, this, &MainWindow::onToolChanged);

    connect(ushortcut, &QShortcut::activated, this, &MainWindow::onUndo);
    connect(rshortcut, &QShortcut::activated, this, &MainWindow::onRedo);

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
        eraser->setWidth(size);
    });

    connect(colorButton, &QToolButton::clicked, this, [this, colorButton]() {
        QColor newColor = QColorDialog::getColor(brush->getColor(), this, "Choose color");
        if (newColor.isValid()) {
            brush->setColor(newColor);
            text->setColor(newColor);
            QString style = QString("background-color: %1;").arg(newColor.name());
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
    else if (action->text() == "Eraser")
        scene->setTool(eraser);
    else if (action->text() == "Add Text")
        scene->setTool(text);
    else if (action->text() == "Add Image")
        scene->setTool(image);
}

MainWindow::~MainWindow()
{
    delete ui;
}

