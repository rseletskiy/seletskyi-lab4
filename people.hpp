#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

class Person {
    std::string name;

public:
    explicit Person(std::string name = "") : name(std::move(name)) {}
    virtual ~Person() = default;

    friend std::istream& operator>>(std::istream& input, Person& person) {
        return input >> std::quoted(person.name);
    }

    virtual void output(std::ostream& output = std::cout) const {
        output << "Name: " << name << '\n';
    }
};

class Learner : public Person {
    std::string institution;

public:
    Learner(std::string name = "", std::string institution = "")
        : Person(std::move(name)), institution(std::move(institution)) {}

    friend std::istream& operator>>(std::istream& input, Learner& learner) {
        return input >> static_cast<Person&>(learner) >> std::quoted(learner.institution);
    }

    void output(std::ostream& output = std::cout) const override {
        Person::output(output);
        output << "Institution: " << institution << '\n';
    }
};

class Schoolchild : public Learner {
    int grade;

public:
    Schoolchild(std::string name = "", std::string institution = "", int grade = 0)
        : Learner(std::move(name), std::move(institution)), grade(grade) {}

    friend std::istream& operator>>(std::istream& input, Schoolchild& schoolchild) {
        return input >> static_cast<Learner&>(schoolchild) >> schoolchild.grade;
    }

    void output(std::ostream& output = std::cout) const override {
        Learner::output(output);
        output << "Grade: " << grade << '\n';
    }
};

class Student : public Learner {
    int course;

public:
    Student(std::string name = "", std::string institution = "", int course = 0)
        : Learner(std::move(name), std::move(institution)), course(course) {}

    friend std::istream& operator>>(std::istream& input, Student& student) {
        return input >> static_cast<Learner&>(student) >> student.course;
    }

    void output(std::ostream& output = std::cout) const override {
        Learner::output(output);
        output << "Course: " << course << '\n';
    }
};
