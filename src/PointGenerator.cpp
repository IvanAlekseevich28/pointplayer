#include "PointGenerator.h"
#include "PlotWidget.h"

PointGenerator::PointGenerator(PlotWidget *plotWidget, QObject *parent)
        : QThread(parent),
          plotWidget(plotWidget),
          running(false),
          delay(500),
          randomEngine(std::random_device()()) {
}

void PointGenerator::run() {
    while (running) {
        double x = randomDistribution(randomEngine);
        double y = randomDistribution(randomEngine);
        emit newPoint(x, y);
        QThread::msleep(delay);
    }
}

void PointGenerator::startGenerating() {
    QMutexLocker locker(&mutex);
    running = true;
    condition.wakeAll();
    start();
}

void PointGenerator::pauseGenerating() {
    QMutexLocker locker(&mutex);
    running = false;
}

void PointGenerator::stopGenerating() {
    QMutexLocker locker(&mutex);
    running = false;
    plotWidget->reset();
    condition.wakeAll();
}

void PointGenerator::setDelay(int newDelay) {
    QMutexLocker locker(&mutex);
    delay = newDelay;
}
