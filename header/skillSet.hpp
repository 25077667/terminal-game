#ifndef SKILLSET_HPP
#define SKILLSET_HPP
#include <vector>
#include "role.hpp"

namespace TeamSkill {
void noneSkill(Object::People& _this, std::vector<unsigned int>& argvs) {
}
void addHp(Object::People& _this, std::vector<unsigned int>& argvs) {
    _this.setHP(_this.getHP() + argvs.at(1));
}
void minusHP(Object::People& _this, std::vector<unsigned int>& argvs){
    _this.setHP(_this.getHP()-argvs.at(1));
}
}  // namespace TeamSkill

namespace EnemySkill {
void noneSkill(Object::People& _this, std::vector<unsigned int>& argvs) {
}
void addHp(Object::People& _this, std::vector<unsigned int>& argvs) {
    _this.setHP(_this.getHP() + argvs.at(1));
}
void minusHP(Object::People& _this, std::vector<unsigned int>& argvs) {
    _this.setHP(_this.getHP() - argvs.at(1));
}
}  // namespace EnemySkill

#endif