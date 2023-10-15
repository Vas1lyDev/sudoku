#include "my_table.h"



void My_table::paintEvent(QPaintEvent *event)
{
    QTableWidget::paintEvent(event);
    QPainter painter(viewport());

    painter.setRenderHint(QPainter::Antialiasing,true);
    painter.setPen(Qt::black);
    painter.drawLine(105,0,105,400);
    painter.drawLine(210,0,210,400);
    painter.drawLine(0,90,400,90);
    painter.drawLine(0,180,400,180);
    painter.drawLine(1,1,400,1);
    painter.drawLine(1,1,1,400);
    painter.drawLine(315,0,315,400);
    painter.drawLine(0,270,400,270);


}

