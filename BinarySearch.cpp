#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
适用于基本类型
要保证s，t不超出d的大小
在d中查找x，返回x的下标，如果不存在x返回-1

d 要从d中查找数据,d中数据按照从小到大排序
x 要查找的数字
s 从下标s处开始查找
t 查找到位置t
*/
template<class T> int binarySearch(T d[],const T &x,int s,int t){
    int l=s;
    int r=t;
    while(l<r){
        int m=(l+r)>>1;
        if(d[m]==x)return m;
        if(d[m]<x)l=m+1;
        else r=m;
    }
    return -1;
}

/*
适用于基本类型
要保证s，t不超出d的大小
在d中查找x，如果存在多个x返回最左边x的下标，如果不存在x返回-1

d 要从d中查找数据,d中数据按照从小到大排序
x 要查找的数字
s 从下标s处开始查找
t 查找到位置t
*/
template<class T> int binarySearchL(T d[],const T &x,int s,int t){
    int l=s;
    int r=t;
    while(l<r){
        int m=(l+r)>>1;
        if(x<=d[m])r=m;     //d[r]任何时候都 大于等于x
        else l=m+1;
    }
    if(d[l]==x)return l;
    return -1;
}

/*
适用于基本类型
要保证s，t不超出d的大小
在d中查找x，如果存在多个x返回最右边x的下标，如果不存在x返回-1

d 要从d中查找数据,d中数据按照从小到大排序
x 要查找的数字
s 从下标s处开始查找
t 查找到位置t
*/
template<class T> int binarySearchR(T d[],const T &x,int s,int t){
    int l=s;
    int r=t;
    while(l<r){
        int m=(l+r+1)>>1;
        if(d[m]<=x)l=m;     // d[l]任何时候都 小于等于x
        else r=m-1;
    }
    if(d[l]==x)return l;
    return -1;
}

int main(){
    int a[]={1,3,3,3,3,7,7,7,15,17};
    for(int i=0;i<10;i++)cout<<a[i]<<"\t";
    cout<<endl;
    int x;
    while(cin>>x)cout<<binarySearchL(a,x,0,9)+1<<endl;
    return 0;
}
