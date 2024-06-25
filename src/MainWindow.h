#pragma once

#include <QMainWindow>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "PlotWidget.h"
#include "PointGenerator.h"

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    void setDelay(int delay);

private slots:
    void stop();

private:
    PlotWidget *plotWidget;
    PointGenerator *pointGenerator;
};
