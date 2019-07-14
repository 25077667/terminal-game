#include "role.hpp"

namespace TeamSkill {
void noneSkill() {
}
void addHp((*Object::People) & current, std::vector<double>& argvs) {
    current->setHp(current->getHp() + argvs.at(0));
}
}  // namespace TeamSkill
namespace EnemySkill {
void noneSkill() {
}
void addHp((*Object::People) & current, std::vector<double>& argvs) {
    current->setHp(current->getHp() + argvs.at(0));
}
}  // namespace EnemySkill