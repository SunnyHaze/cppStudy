#include <iostream>
using namespace std;

//定义链表类模板
template <class T>
class Link{
    public:
        //内嵌类模板
        struct Node{
            T data;
            Node *next;
        };
    private:
        Node *head;
        Node *tail;
        Node *prev;
    
    public:
        //内嵌链表迭代器类模板
        class LinkIterator{
            private:
                Node *itptr;
            public:
                LinkIterator(Node *p): itptr(p){}
                bool operator != (const LinkIterator &it) const{
                    return this->itptr != it.itptr;
                }
                void operator ++ (int){ //重定义链表类中迭代器的步进；
                    itptr = itptr->next;
                }
                Node operator *(){
                    return *itptr;
                }
        };

    public:
        Link(){
            head = prev = tail = NULL;
        }

        virtual ~Link(){
            int i = 0;
            while(head != NULL){
                Node *p = head;
                head = p->next;
                cout <<"正在清除第" << i << "个节点。" << endl;
                delete p;
                i++;
            }
        }

        void Append(const T &e){
            Node *p = new Node;
            p->next = NULL;
            p->data = e;
            if(head == NULL){
                head = prev = p;
                tail = p->next;
            }
            else{
                prev->next = p;
                prev = p;
                tail = p->next;
            }
        }
        Node *begin(){
            return head;
        }
        Node *end(){
            return tail;
        }
};
template<class T>
ostream &operator << (ostream &out,const typename Link<T>::Node &nd){
    out << nd.data;
    return out;
}

template <class It>
void show(It begin,It end){
    for(It it = begin; it != end;it++){
        cout << *it << " ";
    }
    cout << endl;
}

int main(){
    Link<int> a;
    for(int i = 0 ; i < 6 ; i++){
        a.Append(i);
    }
    Link<int>::LinkIterator begin(a.begin() );
    Link<int>::LinkIterator end(a.end() );
    cout << "链表元素：";
    show(begin,end);
    return 0;
}


