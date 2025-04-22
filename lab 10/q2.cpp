#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Resume{
    string name, email,summary;
    int yearsOfExperience;

    public:

    Resume(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter email: ";
        cin>>email;
        cin.ignore();
        cout<<"Enter summary: ";
        getline(cin,summary);

        cout<<"Enter years of experience: ";
        cin>>yearsOfExperience;
    }

    void WritetoFile(ofstream& file){
        file<<name<<endl<<email<<endl<<summary<<endl<<yearsOfExperience<<endl;
    }

    void ReadfromFile(ifstream& file){

        string line;
        file>>line;
        name=line;
        cout<<"Name: "<<line<<endl;
        file>>line;
        email=line;
        cout<<"Email: "<<line<<endl;
        file>>line;
        summary=line;
        cout<<"Summary: "<<line<<endl;
        file>>yearsOfExperience;
        cout<<"Years of experience: "<<yearsOfExperience<<endl;
    }
};

int main(){
    
    Resume resume;
    ofstream file("resume.txt");
    if (!file) {
        cout << "Error opening the file for writing!" << endl;
        return 1;
    }
    resume.WritetoFile(file);
    file.close();

    ifstream file2("resume.txt");
    resume.ReadfromFile(file2);
    file2.close();

    ofstream file3("resume.txt",ios::trunc);
    if (!file3) {
        cout << "Error opening the file for writing!" << endl;
        return 1;
    }
    resume.WritetoFile(file3);
    file3.close();

    ifstream file4("resume.txt");
    resume.ReadfromFile(file4);
    file4.close();


    
    return 0;
}
