#include <iostream>
#include <vector>

class shape{
    protected:
    int pos_x;
    int pos_y;
    shape(int x, int y): pos_x(x), pos_y(y){}
    public :
    void move(int pos_x, int pos_y)
};
class Circle : public shape{
    int radius;
};
class Rectangle : public shape{
    int h,w;
};
int main(){
    Circle c1(10)
}
