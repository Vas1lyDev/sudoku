#ifndef MY_TABLE_H
#define MY_TABLE_H

#include <QObject>
#include <QWidget>
#include <qtablewidget.h>
#include <qpainter.h>

class My_table:public QTableWidget
{

public:
    explicit My_table(QWidget *parent = 0):QTableWidget(parent){};
protected:
   void paintEvent(QPaintEvent*event) ;
};

#endif // MY_TABLE_H
