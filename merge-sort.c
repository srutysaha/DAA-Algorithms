// Merge sort using divide and conquer approach
#include <stdio.h>
void conquer(int a[],int beg,int mid,int end){
    int n1=mid-beg+1; //size of left sub-array
    int n2=end-mid; //size of right sub-array
    int l1[n1],l2[n2];// creating two sub-arrays
    int k,i=0,j=0;
    for(k=0;k<n1;k++){
        l1[k]=a[beg+k]; //copying left content 
    }
    for(k=0;k<n2;k++){
        l2[k]=a[mid+1+k];//copying right content
    }
    k=beg;
    //comparing elements in both sub-arrays
    while(i<n1 && j<n2){
        if(l1[i]<=l2[j]){
            a[k]=l1[i]; //adding smaller element to orig array
            k++;
            i++;
        }
        else{
            a[k]=l2[j];
            k++;
            j++;
        }
    }
    while(i<n1){
        a[k]=l1[i];
        k++;i++;
    }
    while(j<n2){
        a[k]=l2[j];
        k++;j++;
    }
}
void divide(int a[],int beg,int end){
    if(beg<end){
        int mid=(beg+end)/2;
        divide(a,beg,mid);//dividing first part
        divide(a,mid+1,end);//dividing second part
        conquer(a,beg,mid,end);
    }
}

int main() {
    int a[]={4,25,7,65};
    int l=sizeof(a)/sizeof(typeof(a[0]));//finding size of array
    printf("INITIAL ARRAY: [ ");
    for(int i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    printf("] \n");
    int beg=0;
    int end=l;
    divide(a,beg,end);
    printf("FINAL ARRAY: [ ");
    for(int i=0;i<l;i++){
        printf("%d ",a[i]);
    }
    printf("] \n");
    return 0;
}