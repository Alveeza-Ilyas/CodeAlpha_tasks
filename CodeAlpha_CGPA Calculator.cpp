#include<iostream>
using namespace std;

int main(){
	
	int totalSubjects;
	cout<<"\n-------------------------------------------------CGPA Calculator-------------------------------------------------------\n\n";
	cout<<"Enter total subjects of current semester: ";
	cin>>totalSubjects;
	
	//Initialization
	int subjectCreditHours[totalSubjects],totalSemester,totalCreHrs=0;
	float crntSemGPA=0.0,subjectGrade[totalSubjects];
	string subjectName[totalSubjects];
	
	cout<<"Enter subject names!";
	cout<<"Enter Subject Name, credit hours and grades of each subject!\n";
	
	for(int i=0;i<totalSubjects;i++){
		
		//input Subjects Name
		cout<<"Subject "<<i+1<<" Name: ";
		cin>>subjectName[i];
		
		//Input Subject Credit Hours (Validation of min value 1)
		do {
		    cout << subjectName[i] << " Credit hours (must be > 0): ";
		    cin >> subjectCreditHours[i];
		    if(subjectCreditHours[i] <= 0) {
		        cout << "Invalid input! Credit hours must be greater than 0.\n";
		    }
		} while(subjectCreditHours[i] <= 0);

		totalCreHrs+=subjectCreditHours[i];
		
		//Input Subject Grades (Validation of min value 0 and max 4.0)
		do {
		    cout << subjectName[i] << " Grade (max 4.0): ";
		    cin >> subjectGrade[i];
		    if(subjectGrade[i] < 0 || subjectGrade[i] > 4) {
		        cout << "Invalid grade! Enter a value between 0 and 4.\n";
		    }
		} while(subjectGrade[i] < 0 || subjectGrade[i] > 4);

		cout<<endl;
		crntSemGPA+=(subjectCreditHours[i]*subjectGrade[i]);
	}
	crntSemGPA/= totalCreHrs;
	cout<<"Current Semester GPA: "<<crntSemGPA<<endl<<endl;
	
	//Initialization and Input values for CGPA Calculation
	cout<<"Enter Total semesters: ";
	cin>>totalSemester;
	float allSemGPA[totalSemester],CGPA = 0.0;
	
	//Input each Semester GPA(Validation of min value 0 and max 4.0)
	cout<<"Enter all Semesters GPA!\n";
	for(int i=0;i<totalSemester;i++){
		do {
	    cout << "Semester " << i+1 << " GPA (max 4.0): ";
	    cin >> allSemGPA[i];
	    if(allSemGPA[i] < 0 || allSemGPA[i] > 4) {
	        cout << "Invalid GPA! Enter a value between 0 and 4.\n";
	    }
	} while(allSemGPA[i] < 0 || allSemGPA[i] > 4);

		CGPA+= allSemGPA[i];
	}
	CGPA/= totalSemester;
	
	//Display current Semester's subjects Grade and Final CGPA
	cout<<"\nAll subjects Grades of current semester are as follows!\n";
	for(int i=0;i<totalSubjects;i++){
		cout<<subjectName[i]<<" Grade: "<<subjectGrade[i]<<endl;
	}
	cout<<"\nFinal CGPA: "<<CGPA;

}