#include<iostream>
#include<cstring>
using std::cout;
using std::endl;
using std::cin;
int main(){
    std::string nishabi = "nvrendazhutizi";
    const char *word = nishabi.c_str();
    std::cout << word;
    size_t colCnt = 0;
    int a[5][6];
    for(auto &row : a){
        for(auto &col : row){
            col = colCnt;
            colCnt++;
        }
    }
    for(auto &row : a){
        for(auto col : row){
            std::cout << col <<std::endl;
        }
    }
    size_t cnt = 0;
    int ia[3][4];
    for(auto &row : ia){
        for(auto &col : row){
            col = ++cnt;
        }
    }
    int (*p)[4] = ia;
    p = &ia[0]; 
    std::cout << **p;
    for(auto p1 = ia; p1 != ia + 3; ++p1){
        for(auto q = *p1; q != *p1 + 4; ++q){
            cout << *q << ' ';
        }
        cout << endl;
    }
    for(auto p1 = std::begin(ia); p1 != std::end(ia); p1++){
        for(auto q = std::begin(*p1) ; q != std::end(*p1); q++){
            cout << *q << ' ';
        }
        cout << endl;
    }
//    typedef int int_array[4];
    using int_array = int[4];
    for(int_array *p2 = ia; p2 != ia + 3 ; p2++){
        for(int *q = *p2 ; q != *p2 + 4 ; q++){
            cout << *q << " ";
        }
        cout << endl <<"!!!";
    }

}
