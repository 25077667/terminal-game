#include <functional>
#include <random>
#include <vector>
#include "skillSet.hpp"

void Object::Enemy::skill() {
    void (*doSkill)((*People) &, std::vector<double> & argvs);
    std::vector<double> argvs;

    switch (this->skillID) {
        case 0:
            doSkill = EnemySkill::noneSkill;
            break;
        case 1:
            doSkill = EnemySkill::addHp;
            break;
        default:
            break;
    }
    doSkill(this, argvs);
}

void Object::Me::boost(){}
void Object::Me::skill() {
    void (*doSkill)((*People) &, std::vector<double> &);
    std::vector<double> argvs;

    switch (this->skillID) {
        case 0:
            doSkill = TeamSkill::noneSkill;
            break;
        case 1:
            doSkill = TeamSkill::addHp;
            break;
        default:
            break;
    }

    doSkill(this, argvs);
}
void Object::Me::touch() {}

void Object::Teammate::skill() {
    void (*doSkill)((*People) &, std::vector<double> &);
    std::vector<double> argvs;

    switch (this->skillID) {
        case 0:
            doSkill = TeamSkill::noneSkill;
            break;
        case 1:
            doSkill = TeamSkill::addHp;
            break;
        default:
            break;
    }
    doSkill(this, argvs);
}
