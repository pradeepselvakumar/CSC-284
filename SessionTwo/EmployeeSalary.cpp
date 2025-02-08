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
