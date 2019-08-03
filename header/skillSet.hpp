#ifndef SKILLSET_HPP
#define SKILLSET_HPP
#include <vector>
#include "role.hpp"

namespace TeamSkill {
void noneSkill(Object::People& current, std::vector<double>& argvs) {
}
void addHp(Object::People& current, std::vector<double>& argvs) {
    current.setHP(current.getHP() + argvs.at(0));
}
}  // namespace TeamSkill

namespace EnemySkill {
void noneSkill(Object::People& current, std::vector<double>& argvs) {
}
void addHp(Object::People& current, std::vector<double>& argvs) {
    current.setHP(current.getHP() + argvs.at(0));
}
}  // namespace EnemySkill

#endif