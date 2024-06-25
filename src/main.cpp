#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    MainWindow mainWindow;
    mainWindow.resize(800, 600);
    mainWindow.show();

    // Пример изменения интервала генерации точек.
    mainWindow.setDelay(100);

    return QApplication::exec();
}
