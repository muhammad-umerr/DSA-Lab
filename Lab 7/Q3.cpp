#include <iostream>
#include <string>
using namespace std;

struct Runner{
    string name;
    double time;
};

void merge(Runner arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    Runner *L=new Runner[n1],*R=new Runner[n2];
    for(int i=0;i<n1;i++) L[i]=arr[l+i];
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i].time<=R[j].time) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
    delete[] L;
    delete[] R;
}

void mergeSort(Runner arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    Runner runners[6]={
        {"Ali",135.25},
        {"Sara",129.75},
        {"Bilal",142.10},
        {"Hira",128.50},
        {"Omar",131.00},
        {"Zara",127.90}
    };
    mergeSort(runners,0,5);
    for(int i=0;i<6;i++) cout<<runners[i].name<<" "<<runners[i].time<<endl;
    return 0;
}
