#pragma once
#include <iostream>
template <typename T>
struct Node {
    T data;
    Node *pNext;
};
template <typename T>
class NodeList {
private:
    //头节点
    Node<T> *first;
    //当前数据长度
    int length;
    //比较函数
    int(*compare)(T& left, T& right);
public:
    //初始化
    NodeList();
    //拷贝构造函数
    NodeList(const NodeList<T>&);
    //销毁
    ~NodeList();
    //插入，插入时是否排序
    NodeList& Insert(int x, const T &value, const bool sort = false);
    //是否为空
    bool IsEmpty() const;
    //获取长度
    int GetLength() const;
    //返回第x个元素
    bool Find(int x, T &ret) const;
    //搜索，并返回索引
    int Search(const T& value) const;
    //删除第x个数据
    NodeList& Delete(const int x);
    //打印表
    std::ostream& Print(std::ostream& out) const;
    //排序
    NodeList& Sort();
    //链表合并
    NodeList& AddNodeList(const NodeList& Source, const bool sort = false);
    //设置比较函数
    void SetCompareFunction(int(*function)(T& left, T&right));
};
