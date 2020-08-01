#include <iostream>

using namespace std;
//创建节点类
class Node{
    public:
        int data_;
        Node* next_;
    public:
        //Node的构造函数
        Node():data_(-1),next_(nullptr){}
};

class List
{
    public:
        //构造函数
        List();
        ~List();//析构函数
        void insert(int pos,int value);//插入函数
        void print();
        void remove(int pos);

        void CreateList_h(int n);
        void CreateList_t(int n);

        void insert_h(int value);
        void insert_t(int value);

        void Delete_t();
        void Delete_h();
        void Delete_all();
        void Delete_p(int pos);
        void Delete_k(int k);
        void Delete_data(int data);
        int GetLength();
        int operator[](int i);//运算符重载

        Node* Reverse();
        Node* Reverse_r(Node* pNode);
        Node* find(int data);
        Node* cut(Node* phead_,int n);
        Node* merge(Node* l1,Node* l2);
        Node* sortList();
        Node* swapPairs(Node* phead);
        Node* reverseBetween(Node* phead, int m, int n);
        void mergeLists(List& list3,List& list4,List& list34);
    private:
        Node* head_;
        int size_;//维护一个size
};
//单链表操作类型：
//1.添加节点：
//  1.1头插：从链表头插入
//  创建链表
void List::CreateList_h(int n){
    Node* p_curr;
    Node* temp;
    p_curr = head_;
    cout<<"Plesae input "<<n<<" value in list："<<endl;
    for (int i=0;i<n;i++){
        temp = new Node();
        cin>>temp->data_;
        temp->next_ = p_curr->next_;
        p_curr->next_ = temp;
    }
}
//插值
void List::insert_h(int value){
    Node* newnode = new Node();
    newnode->data_ = value;
    Node* p_curr = head_;
    if(head_==nullptr){
        head_ = newnode;
    }
    newnode->next_ = p_curr->next_;
    p_curr->next_ = newnode;
}
//  1.2尾插：从链表尾部插入
//  创建链表
void List::CreateList_t(int n){
    Node* p_curr;
    Node* temp;
    p_curr = head_;
    cout<<"Plesae input "<<n<<" value in list："<<endl;
    for (int i=0;i<n;i++){
        temp = new Node();
        cin>>temp->data_;
        p_curr->next_=temp;
        p_curr = temp;
    }
    p_curr->next_ = nullptr;
}
//插值
void List::insert_t(int value){
    Node* p_curr = head_;
    Node* temp = nullptr;
    if(p_curr->next_==nullptr){
        cout<<"单链表为空"<<endl;
    }
    else{
        while(p_curr->next_ != nullptr)//循环到尾部的前一个
        {
            temp = p_curr;
            p_curr = p_curr->next_;
        }
        delete p_curr;
        p_curr = nullptr;
        temp->next_ = nullptr;
    }
}
//  1.3指定位置：在指定位置插入,或给定节点插入
//在pos的前一位置插入节点
void List::insert(int pos, int value){
    if (pos<0||pos>size_)
        return ;
    //创建新的节点接受数据
    Node* newnode = new Node();
    newnode->data_ = value;
    newnode->next_ = nullptr;

    //利用辅助指针找到pos前一个节点
    Node* p_curr = head_;
    for (int i=0;i<pos;i++){
        p_curr = p_curr->next_;
    }
    //现在p_curr就是pos前一个节点的指针阈
    //新节点入链表
    newnode->next_ = p_curr->next_;//连接右边
    p_curr->next_ = newnode;//连接左边
    size_ ++;
    print();
}
//2.删除节点：
//  2.1头删：删除链表头
void List::Delete_h()
{
    Node* p_curr = head_;
    if (p_curr==nullptr||p_curr->next_==nullptr){
    //判断是否为空表 ******基本组件******
        cout<<"List is empty"<<endl;
    }
    else{
        Node* temp = nullptr;
        p_curr = p_curr ->next_;
        delete p_curr;
        p_curr = nullptr;
        head_->next_=temp;
    }
}
//  2.2尾删：删除链表尾部
void List::Delete_t(){
    Node* p_curr = head_;
    Node* temp = nullptr;
    if (p_curr->next_!=nullptr){
        temp = p_curr;//将temp指向尾部的前一个节点
        p_curr = p_curr->next_;//p指向最后一个节点
    }
    delete p_curr;
    p_curr = nullptr;
    temp->next_ = nullptr;
}
//  2.3指定位置删除：给定节点位置或给定节点
void List::Delete_p(int pos){
    Node* p_curr = head_;
    int j = 0;
    while(p_curr&&j<pos-1){
        p_curr = p_curr->next_;
        j++;
    }
    if(!p_curr||j>pos-1){
        cout<<"删除位置错误"<<endl;
        return ;
    }
    else{
        Node* temp;
        temp = p_curr->next_;
        p_curr->next_=temp->next_;
        delete p_curr;
    }
}
//  2.4全部删除
void List::Delete_all(){
    Node* p_curr = head_->next_;
    Node* temp = new Node();
    while(p_curr!= nullptr ){
        temp = p_curr;
        p_curr = p_curr->next_;
        head_->next_ = p_curr;
        temp->next_ = nullptr;
        delete temp;
    }
    head_->next_ = nullptr;
}
//  2.5删除满足条件的：如值为data的所有节点
void List::Delete_data(int data){
    Node* p_curr = head_->next_;
    Node* q_curr = nullptr;
    if (p_curr==nullptr){
        return ;
    }
    if(p_curr->data_ == data){
        head_->next_ = p_curr->next_;
        delete p_curr;
    }
    else{
        while(p_curr->data_!= data&&p_curr->next_!=nullptr){
            q_curr = p_curr;
            p_curr = p_curr->next_;
        }
        if(p_curr->data_ == data){
            q_curr->next_ = p_curr->next_;
            delete p_curr;
        }
    }
}
//  2.6删除倒数第k个节点
void List::Delete_k(int k){
    Node* p_curr = head_->next_;
    Node* q_curr = head_->next_;
    int i = 1;
    while (i<=k){//为了让q指向倒数第k+1个，q->next_指向倒数第k个
        i++;
        p_curr = p_curr->next_;
    }
    while (p_curr->next_ != nullptr){
        p_curr = p_curr->next_;
        q_curr = q_curr->next_; //这时q指向倒数第k+1个，q->next_指向倒数第k个
    }
    Node* temp = q_curr->next_;
    q_curr->next_ = temp->next_;
    delete temp;
}
//3.交换节点：
//  3.1相邻节点
//  3.2不相邻节点
//4.逆序：
//  4.1整个链表逆序
Node* List::Reverse(){//迭代的方法
    if(head_==nullptr)
        return nullptr;
    Node* p_curr = head_;
    Node* retnode = nullptr;
    while(p_curr!= nullptr){
        Node* temp = p_curr->next_;//指向当前节点的下一个节点
        p_curr->next_ = retnode;//当前节点指向前一个节点
        retnode = p_curr;//前一节点指向当前节点
        p_curr = temp;//当前节点指向下一节点
    }
    return retnode;
}
Node* List::Reverse_r(Node* pNode){
    Node* p_curr = pNode;
    if(pNode->next_==nullptr){
        return pNode;
    }
    else{
        Reverse_r(pNode->next_);
        pNode->next_->next_=pNode;
        if(pNode==p_curr){
            p_curr->next_=nullptr;
        } 
    }
    return nullptr;
}
//  4.2局部逆序
//  LeetCode 92 m到n之间翻转
Node* List::reverseBetween(Node* phead, int m, int n){
    Node* dummyHead = new Node;
    Node* pre = dummyHead;
    dummyHead->next_ = phead;
    for(int i =0;i<m-1;i++)
        pre = pre->next_;
    Node* cur = pre->next_;
    for (int i=m;i<n;i++){
        Node* t= cur->next_;
        cur->next_ = t->next_;
        t->next_ = pre->next_;
        pre->next_ = t;
    }
    return dummyHead->next_;
}
//5.查找：
//  5.1查找指定值的节点
Node* List::find(int data){
    if(nullptr==head_){
        return nullptr;
    }
    Node* p_curr = head_;
    while(p_curr){
        if(p_curr->data_==data){
            return p_curr;
        }
        p_curr = p_curr->next_;
    }
    return nullptr;
}
//  5.2查找指定位置的节点
//6.其他：
//  6.1获取长度
int List::GetLength(){
    int cnt = 0;
    Node* p_curr = head_->next_;
    while(p_curr!= nullptr){
        cnt++;
        p_curr = p_curr->next_;
    }
    return cnt;
}
//  6.2遍历链表：并进行输出
//输出整个链表的值
void List::print()
{
    if(size_==0){
        cout<<"size = 0"<<endl;
        return;
    }
    //遍历
    Node* p_curr = head_->next_;
    while(p_curr != nullptr){
        cout<<p_curr->data_<<" ";
        p_curr = p_curr->next_;    
    }
    cout<<endl;
}
//  6.3创建，销毁
List::~List()
{
    while(size_!=0){
        Node* p_curr = head_;
        for (int i=0;i<(size_ -1); i++){
            p_curr = p_curr->next_;
        }
        delete p_curr -> next_;
        p_curr->next_ = nullptr;
        size_ --;
        print();
    }
    delete head_; //???
    cout<<"delete!"<<endl;
}
List::List(){
    this->head_ = new Node();//必须分配空间
    this->head_->next_ = nullptr;
    this->size_ = 0;
}
//  6.4两个链表：
//      6.4.1：合并:有序链表按值排序，无序链表的插入和连接
//  破坏了原有链表    
void List::mergeLists(List& list3,List& list4,List& list34){
    Node* p_curr3 = list3.head_->next_;
    Node* p_curr4 = list4.head_->next_;
    Node* p_curr34 = list34.head_->next_;
    int location = 0;
    while((p_curr3!=nullptr)||(p_curr4!=nullptr))
    {
        if ((p_curr3!=nullptr)&&(p_curr4!=nullptr)){
            if (p_curr3->data_<p_curr4->data_){
                list34.insert(location,p_curr3->data_);
                location++;
                list34.insert(location,p_curr4->data_);
                location++;
            }
            else{
                list34.insert(location,p_curr4->data_);
                location++;
                list34.insert(location,p_curr3->data_);
                location++;
            }
        p_curr3 = p_curr3->next_;
        p_curr4 = p_curr4->next_;
    }
    else if((p_curr3!=nullptr)&&(p_curr4==nullptr)){
        list34.insert(location,p_curr3->data_);
        location++;
        p_curr3 = p_curr3->next_;
    }
    else if((p_curr3==nullptr)&&(p_curr4!= nullptr)){
        list34.insert(location,p_curr4->data_);
        location++;
        p_curr4 = p_curr4->next_;
    }
    }
}
Node* List:: merge(Node* l1, Node* l2){
    Node* dummyHead = new Node();
    Node* p_curr = dummyHead;
    while(l1&&l2){
        if(l1->data_<l2->data_){
            p_curr->next_ = l1;
            p_curr = l1;
            l1 = l1->next_;
        }
        else{
            p_curr->next_ = l2;
            p_curr = l2;
            l2 = l2->next_;
        }
    }
    p_curr->next_ = l1 ? l1 : l2;
    return dummyHead->next_;
}
//      6.4.2：第一个公共节点
//  6.6运算符重载：如[]
int List::operator[](int i)
{
    Node* p_curr = head_;
    int cnt = 0;
    while(cnt <= i ){
        p_curr = p_curr->next_;
        cnt++;
    }
    return p_curr->data_;
}
//  6.7断链
Node* List::cut(Node* phead_,int n){
    Node* p_curr = phead_;
    while(--n&&p_curr){
        p_curr = p_curr->next_;
    }
    if (!p_curr) return nullptr;
    Node* temp = p_curr->next_;
    return temp;
}
//链表排序 LeetCode 148
Node* List::sortList(){
    Node* dummyHead = new Node();
    dummyHead->next_ = head_;
    Node* p_curr = head_;
    int length = 0;
    while(p_curr){
        ++length;
        p_curr = p_curr->next_;
    }
    for(int size = 1;size<length;size<<=1){
        Node* cur = dummyHead->next_;
        Node* tail = dummyHead;
        while(cur){
            Node* left = cur;
            Node* right = cut(left,size);
            cur = cut(right,size);
            tail->next_ = merge(left,right);
            while(tail->next_){
                tail = tail->next_;
            }
        
        }
    }
    return dummyHead->next_;
}
//两两交换链表中的节点 LeetCode 24
Node* List::swapPairs(Node* phead){
    if(phead == nullptr|| phead->next_==nullptr) return head_;
    Node* p1 = head_;
    Node* p2 = p1->next_;
    p1->next_ = swapPairs(p2->next_);
    p2->next_ = p1;
    return p2;
}
