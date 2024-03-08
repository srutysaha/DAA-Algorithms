// Binary Search using divide and conquer approach
#include <stdio.h>
int binary_search(int a[],int key,int beg,int end){
   if(beg>=end){
       return -1; //if element not found
   }
   else{
       int mid=(beg+end)/2; //finding the mid index
       if(key==a[mid]){ //comparing number with element at mid index
           return mid; //position of element returned
       }
       else{ //finding part of sub-array
           if(key<a[mid]){ 
               return binary_search(a,key,beg,mid);
           }
           else{
               return binary_search(a,key,mid+1,end);
           }
       }
   }
}
int main() {
    int a[]={4,25,7,65};
    int num;
    int l=sizeof(a)/sizeof(typeof(a[0])); //finding size of array
    printf("Enter number to be searched: ");
    scanf("%d",&num);
    int pos=binary_search(a,num,0,l);
    if(pos==-1){
        printf("Element not found! ");
    }
    else{
        printf("Element found! at index: %d",pos);
    }
    return 0;
}