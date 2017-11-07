#include<iostream>

using namespace std;

class person;
class command{ // save owner and method and other parameters so that perform action or event can be triggered in the future
	person* p;
	typedef void (person::*method)();
	method m;
	public:
	command(person *pp=NULL,method mm=NULL):p(pp),m(mm){//save owners pointer and method....by default cause it not to cause segmentation fault
	}
	
	void execute(){ //call this in future so that stored command get executed
	  if (p!=NULL)
		(p->*m)();	
	  else
		cout<<"nothing\n";
}
};

class person{//client which will execute command
	
		string name;
		command cmd;//save command so that it can be called in future 
		public:
		
		person(string s,command c):cmd(c){
			name=s;
		}
	
		void passon(){ //when this nethod called trigger event using cmd.execute 
			cout<<name<<" pass on \n";
			cmd.execute();////when this nethod called trigger event using cmd.execute
		}
		
		void gossip(){
			cout<<name<<" gossip \n";
			cmd.execute();//when this nethod called trigger event using cmd.execute
		}
		
		void talk(){
			cout<<name<<" talk \n";
			cmd.execute();//when this nethod called trigger event using cmd.execute
		}
		
		void listen(){
			cout<<name<<" listen \n";
			cmd.execute();//when this nethod called trigger event using cmd.execute
		}
};

int  main(){
	//client create command but do not execute
	person raghu("raghu",command());
	person rohit("rohit",command(&raghu,&person::listen));//any method we can mention
    person ritesh("ritesh",command(&rohit,&person::gossip))	;
	person romit("romit",command(&ritesh,&person::passon));

	
	romit.talk();
}