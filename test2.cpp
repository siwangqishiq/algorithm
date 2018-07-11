/*************************************************************************
    > File Name: test2.cpp
    > Author: panyi
    > Mail: 525647740@qq.com 
    > Created Time: 二  7/10 12:37:25 2018
 ************************************************************************/

#include<iostream>
#include <queue>

using namespace std;



int main(int argc , char *agrv[]){
	queue<int> q;

	q.push(1);
	q.push(2);
	q.push(3);


	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	return 0;
}
