#include<iostream>
#include<algorithm>
using namespace std;

int find2MAXNaive(int *a,int n){
    sort(a,a+n);
    return a[n-2];
}

//the correct one
int find2MAXFast(int *a,int n){
    int k, max1, max2;
    max1 = max2 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max1 < a[i]){
            max1 = a[i];
            k = i;
        }
    }
    for(int i = 0; i < n; i++){
        if(max2 < a[i] && k != i){
            max2 = a[i];
        }
    }
    return max2;
}

//The wrong one
/*int find2MAXFast(int *a,int n){
    int k, max1, max2;
    max1 = max2 = INT_MIN;
    for(int i = 0; i < n; i++){
        if(max1 < a[i]){
            max1 = a[i];
        }
    }
    for(int i = 0; i < n; i++){
        if(max2 < a[i] && a[i] != max1){
            max2 = a[i];
        }
    }
    return max2;
}*/

int main()
{
    int n,*a,i,c,ans1,ans2;
    //stress test
    c=1;
    while(1){
        n = rand()%9 + 2; // n = [2,10]
        a = new int[n];
        for(i = 0; i < n; i++){
            a[i] = rand()%100 + 1;// a[i] = [1,100]
        }

        // Now my random test data is ready

        if((ans1=find2MAXNaive(a,n)) == (ans2=find2MAXFast(a,n))){
            cout<<"Test "<<c++<<": OK\n";
        }
        else {
            cout<<"Error Found!\n";
            cout<<"Result from naive solution: "<<ans1<<"\n";
            cout<<"Result from fast solution: "<<ans2<<"\n";
            cout<<"Test data:";
            for(i = 0; i < n; i++){
                cout<<" "<<a[i];
            }
            cout<<"\n";
            break;
        }
    }

    return 0;
}
