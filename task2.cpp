#include <iostream>
using namespace std;
struct song{
	int id;
	string title;
	string artist;
	int duration;
	song *p;
	song*n;
};
class playlist{
	song *start,*cur,*temp;
	public:
	playlist(){
			start = NULL;}
		void insert(int i,string a,string t,int d){
			if (start == NULL){
				start = new song;
				start->id=i;
				start->artist=a;
				start->title=t;
				start->duration=d;
				start->n=NULL;
				start->p=NULL;}
			else{
				cur = start;	
				while(cur->n!=NULL)
				cur = cur->n;
				temp = new song;
				temp->id=i;
				temp->artist=a;
				temp->title=t;
				temp->duration=d;
				temp->n=NULL;
				temp->p=cur;
				cur->n=temp;
			}}
		void search(){
			string name;
			cout<<"Enter title to search:";
			cin>>name;
			cur=start;
			while(cur!=NULL){
				if(cur->title==name){
					cout<<"Found:"<<cur->title<<"by:"<<cur->artist<<endl;
					return;}
				cur=cur->n;}
			cout<<"Not Found:"<<endl;}	
		void update(){
			string name;
			cout<<"Enter title to update:";
			cin>>name;
			cur = start;
				while(cur!=NULL){
				if(cur->title==name){
			cout<<"Enter new Artist:";
			cin>>cur->artist;
			cout<<"Enter new Duration:";
            cin >> cur->duration;
            cout<<"Song Successfully Updated"<<endl;
                        return;
					} cur = cur->n;
				}  cout<<"Not Found"<<endl;}	
			void display(){
				cur = start;
			while(cur != NULL){
					cout<<" ID: "<<cur->id;
					cout<<"Song Title:"<<cur->title;
				    cout<<" Artist: "<<cur->artist;
					cout<<" Duration(sec) "<<cur->duration;
					cout<<endl; 
					cur = cur->n;}
				 return;}
			void playnext(int i){
				cur = start;
				while (cur != NULL){
					if (cur->id == i){
					   if (cur->n!=NULL){
					    cur=cur->n;
						cout<<"Now Playing "<<cur->title<<" Song!!"<<endl;}   
					else{
						cout<<"This is the last song!"<<endl;
					} return;  
					} cur=cur->n;}  
				cout<<"Song not Found!!"<<endl;}
			void playpervious(int i){
				cur = start;
				while (cur != NULL){
					if (cur->id == i){
					   if ( cur->p!= NULL){
					    cur=cur->p;
						cout<<"Now Playing "<<cur->title<<" Song!"<<endl;}   
					else{
						cout<<"This is the First song!"<<endl;
					} return;  
					} cur=cur->n;}  
				cout<<"Song not Found!"<<endl;}		
};
int main() {
	playlist p;
	int choice;
	do{ 
	    cout<<"1. Insert\n2. Search\n3. Update\n4.  Display\n5. Play Next\n6. Play pervious\n7. Exit"<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice){
			case 1: {
			int i,d; string a, t;
            cout << "Enter ID: ";
            cin >> i;
            cout << "Enter Artist Name: ";
            cin>>a;
            cout << "Enter Song Title: ";
            cin>>t;
            cout << "Enter Duration (sec): ";
            cin>>d;
            p.insert(i, a, t, d);
           break; }
			case 2:
				p.search(); break;
			case 3:
				p.update(); break;
			case 4: 
			    p.display(); break;
			case 5:
				int id;
			     cout<<"Enter cur song ID:";
				 cin>>id;
				 p.playnext(id); break;
			case 6: 
			    cout<<"Enter cur song ID:";
				 cin>>id;
				 p.playpervious(id); break;	
				 case 7:
				 cout<<"Invalid choice"<<endl;			
		}} while(choice!= 7);
	return 0;
}
