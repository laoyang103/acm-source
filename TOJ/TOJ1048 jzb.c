#include<iostream>
using namespace std;
int comp( const void * p, const void * q) ;
int main(){
	int zushu;
	int shuzudaxiao;
	int arr[100];
	int t,i,j,k;
	int count=1,max=1;
//	cout<<"input zhushu:"<<endl;
	cin>>zushu;
	for(i=0;i<zushu;i++){
//		cout<<"input shuzudaxiao"<<endl;	
		cin>>shuzudaxiao;
		for(j=0;j<shuzudaxiao;j++){
		cout<<"input a em"<<endl;
		cin>>t;
		arr[j]=t;
//		cout<<arr[j]<<endl;
		}
		qsort(arr,shuzudaxiao,sizeof(int),comp);
		for(k=0;k<shuzudaxiao-1;k++){
//			cout<<arr[k];
			if(arr[k]==arr[k+1]){
				count+=1;
				if(max<count){
					max=count;
				}
			}else{
				count=1;
			}
		}
//		cout<<"count: "<<count<<endl;
		cout<<max<<endl;
		count=1;
		max=1;
	}
	
}


int comp( const void * p, const void * q) 
{ 
    return ( * ( int * ) p - * ( int * ) q) ; 
}

