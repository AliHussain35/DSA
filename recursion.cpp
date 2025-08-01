//recursion
#include<iostream>
using namespace std;
//---static variables in recursion---
//int fun(int n){
//	static int a = 0;
//	if(n>0){
//		a++;
//		return fun(n-1) + a;
//	}
//	return 0;
//}
//int main(){
//	int x=5;
//	int m = fun(x);
//	cout<<m;
//}
//---tree recursion---
//void fun(int n){
//	if(n>0){
//		cout<<n;
//		fun(n-1);
//		fun(n-1);
//	}
//}
//int main(){
//	fun(3);
//}
//---nested recursion---
//int fun(int n){
//	if(n>100){
//		return n-10;
//	}
//	return fun(fun(n+11));
//}
//int main(){
//	int r;
//	r = fun(95);
//	cout<<r;
//}
//---sum of first n natural numbers---
//int sumOfnatural(int n){
//	static int i=0;
//	if(n==0){
//		return 0;
//	}
//	i++;
//	return i + sumOfnatural(n-1);
//}
//int main(){
//	int r;
//	r = sumOfnatural(3);
//	cout<<r;
//}
//---factorial of a number---
//int fact(int n){
//	if(n==0){
//		return 1;
//	}
//	return fact(n-1)*n;
//}
//int main(){
//	int r;
//	r = fact(3);
//	cout<<r;
//}
