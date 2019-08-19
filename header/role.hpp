// there is many role in this game
// Our role, enemy and other bonus item
// maybe have some friends? or competitor?
//
#ifndef ROLE_HPP
#define ROLE_HPP
#include <time.h>
#include <functional>
#include <random>
#include <string>
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
    ~Role(){}
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
    People() {
        setName();
        this->score = 0;
        this->speed = 1;
        this->skin = nullptr;
    }
    People(Role _base, std::string _name, unsigned int _score, unsigned int _speed)
        : Role(_base), name(_name), score(_score), speed(_speed) {}
    People(const People &_base) : Role(_base.getRole()) {
        this->score = _base.getScore();
        this->name = _base.getName();
        this->speed = _base.getSpeed();
    }
    ~People(){}

    const unsigned int getScore() const { return this->score; }
    const std::string getName() const { return this->name; }
    const unsigned int getSpeed() const { return this->speed; }
    const Role getRole() const { return Role(this->coordinates, this->width, this->length); }
    

    void setScore(unsigned int _score) { this->score = _score; }
    void setName(std::string _name) {
        this->name = _name;
    }
    void setName() {
        std::string _name;
        std::cout << "Please input your name: ";
        std::cin >> _name;
        this->name = _name;
        cout << "Set name compeleted!" << std::endl;
    }
    void setSpeed(unsigned int _speed) { this->speed = _speed; }

    void virtual skill(std::vector<unsigned int> &argvs);
    const char **getSkin();
    void moveTo(int _row, int _column) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }

   protected:
    unsigned int score, speed;
    std::string name;
    char **skin;  // might delete
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
    ~Me() {
        // game over and upload the score
    }
    const unsigned int getID() const { return this->id; }
    const time_t getTimeStamp() const { return this->timeStamp; }
    void boost();
    void virtual skill(std::vector<unsigned int> &argvs);
    void whileTouch(Object::Item &);

   private:
    void generateID() {
        unsigned int r = genRandom();
        std::hash<unsigned int> int_hash;
        this->id = int_hash(r);
    }
    void setTimeStamp() {
        this->timeStamp = time(NULL);
    }
    unsigned int id;
    time_t timeStamp;
};

class Teammate : public People {
   public:
    Teammate(const People _base) : People(_base) {}
    ~Teammate() {
        //send signal to the server
    }
    void virtual skill(std::vector<unsigned int> &argvs);
};
}  // namespace Object

#endif