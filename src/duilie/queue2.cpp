#include"queue2.h"
queue2::queue2(){
    count=0;
    front=0;
    rear=0;
}
bool queue2::empty()const{ return count==0; }
bool queue2::full()const{
    if(count==maxlen-1)return true;
    return false;
}
error_code queue2::get_front(elementtype &x)const{
    if(empty())return underflow;
    else x=data[(front+1)%maxlen];
    return success;
}
error_code queue2::append(const elementtype x){
    if(full())return overflow;
    else {
        rear=(rear+1)%maxlen;
        data[rear]=x;
        count++;
        return success;
    }
}
int queue2::serve(){
    if(empty())return underflow;
    else{
        front=(front+1)%maxlen;
        count--;
        return data[front];
    }
}

error_code queue2::clear()
{
    while(!empty())serve();
    return success;
}
