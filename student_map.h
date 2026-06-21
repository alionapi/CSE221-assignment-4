#ifndef STUDENT_MAP_H
#define STUDENT_MAP_H

#include <stdexcept>

class StudentMap {
public:
    struct Node {
        int student_id;
        int score;
        Node* next;

        Node(int student_id, int score) : student_id(student_id), score(score), next(nullptr) {}
    };

    static const int TABLE_SIZE = 1000;

    StudentMap();
    void add_student(int student_id, int score);
    void update_score(int student_id, int new_score);
    int get_score(int student_id) const;
    void remove_student(int student_id);
    ~StudentMap();

private:
    Node** table;
    int hash(int student_id) const;
};

#endif