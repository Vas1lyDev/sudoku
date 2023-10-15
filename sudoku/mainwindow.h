#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "zapoln.h"
#include <qmessagebox.h>
#include <qpainter.h>
#include "my_table.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();



private:
    Ui::MainWindow *ui;
    int m_level=0;
    int **m_pravilo;
    void fillMe( My_table* table);
    void cleanPravilo();

};
bool legit(int i, int j, int k);
#endif // MAINWINDOW_H
