#include <QApplication>

#include "mainwindow.hpp"

int main(int ac, char **av) {
  QApplication app{ac, av};
  MainWindow window{};
  window.show();
  app.exec();
}
