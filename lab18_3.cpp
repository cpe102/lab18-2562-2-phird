#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{
	//Define struct student with four member (name ,id , gender, gpa);
	string name;
	int id;
	string gender;
	double gpa;
	//int ngender;
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student *findstudent(vector<student> &allstudents,int key){ // add & to allstudent
//student *findstudent(vector<student> allstudents,int key){ //Correct this line
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << "Course:\t\t" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << "Lecturers:\t";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		} 
		cout << "\n\nStudents:\t";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << "\t\t";
			cout << setw(20) << left << allcourses[i].student_list[j]->name << "\t";
			cout << allcourses[i].student_list[j]->id << "\t";
			cout << allcourses[i].student_list[j]->gender << "\t";
			cout << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

int main(){
	ifstream student_file("students.txt");
	ifstream course_file("courses.txt");
	vector<student> allstudents; //kept student text in this vector;
	vector<course> allcourses; //kept course text in this vector;
	
	string textline;
	
	while(getline(student_file,textline)){ //get student file into textline
		student s; 		
		//Assign value to the members of struct s;
		char name1[100];
		int id1;
		char gender1;
		float gpa1;
		sscanf(textline.c_str(),"%[^,],%d,%c,%f",&name1,&id1,&gender1,&gpa1);
		s.name=name1;
		s.id=id1;
		s.gender=gender1;
		s.gpa=gpa1;
		allstudents.push_back(s); // s that contain the string of student file and pushback into vector allstudent 		
	}
	// text line clear 
	int state = 1;
	while(getline(course_file,textline)){
		if(state == 1){
			course c;
			int loc = textline.find_first_of('(');
			c.name = textline.substr(0,loc-1);
			c.id = atof(textline.substr(loc+1,5).c_str());
			getline(course_file,textline);
			allcourses.push_back(c);
			state = 2;			
		}else if(state == 2){
			if(textline == "> Students"){
				state = 3;
			}else{
				//Append lecture_list;
				allcourses[allcourses.size()-1].lecture_list.push_back(textline.c_str()); // line nee kee ar lai ?
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;
			}else{
				student *p = findstudent(allstudents,atof(textline.c_str()));
				//Append student_list;
				allcourses[allcourses.size()-1].student_list.push_back(p); //mai kaw jai
			}
		}
	}
	printreport(allcourses);
	
}
