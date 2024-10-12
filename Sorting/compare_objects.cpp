#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Define a custom struct
struct Student
{
    std::string name;
    int age;
};

// Comparator function to sort by age
bool compareByAge(const Student &a, const Student &b)
{
    return a.age < b.age; // Ascending order
}

int main()
{
    std::vector<Student> students = {
        {"Alice", 22}, {"Bob", 18}, {"Charlie", 20}};

    // Sort students by age
    std::sort(students.begin(), students.end(), compareByAge);

    // Print the sorted students
    for (const auto &student : students)
    {
        std::cout << student.name << " (" << student.age << ")\n";
    }

    return 0;
}
