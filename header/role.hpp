// there is many role in this game
// Our role, enemy and other bonus item
// maybe have some friends? or competitor?
//
#ifndef ROLE_HPP
#define ROLE_HPP
#include <functional>
#include <random>
#include <vector>
#include "skillSet.hpp"

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
    Role(int _row, int _column, int _length = 1, int _width = 1);
    Role(Place _coordination, int _length = 1, int _width = 1);
    Role(const Role &_role);
    ~Role();
    void actionEffect();
    //void sync();
    const int getLength();
    const int getWidth();
    void setCorrdinates(int row, int column);
    Place getCorrdinates();

   protected:
    int length, width;
    Place coordinates;
};

class Item : public Role {
   public:
    Item(int _row, int _column, int _color, int _length = 1, int _width = 1);
    ~Item();
    const int getColor() const;
    void setColor(int _color);
    void moveTo(int _row, int _column);

   private:
    int color;
};

class People : public Role {
   public:
    People(Role _base, int _hp, int _atk, int _def, int _att);
    People(const People &_base) : Role(_base.getRole());
    ~People();

    const int getHP();
    const int getATK();
    const int getDEF();
    const int getAttribute();
    const unsigned int getID();
    const Role getRole() const;

    void setHP(int _hp);
    void setATK(int _atk);
    void setDEF(int _def);
    void setAttribite(int _att);

    void minusHP(const int value);
    void virtual skill();
    const char **getSkin();
    void moveTo(int _row, int _column);

   private:
    void generateID();

   protected:
    int hp, attack, defense, attribute;
    unsigned int id;
    char **skin;
};

class Enemy : public People {
   public:
    Enemy(People _base, int _skillID = 0);
    ~Enemy();  //drop bonus
    void virtual skill();

   private:
    int skillID;
};

class Me : public People {
   public:
    Me(const People _base, int _skillID);
    ~Me();
    void boost();
    void virtual skill();
    void touch();

   private:
    int skillID;
};

class Teammate : public People {
   public:
    Teammate(const People _base, int _skillID);
    ~Teammate();
    void virtual skill();

   private:
    int skillID;
};
}  // namespace Object

#endif