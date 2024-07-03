#pragma once

#include <QWidget>
#include <QPainter>
#include <QVector>
#include <QPixmap>

class PlotWidget : public QWidget {
Q_OBJECT

public:
    explicit PlotWidget(QWidget *parent = nullptr);

public slots:
    void setPoint(double x, double y);
    void reset();

protected:
    void paintEvent(QPaintEvent *) override;
    void resizeEvent(QResizeEvent *) override;

private:
    void drawAxes();
    void updatePoint(double x, double y);

private:
    QVector<QPointF> points;
    QPixmap axesPixmap;
    const int margin = 35;
    const int arrowSize = 10;
    const int pointSize = 3;
};
