#include <iostream>
int n;
char c;
int main(){
    std::cout<<"entrez taille tableau";std::cin>>n;
    char tab[n];
    for (int i =0; i<n;i++){
        std::cout<<"entrez l'elt ";std::cin>>c;
        tab[i]=c;
    }
    std::cout<<tab<<std::endl; 
}