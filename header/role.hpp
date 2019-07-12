// there is many role in this game
// Our role, enemy and other bonus item
// maybe have some friends? or competitor?
//

namespace Oblect {

typedef struct {
    int row, column;
} Place;

class Role {
   public:
    Role();
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
    Item();
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

class People : public Role {
   public:
    People();
    ~People();
    const int getHP() { return this->hp; }
    const int getATK() { return this->attack; }
    const int getDEF() { return this->defense; }
    const int getAttribute() { return this->attribute; }
    void minusHP(const int value) { this->hp -= value; }
    void virtual skill();
    const char **getSkin();
    void moveTo(int _row, int _column) {
        this->coordinates.row = _row;
        this->coordinates.column = _column;
    }

   protected:
    int hp, attack, defense, attribute;
    unsigned int id;
    char **skin;
};

class Enemy : public People {
   public:
    Enemy();
    ~Enemy();  //drop bonus
    void virtual skill();
};

class Me : public People {
   public:
    Me();
    ~Me();
    void boost();
    void virtual skill();
    void touch() {}  //listing everytime
};
class Teammate : public People {
   public:
    Teammate();
    ~Teammate();
    void virtual skill();
};
}  // namespace Oblect
