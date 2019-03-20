#ifndef CIRWIDGET_H
#define CIRWIDGET_H

#include <QWidget>
#include<QPainter>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QString>
#include<QLabel>
#include <QWidget>
#include<QPushButton>
namespace Ui {
class cirwidget;
}

class cirwidget : public QWidget
{
    Q_OBJECT

public:
    explicit cirwidget(QWidget *parent = 0);
    ~cirwidget();
    void addWidget(QString);
    void newwidget();
signals:
    void mySignals();
private slots:
    void on_pushButton_clicked();

private:
    Ui::cirwidget *ui;
    QPushButton b;
    QLabel *label;
    QWidget *pWidget;
    QScrollArea *pArea;
    //QPushButton *pAddButton;
    QHBoxLayout *pHlayout;
friend class MainWindow;
};

#endif // CIRWIDGET_H
