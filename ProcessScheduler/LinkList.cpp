#include "LinkList.h"
//初始化
template<typename T>
NodeList<T>::NodeList() {
    first = new Node<T>;
    first->pNext = nullptr;
    length = 0;
    compare = nullptr;
}

//拷贝构造函数
template<typename T>
NodeList<T>::NodeList(const NodeList<T>& nodelist) {
    first = new Node<T>;
    first->pNext = nullptr;
    length = 0;
    compare = nullptr;
    AddNodeList(nodelist);
}

//销毁
template<typename T>
NodeList<T>::~NodeList() {
    while(first != nullptr) {
        Node<T> *p = first;
        first = first->pNext;
        //cout<<p<<endl;
        delete p;
        length--;
    }
}

//插入，插入时是否排序
template<typename T>
NodeList<T>& NodeList<T>::Insert(int x, const T& value, const bool sort) {
    if(x < 0 || x > length) {
        x = length;
    }
    Node<T> *p = first;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    Node<T> *newp = new Node<T>;
    newp->data = value;
    newp->pNext = p->pNext;
    p->pNext = newp;
    length++;
    if(sort) {
        Sort();
    }
    return *this;
}

//是否为空
template<typename T>
bool NodeList<T>::IsEmpty() const {
    return length == 0 || first->pNext == nullptr;
}

//获取长度
template<typename T>
int NodeList<T>::GetLength() const {
    return length;
}

//返回第x个元素
template<typename T>
bool NodeList<T>::Find(int x, T& ret) const {
    if(x < 0 || x > length - 1) {
        return false;
    }
    Node<T> *p = first->pNext;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    ret = p->data;
    return true;
}

//搜索，并返回索引
template<typename T>
int NodeList<T>::Search(const T& value) const {
    Node<T> *p = first->pNext;
    for(int i = 0; i < length && p != nullptr; i++, p = p->pNext) {
        if(compare(p->data, value) == 0) {
            return i;
        }
    }
    return -1;
}

//删除第x个数据
template<typename T>
NodeList<T>& NodeList<T>::Delete(const int x) {
    if(x < 0 || x > length - 1) {
        return *this;
    }
    Node<T> *p = first;
    for(int i = 0; i < x; i++) {
        p = p->pNext;
    }
    Node<T> *temp = p->pNext;
    p->pNext = temp == nullptr ? nullptr : temp->pNext;
    delete temp;
    length--;
    return *this;
}

//打印表
template<typename T>
std::ostream& NodeList<T>::Print(std::ostream& out) const {
    Node<T> *p = first->pNext;
    for(int i = 0; i < length && p != nullptr; i++, p = p->pNext) {
        out << p->data << '\n';
    }
    return out;
}

//排序
template<typename T>
NodeList<T>& NodeList<T>::Sort() {
    Node<T> *p = first->pNext;
    bool finish = false;
    for(int i = 0; i < length - 1; i++) {
        finish = true;
        Node<T> *temp = p;
        for(int j = 0; j < length - 1 - i; j++) {
            if(compare(temp->data, temp->pNext->data) > 0) {
                T ii;
                ii = temp->data;
                temp->data = temp->pNext->data;
                temp->pNext->data = ii;
                finish = false;
            }
            temp = temp->pNext;
        }
        if(finish) {
            break;
        }
    }
    return *this;
}

//链表合并
template<typename T>
NodeList<T>& NodeList<T>::AddNodeList(const NodeList& Source, const bool sort) {
    T value;
    for(int i = 0; i < Source.length; i++) {
        Source.Find(i, value);
        this->Insert(this->length, value, false);
    }
    if(sort) {
        this->Sort();
    }
    return *this;
}

//设置比较函数
template<typename T>
void NodeList<T>::SetCompareFunction(int(*function)(T& left, T& right)) {
    compare = function;
}
