//
// Created by Tommy on 2019-11-02.
//

#ifndef DATASTRUCTURE_CPP_STUDENT_H
#define DATASTRUCTURE_CPP_STUDENT_H

#include <iostream>
#include <string>
using namespace std;

struct  Student{
    string name;
    int score;
    bool operator<(const Student &other){
        return this->score != other.score ? this->score < other.score : this->name < other.name;
    }
    friend ostream&operator<<(ostream &os,const Student &student){
        os<<"Student: " << student.name << " " << student.score << endl;
        return os;
    }
};

#endif //DATASTRUCTURE_CPP_STUDENT_H
