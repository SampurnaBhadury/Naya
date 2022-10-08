#include<stdio.h>
#include<iostream>
using namespace std;
struct queue{
	int size;
	int front;
	int rear;
	int *Q;
};
void enqueue(struct queue *q, int x){
	if((q->rear+1)%q->size==q->front){
		cout<<"Queue full"<<endl;
	}else{
		q->rear=(q->rear+1)%q->size;  //side by side
		q->Q[q->rear]=x;
	}
}

int dequeue(struct queue *q){
	int a;
	if(q->rear==q->front){            //same position.
		cout<<"Queue empty"<<endl;
	}else{
		q->front=(q->front+1)%q->size;
		a=q->Q[q->front];
	}
}

void display(struct queue q,int s){
	int i=q.front+1;
	do{
		cout<<q.Q[i]<<" ";
		i=(i+1)%q.size;
	}while(i!=(q.rear+1)%q.size);
}
int main(){
	int s,ch,num,ch1,del,i;
	struct queue q;
	cout<<"Enter the size of the queue"<<endl;
	cin>>s;
	q.size=s;
	q.front=q.rear=-1;
	q.Q=new int[s];
	cout<<"Enter your choice "<<endl;
	cin>>ch;
	int choose=1;
	while(choose==1){
		switch(ch){
		case 1:
			cout<<"Enter the number "<<endl;
			cin>>num;
			enqueue(&q,num);
			break;
		case 2:
			del=dequeue(&q);
			cout<<"The deleted element is= "<<del<<" "<<endl;
			break;
		case 3:
			cout<<"The final queue is :"<<endl;
			display(q,s);
			break;
		default:
			cout<<"Invalid"<<endl;
		}
		cout<<"Enter your choice "<<endl;
		cin>>ch;
	}
}
