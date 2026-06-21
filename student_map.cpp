#include "student_map.h"
#include <stdexcept>

StudentMap::StudentMap() {
    table = new Node*[TABLE_SIZE]();
}
int StudentMap::hash(int student_id) const {
    return student_id % TABLE_SIZE;
}
void StudentMap::add_student(int student_id, int score) {
    int index = hash(student_id);
    Node* new_node = new Node(student_id, score);
    new_node->next = table[index];
    table[index] = new_node;
}
void StudentMap::update_score(int student_id, int new_score) {
    int index = hash(student_id);
    Node* current = table[index];
    while (current) {
        if (current->student_id == student_id) {
            current->score = new_score;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error("Student ID not found");
}
int StudentMap::get_score(int student_id) const {
    int index = hash(student_id);
    Node* current = table[index];
    while (current) {
        if (current->student_id == student_id) {
            return current->score;
        }
        current = current->next;
    }
    throw std::runtime_error("Student ID not found");
}
void StudentMap::remove_student(int student_id) {
    int index = hash(student_id);
    Node* current = table[index];
    Node* prev = nullptr;
    while (current) {
        if (current->student_id == student_id) {
            if (prev) {
                prev->next = current->next;
            } else {
                table[index] = current->next;
            }
            delete current;
            return;
        }
        current = current->next;
    }
    throw std::runtime_error("Student ID not found");
}
StudentMap::~StudentMap() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
    delete[] table;
}