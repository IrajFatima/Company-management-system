#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <chrono>
#include <cstdlib>
#include <random>  
using namespace std;

class department;
// class address;
class employee;
// class employee;
class project;
//classes




//class char_string
class char_string
{
private:
    char*cstr;
    int size;
public:
    //constructors
    char_string();
    char_string(int ,char* );
    //copy functions
    void copy_from(const char*str);
    void copy_from(const char_string& str);
    int get_size();
    char* get_char();
    //display
    void display() const;
    //destructor
    ~char_string();
};






//class address
class address
{
private:
    int house_no;
    char block;
    int street_no;
    char_string city;
public:
    address();
    address(int h,char b,int s,int ,char* );
    address(const address& a);
    void display_address() const ;
    ~address();
};







//class project
class project
{
private:
    int id;
    char_string project_description;
    int emp_working;
    employee* emp[10];
public:
    project();
    project(int ,int ,char*  );
    int get_id();
    void display_info() const ;
    void inc_emp_count();
    void dec_emp_count();
    bool assign_to_employee(employee* e);
    bool remove_employee(int empID);
    void display_emp();
    ~project();
};













//class employee
class employee
{
private:
    int id;
    char_string name;
    address permanent_addr;
    bool assigned_to_dept;
    project* proj[3];
    int proj_count;
    float salary;
    department* dept;
public:
    employee();
    employee(int i,int ,char* ,int h,char b,int s,int ,char*,float );
    employee(const employee& e);
    int get_id();
    void display_employee_info();
    bool add_project(project*pro);
    bool remove_project(int proj_id);
    void display_project();
    bool set_dept(department* d);
    bool remove_dept();
    void set_assigned_to_dept(bool val);
    ~employee();
};








//class department
class department
{
private:
    int id;
    char_string name;
    employee* emp[20];
    int emp_count;
public:
    department();
    department(int ,int ,char* );
    void display_dept_info();
    string get_name();
    bool add_employee(employee*);
    bool remove_emp(int emp_id);
    void display_emp();
    int get_id();
    ~department();
};



//class company
class Company
{
private:
int employee_count;
employee* emp[300];
int dept_count;
department* dept[20];
int project_count;
project* proj[50];
public:
//constructor
Company(); 
//other functions
void add_employee(int i,int x,char* y,int h,char b,int s,int a ,char* m,float d); 
void add_department (int i,int x,char* y); 
void add_project(int i, int x,char* y);
void assign_project_to_employee(int empID, int prjID) ;
void assign_employee_to_department(int deptID, int empID); 
void remove_project_from_employee(int empID, int prjID);
void remove_employee_from_department(int deptID, int empID); 
//display functions
void display_projects();
void display_employees();
void display_departments();
void display_all_projects_Of_employee(int empID);
void display_all_employees_of_dept(int deptID);
void display_all_employees_on_proj(int prjID);
//destructor
~Company(); 
};


//company class implementation
Company::Company(): employee_count(0),dept_count(0),project_count(0)
{
    int i;
    for(i=0;i<300;i++)
        emp[i]=nullptr;
    for(i=0;i<20;i++)
        dept[i]=nullptr;
    for(i=0;i<50;i++)
        proj[i]=nullptr;    
}
void Company::add_employee(int q,int x,char* y,int h,char b,int s,int a ,char* m,float d){
    for(int i=0;i<300;i++)
        if(emp[i]==nullptr){
            emp[i]=new employee(q,x,y,h,b,s,a,m,d);
            employee_count++;
            cout<<"<--------Employee added to the company------->"<<endl;
            return;
        }
    cout<<"<------No vacancy for employee------>"<<endl;
    return;    
}
void Company::add_department(int q,int x,char* y){
    for(int i=0;i<20;i++)
        if(dept[i]==nullptr){
            dept[i]=new department(q,x,y);
            cout<<"<--------Department added to the company------->"<<endl;
            dept_count++;
            return;
        }
    cout<<"<------No vacancy for department------>"<<endl;
    return;
}
void Company::add_project(int q, int x,char* y){
    for(int i=0;i<50;i++)
        if(proj[i]==nullptr){
            proj[i]=new project(q,x,y);
            cout<<"<--------Ptoject assigned to the company------->"<<endl;
            return;
        }
    cout<<"<------No vacancy for project------>"<<endl;
    return;
}
void Company::assign_project_to_employee(int empID, int prjID){
    int i,j;
    for(i=0;i<300;i++)
        if(emp[i])
            if(emp[i]->get_id()==empID)
                break;
    for(j=0;j<50;j++)
        if(proj[j])
            if(proj[j]->get_id()==prjID)
                break;
    emp[i]->add_project(proj[j]);                        
}
void Company::remove_project_from_employee(int empID,int prjID ){
    int i,j;
    for(i=0;i<300;i++)
        if(emp[i])
            if(emp[i]->get_id()==empID)
                break;
    for(j=0;j<50;j++)
        if(proj[j])
            if(proj[j]->get_id()==prjID)
                break;
    emp[i]->remove_project(prjID);
}
void Company::assign_employee_to_department(int deptID,int empID){
    int i,j;
    for(i=0;i<300;i++)
        if(emp[i])
            if(emp[i]->get_id()==empID)
                break;
    for(j=0;j<20;j++)
        if(dept[j])
            if(dept[j]->get_id()==deptID)
                break;
    dept[j]->add_employee(emp[i]);            
}
void Company::remove_employee_from_department(int deptID,int empID){
    int i,j;
    for(i=0;i<300;i++)
        if(emp[i])
            if(emp[i]->get_id()==empID)
                break;
    for(j=0;j<20;j++)
        if(dept[j])
            if(dept[j]->get_id()==deptID)
                break;
    dept[i]->remove_emp(emp[j]->get_id());
}
void Company::display_projects(){
    cout<<"\nTotal projects\t\t:\t"<<project_count<<endl;
    if(project_count==0)
        return;
    for(int i=0,j=1;i<50;i++)
        if(proj[i]){
            cout<<"Project "<<j<<endl;
            proj[i]->display_info();
            j++;
        }
}
void Company::display_employees(){
    cout<<"\nTotal employees\t\t:\t"<<employee_count<<endl;
    if(employee_count==0)
        return;
    for(int i=0,j=1;i<300;i++)
        if(emp[i]){
            cout<<"Employee "<<j<<endl;
            emp[i]->display_employee_info();
            j++;
        }
}
void Company::display_departments(){
    cout<<"\nTotal departments\t\t:\t"<<dept_count<<endl;
    if(dept_count==0)
        return;
    for(int i=0,j=1;i<20;i++)
        if(dept[i]){
            cout<<"Department "<<j<<endl;
            dept[i]->display_dept_info();
        }
}
void Company::display_all_employees_of_dept(int deptID){
    for(int i=0;i<20;i++)
        if(dept[i])
            if(dept[i]->get_id()==deptID){
                dept[i]->display_emp();
                break;
            }
}
void Company::display_all_employees_on_proj(int projID){
    for(int i=0;i<50;i++)
        if(proj[i])
            if(proj[i]->get_id()==projID){
                proj[i]->display_emp();
                break;
            }
}
void Company::display_all_projects_Of_employee(int empID){
    for(int i=0;i<300;i++)
        if(emp[i])
            if(emp[i]->get_id()==empID){
                emp[i]->display_project();
                break;
            }
}
Company::~Company(){
    for(int i=0;i<300;i++)
        delete emp[i];
    for(int i=0;i<20;i++)
        delete dept[i];
    for(int i=0;i<50;i++)
        delete proj[i];                
}








class char_string;

//char_string implementation
//constructor
char_string::char_string(): cstr(nullptr),size(0){}
char_string::char_string(int s,char*c):size(s)
{
    cstr=new char[size];
    int i;
    for( i=0;i<size;i++){
        cstr[i]=c[i];
    }
    cstr[i]='\0';
}
//copy functions
void char_string::copy_from(const char*str){
    int i;
    for( i=0;str[i]!='\0';i++);
    this->size=++i;
    cstr=new char[size];
    for( i=0;str[i]!='\0';i++){
        cstr[i]=str[i];
    }
    cstr[i]='\0';
}
void char_string::copy_from(const char_string& str){
    this->size=str.size;
    cstr=new char[size];
    int i;
    for( i=0;str.cstr[i]!='\0';i++){
        this->cstr[i]=str.cstr[i];
    }
    this->cstr[i]='\0';
}
int char_string::get_size(){return size;}
char* char_string::get_char(){return cstr;}
//display
void char_string::display() const {
    int i;
    for( i=0;i<size;i++){
        cout<<cstr[i];
    }
    cout<<endl;
}
//destructor
char_string::~char_string(){delete[] cstr;}







//address class implementation
//constructors
address::address(int h,char b,int s,int x,char*y ):house_no(h),block(b),street_no(s),city(x,y){}
address::address():house_no(0),block('\0'),street_no(0),city(){}
address::address(const address& a){
    house_no=a.house_no;
    block=a.block;
    street_no=a.street_no;
    city.copy_from(a.city);
}
//display
void address::display_address() const {
    cout<<"-------------------------------------"<<endl;
    cout<<"house no\t\t:\t"<<house_no<<endl;
    cout<<"block\t\t\t:\t"<<block<<endl;
    cout<<"street no\t\t:\t"<<street_no<<endl;
    cout<<"city\t\t\t:\t";
    city.display();
    cout<<"--------------------------------------"<<endl;


}
//destructor
address::~address(){}


//project implementation
//constructors
project::project(int i, int x,char* y):id(i),project_description(x,y),emp_working(0){
    for(int i=0;i<10;i++){
        emp[i]=nullptr;
    }
}
project::project():id(0),project_description(),emp_working(0){
    for(int i=0;i<10;i++){
        emp[i]=nullptr;
    }
}
//getter
int project::get_id(){return id;}
//display
void project::display_info() const {
    cout<<"-----------------------------------------"<<endl;
    cout<<"Project ID\t\t\t:\t"<<id<<endl;
    cout<<"Project Description\t\t:\t";
    project_description.display();
    cout<<"Employees working on project\t:\t"<<emp_working<<endl;
    cout<<"------------------------------------------"<<endl;
}
void project::display_emp(){
    for(int i=0;i<10;i++)
        if(emp[i])
            emp[i]->display_employee_info();
}
//increment function
void project::inc_emp_count(){emp_working++;}
void project::dec_emp_count(){emp_working--;}
bool project::assign_to_employee(employee* e){
    for(int i=0;i<10;i++)
        if(emp[i]==nullptr){
            emp[i]=e;
            cout<<"<-------Employee assigned to project------->"<<endl;
            return true;
        }
    cout<<"<------employee cant be added------->"<<endl;
    return false;    
}
bool project::remove_employee(int empID) {
    for(int i=0;i<10;i++){
        if (emp[i]!=nullptr&&emp[i]->get_id()==empID){
            emp[i]=nullptr;
            return true;
        }
    }
    return false; // Employee not found in project
}
//destructor
project::~project(){}






//class employee implementation
//constructors
employee::employee():id(0),name(),permanent_addr(),assigned_to_dept(false),proj_count(0),salary(0){
    for(int i=0;i<3;i++)
        proj[i]=nullptr;
    dept=nullptr;    
}
employee::employee(int q,int x,char* y,int h,char b,int s,int a ,char* m,float d):id(q),name(x,y),permanent_addr(h,b,s,a,m),assigned_to_dept(false),proj_count(0),salary(d)
{
    for(int i=0;i<3;i++)
        proj[i]=nullptr;
    dept=nullptr;    
}
employee::employee(const employee& e):permanent_addr(e.permanent_addr)
{
    id=e.id;
    name.copy_from(e.name);
    assigned_to_dept=e.assigned_to_dept;
    proj_count=e.proj_count;
    for(int i=0;i<e.proj_count;i++)
        proj[i]=e.proj[i];
}
int employee::get_id(){return id;}
//display
void employee::display_employee_info(){
    cout<<"\n<-----------Employee info------------>\n"<<endl;
    cout<<"Employee ID\t\t\t:\t"<<id<<endl;
    cout<<"Employee name\t\t\t:\t";
    name.display();
    cout<<"Employee Address\t\t\n";
    permanent_addr.display_address();
    cout<<"Employee Salary\t\t\t:\t$ "<<salary<<endl;
    if(dept!=nullptr)
        cout<<"Employee Department\t\t:\t"<<dept->get_name()<<endl;
    cout<<"Projects count\t\t\t:\t"<<proj_count<<endl;
    cout<<"----------------------------------------"<<endl;
}
bool employee::add_project(project*pro){
    int i;
    for(i=0;i<3;i++)
        if(proj[i]==nullptr){
            proj[i]=pro;
            proj_count++;
            proj[i]->inc_emp_count();
            cout<<"<----project added successfully---->"<<endl;
            proj[i]->assign_to_employee(this);
            return true;
        }
    cout<<"<----project cant be added---->"<<endl;
    return false; 
}
bool employee::remove_project(int proj_id){
    int i;
    for(i=0;i<3;i++){
        if(proj[i]!=nullptr)
            if(proj_id==proj[i]->get_id()){
                proj[i]->dec_emp_count();
                proj[i]->remove_employee(id);
                proj[i]=nullptr;
                proj_count--;
                cout<<"<----project removed successfully---->"<<endl;
                return true;
            }
    }
    cout<<"<----project is not found---->"<<endl;
    return false;
}
void employee::display_project(){
    cout<<"\n<--------All Projects info------->\n"<<endl;
    for(int i=0;i<3;i++){
        if(proj[i]!=nullptr){
            cout<<"project "<<i+1<<endl;
            proj[i]->display_info();
        }
    }
}
void employee::set_assigned_to_dept(bool val){
    this->assigned_to_dept=val;
    if(val)
        cout<<"<---Employee assigned to department--->"<<endl;
    else {
        cout<<"<---Employee removed from department--->"<<endl;
    }
}
bool employee::set_dept(department* d){
    if(dept){
        set_assigned_to_dept(false);
        return false;
    }
    dept=d;
    set_assigned_to_dept(true);
    return true;
}
bool employee::remove_dept(){
    if(dept){
    dept=nullptr;
    set_assigned_to_dept(false);
    return true;
    }
    return false;
}
employee::~employee(){}












//department class implementation
//constructors
department::department():id(0),name(),emp_count(0){
    for(int i=0;i<20;i++)
        emp[i]=nullptr;
}
department::department(int i,int x,char* y):id(i),name(x,y),emp_count(0)
{
    for(int i=0;i<20;i++)
        emp[i]=nullptr;
}
string department::get_name(){
    string s;
    for(int i=0;i<name.get_size();i++){
        s=s+name.get_char()[i];
    }
    s=s+'\0';
    return s;
}
//display
void department::display_dept_info(){
    cout<<"\n<----------Department info-------------->\n"<<endl;
    cout<<"Department ID\t\t\t:\t"<<id<<endl;
    cout<<"Department name\t\t\t:\t";
    name.display();
    cout<<"No.of Employees\t\t\t:\t"<<emp_count<<endl;
    cout<<"-------------------------------------------"<<endl;
}
bool department::add_employee(employee*em){
    int i;
    for(i=0;i<20;i++){
        if(emp[i]==nullptr){
            emp[i]=em;
            emp_count++;
            emp[i]->set_dept(this);
            return true;
        }
    }
    cout<<"<---no vacant space for employee--->"<<endl;
    return false;   
}
bool department::remove_emp(int emp_id){
    int i;
    for(i=0;i<20;i++){
        if(emp[i]!=nullptr)
            if(emp[i]->get_id()==emp_id){
                emp[i]->remove_dept();
                emp[i]=nullptr;
                emp_count--;
                return true;
            }
    }
    cout<<"<-----Employee not found----->"<<endl;
    return false;
}
void department::display_emp(){
    cout<<"<-----------------All employees info in department------------------>"<<endl;
    cout<<"-------------------------------------------------------------"<<endl;
    for(int i=0;i<20;i++)
        if(emp[i]){
            cout<<"Employee "<<i+1<<endl;
            emp[i]->display_employee_info();
        }
    cout<<"--------------------------------------------------------------"<<endl;
}
int department::get_id(){return id;}
//destructor
department::~department(){}







int main(){
    Company company;
    cout<<"<------------------------------------- Menu --------------------------------------------->"<<endl<<endl;
    cout<<"To add employee:        1\t\t\tTo assign employee to department:     7"<<endl;
    cout<<"To add project:         2\t\t\tTo assign project to employee:        8"<<endl;
    cout<<"To add department:      3\t\t\tTo remove project from employee:      9"<<endl;
    cout<<"To display projects:    4\t\t\tTo remove employee from department:  10"<<endl;
    cout<<"To display employees:   5\t\t\tTo display all projects of employee: 11"<<endl;
    cout<<"To display departments: 6\t\t\tTo display all employees on project: 12"<<endl;
    cout<<"To display all employees of department: 13"<<endl<<endl;
    cout<<"<---------------------------------------------------------------------------------------->"<<endl<<endl;
    cout<<"Enter the total number of operations you want to perform :";
    int op;
    cin>>op;
    while(op--){
        int num;
        cout<<"Enter the number for specific operation you want to perform : ";
        do{
            cin>>num;
            if(num<1 || num>13)
                cout<<"Enter valid input : ";
        }while(num<1||num>13);
        if(num==1){
            int i,h,s;
            char c;
            float sal;
            string n,cit;
            cout<<"Enter Employee ID :";
            cin>>i;
            cout<<"Enter Employee name : ";
            cin.ignore();
            getline(cin,n);
            cout<<"Enter Employee's house number : ";
            cin>>h;
            cout<<"Enter Employee's Block number : ";
            cin>>c;
            cout<<"Enter Employee's street number : ";
            cin>>s;
            cin.ignore();
            cout<<"Enter Employee's city : ";
            getline(cin,cit);
            cout<<"Enter Employee's salary : ";
            cin>>sal;
            company.add_employee(i,n.length(),&n[0],h,c,s,cit.length(),&cit[0],sal);
        }
        else if(num==2){
            int id;
            string des;
            cout<<"Enter project ID : ";
            cin>>id;
            cout<<"Enter project description : ";
            cin.ignore();
            getline(cin,des);
            company.add_project(id,des.length(),&des[0]);            
        }
        else if(num==3){
            int id;
            string name;
            cout<<"Enter Department ID : ";
            cin>>id;
            cout<<"Enter Department name : ";
            cin.ignore();
            getline(cin,name);
            company.add_department(id,name.length(),&name[0]);
        }
        else if(num==4){
            company.display_projects();
        }
        else if(num==5){
            company.display_employees();
        }
        else if(num==6){
            company.display_departments();
        }
        else if(num==7){
            int eid,did;
            cout<<"Enter Departement ID : ";
            cin>>did;
            cout<<"Enter employee ID : ";
            cin>>eid;
            company.assign_employee_to_department(did,eid);
        }
        else if(num==8){
            int eid,pid;
            cout<<"Enter employee ID : ";
            cin>>eid;
            cout<<"Enter project ID : ";
            cin>>pid;
            company.assign_project_to_employee(eid,pid);
        }
        else if(num==9){
            int eid,pid;
            cout<<"Enter employee ID : ";
            cin>>eid;
            cout<<"Enter project ID : ";
            cin>>pid;
            company.remove_project_from_employee(eid,pid);
        }
        else if(num==10){
            int eid,did;
            cout<<"Enter Departement ID : ";
            cin>>did;
            cout<<"Enter employee ID : ";
            cin>>eid;
            company.remove_employee_from_department(did,eid);
        }
        else if(num==11){
            int eid;
            cout<<"Enter Employee ID : ";
            cin>>eid;
            company.display_all_projects_Of_employee(eid);
        }
        else if(num==12){
            int pid;
            cout<<"Enter Project ID : ";
            cin>>pid;
            company.display_all_employees_on_proj(pid);
        }
        else{
            int did;
            cout<<"Enter department ID : ";
            cin>>did;
            company.display_all_employees_of_dept(did);
        }
    }
}


