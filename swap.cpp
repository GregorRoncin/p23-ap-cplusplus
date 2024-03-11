#include <iostream>
void swap

int main(){
    int a =14;
    int b =82;
    swap(&a,&b);
    std::cout<<'a'<<' '<<'b'<<std::endl;
}

void swap(int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
    }