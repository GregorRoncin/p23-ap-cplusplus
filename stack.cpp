#include <iostream>

struct stack{
   int nb;
   int size;
   char *tab;
   stack (int n): nb(n), size(n){
    if (size=0){
        throw "STOP";
    }
      tab = new char[n];
   };
   ~stack(){
      delete[] tab;
   };
    int top(stack s){
      if (nb = 0){return 'EMPTY'}
      else{
        return s[nb]
    }}
    void push(stack s, int n){
      if (nb = size){return "FULL"}
      else{s.nb=s.nb+1;
        s[s.nb]=n;
      }}
    char pop(stack s){
        return s[s.nb];
    }
    bool is_empty(stack s){
        if (s.nb = 0){return true }
        else{return false}
    }
    bool is_full(stack s){
        if (s.nb = size){return true}
        else{return false}
    }
    void print(stack s){
      for (int i=0; i<s.nb; i++){
        std::cout << s[i] << " ";
      }
    }
   }
