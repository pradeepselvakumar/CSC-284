int main() {
    // Using polymorphism with base class pointers
    std::vector<Employee*> employees;

    employees.push_back(new SalariedEmployee("Alice", 5000));
    employees.push_back(new HourlyEmployee("Bob", 20, 160));

    // Print all employee details using polymorphism
    for (const auto& emp : employees) {
        emp->printInfo();
    }

    return 0;
}