#ifndef QUEUE1_H
#define QUEUE1_H
#include<iostream>
#include"queue2.h"
using namespace std;
typedef int elementtype;

struct node{
    elementtype data;
    node*next;
};

class queue1{
public:
    queue1();
    ~queue1();
    bool empty()const;
    error_code get_front(elementtype &x)const;
    error_code append(const elementtype x);
    error_code clear();
    int serve();
private:
    int count;
    node*front,*rear;
friend class MainWindow;
};



#endif // QUEUE1_H

