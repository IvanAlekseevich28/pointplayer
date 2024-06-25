#include "PlotWidget.h"

PlotWidget::PlotWidget(QWidget *parent) : QWidget(parent) {
    setAttribute(Qt::WA_OpaquePaintEvent);
}

void PlotWidget::setPoint(double x, double y) {
    if (x < 0 || x > 1 || y < 0 || y > 1) return;
    points.append(QPointF(x, y));
    updatePoint(x, y);
}

void PlotWidget::reset() {
    points.clear();
    drawAxes();
    update();
}

void PlotWidget::paintEvent(QPaintEvent *event) {
    QPainter painter(this);

    if (axesPixmap.isNull() || axesPixmap.size() != size()) {
        drawAxes();
    }

    painter.drawPixmap(0, 0, axesPixmap);

    painter.setPen(Qt::black);
    for (const auto &point : points) {
        auto x = margin + point.x() * (width() - 2 * margin);
        auto y = height() - (margin + point.y() * (height() - 2 * margin));
        painter.drawEllipse(QPointF(x, y), pointSize, pointSize);
    }
}

void PlotWidget::drawAxes() {
    int w = width();
    int h = height();

    axesPixmap = QPixmap(w, h);
    axesPixmap.fill(Qt::white);

    QPainter painter(&axesPixmap);
    painter.setRenderHint(QPainter::Antialiasing);

    QPen axisPen(Qt::black, 2);
    painter.setPen(axisPen);

    painter.drawLine(margin, h - margin, w - margin, h - margin);  // X-axis
    painter.drawLine(w - margin, h - margin, w - margin - arrowSize, h - margin - arrowSize / 2);
    painter.drawLine(w - margin, h - margin, w - margin - arrowSize, h - margin + arrowSize / 2);

    painter.drawLine(margin, h - margin, margin, margin);  // Y-axis
    painter.drawLine(margin, margin, margin - arrowSize / 2, margin + arrowSize);
    painter.drawLine(margin, margin, margin + arrowSize / 2, margin + arrowSize);

    painter.drawText(margin - 5, h - margin + 15, "0");
    painter.drawText(w - margin - 5, h - margin + 15, "1");
    painter.drawText(margin - 15, margin + 5, "1");
}

void PlotWidget::updatePoint(double x, double y) {
    QPainter painter(&axesPixmap);
    painter.setPen(Qt::black);
    auto px = margin + x * (width() - 2 * margin);
    auto py = height() - (margin + y * (height() - 2 * margin));
    painter.drawEllipse(QPointF(px, py), pointSize, pointSize);
    update(px - pointSize, py - pointSize, 2 * pointSize, 2 * pointSize);
}
