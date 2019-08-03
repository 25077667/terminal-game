// there is many role in this game
// Our role, enemy and other bonus item
// maybe have some friends? or competitor?
//
#ifndef ROLE_HPP
#define ROLE_HPP
#include <functional>
#include <random>
#include <vector>
//#include "skillSet.hpp"

unsigned int genRandom() {
    std::random_device rd;
    std::mt19937_64 mt_rand(rd());
    return mt_rand();
}

namespace Object {

typedef struct {
    int row, column;
} Place;

class Role {
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

class Item : public Role {
   public:
    Item(int _row, int _column, int _color, int _attribute, int _vlaue, int _length = 1, int _width = 1)
        : Role(_row, _column, _length, _width) {
        setColor(_color);
        setAttribute(_attribute);
        setValue(_vlaue);
    }
    ~Item() {}
    const int getColor() const { return this->color; }
    const int getAttribute() const { return this->attribute; }
    const int getValue() const { return this->value; }
    void setColor(int _color) { this->color = _color; }
    void setAttribute(int _attribute) { this->attribute = _attribute; }
    void setValue(int _value) { this->value = _value; }
    void moveTo(int _row, int _column) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }

   private:
    int color, attribute, value;
};

class People : public Role {
   public:
    People(Role _base, int _hp, unsigned int _atk, unsigned int _def, unsigned int _att)
        : Role(_base), hp(_hp), attack(_atk), defense(_def), attribute(_att) {
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
    const unsigned int getATK() { return this->attack; }
    const unsigned int getDEF() { return this->defense; }
    const unsigned int getAttribute() { return this->attribute; }
    const unsigned int getID() { return this->id; }
    const Role getRole() const { return Role(this->coordinates, this->width, this->length); }

    void setHP(int _hp) { this->hp = _hp; }
    void setATK(unsigned int _atk) { this->attack = _atk; }
    void setDEF(unsigned int _def) { this->defense = _def; }
    void setAttribite(unsigned int _att) { this->attribute = _att; }

    void virtual skill(std::vector<unsigned int> &argvs);
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
    int hp;
    unsigned int id, attack, defense, attribute;
    char **skin;
};

class Enemy : public People {
   public:
    Enemy(People _base) : People(_base) {}
    ~Enemy() {}  //drop bonus
    void virtual skill(std::vector<unsigned int> &argvs);
};

class Me : public People {
   public:
    Me(const People _base);
    ~Me() {}
    void boost();
    void virtual skill(std::vector<unsigned int> &argvs);
    void whileTouch(Object::Item &);
};

class Teammate : public People {
   public:
    Teammate(const People _base) : People(_base) {}
    ~Teammate() {}
    void virtual skill(std::vector<unsigned int> &argvs);
};
}  // namespace Object

#endif