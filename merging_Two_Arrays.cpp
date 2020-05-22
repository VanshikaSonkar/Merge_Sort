#include <iostream>
using namespace std;
int nextGap(int gap) 
{ 
    if (gap <= 1) 
        return 0; 
    return (gap / 2) + (gap % 2); 
} 
void mergeSort(int a[], int b[], int m, int n){
    int i,j,temp,gap=m+n;
    for(gap= nextGap(gap); gap>0; gap=nextGap(gap) ){
        for(i=0; i+gap<m; i++){
            if(a[i]> a[i+gap]){
                temp= a[i];
                a[i]= a[i+gap];
                a[i+gap]= temp;
            }
        }
        for(j= gap>m? gap-m:0; j<n && i<m; i++, j++){
            if(a[i]> b[j]){
                temp= a[i];
                a[i]= b[j];
                b[j]= temp;
            }
        }
        if(j<n){
            for(i=0; i+gap<n; i++){
            if(b[i]> b[i+gap]){
                temp= b[i];
                b[i]= b[i+gap];
                b[i+gap]= temp;
                }
            }
        }
        
    }
    for (int i = 0; i < m; i++) 
        printf("%d ", a[i]); 
  
    for (int i = 0; i < n; i++) 
        printf("%d ", b[i]); 
    printf("\n"); 
}
int main() {
	int t,m,n,i;
	cin>>t;
	while(t--){
	    cin>>m>>n;
	    int a[m];
	    int b[n];
	    for(i=0; i<m; i++){
	        cin>>a[i];
	    }
	    for(i=0; i<n; i++){
	        cin>>b[i];
	    }
	    mergeSort(a, b, m, n);
	}
	return 0;
}
