#include "student_database.h"
#include <stdexcept>
#include <iostream>

void StudentDatabase::add_student(int student_id, int score) {
    try {
        map.get_score(student_id);
        throw std::runtime_error("Student ID already exists");
    } catch (const std::runtime_error&) {
        map.add_student(student_id, score);
        ordered_map.add_student(student_id, score);
    }
}
void StudentDatabase::update_score(int student_id, int new_score) {
    try {
        int old_score = map.get_score(student_id);
        map.update_score(student_id, new_score);
        ordered_map.update_score(student_id, new_score);
    } catch (const std::runtime_error&) {
        std::cerr;
    }
}
int StudentDatabase::get_score(int student_id) const {
    return map.get_score(student_id);
}
int StudentDatabase::get_student(int score) const {
    try {
        return ordered_map.get_student(score);
    } catch (const std::runtime_error&) {
        throw std::runtime_error("Score not found");
    }
}
void StudentDatabase::remove_student(int student_id) {
    try {
        map.get_score(student_id);
        map.remove_student(student_id);
        ordered_map.remove_student(student_id);
    } catch (const std::runtime_error&) {
        std::cerr;
    }
}
int** StudentDatabase::get_top_k_students(int k) {
    int** result = new int*[k];
    for (int i = 0; i < k; ++i) {
        result[i] = new int[2]{-1, -1};
    }
    StudentOrderedMap::Node* current = ordered_map.head->next[0];
    int index = 0;
    while (current && index < k) {
        result[index][0] = current->student_id;
        result[index][1] = current->score;
        current = current->next[0];
        index++;
    }
    return result;
}
int StudentDatabase::get_rank(int score) const {
    StudentOrderedMap::Node* current = ordered_map.head->next[0];
    int rank = 1;
    while (current) {
        if (current->score == score) {
            return rank;
        }
        if (!current->next[0] || current->score != current->next[0]->score) {
            rank++;
        }
        current = current->next[0];
    }
    throw std::runtime_error("Score not found");
}