#include <functional>
#include <random>
#include <vector>
#include "skillSet.hpp"
#define ADD_SCORE_PROP 1
#define MINUS_SCORE_PROP 2

/*
* argvs 0 skill ID
* argvs 1 skill parameter
...
*/

void Object::Enemy::skill(std::vector<unsigned int>& argvs) {
    void (*doSkill)(Object::People & _this, std::vector<unsigned int> & argvs) = nullptr;

    switch (argvs.at(0)) {
        case 0:
            doSkill = EnemySkill::noneSkill;
            break;
        case 1:
            doSkill = EnemySkill::addScore;
            break;
        default:
            doSkill = TeamSkill::noneSkill;
            break;
    }
    doSkill(*this, argvs);
}

void Object::Me::boost() {}
void Object::Me::skill(std::vector<unsigned int>& argvs) {
    void (*doSkill)(Object::People & _this, std::vector<unsigned int> & argvs) = nullptr;

    switch (argvs.at(0)) {
        case 0:
            doSkill = TeamSkill::noneSkill;
            break;
        case 1:
            doSkill = TeamSkill::addScore;
            break;
        default:
            doSkill = TeamSkill::noneSkill;
            break;
    }

    doSkill(*this, argvs);
}
void Object::Me::whileTouch(Object::Item& _item) {
    std::vector<unsigned int> skillArgvs;
    switch (_item.getAttribute()) {
        case ADD_SCORE_PROP:
            skillArgvs.push_back(1);
            skillArgvs.push_back(_item.getValue());
            this->skill(skillArgvs);
        case MINUS_SCORE_PROP:
            skillArgvs.push_back(2);
            skillArgvs.push_back(_item.getValue());
            this->skill(skillArgvs);
        default:
            // minus blood
            skillArgvs.push_back(2);
            skillArgvs.push_back(10);
            this->skill(skillArgvs);
            break;
    }
    _item.~Item();
}

void Object::Teammate::skill(std::vector<unsigned int>& argvs) {
    void (*doSkill)(Object::People & _this, std::vector<unsigned int> & argvs) = nullptr;

    switch (argvs.at(0)) {
        case 0:
            doSkill = TeamSkill::noneSkill;
            break;
        case 1:
            doSkill = TeamSkill::addScore;
            break;
        default:
            doSkill = TeamSkill::noneSkill;
            break;
    }
    doSkill(*this, argvs);
}
