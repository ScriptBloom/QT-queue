#include "orderwidget.h"
#include "ui_orderwidget.h"
#include"queue2.h"
#include<QHBoxLayout>
#include<QPainter>
#include<QScrollArea>
cirwidget::cirwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::cirwidget)
{
    ui->setupUi(this);
    connect(&b,&QPushButton::clicked,this,&cirwidget::on_pushButton_clicked);
    setWindowTitle(QString("顺序队列界面"));
    pArea = new QScrollArea();
    resize(700,400);
    pWidget = new QWidget();
    pWidget->setStyleSheet("QWidget""{background:white;}");
    pHlayout = new QHBoxLayout();
    pHlayout->addSpacerItem(new QSpacerItem(100, 30, QSizePolicy::Expanding, QSizePolicy::Expanding));
    pWidget->setLayout(pHlayout);
    pArea->setWidget(pWidget);
    pArea->setWidgetResizable(true);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(pArea);
    mainLayout->addWidget(ui->pushButton);
    this->setLayout(mainLayout);
}






void cirwidget::addWidget(QString s)
{
    label= new QLabel();
    QPixmap pixmap2(":/new/prefix1/image/2.png");
    pixmap2 = pixmap2.scaled(120, 70, Qt::IgnoreAspectRatio);
    QPainter painter1;
    painter1.begin(&pixmap2);
    painter1.setPen(Qt::red);
    painter1.drawText(20,20,100,20, Qt::AlignBottom, s);    //这里要确保你的坐标等等参数正确，不然你就不知道画到哪里去了
    painter1.end();
    label->setPixmap(pixmap2);
    pHlayout->insertWidget(pHlayout->count()-1, label);
}

void cirwidget::newwidget()
{
    pWidget = new QWidget();
    pWidget->setStyleSheet("QWidget" "{background:white;}");
    pHlayout = new QHBoxLayout();
    pHlayout->addSpacerItem(new QSpacerItem(100, 30, QSizePolicy::Expanding, QSizePolicy::Expanding));
    pWidget->setLayout(pHlayout);
    pArea->setWidget(pWidget);
    pArea->setWidgetResizable(true);
    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(pArea);
    mainLayout->addWidget(ui->pushButton);
    this->setLayout(mainLayout);
}

cirwidget::~cirwidget()
{
    delete ui;
}

void cirwidget::on_pushButton_clicked()
{
    emit mySignals();
}
