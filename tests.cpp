#include "people.hpp"

#include <iostream>
#include <sstream>
#include <stdexcept>

void expect(bool condition) {
    if (!condition) throw std::runtime_error("Test failed");
}

std::string describe(const Person& person) {
    std::ostringstream output;
    person.output(output);
    return output.str();
}

int main() {
    try {
        expect(describe(Person("Roman")) == "Name: Roman\n");
        expect(describe(Learner("Roman", "LUTE")) == "Name: Roman\nInstitution: LUTE\n");
        expect(describe(Schoolchild("Anna", "School 1", 9)) ==
               "Name: Anna\nInstitution: School 1\nGrade: 9\n");
        expect(describe(Student("Roman", "LUTE", 2)) ==
               "Name: Roman\nInstitution: LUTE\nCourse: 2\n");

        Person person;
        Learner learner;
        Schoolchild schoolchild;
        Student student;
        expect(describe(schoolchild) == "Name: \nInstitution: \nGrade: 0\n");
        expect(describe(student) == "Name: \nInstitution: \nCourse: 0\n");

        std::istringstream input("\"John Smith\" \"Anna Brown\" \"School 2\" \"Olena\" \"School 3\" 7 \"Roman\" \"Lviv University\" 3");
        expect(static_cast<bool>(input >> person >> learner >> schoolchild >> student));
        expect(describe(person) == "Name: John Smith\n");
        expect(describe(learner) == "Name: Anna Brown\nInstitution: School 2\n");
        expect(describe(schoolchild) == "Name: Olena\nInstitution: School 3\nGrade: 7\n");
        expect(describe(student) == "Name: Roman\nInstitution: Lviv University\nCourse: 3\n");

        std::istringstream invalid("Roman LUTE abc");
        expect(!(invalid >> student));
        std::istringstream incomplete("Anna");
        expect(!(incomplete >> schoolchild));
        std::cout << "All tests passed\n";
    } catch (const std::exception& error) {
        std::cerr << error.what() << '\n';
        return 1;
    }
}
