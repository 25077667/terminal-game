#include <functional>
#include <random>
#include <vector>
#include "skillSet.hpp"

unsigned int genRandom() {
    std::random_device rd;
    std::mt19937_64 mt_rand(rd());
    return mt_rand();
}

class Object::Role {
   public:
    Role(int _row, int _column, int _length = 1, int _width = 1) : length(_length), width(_width) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }
    Role(Place _coordination, int _length = 1, int _width = 1) : coordinates(_coordination), length(_length), width(_width) {}
    Role(const Role &_role) {
        this->length = _role.length;
        this->width = _role.width;
        this->coordinates = _role.coordinates;
    }
    ~Role();
    void actionEffect();
    //void sync();
    const int getLength() { return this->length; }
    const int getWidth() { return this->width; }
    void setCorrdinates(int row, int column) {
        this->coordinates.row = row;
        this->coordinates.column = column;
    }
    Place getCorrdinates() {
        return this->coordinates;
    }

   protected:
    int length, width;
    Place coordinates;
};

class Object::Item : public Role {
   public:
    Item(int _row, int _column, int _color, int _length = 1, int _width = 1) : Role(_row, _column, _length, _width), color(_color) {}
    ~Item();
    const int getColor() const { return this->color; }
    void setColor(int _color) { this->color = _color; }
    void moveTo(int _row, int _column) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }

   private:
    int color;
};

class Object::People : public Role {
   public:
    People(Role _base, int _hp, int _atk, int _def, int _att) : Role(_base), hp(_hp), attack(_atk), defense(_def), attribute(_att) {
        generateID();
    }
    People(const People &_base) : Role(_base.getRole()) {
        this->hp = _base.hp;
        this->attack = _base.attack;
        this->defense = _base.defense;
        this->attribute = _base.attribute;
        generateID();
    }
    ~People();

    const int getHP() { return this->hp; }
    const int getATK() { return this->attack; }
    const int getDEF() { return this->defense; }
    const int getAttribute() { return this->attribute; }
    const unsigned int getID() { return this->id; }
    const Role getRole() const { return Role(this->coordinates, this->width, this->length); }

    void setHP(int _hp) { this->hp = _hp; }
    void setATK(int _atk) { this->attack = _atk; }
    void setDEF(int _def) { this->defense = _def; }
    void setAttribite(int _att) { this->attribute = _att; }

    void minusHP(const int value) { this->hp -= value; }
    void virtual skill();
    const char **getSkin();
    void moveTo(int _row, int _column) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }

   private:
    void generateID() {
        unsigned int r = genRandom();
        std::hash<unsigned int> int_hash;
        this->id = int_hash(this->hp) + int_hash(this->attack) + int_hash(this->defense) + int_hash(this->attack) + int_hash(r);
    }

   protected:
    int hp, attack, defense, attribute;
    unsigned int id;
    char **skin;
};

class Object::Enemy : public People {
   public:
    Enemy(People _base, int _skillID = 0) : People(_base), skillID(_skillID) {}
    ~Enemy();  //drop bonus
    void virtual skill() {
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

   private:
    int skillID;
};

class Object::Me : public People {
   public:
    Me(const People _base, int _skillID) : People(_base), skillID(_skillID) {}
    ~Me();
    void boost();
    void virtual skill() {
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
    void touch() {}  //listing everytime

   private:
    int skillID;
};

class Object::Teammate : public People {
   public:
    Teammate(const People _base, int _skillID) : People(_base), skillID(_skillID) {}
    ~Teammate();
    void virtual skill() {
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

   private:
    int skillID;
};