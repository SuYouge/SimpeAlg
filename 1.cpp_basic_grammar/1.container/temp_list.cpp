#include <iostream>
using namespace std;
//basic component ListNode 
class ListNode{
    public://共有变量 包含节点的数据和下一个节点
        int data_;
        ListNode* next_;
    public://ListNode的构造函数
        ListNode():data_(-1),next_(nullptr){}
};

class List{
    public:
        List();//构造函数
        ~List();//析构函数
        void print();//输出整个链表
        void CreateList_h(int n);//insert from head one by one
        void CreateList_t(int n);//insert from tail one by one
        void insert_t(int value);
        int getLength(void);
        void insert_p(int pos,int value);
        void renum_init(int value);
        ListNode* addtwolists(ListNode* l1, ListNode* l2);
        ListNode* head_p();
    private:
        ListNode* head_;
        //也可以维护一个链表长度size
        int size_;
};
//构造函数
List::List(){
    this->head_ = new ListNode();
    this->size_ = 0 ;
    cout<<"List is created"<<endl;
};
//析构函数
List::~List(){
    while(size_!=0){ 
        ListNode* p_curr = head_;
        for (int i = 0;i<(size_-1);i++){
            p_curr = p_curr->next_;
        }
        delete p_curr->next_;
        p_curr->next_ = nullptr;
        size_--;
    }
    delete head_;
    cout<<"List is destroyed"<<endl;
};
ListNode* List::head_p(){
    return head_;
}
//遍历整个链表进行输出
void List::print(){
    if(size_==0){
        cout<<"size = 0"<<endl;
        return ;
    }; 
    ListNode* p_curr = head_->next_;
    int cnt = 0;
    while(p_curr != nullptr){
        cnt++;
        if ((p_curr->next_==nullptr)||(cnt>10))
        {
            cout<<p_curr->data_;
            cout<<endl;
            return;
        }
        cout<<p_curr->data_<<" -> ";
        p_curr = p_curr->next_;
    };
    cout<<endl;        
}
//insert from head
void List::CreateList_h(int n){
    ListNode* p_curr;//make assistant pointer
    ListNode* temp;
    p_curr = head_;//only set once and keep using  p_curr->next 
    cout<<"please input "<<n<<" values in list: "<<endl;
    for (int i =0;i<n;i++){
        temp = new ListNode();//create temp node
        cin>>temp->data_;//input value of temp node
        cout<<temp->data_<<" -> ";
        temp->next_ = p_curr->next_;//insert from head node
        p_curr->next_ = temp;    
        size_++;
    }
    cout<<endl;
    //the value input first in the bottom of the list
}
//insert from tail
void List::CreateList_t(int n){
    ListNode* p_curr = head_;
    ListNode* temp;
    cout<<"Please input "<<n<<" values in list :"<<endl;
    for(int i=0;i<n;i++){
        temp = new ListNode();
        cin>>temp->data_;
        p_curr->next_ = temp;
        p_curr = temp;
        size_++;
    }
    p_curr->next_ = nullptr;
}
//insert single node
void List::insert_t(int value){
    ListNode* p_curr = head_;
    ListNode* temp = new ListNode();
    temp->data_ = value;
    temp->next_ = nullptr;
    if(p_curr->next_ == nullptr){
        cout<<" list is empty"<<endl;
    }
    else{
        while(p_curr->next_!=nullptr){
            p_curr = p_curr->next_;
        }
        p_curr->next_ = temp;
        size_++;
    }
}
int List::getLength(void){
    int cnt = 0;
    ListNode* p_curr = head_;
    while(p_curr->next_!=nullptr){
        p_curr = p_curr->next_;
        cnt+=1;
    };
    //cout<<"size of list is "<<size_<<endl;
    //cout<<"length of list is "<<cnt<<endl;
    return cnt;
}

void List::insert_p(int pos, int value){
    ListNode* p_curr = head_;
    ListNode* temp = new ListNode();
    //init temp node
    temp->data_ = value;
    temp->next_ = nullptr;
    //judge pos
    if(pos<0||pos>size_){
    cout<<"pos is wrong"<<endl;
    return;
    }
    //(pos-1) make temp pos element and origin pos will move backward
    //(pos) make temp pos+1 element
    //all other elements move backward
    for(int i=0;i<(pos-1);i++){//pos times move
       p_curr = p_curr->next_;
    }
    temp->next_ = p_curr->next_;
    p_curr->next_ = temp;
    size_++;
    cout<<"insert_p done"<<endl;
}
void List::renum_init(int value){
    //should insert from tail
    ListNode* p_curr = head_;
    while(value!=0){
        ListNode* temp = new ListNode();
        temp->data_ = value%10;
        //cout<<"value is "<<value<<endl;
        //cout<<"input data is "<<value%10<<endl;
        temp->next_ = nullptr;
        p_curr->next_ = temp;
        p_curr = p_curr->next_;
        value = value/10;
        size_++;
    }
}
ListNode* addtwolists(ListNode* l1,ListNode* l2){
    int len1 = 0;
    int len2 = 0;
    ListNode* p1 = l1;
    ListNode* p2 = l2;
    while(p1->next_!=nullptr){
        len1++;
        p1 = p1->next_;
    }
    cout<<"l1 length is "<<len1<<endl;
    while(p2->next_!=nullptr){
        len2++;
        p2 = p2->next_;
    }
    cout<<"l2 length is "<<len2<<endl;
    if(len1>len2){
        cout<<"l1 is longer"<<endl;
        for(int i =0; i<(len1-len2);i++){
            ListNode* temp1 = new ListNode();
            temp1->data_ = 0;
            temp1->next_ = nullptr;
            temp1->next_ = p2->next_;
            p2->next_ = temp1;
            p2 = p2->next_;
            //cout<<" -> ";
        }
        //p2->next_ =nullptr;
    }else{
        cout<<"l2 is longer"<<endl;
        for(int i =0;i<(len2-len1);i++){
            ListNode* temp2 = new ListNode();
            temp2->data_ = 0;
            temp2->next_ = nullptr;
            temp2->next_ = p1->next_;
            p1->next_ = temp2;
            p1 = p1->next_;       
            //cout<<" -> ";
        }
        //p1->next_ = nullptr;
    
    }
    return l1;
}
int main(){
    List l1;
    l1.renum_init(1);
    l1.print();
    List l2;
    l2.renum_init(5236);
    l2.print();
    ListNode* sum = addtwolists(l1.head_p(),l2.head_p());
    l1.print();
    l2.print();
    /*
    List l1;
    l1.CreateList_h(5);
    l1.print();
    List l2;
    l2.CreateList_t(4);
    l2.print();
    l2.insert_t(10);
    l2.print();
    l2.insert_p(5,99);
    l2.print();
    cout<<"len of l2 is "<<l2.getLength()<<endl;
    */
}
