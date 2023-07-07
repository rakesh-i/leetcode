#include<iostream>
using namespace std;
#include<vector>

int part(vector<int> &a, int s, int e){
    int p = a[e];
    int i = s-1;
    for(int j=s; j<e; j++){
        if(p>a[j]){
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    i++;
    int temp = a[i];
    a[i] = a[e];
    a[e] = temp;
    return i;

}

void quick(vector<int> &a, int s, int e){
    if(s>=e){
        return;
    }
    int p = part(a, s, e);
    quick(a, s, p-1);
    quick(a, p+1, e);
}

int main()
{
    vector<int>a = {8,2,5,3,9,4,7,6,1};
    quick(a, 0, a.size()-1);
    for(int i=0; i<a.size(); i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}