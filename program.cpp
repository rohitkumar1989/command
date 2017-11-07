#include<iostream>

using namespace std;

class giant{ // owner class of te function
	
	public :
	void func1(){
		cout<<"func1 \n";
	}
	
	void func2(){
		cout<<"func2 \n";
	}
	
	void func3(){
		cout<<"func3 \n";
	}
	
	
};

class command{
	giant* g;
	typedef void (giant::*method)();
	method mm;
	public:
	command(giant* g,method m):g(g),mm(m){//receive owner and methods here....
		
	}
	
	void execute(){
		
		(g->*mm)();
	}
};

template<typename T>
class queue{
	T m_array[20];
	int add=0,remove=0;
	
	public: 
		   void enqueue(T c){//save commands in array of pointers to commands data structure
			   m_array[add]=c;
			   add=(add+1)%20;
			}
			command* dequeue(){//get commands pointer from the array of the command pointer data structure
			   int temp=remove;
			   remove=(remove+1)%20;
			   return  m_array[temp];
			}
	
};

int main(){
	
	queue<command*> que;
	command *c[]={new command(new giant,&giant::func1),new command(new giant,&giant::func2),new command(new giant,&giant::func3)};//create commands with owner and methods..
     que.enqueue(c[0]);//save command
	 que.enqueue(c[1]);//save command
	 que.enqueue(c[2]);//save command
	 
	 que.dequeue()->execute();//execute method
	 que.dequeue()->execute();//execute method
	 que.dequeue()->execute();//execute method
}


