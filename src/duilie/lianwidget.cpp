#include "lianwidget.h"
#include "ui_lianwidget.h"
#include"queue1.h"
#include<QHBoxLayout>
#include<QPainter>
#include<QScrollArea>
lianwidget::lianwidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lianwidget)
{
    ui->setupUi(this);
    setWindowTitle(QString("链队列界面"));
    connect(&a,&QPushButton::clicked,this,&lianwidget::on_pushButton_clicked);
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

lianwidget::~lianwidget()
{
    delete ui;
}

void lianwidget::on_pushButton_clicked()
{
    emit mySignal();
}

void lianwidget::addWidget(QString s)
{

    label2= new QLabel();
    QPixmap pixmap(":/new/prefix1/image/12.png");
    pixmap = pixmap.scaled(120, 120, Qt::IgnoreAspectRatio);  // 图片缩放
    label2->setPixmap(pixmap);
    pHlayout->insertWidget(pHlayout->count()-1, label2);
    label= new QLabel();
    QPixmap pixmap2(":/new/prefix1/image/11.png");
    pixmap2 = pixmap2.scaled(120, 70, Qt::IgnoreAspectRatio);// 图片缩放
    QPainter painter1;
    painter1.begin(&pixmap2);
    painter1.setPen(Qt::blue);
    painter1.drawText(20,20,100,20, Qt::AlignBottom, s);    //这里要确保你的坐标等等参数正确，不然你就不知道画到哪里去了
    painter1.end();
    label->setPixmap(pixmap2);
    pHlayout->insertWidget(pHlayout->count()-1, label);
}

void lianwidget::newwidget()
{
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
