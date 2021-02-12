#include <iostream>
#include "sclass4_11_node.cpp"
int CNode::sNodeNum = 0;

int main(){
    cout << "1*******************************************."<<endl;
    {
        CNodeArray array;
        {
            int i;
            char s[81];
            string str;
            CNode oCN1("Zhang San"),oCN2("Li Si");
            oCN2 = oCN1;
            CNode *poCN1,*poCN2;
            for(i = 0 ; i < 5 ; i++){
                cout << "Input a Node Name or word \"stop\":";
                cin.getline(s,81,'\n');
                str = s;
                if(str == "stop"){
                    cout << endl;
                    break;
                }
                poCN1 = new CNode(str);
                poCN2 = new CNode(*poCN1);
                array.Insert(*poCN1);
                array.Insert(*poCN2);
            }
            CNode temp = array[0];
            cout << temp <<"!!!!!"<< endl;
            CNode dick(oCN1);
            dick = array[1];
            free(poCN1);
            free(poCN2);
            // cout << array[1];
        }

    }
}