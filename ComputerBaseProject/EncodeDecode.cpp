#include<iostream>
#include<string>
using namespace std;

int main(void){
	string k;
	int intk[50];
	for(int i=0;i<50;i++)
		intk[i]=0;
	int bound;
	bool more1=false;

	cout<<"Enter message: ";
	cin>>k;
	cout<<endl;
	cout<<"The vectors for the original message: "<<endl;
	cout<<"\t";
	for(int i=0; i<k.size();i+=2)
	{
		intk[i]=int(k[i]-96);
		if(intk[i]<10)
			cout<<" ";
		cout<<intk[i]<<"   ";
	}
	cout << endl << "\t";
	for(int i=1; i<k.size();i+=2)
	{
		intk[i]=int(k[i]-96);
		if(intk[i]<10)
			cout<<" ";
		cout<<intk[i]<<"   ";
		if(i==k.size()-2)
		{
			intk[i+2]=intk[i+1];
			if(intk[i+2]<10)
				cout<<" ";
			cout<<intk[i+2];
		}
	}
	bound=k.size();

	if (2*int(bound/2)!=bound)
	{
		intk[bound]=intk[bound-1];
		more1=true;
		bound++;
		cout<<endl<<"  (Added 1 \"dummy\" letter for even.)"<<endl;
	}
	else
		cout<<endl<<endl;

	int cm[4];
	cout<<endl<<"Code Matrix Format:"<<endl;
	cout<<"    a b"<<endl<<"    c d"<<endl;
	cout<<"Enter the code Matrix"<<endl;
	cout<<"format = (a b c d):  ";
	for(int i=0;i<4;i++)
		cin>>cm[i];
	cout<<endl<<endl;
	cout << "The vectors for coded message: "<<endl;
	int* newk= new int[bound];
	for(int i=0;i<bound;i+=2)
	{
		newk[i]=(cm[0]*intk[i]+cm[1]*intk[i+1])%26;
		newk[i+1]=(cm[2]*intk[i]+cm[3]*intk[i+1])%26;
	}
//	for(int i=0;i<bound;i+=2)
//		cout<<'('<<(newk[i]<10?" ":"")<<newk[i]<<','<<(newk[i+1]<10?" ":"")<<newk[i+1]<<')'<<endl;
	cout << "\t";
	for(int i=0; i<bound;i+=2)
	{
		if(newk[i]<10)
			cout<<" ";
		cout<<newk[i]<<"   ";
	}
	cout << endl << "\t";
	for(int i=1; i<bound;i+=2)
	{
		if(newk[i]<10)
			cout<<" ";
		cout<<newk[i]<<"   ";
	}

	if(more1)
		bound--;
	cout<<endl<<endl<<"The coded message is [ ";
	for(int i=0; i<bound;i++){
		char t=newk[i]+96;
		if(newk[i]!=0)
			cout<<t;
		else
			cout<<'z';
	}
	cout<<" ] !!!"<<endl<<endl;
	
	system("pause");
	return 0;
}
