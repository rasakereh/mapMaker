#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "headers/MapDraft.h"
#include <vector>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void Connector();
    void Save();
    std::vector<Cell *> Load();
    MapDraft defaultDraft;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
