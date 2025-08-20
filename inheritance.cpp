#include <iostream.h>
#include <conio.h>
#include <string.h>

class Employee {
protected:
    char Emp_name[50], Address[100], Mail_id[50];
    int Emp_id;
    long Mobile_no;

public:
    void getEmployeeDetails() {
        cout << "Enter Employee Name: ";
        cin >> Emp_name;
        cout << "Enter Employee ID: ";
        cin >> Emp_id;
        cout << "Enter Address: ";
        cin >> Address;
        cout << "Enter Mail ID: ";
        cin >> Mail_id;
        cout << "Enter Mobile Number: ";
        cin >> Mobile_no;
    }

    void displayEmployeeDetails() {
        cout << "\nEmployee Name : " << Emp_name;
        cout << "\nEmployee ID   : " << Emp_id;
        cout << "\nAddress       : " << Address;
        cout << "\nMail ID       : " << Mail_id;
        cout << "\nMobile No     : " << Mobile_no;
    }
};

class Pay {
protected:
    float BP, DA, HRA, PF, SCF, gross, net;

public:
    void getPayDetails() {
        cout << "Enter Basic Pay (BP): ";
        cin >> BP;

        DA  = 0.97 * BP;
        HRA = 0.10 * BP;
        PF  = 0.12 * BP;
        SCF = 0.001 * BP;
        gross = BP + DA + HRA;
        net   = gross - (PF + SCF);
    }

    void displayPaySlip() {
        cout << "\nBasic Pay        : " << BP;
        cout << "\nDA (97%)         : " << DA;
        cout << "\nHRA (10%)        : " << HRA;
        cout << "\nPF (12%)         : " << PF;
        cout << "\nStaff Club Fund  : " << SCF;
        cout << "\nGross Salary     : " << gross;
        cout << "\nNet Salary       : " << net;
    }
};

class AssistantProfessor : public Employee, public Pay {
public:
    void process() {
        cout << "\n--- Assistant Professor Details ---\n";
        getEmployeeDetails();
        getPayDetails();
    }
    void show() {
        displayEmployeeDetails();
        displayPaySlip();
    }
};

class AssociateProfessor : public Employee, public Pay {
public:
    void process() {
        cout << "\n--- Associate Professor Details ---\n";
        getEmployeeDetails();
        getPayDetails();
    }
    void show() {
        displayEmployeeDetails();
        displayPaySlip();
    }
};

class Professor : public Employee, public Pay {
public:
    void process() {
        cout << "\n--- Professor Details ---\n";
        getEmployeeDetails();
        getPayDetails();
    }
    void show() {
        displayEmployeeDetails();
        displayPaySlip();
    }
};

int main() {
    clrscr(); 
    AssistantProfessor ap;
    AssociateProfessor asp;
    Professor p;

    ap.process();
    ap.show();

    asp.process();
    asp.show();

    p.process();
    p.show();

    getch(); 
    return 0;
}