#include <iostream>
char c;
int main(){
    do {std::cout<<"entrez un char ";std::cin>>c;
    std::cout<<c<<'/n';}
    while (c!='q');
}