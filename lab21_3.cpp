#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdlib>
#include<iomanip>

using namespace std;

struct student{

    char *name;
	int id;
	char gender;
	float gpa;
};

struct course{
	string name;
	int id;
	vector<string> lecture_list;
	vector<student *> student_list;
};

student * findstudent(vector<student> &allstudents,int key){ //There is something wrong in this line.
	for(unsigned int i = 0; i < allstudents.size(); i++){
		if(allstudents[i].id  == key) return &allstudents[i];
	}
	return 0;
}

void printreport(vector<course> allcourses){
	for(unsigned int i = 0;i < allcourses.size(); i++){
		cout << "-----------------------------------------------------------------------------\n";
		cout << left << setw(20);
		cout << "Course:" << allcourses[i].name << " ("<< allcourses[i].id << ")\n\n";
		cout << left << setw(20);
		cout << "Lecturers:";
		for(unsigned int j = 0; j < allcourses[i].lecture_list.size();j++){
			if(j != 0) cout << ", ";
			cout << allcourses[i].lecture_list[j];
		}
		cout << "\n\n";
		cout << left << setw(20);
		cout << "Students:";
		for(unsigned int j = 0; j < allcourses[i].student_list.size();j++){
			if(j != 0) cout << left << setw(20) << " ";
			cout << left << setw(20) << allcourses[i].student_list[j]->name;
			cout << left << setw(10) << allcourses[i].student_list[j]->id;
			cout << left << setw(3) << allcourses[i].student_list[j]->gender;
			cout << left << setw(5) << setprecision(2) << fixed << allcourses[i].student_list[j]->gpa << "\n";
		} 
		
	}
	cout << "-----------------------------------------------------------------------------\n";
}

int main(){
	ifstream student_file("students.txt");
	ifstream course_file("courses.txt");
	vector<student> allstudents;
	vector<course> allcourses;
	int a = 0;
	int b = 0;
	int x = 0;
	string textline;
	char names[100][100];
	while(getline(student_file,textline)){
		student s; 
		int y;
		char g;
		float gp;
		
		sscanf(textline.c_str(),"%[^,],%d,%c,%f",&names[x][0],&y,&g,&gp);
		s = {&names[x][0],y,g,gp};
		x++;
		//Use sscanf() to split the values in textline and assign those values to the members of struct s;
		
		allstudents.push_back(s); 		
	}
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
				do{
					if(textline == "> Students")
					{
						a++;
						state = 3;
						break;
					}

				allcourses[a].lecture_list.push_back(textline);
				}while (getline(course_file,textline));
				
				
			    //Append (push_back) textline to lecture_list[] of the recently added course in allcourses[];
			    
			}			
		}else{
			if(textline == "---------------------------------------"){
				state = 1;
				b++;
			}else{
				student *p = findstudent(allstudents,atof(textline.c_str()));

				allcourses[b].student_list.push_back(p);
				
				//Append (push_back) p to student_list of the recently added course in allcourses[];
				
			}
		}
	}
	printreport(allcourses);
	
}
