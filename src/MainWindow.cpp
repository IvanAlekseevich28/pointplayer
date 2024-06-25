#include "MainWindow.h"
#include <QStyle>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    auto centralWidget = new QWidget(this);

    auto mainLayout = new QVBoxLayout(centralWidget);
    auto buttonLayout = new QHBoxLayout();

    auto startButton = new QPushButton(this);
    auto pauseButton = new QPushButton(this);
    auto stopButton = new QPushButton(this);

    startButton->setIcon(style()->standardIcon(QStyle::SP_MediaPlay));
    pauseButton->setIcon(style()->standardIcon(QStyle::SP_MediaPause));
    stopButton->setIcon(style()->standardIcon(QStyle::SP_MediaStop));

    plotWidget = new PlotWidget(this);
    pointGenerator = new PointGenerator(plotWidget, this);

    buttonLayout->addWidget(startButton);
    buttonLayout->addWidget(pauseButton);
    buttonLayout->addWidget(stopButton);

    mainLayout->addWidget(plotWidget);
    mainLayout->addLayout(buttonLayout);

    setCentralWidget(centralWidget);

    connect(startButton, &QPushButton::released, pointGenerator, &PointGenerator::startGenerating);
    connect(pauseButton, &QPushButton::released, pointGenerator, &PointGenerator::pauseGenerating);
    connect(stopButton, &QPushButton::released, this, &MainWindow::stop);

    connect(pointGenerator, &PointGenerator::newPoint, plotWidget, &PlotWidget::setPoint);

    pointGenerator->start();
}

void MainWindow::setDelay(int delay) {
    pointGenerator->setDelay(delay);
}

void MainWindow::stop() {
    pointGenerator->stopGenerating();
}
