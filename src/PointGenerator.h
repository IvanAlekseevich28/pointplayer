#pragma once

#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include <random>

class PlotWidget;

class PointGenerator : public QThread {
Q_OBJECT

public:
    explicit PointGenerator(PlotWidget *plotWidget, QObject *parent = nullptr);

    void run() override;
    void startGenerating();
    void pauseGenerating();
    void stopGenerating();
    void setDelay(int newDelay);

signals:
    void newPoint(double x, double y);

private:
    PlotWidget *plotWidget;
    bool running;
    QMutex mutex;
    QWaitCondition condition;
    int delay;
    std::mt19937 randomEngine;
    std::uniform_real_distribution<double> randomDistribution{0.0, 1.0};
};
