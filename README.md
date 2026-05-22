# Company Management System

A comprehensive C++ application designed to manage company operations efficiently. This system handles employee management, department organization, project tracking, and employee-project assignments with full CRUD operations.

## 🎯 Features

- **Employee Management**: Add, remove, update, search, and display employee records
- **Department Management**: Create and manage company departments
- **Project Management**: Track projects and manage project assignments
- **Employee-Department Assignment**: Assign employees to departments
- **Employee-Project Assignment**: Allocate employees to specific projects
- **Search Functionality**: Search employees by ID, name, or department
- **Report Generation**: Generate comprehensive reports on:
  - All employees and their details
  - Department structure and hierarchy
  - Project assignments
  - Employee workload distribution
- **Data Persistence**: File-based storage for all company data

## 🛠️ Technology Stack

- **Language**: C++
- **Data Storage**: File-based system (text files)
- **Build System**: Standard C++ compiler (g++, clang, MSVC)
- **Data Structures**: Vectors, Maps, Structs

## 📁 Project Structure

```
Company-management-system/
├── src/
│   ├── main.cpp
│   ├── Employee.cpp/h
│   ├── Department.cpp/h
│   ├── Project.cpp/h
│   ├── Company.cpp/h
│   └── Assignment.cpp/h
├── data/
│   ├── employees.txt
│   ├── departments.txt
│   ├── projects.txt
│   └── assignments.txt
└── README.md
```

## 🚀 Getting Started

### Prerequisites

- C++ compiler (C++11 or higher)
- Standard C++ Library
- Text editor or IDE

### Compilation

```bash
g++ -std=c++11 -o company-system src/*.cpp
```

### Running the Application

```bash
./company-system
```

## 💻 Main Menu

The application provides an interactive menu:

```
=== Company Management System ===
1. Add Employee
2. Remove Employee
3. Search Employee
4. List All Employees
5. Add Department
6. List All Departments
7. Add Project
8. List All Projects
9. Assign Employee to Department
10. Assign Employee to Project
11. View Employee Details
12. Generate Reports
13. Exit
```

## 📊 Core Operations

### Employee Management

**Add Employee:**
- Employee ID, Full Name, Email, Phone, Position, Salary
- Automatic validation to prevent duplicate IDs

**Search Employee:**
- Search by ID, Name, or Department
- Display detailed employee information

**Update Employee:**
- Modify employee details (salary, position, contact info)
- Maintain employment history

### Department Management

**Create Department:**
- Department ID, Name, Budget, Manager
- Set department description and goals

**View Department:**
- List all departments with details
- View department members

### Project Management

**Create Project:**
- Project ID, Name, Description, Budget, Timeline
- Set project deadlines and objectives

**Assign Employees:**
- Link employees to projects
- Track resource allocation

## 🔧 Class Structure

### Employee Class
```cpp
class Employee {
    int id;
    string name;
    string email;
    string phone;
    string position;
    double salary;
};
```

### Department Class
```cpp
class Department {
    int id;
    string name;
    double budget;
    string manager;
};
```

### Project Class
```cpp
class Project {
    int id;
    string name;
    string description;
    double budget;
    string deadline;
};
```

### Company Class
```cpp
class Company {
    vector<Employee> employees;
    vector<Department> departments;
    vector<Project> projects;
    // CRUD operations
};
```

## 📈 Features in Detail

### Advanced Operations

- **Bulk Operations**: Import/export employee data
- **Department Hierarchy**: Manage reporting structure
- **Project Tracking**: Monitor project progress and team allocation
- **Resource Management**: Track budgets and allocations
- **Conflict Detection**: Prevent duplicate assignments
- **Audit Trail**: Log all major operations

### Reports

- **Employee Report**: Complete list of all employees with roles
- **Department Report**: Department structure and member count
- **Project Report**: Active projects and team composition
- **Budget Report**: Expenditure vs. allocated budget
- **Workload Report**: Employee assignments and capacity

## 💾 Data Storage

The system persists data using text files:
- **employees.txt**: Employee records
- **departments.txt**: Department information
- **projects.txt**: Project details
- **assignments.txt**: Employee-Project and Employee-Department links

## ⚙️ Configuration

Customize system behavior:

```cpp
const int MAX_EMPLOYEES = 1000;
const int MAX_DEPARTMENTS = 50;
const int MAX_PROJECTS = 100;
const double MIN_SALARY = 20000.0;
const double MAX_SALARY = 500000.0;
```

## 🎓 Usage Examples

### Example 1: Add an Employee
```
1. Select "Add Employee"
2. Enter Employee ID: 101
3. Enter Name: John Doe
4. Enter Email: john.doe@company.com
5. Enter Phone: +1-555-0123
6. Enter Position: Senior Developer
7. Enter Salary: 95000
```

### Example 2: Create a Department
```
1. Select "Add Department"
2. Enter Department ID: 10
3. Enter Name: Engineering
4. Enter Budget: 500000
5. Enter Manager: Jane Smith
```

### Example 3: Create a Project
```
1. Select "Add Project"
2. Enter Project ID: P001
3. Enter Name: Website Redesign
4. Enter Description: Redesign company website
5. Enter Budget: 50000
6. Enter Deadline: 2024-12-31
```

## 🔒 Data Validation

The system implements comprehensive validation:
- ID uniqueness checks
- Email format validation
- Phone number format validation
- Salary range validation
- Budget constraints
- Duplicate assignment prevention

## 🚀 Future Enhancements

- [ ] Database integration (MySQL/PostgreSQL)
- [ ] GUI interface using Qt or wxWidgets
- [ ] Role-based access control (Admin, Manager, Employee)
- [ ] Performance analytics and dashboards
- [ ] Integration with HR systems
- [ ] Payroll calculation module
- [ ] Advanced reporting with charts
- [ ] Email notifications for assignments
- [ ] Mobile app integration
- [ ] Real-time collaboration features

## 🐛 Troubleshooting

**Issue**: Application crashes on startup
- **Solution**: Ensure all data files exist in the data/ directory

**Issue**: Cannot save employee
- **Solution**: Check disk space and file permissions

**Issue**: Duplicate employee ID error
- **Solution**: Use unique employee IDs

## 📝 Performance

- Employee operations: O(n) average
- Search operations: O(n) linear search
- Sorting operations: O(n log n)
- File I/O: Optimized for standard file operations

## 🤝 Best Practices

- Perform regular backups of data files
- Validate all user input before processing
- Keep audit logs for compliance
- Document all custom modifications
- Test thoroughly before production use

## 📄 License

This project is open source and available for educational purposes.

## 👤 Author

Iraj Fatima

## 📞 Support

For issues, questions, or suggestions, please open an issue on GitHub.

---

**Manage Your Company Efficiently!** 🏢
