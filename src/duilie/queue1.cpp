#include"queue1.h"
queue1::queue1(){
    count=0;
    front=new node;
    front->next=0;
    rear=front;
}
bool queue1::empty()const{ return count==0; }

error_code queue1::get_front(elementtype &x)const{
    if(empty())return underflow;
    x=front->next->data;
    return success;
}
error_code queue1::append(const elementtype x){
    node*s=new node;
    s->data=x;
    s->next=0;
    rear->next=s;
    rear=s;
    count++;
    return success;
}
int queue1::serve(){
    if(empty())return underflow;
    else {
        node*u;
        u=front->next;
        front->next=u->next;
        delete u;
        count--;
        if(front->next==0)rear=front;
        return u->data;
    }
}
queue1::~queue1(){
    while(!empty())serve();
    delete front;
}
error_code queue1::clear(){
    while(!empty())serve();
    return success;
}
