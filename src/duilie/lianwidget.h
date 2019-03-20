#ifndef LIANWIDGET_H
#define LIANWIDGET_H
#include<QPushButton>
#include<QHBoxLayout>
#include<QScrollArea>
#include<QString>
#include<QLabel>
#include <QWidget>
namespace Ui {
class lianwidget;
}

class lianwidget : public QWidget
{
    Q_OBJECT

public:
    explicit lianwidget(QWidget *parent = 0);
    ~lianwidget();
    void addWidget(QString);
    void newwidget();

private slots:
    void on_pushButton_clicked();
signals:
    void mySignal();

private:
    Ui::lianwidget *ui;
    QLabel *label;
    QLabel *label2;
    QPushButton a;
    QWidget *pWidget;
    QScrollArea *pArea;
    //QPushButton *pAddButton;
    QHBoxLayout *pHlayout;
friend class MainWindow;
};

#endif // LIANWIDGET_H
