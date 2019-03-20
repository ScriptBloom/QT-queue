#ifndef QUEUE2_H
#define QUEUE2_H

#include<iostream>
using namespace std;
typedef int elementtype;
const int maxlen=100;

enum error_code{
    underflow=-1,
    overflow=0,
    success=1
};

class queue2{
public:
    queue2();
    bool empty()const;
    bool full()const;
    error_code get_front(elementtype &x)const;
    error_code append(const elementtype x);
    int serve();
    error_code clear();
private:
    int count,front,rear;
    elementtype data[maxlen];
friend class MainWindow;
};
#endif // QUEUE2_H

