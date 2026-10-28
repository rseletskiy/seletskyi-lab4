#include "people.hpp"

int main() {
    Person person("Roman");
    Learner learner("Anna", "Learning Center");
    Schoolchild schoolchild("Olena", "School 1", 9);
    Student student("Ivan", "LUTE", 2);
    const Person* people[] = {&person, &learner, &schoolchild, &student};

    std::cout << "Initial data:\n";
    for (const Person* item : people) {
        item->output();
        std::cout << '\n';
    }

    std::cout << "Person: name\n";
    if (!(std::cin >> person)) return 1;
    std::cout << "Learner: name institution\n";
    if (!(std::cin >> learner)) return 1;
    std::cout << "Schoolchild: name institution grade\n";
    if (!(std::cin >> schoolchild)) return 1;
    std::cout << "Student: name institution course\n";
    if (!(std::cin >> student)) return 1;

    std::cout << "\nAfter input:\n";
    for (const Person* item : people) {
        item->output();
        std::cout << '\n';
    }
}
