#include "student_ordered_map.h"
#include <cstdlib>
#include <stdexcept>
#include <iostream>
StudentOrderedMap::StudentOrderedMap() : max_level(16), probability(0.5) {
    head = new Node(-1, -1, max_level);
    level = 1;
}
StudentOrderedMap::~StudentOrderedMap() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next[0];
        delete temp;
    }
}
int StudentOrderedMap::random_level() const {
    int lvl = 1;
    while ((std::rand() / double(RAND_MAX)) < probability && lvl < max_level) {
        ++lvl;
    }
    return lvl;
}
void StudentOrderedMap::add_student(int student_id, int score) {
    Node* current = head;
    Node* update[max_level] = {nullptr};
    for (int i = level - 1; i >= 0; --i) {
        while (current->next[i] &&
               (current->next[i]->score < score ||
                (current->next[i]->score == score && current->next[i]->student_id < student_id))) {
            current = current->next[i];
        }
        update[i] = current;
    }
    int new_level = random_level();
    if (new_level > level) {
        for (int i = level; i < new_level; ++i) {
            update[i] = head;
        }
        level = new_level;
    }
    Node* new_node = new Node(student_id, score, new_level);
    for (int i = 0; i < new_level; ++i) {
        new_node->next[i] = update[i]->next[i];
        update[i]->next[i] = new_node;
    }
}
void StudentOrderedMap::update_score(int student_id, int new_score) {
    try {
        remove_student(student_id);
    } catch (const std::runtime_error& e) {
        std::cerr;
    }
    add_student(student_id, new_score);
}
int StudentOrderedMap::get_student(int score) const {
    Node* current = head;
    for (int i = level - 1; i >= 0; --i) {
        while (current->next[i] && current->next[i]->score < score) {
            current = current->next[i];
        }
    }
    current = current->next[0];
    if (current && current->score == score) {
        return current->student_id; // Return the student ID
    }
    throw std::runtime_error("Score not found");
}
void StudentOrderedMap::remove_student(int student_id) {
    Node* current = head;
    Node* update[max_level] = {nullptr};
    for (int i = level - 1; i >= 0; --i) {
        while (current->next[i] && current->next[i]->student_id < student_id) {
            current = current->next[i];
        }
        update[i] = current;
    }
    current = current->next[0];
    if (current && current->student_id == student_id) {
        for (int i = 0; i < level; ++i) {
            if (update[i]->next[i] == current) {
                update[i]->next[i] = current->next[i];
            }
        }
        delete current;
        while (level > 1 && !head->next[level - 1]) {
            --level;
        }
    } else {
        throw std::runtime_error("Student ID not found");
    }
}