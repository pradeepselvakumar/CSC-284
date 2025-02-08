/*
Instructions
============
1. Identify repetitive logic in the code.
2. Refactor using an abstract base class (Employee) with 
   derived classes (SalariedEmployee, HourlyEmployee).
3. Use templates or base class pointers to handle multiple employee 
   types with reusable code.
4. Modify main() to use polymorphism or templates to print
   employee information without duplicating logic.
*/

import <iostream>;
import <string>;

// Function to calculate salary for a salaried employee
void printSalariedEmployeeInfo(const std::string& name, double salary) {
    std::cout << "Salaried Employee: " << name << "\n";
    std::cout << "Monthly Salary: $" << salary << "\n\n";
}

// Function to calculate salary for an hourly employee
void printHourlyEmployeeInfo(const std::string& name, double hourlyRate, int hoursWorked) {
    double totalPay = hourlyRate * hoursWorked;
    std::cout << "Hourly Employee: " << name << "\n";
    std::cout << "Total Pay: $" << totalPay << "\n\n";
}

int main() {
    printSalariedEmployeeInfo("Alice", 5000);
    printHourlyEmployeeInfo("Bob", 20, 160);

    return 0;
}
