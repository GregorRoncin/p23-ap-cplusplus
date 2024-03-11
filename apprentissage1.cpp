#include <iostream>
int i=12;
class DataFrame{int heigth=0;int width=0;};
int main(){
    int j=10;
    {int j = 21;}
    DataFrame df;
    std::cout<<i<<' '<<j<<' '<<sizeof(j)<<std::endl;
}