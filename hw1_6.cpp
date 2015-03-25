#include <iostream>
using namespace std;

struct count{
	int times;
	int value;
};
typedef struct count COUNT;

int compare_two_int(int a,int b){
	if(a>=b)
		return 1;
	if(b>a)
		return 0;
	}
void swap(int& a,int& b){
	int temp=a;
	a=b;
	b=temp;
}

void eu_swap(int& a,int& b){
	int temp=a;
	a=b%a;
	b=temp;
}	


COUNT GCD_By_Reverse_Search (int a,int b){
	int min_ab;
	COUNT gcd;
	gcd.times=0;
	if(compare_two_int(a,b)==1)
		min_ab=b;
	else 
		min_ab=a;
	for(int i=min_ab;i>0;i--){
			gcd.times++;
		if ( (a%i==0) && (b%i==0) ){
			gcd.value=i;
			return gcd;
		}
	}
}

COUNT GCD_By_Filter (int a,int b){
	int min_ab,i;
	COUNT gcd;
	gcd.times=0;
	if(compare_two_int(a,b)==1)
		min_ab=b;
	else 
		min_ab=a;
	for(i=2;i<=min_ab;i++){
		gcd.times++;
		if( (a%i==0) && (b%i==0) ){
			gcd.times+=GCD_By_Filter(a/i,b/i).times;
			gcd.value=i*GCD_By_Filter(a/i,b/i).value;
			return gcd;
		}
	}
	gcd.value=1;
	return gcd;
}


COUNT GCD_By_Filter_Faster_Internal(int a,int b,int s){
	int min_ab,i;
	COUNT gcd;
	gcd.times=0;
	if(compare_two_int(a,b)==1)
		min_ab=b;
	else 
		min_ab=a;
	for(i=s;i<=min_ab;i++){
		gcd.times++;
		if((a%i)==0 && (b%i)==0){
			gcd.times+=GCD_By_Filter_Faster_Internal(a/i,b/i,i).times;
			gcd.value=i*GCD_By_Filter_Faster_Internal(a/i,b/i,i).value;
			return gcd;
		}
	}
	gcd.value=1;
	return gcd;
}

COUNT GCD_By_Filter_Faster(int a,int b){
	return GCD_By_Filter_Faster_Internal(a,b,2);
}

COUNT GCD_By_Binary (int a,int b){
	int min_ab;
	int max_ab;
	if(compare_two_int(a,b)==1){
		min_ab=b;
		max_ab=a;
	}
	else {
		min_ab=a;
		max_ab=b;
	}
	int n=min_ab;
	int m=max_ab;
	int ans=1;
	COUNT gcd;
	gcd.times=0;
	while (n!=0 && m!=0){
		gcd.times++;
		if(n%2==0 && m%2==0){
			ans=ans*2;
			n=n/2;
			m=m/2;
		}
		else if(n%2==0 && m%2!=0){
			n=n/2;
		}
		else if(n%2!=0 && m%2==0){
			m=m/2;
		}
		if(n>m)
			swap(n,m);
		m=m-n;
	}
	gcd.value=n*ans;
	return gcd;
}

COUNT GCD_By_Euclid (int a,int b){
	int min_ab;
	int max_ab;
	if(compare_two_int(a,b)==1){
		min_ab=b;
		max_ab=a;
	}
	else {
		min_ab=a;
		max_ab=b;
	}
	int n=min_ab;
	int m=max_ab;
	COUNT gcd;
	gcd.times=0;
	while(m%n!=0){
		gcd.times++;
		eu_swap(n,m);
	}
	gcd.value=n;
	return gcd;
}

int main(){
	int a,b;
	while(1){
		cin>>a;
		if(a==0)
			break;
		cin>>b;
		cout<<"Case ("<<a<<", "<<b<<"): ";
		cout<<"GCD-By-Reverse-Search = "<<GCD_By_Reverse_Search (a,b).value;
		cout<<", taking "<<GCD_By_Reverse_Search (a,b).times<<" iterations"<<endl;

		cout<<"Case ("<<a<<", "<<b<<"): ";
		cout<<"GCD-By-Filter = "<<GCD_By_Filter (a,b).value;
		cout<<", taking "<<GCD_By_Filter (a,b).times<<" iterations"<<endl;

		cout<<"Case ("<<a<<", "<<b<<"): ";
		cout<<"GCD-By-Filter-Faster = "<<GCD_By_Filter_Faster (a,b).value;
		cout<<", taking "<<GCD_By_Filter_Faster (a,b).times<<" iterations"<<endl;

		cout<<"Case ("<<a<<", "<<b<<"): ";
		cout<<"GCD-By-Binary = "<<GCD_By_Binary (a,b).value;
		cout<<", taking "<<GCD_By_Binary (a,b).times<<" iterations"<<endl;

		cout<<"Case ("<<a<<", "<<b<<"): ";
		cout<<"GCD-By-Euclid = "<<GCD_By_Euclid (a,b).value;
		cout<<", taking "<<GCD_By_Euclid (a,b).times<<" iterations"<<endl;
	}
	return 0;
}