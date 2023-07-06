#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> &a){
   for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    } 
    cout<<endl;
}

void merge(vector<int> &a, int s, int mid, int e){
    int x = mid-s+1;
    int y = e-mid;
    vector<int> one, two;
    for(int i=0;i<x; i++ ){
        one.push_back(a[s+i]);
    }
    for(int i=0; i<y; i++){
        two.push_back(a[mid+1+i]);
    }
    int i=0, j=0, k=s;
    while(i<x&&j<y){
        if(one[i]<=two[j]){
            a[k++]=one[i++];
        }
        else{
            a[k++] = two[j++];
        }
    }
    while(i<x){
        a[k++] = one[i++];
    }
    while(j<y){
        a[k++] = two[j++];
    }
    print(a);

}

void divide(vector<int> &a, int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;
    divide(a, s, mid);
    divide(a, mid+1, e);
    merge(a, s, mid, e);
}



int main()
{
    vector<int> a = {8,3,1,7,4,5,2,6};
    divide(a, 0, a.size()-1);
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}