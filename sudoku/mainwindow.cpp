#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_2->setDisabled(true);
    m_level=8;    
    QObject::connect(ui->easyGame,&QRadioButton::toggled,this,[=](bool toggle){if(toggle) m_level=8;});
    QObject::connect(ui->mediumGame,&QRadioButton::toggled,this,[=](bool toggle){if(toggle) m_level=6;});
    QObject::connect(ui->hardGame,&QRadioButton::toggled,this,[=](bool toggle){if(toggle) m_level=4;});
    m_pravilo=(int **) malloc(9*sizeof(int *));
   for (int i=0;i<9;++i)
       m_pravilo[i]=(int *) malloc(9*sizeof(int ));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    cleanPravilo();
    ui->tableWidget->clear();
    ui->pushButton_2->setDisabled(false);
    SetValues::fillMe(ui->tableWidget,m_level,m_pravilo);
}



void MainWindow::on_pushButton_2_clicked()
{
    int a=0,ad;
    string str;
    for (int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            QTableWidgetItem * it=ui->tableWidget->item(i,j);

            if (!it->text().isEmpty())
                    ad=it->text().toInt();
            else ad=0;
            if(ad!=m_pravilo[i][j])
            {
                it->setBackground(Qt::red);a++;
            }
            else{
                if(it->background()==Qt::red)
                {
                    it->setBackground(Qt::green);a++;
                }
            }
}
    }
    QMessageBox msb;
    msb.setFixedSize(800,200);
    if(a) {msb.critical(0,"Опа!","В вычисления закралась ошибка...");
    }
    else
    {
        for (int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                QTableWidgetItem * it=ui->tableWidget->item(i,j);
            it->setBackground(Qt::green);
            }
        }
        msb.about(0,"Молодца!","Всё четко!");
    }

}

void MainWindow::cleanPravilo()
{
            for(int i =0; i<9; i++)
            {
                delete[] m_pravilo[i];
            }
            delete[] m_pravilo;

    m_pravilo=(int **) malloc(9*sizeof(int *));
   for (int i=0;i<9;++i)
       m_pravilo[i]=(int *) malloc(9*sizeof(int ));
}

