#include<iostream>
using namespace  std;
struct book{
	string title;
	string author;
	int year;
	int ISBN;
	book*p;
	book*n;
};
class library{
	book*start,*cur,*temp;
	public:
		library(){
			start = NULL;
			cur = NULL;
			temp = NULL;
		}
		bool isDuplicate(int isbn){
		cur = start;
		while(cur!=NULL){
			if(cur->ISBN == isbn){
				return true;
			}
			cur=cur->n;
		}
		return false;
		}
		void insert(string t,string a,int y,int isbn){
			if(isDuplicate(isbn)){
				cout<<"Error: ISBN  must be unique"<<endl;
				return;
			}
		temp=new book;
		temp->title=t;
		temp->author=a;
		temp->year=y;
		temp->ISBN=isbn;
		temp->n=NULL;
		temp->p=NULL;
		if(start == NULL){
			start=temp;
		}
		else{
			cur=start;
			while(cur->n!=NULL){
				cur=cur->n;
			}
			cur->n=temp;
			cur->p=cur;
		}
		cout<<"   Successfully!.. Book Inserted   "<<endl;}
		void search(int key){
			cur=start;
			bool found=false;
			while(cur!=NULL){
				if(cur->ISBN == key)
				cout<<"Book Found:"<<endl;
				cout<<"ISBN:"<<cur->ISBN<<endl;
				cout<<"Title:"<<cur->title<<endl;
				cout<<"Author:"<<cur->author<<endl;
				cout<<"Year:"<<cur->year<<endl;
				found=true;
				break;
			}
		cur=cur->n;
	if(!found)
	cout<<"Book not Found"<<endl;}
		void update(int isbn){
		cur=start;
		bool found=false;
		while(cur!=NULL){
			if(cur->ISBN==isbn){
			cout<<"Enter New Title:";
			cin>>cur->title;
			cout<<"Enter New Author:";
			cin>>cur->author;
			cout<<"Enter New Year:";
			cin>>cur->year;
			cout<<"Book Details Updated!"<<endl;
			found=true;
			break;}
				cur=cur->n;}
		if(!found){
		cout<<"Book Not Found"<<endl;}}
		void display(){
			cur=start;
			int count=0;
			if(start=NULL){
				cout<<"No Book in the Library"<<endl;
				return;}
			while(cur!=NULL){
			cout<<"ISBN:"<<cur->ISBN<<endl;
				cout<<"ISBN:"<<cur->ISBN<<endl;
				cout<<"Title:"<<cur->title<<endl;
				cout<<"Author:"<<cur->author<<endl;
				cout<<"Year:"<<cur->year<<endl;
				count++;
				cur=cur->n;}}	
};
int main(){
	library l;
	int choice;
	int isbn,year;
	string title,author;
	do{
		cout<<"......Library Menu......."<<endl;
		cout<<"1. Insert\n2. Search\n3. Update\n4. Display\n5. Exit\n";
		cout<<"Enter choice:";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter ISBN:";
				cin >> isbn;
				cout<<"Year:"; 
				cout<<"Author:";
				cout<<"Title:";
				cin>>year;
				cin>>author;
			    cin>>title;
				l.insert(title,author,year,isbn);
				break;
				case 2:
					cout<<"Enter ISBN to Search:";
					cin>>isbn;
					l.search(isbn);
					break;
					case 3:
						cout<<"Enter ISBN to Update:";
						cin>>isbn;
						l.update(isbn);
						break;
						case 4:
							l.display();
							break;
							case 5:
								cout<<"Exit"<<endl;
								break;
								default:
									cout<<"Invalid choice"<<endl;}
			}while(choice!=5);
			return 0;
}




