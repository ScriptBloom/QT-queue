#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"lianwidget.h"
#include"orderwidget.h"
#include"queue1.h"
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>      //打开或保存文件对话框
#include <QFile>
#include<QLabel>
#include<QString>
#include <QLayoutItem>
#include<QHBoxLayout>
#include<QPainter>
#include<QPen>
#include<QPushButton>
#include <QStringList>//文件类
#include <QTextStream>      //文本流输入输出
#include <QListWidgetItem>
#include <QWebView>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(QString("主界面"));
    void (lianwidget::*meiyouc)()=&lianwidget::mySignal;
    connect(&w,meiyouc,this,&MainWindow::deals);
    void (cirwidget::*meic)()=&cirwidget::mySignals;
    connect(&h,meic,this,&MainWindow::deals2);
    ui->label_8->setText("<h1><a href=\"http://baike.so.com/doc/26301156-27538957.html\">顺序队列-百科</a></h1>");
    ui->label_8->setOpenExternalLinks(true);
    ui->label_3->setText("<h1><a href=\"https://www.cnblogs.com/muzijie/p/5655228.html\">链队列-博客</a></h1>");
    ui->label_3->setOpenExternalLinks(true);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(
                this,
                tr("打开文件"),
                tr("."),
                tr("Text Files(*.txt);;All files(*)")
                );
    //判断文件名
    if( strFile.isEmpty() )
    {
        return;
    }
    //有文件名，定义文件对象并打开
    QFile file(strFile);
    if( ! file.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, tr("打开文件"),
                             tr("打开文件失败：") + file.errorString());
        return;
    }
    ui->listWidget->clear();
    QTextStream stream(&file);
    QString line;
    while(!stream.atEnd())
    {
        line=stream.readLine();

        ui->listWidget->addItem(line);
    }
    file.close();
    //提示加载完毕
    QMessageBox::information(this, tr("加载数据"), tr("加载数据完毕。"));
}


void MainWindow::on_pushButton_3_clicked()
{
    QFile file("D:/Qtcode/duilie/write.txt");
    if(Queue1.empty())
    {
        QMessageBox::warning(this, tr("出队"), tr("请先确认有数据再出队！"));
        return;
    }
    else
    {
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            QString line;

            QStringList lines;
            while(!stream.atEnd())
            {
                line=stream.readLine();
                lines<<line;

            }
            file.resize(0);
        //开始写入文本
            for ( QStringList::Iterator it=lines.begin()+1;it!=lines.end();++it )
            {stream<<*it<<"\r\n";}//注意是"\r\n"！！！！！！如果是单个"\n"  保存文本的时候它不保留换行符！！！！

        }
        file.close();
        if (!Queue1.empty()) delete w.pWidget;
        w.newwidget();
        qDebug()<<Queue1.serve()<<"出队成功！";
        node *s=Queue1.front->next;
        while(s!=0)
        {
            w.addWidget(QString::number(s->data));
            s=s->next;
        }

    }

}

void MainWindow::on_pushButton_4_clicked()
{
    QFile file("D:/Qtcode/duilie/write.txt");

    bool isOk=file.open(QIODevice::Append);
    if(isOk==true)
    {
        QString a=ui->lineEdit->text().trimmed();
        if(a.isEmpty())
        {
            QMessageBox::warning(this, tr("入队"), tr("请先填好数据再入队！"));
            return;
        }
        ui->listWidget->addItem(a);
        int b; b=a.toInt();
        Queue1.append(b);
        file.write(a.toUtf8());
        file.write("\r\n");
        w.addWidget(a);
        qDebug()<<b<<"入队成功！";
    }
    file.close();

}

void MainWindow::on_pushButton_2_clicked()
{
    QStringList lines;
    QString line;
    QFile file("D:/Qtcode/duilie/write.txt");//打开该文件进入编辑模式
    int row=0;
    if(ui->listWidget->count()==0)
    {
        QMessageBox::warning(this, tr("没有数据"), tr("请输入数据再入队保存！"));
    }
    else
    {
        if(file.open(QIODevice::WriteOnly))//如果被打开
        {
            file.resize("D:/Qtcode/duilie/write.txt",0);//清空内容
            Queue1.clear();
            while(row<(ui->listWidget->count()))//从wistlidget里一行一行的读取文本并存入lines里边
            {line=ui->listWidget->item(row)->text();
                int b=line.toInt();
                Queue1.append(b);
                w.addWidget(line);
                qDebug()<<b<<"入队成功！";
                row++;
                lines<<line;

            }
            QTextStream stream( &file );//开始写入文本
            for ( QStringList::Iterator it=lines.begin();it!=lines.end();++it )
            stream<<*it<<"\r\n";//注意是"\r\n"！！！！！！如果是单个"\n"  保存文本的时候它不保留换行符！！！！
            file.close();
         QMessageBox::information(this, tr("数据入队"), tr("全部入队成功。"));
        }
    }
}

void MainWindow::on_pushButton_5_clicked()
{
    Queue1.clear();
    QFile file("D:/Qtcode/duilie/write.txt");
    file.resize(0);
    ui->listWidget->clear();
    QMessageBox::information(this, tr("清空数据和队列"), tr("清空成功，队列为空，文件为空。"));
    qDebug()<<"全部数据已出队";
    delete w.pWidget;
    w.newwidget();

}


void MainWindow::on_pushButton_6_clicked()
{
    w.show();
    this->hide();

}

void MainWindow::deals()
{
    this->show();
    w.hide();
}

void MainWindow::deals2()
{
    this->show();
    h.hide();
}


void MainWindow::on_pushButton_8_clicked()
{
    QString strFile = QFileDialog::getOpenFileName(
                this,
                tr("打开文件"),
                tr("."),
                tr("Text Files(*.txt);;All files(*)")
                );
    //判断文件名
    if( strFile.isEmpty() )
    {
        return;
    }
    //有文件名，定义文件对象并打开
    QFile file(strFile);
    if( ! file.open(QIODevice::ReadOnly) )
    {
        QMessageBox::warning(this, tr("打开文件"),
                             tr("打开文件失败：") + file.errorString());
        return;
    }
    ui->listWidget_2->clear();
    QTextStream stream(&file);
    QString line;
    while(!stream.atEnd())
    {
        line=stream.readLine();

        ui->listWidget_2->addItem(line);
    }
    file.close();
    //提示加载完毕
    QMessageBox::information(this, tr("加载数据"), tr("加载数据完毕。"));
}

void MainWindow::on_pushButton_9_clicked()
{
    QStringList lines;
    QString line;
    QFile file("D:/Qtcode/duilie/write2.txt");//打开该文件进入编辑模式
    int row=0;
    if(ui->listWidget_2->count()==0)
    {
        QMessageBox::warning(this, tr("没有数据"), tr("请输入数据再入队保存！"));
    }
    else
    {
        if(file.open(QIODevice::WriteOnly))//如果被打开
        {
            file.resize("D:/Qtcode/duilie/write2.txt",0);//清空内容
            Queue2.clear();
            while(row<(ui->listWidget_2->count()))//从wistlidget里一行一行的读取文本并存入lines里边
            {
                line=ui->listWidget_2->item(row)->text();
                int b=line.toInt();
                Queue2.append(b);
                h.addWidget(line);
                qDebug()<<b<<"入队成功！";
                row++;
                lines<<line;
            }
            QTextStream stream( &file );//开始写入文本
            for ( QStringList::Iterator it=lines.begin();it!=lines.end();++it )
            stream<<*it<<"\r\n";//注意是"\r\n"！！！！！！如果是单个"\n"  保存文本的时候它不保留换行符！！！！
            file.close();
         QMessageBox::information(this, tr("数据入队"), tr("全部入队成功。"));
        }
    }
}

void MainWindow::on_pushButton_10_clicked()
{
    Queue2.clear();
    QFile file("D:/Qtcode/duilie/write2.txt");
    file.resize(0);
    ui->listWidget_2->clear();
    QMessageBox::information(this, tr("清空数据和队列"), tr("清空成功，队列为空，文件为空。"));
    qDebug()<<"全部数据已出队";
    delete h.pWidget;
    h.newwidget();

}

void MainWindow::on_pushButton_11_clicked()
{
    QFile file("D:/Qtcode/duilie/write2.txt");
    bool isOk=file.open(QIODevice::Append);
    if(isOk==true)
    {
        QString a=ui->lineEdit_2->text().trimmed();
        if(a.isEmpty())
        {
            QMessageBox::warning(this, tr("入队"), tr("请先填好数据再入队！"));
            return;
        }
        ui->listWidget_2->addItem(a);
        int b; b=a.toInt();
        Queue2.append(b);
        h.addWidget(a);
        file.write(a.toUtf8());
        file.write("\r\n");
        qDebug()<<b<<"入队成功！";
    }
    file.close();
}

void MainWindow::on_pushButton_12_clicked()
{
    QFile file("D:/Qtcode/duilie/write2.txt");
    if(Queue2.empty())
    {
        QMessageBox::warning(this, tr("出队"), tr("请先确认有数据再出队！"));
        return;
    }
    else
    {
        if(file.open(QIODevice::ReadWrite))
        {
            QTextStream stream(&file);
            QString line;
            QStringList lines;
            while(!stream.atEnd())
            {
                line=stream.readLine();
                lines<<line;

            }
            file.resize(0);
        //开始写入文本
            for ( QStringList::Iterator it=lines.begin()+1;it!=lines.end();++it )
            {stream<<*it<<"\r\n";}//注意是"\r\n"！！！！！！如果是单个"\n"  保存文本的时候它不保留换行符！！！！

        }
        file.close();
        if (!Queue2.empty()) delete h.pWidget;
        h.newwidget();
        qDebug()<<Queue2.serve()<<"出队成功！";
        for(int i=Queue2.front+1;i<Queue2.rear+1;i++)
        {
            h.addWidget(QString::number(Queue2.data[i]));
        }
    }
}

void MainWindow::on_pushButton_13_clicked()
{
    h.show();
    this->hide();
}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_16_clicked()
{
    ui->listWidget->clear();
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->listWidget_2->clear();
}
