#ifndef STUDENT_ORDERED_MAP_H
#define STUDENT_ORDERED_MAP_H

#include <cstdlib>
#include <stdexcept>

class StudentOrderedMap {
public:
    struct Node {
        int student_id;
        int score;
        Node** next;

        Node(int student_id, int score, int level)
            : student_id(student_id), score(score), next(new Node*[level]()) {}
        ~Node() { delete[] next; }
    };

    StudentOrderedMap();
    void add_student(int student_id, int score);
    void update_score(int student_id, int new_score);
    int get_student(int score) const;
    void remove_student(int student_id);
    ~StudentOrderedMap();

    Node* head;

private:
    int max_level;
    double probability;
    int level;

    int random_level() const;
    Node* find_predecessor(int student_id, Node** update) const;
};

#endif