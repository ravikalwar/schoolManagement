#include<iostream>
#include<fstream>
using namespace std;
class student{
	public:
		string name;
		int roll;
		string address;
		long long number;
		void get(){
			cout<<"Enter the name of the students"<<endl;
			cin>>name;
			cout<<" his roll number"<<endl;
			cin>>roll;
			cout<<" address"<<endl;
			cin>>address;
			cout<<" mobile number"<<endl;
			cin>>number;
		}
		void display(){
			cout<<"----      Details of students:     ----"<<endl;
			cout<<"  Name      : "<<name;
			cout<<"  Roll no.  : "<<roll;
			cout<<"  address   : "<<address;
			cout<<" mobile number: "<<number<<endl;
		}
};
class sem: public student{
	public:
		int semester;
		string subject;
		float fees;
		void get(){
			student::get();
			cout<<"Enter the semesters enrolled by the students: "<<endl;
			cin>>semester;
				cout<<"Enter the subjects taught in the "<<semester<<"  semester "<<endl;
				cin>>subject;
			cout<<"The fees: "<<endl;
			cin>>fees;
		}
		void display(){
			student::display();
			cout<<"----   Brief description of students:----   "<<endl;
			cout<<"semester enrolled: "<<semester<<endl;
			cout<<"   subjects: "<<subject<<endl;
				cout<<"   fees: "<<fees;
		}
};
class teacher{
	public:
		string Name;
		int age;
		float salary;
		long long Number;
		double payment;
		char subj;
		void get(){
			cout<<"Enter the name of Teachers: "<<endl;
			cin>>Name;
			cout<<"Enter his age, salary and mobile number: "<<endl;
			cin>>age>>salary>>Number;
			cout<<"Enter his salary debbited: "<<endl;
			cin>>payment;
			cout<<"Enter the subject he teaches: "<<endl;
			cin>>subj;
		}
		void display(){
			cout<<"  --- Description of teachers: ----   "<<endl;
			cout<<"Name        :"<<Name<<endl;
			cout<<"Age  : "<<age<<" salary: "<<salary<<"  contact number: "<<Number<<endl;
			cout<<"paid salary: "<<payment;
			cout<<" "<<subj<<" subject teacher"<<endl;
			
		}
};
class school_management:public sem, public teacher{
	public:
		char choice;
		void get(){
			cout<<"Enter your choice:"<<endl;
			cout<<"Click 'y' or 'Y' if you want to add new new details: "<<endl;
			cout<<"anotherwise press any key: "<<endl;
			cin>>choice;
			if(choice=='y' || choice == 'Y'){
				sem::get();
				teacher::get();
			}
		}
		void display(){
			cout<<"NEW English Boarding School:"<<endl;
			student::display();
			teacher::display();
			cout<<"Happy journey: "<<endl;
			
		}
};
int main(){
	school_management s;
	s.get();
	if(s.choice == 'y' || s.choice == 'Y'){
		s.display();
	}
	
	fstream file;
	file.open("school.txt",ios::out);
	if(!file){
		cout<<"Error in opening file"<<endl;
		return 1;
	}
	file<< s.name<<"  "<<s.roll<<"  "<<s.address<<"   "<<endl;
	file<<s.number <<"  "<<s.semester<<"    "<<s.subject<<"   "<<"   "<<s.fees<<endl;
	file<<s.name<<"  "<<s.age<<" "<<s.subj<<"  "<<s.salary<<" "<<s.Number<<"  "<<s.payment<<endl;
	file.close();
	
	file.open("school.txt", ios::in);
	if(!file){
		cout<<"Error in opening file: "<<endl;
		return 1; 
	}
	cout<<"  \n   Reading Data from file   "<<endl;
	string line;
	while(getline(file,line)){
		cout<<line<<endl;
	}
	file.close();
	
	return 0;
}