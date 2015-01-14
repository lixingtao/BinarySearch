#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
�����ڻ�������
Ҫ��֤s��t������d�Ĵ�С
��d�в���x������x���±꣬���������x����-1

d Ҫ��d�в�������,d�����ݰ��մ�С��������
x Ҫ���ҵ�����
s ���±�s����ʼ����
t ���ҵ�λ��t
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
�����ڻ�������
Ҫ��֤s��t������d�Ĵ�С
��d�в���x��������ڶ��x���������x���±꣬���������x����-1

d Ҫ��d�в�������,d�����ݰ��մ�С��������
x Ҫ���ҵ�����
s ���±�s����ʼ����
t ���ҵ�λ��t
*/
template<class T> int binarySearchL(T d[],const T &x,int s,int t){
    int l=s;
    int r=t;
    while(l<r){
        int m=(l+r)>>1;
        if(x<=d[m])r=m;     //d[r]�κ�ʱ�� ���ڵ���x
        else l=m+1;
    }
    if(d[l]==x)return l;
    return -1;
}

/*
�����ڻ�������
Ҫ��֤s��t������d�Ĵ�С
��d�в���x��������ڶ��x�������ұ�x���±꣬���������x����-1

d Ҫ��d�в�������,d�����ݰ��մ�С��������
x Ҫ���ҵ�����
s ���±�s����ʼ����
t ���ҵ�λ��t
*/
template<class T> int binarySearchR(T d[],const T &x,int s,int t){
    int l=s;
    int r=t;
    while(l<r){
        int m=(l+r+1)>>1;
        if(d[m]<=x)l=m;     // d[l]�κ�ʱ�� С�ڵ���x
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
