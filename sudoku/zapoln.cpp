#include <iostream>
#include <ctime>
#include <cstdlib>
#include "zapoln.h"
using namespace std;


namespace {

/* Начало блоков с проверками на наполнение.
    ВАЖНО!!!!
    Тут использован Си-стайл только потому, что я тренировался в понимании концепции работы указателей.
    Про существование контейнеров знаю, про булевый тип тоже, но тут такой код сделан намеренно
*/


/*Проверяем число в квадрате*/
int IsSq(int** a,int i,int j, int b)
{
    int di=i/3,dj=j/3;
    for (int _b(di*3),ddi=_b;ddi<_b+3;++ddi)
        for (int __b(dj*3),ddj=__b;ddj<__b+3;++ddj)
            if(a[ddi][ddj]==b) return 1;
    return 0;

}

/*Проверяем число вертикально*/
int IsVer(int** a,int i,int b)
{
    for (int dj=0;dj<9;++dj)
        if(a[i][dj]==b) return 1;
    return 0;
}

/*Проверяем число горизонтально*/
int IsHor(int** a,int j,int b)
{
    for (int di=0;di<9;++di)
        if(a[di][j]==b) return 1;
    return 0;
}

/*Конец блока с проверками*/

/*Заполняем двумерный массив числами "-1"*/
void InitMas(int** a)
{
    for(int i=0;i<9;++i)
        for( int j=0;j<9;++j)
            a[i][j]=-1;
}

/*Производим заполнение массива с значениями для таблицы судоку*/
void zap(int** a)
{
    for (int i=0;i<9;++i)
    {
        for (int j=0;j<9;++j)
        {
            int c=9;
            for (int h=1;h<10;++h)
                if (IsSq(a,i,j,h)||IsHor(a,j,h)||IsVer(a,i,h))
                    --c;
            if(!c)
            {
                InitMas(a);
                zap(a);
                return;
            }
            int b=rand()%9+1;
            while (IsSq(a,i,j,b)||IsHor(a,j,b)||IsVer(a,i,b))
                b=rand()%9+1;
            a[i][j]=b;

        }


    }
}

/*Копируем значения */
void ShowMas(int** a,int** aaa)
{
    for (int i=0;i<9;++i)
    {
        for (int j=0;j<9;++j){
           aaa[i][j]=a[i][j];
         }
         delete[] a[i];
    }
    delete[] a;
}

/*Инициализируем временный массив*/
void nachalo(int** arrr)
{
    int** a=(int **) malloc(9*sizeof(int *));
    for (int i=0;i<9;++i)
        a[i]=(int *) malloc(9*sizeof(int ));
    InitMas(a);
    zap(a);
    ShowMas(a,arrr);
}
}

/*  Заполним  таблицу для судоку (да, это не лучшее решение с указателем на таблицу, и оно совершенно не по MVC, но так как приложение микроскопическое, то применяем подход KISS и удовлетворяемся решением) */
void SetValues::fillMe( My_table* table,int level,int *pravilo[])
{
    srand(time(NULL));
    int** arr=(int **) malloc(9*sizeof(int *));
    for (int i=0;i<9;++i)
        arr[i]=(int *) malloc(9*sizeof(int ));
    nachalo(arr);
    for (int i=0;i<9;++i)
    {
        for(int j=0;j<9;++j)
        {
            if (rand()%10+1<level){
            QTableWidgetItem *it=new QTableWidgetItem;
            it->setText(QString::number(arr[i][j]));
            table->setItem(i,j,it);
            } else{
            QTableWidgetItem *it=new QTableWidgetItem;
            table->setItem(i,j,it);
            }
            pravilo[i][j]=arr[i][j];

        }
    }
}
