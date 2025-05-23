#include <iostream>
#include <cmath>

class Character {
private:
    int hp;
    int x;
    int y;
public:
    Character();
    Character(int hp, int x, int y);
    int getHp();
    void setHp(int hp);
    int getX();
    void setX(int x);
    int getY();
    void setY(int y);
    int getManhattanDistTo(Character* other);
};


Character::Character() {
    // STUDENT ANSWER
    this->hp=0;
    this->x=0;
    this->y=0;
}

Character::Character(int hp, int x, int y) {
   this->hp=hp;
   this->x=x;
   this->y=y;
}

int Character::getHp() {
    // STUDENT ANSWER
    return this->hp;
}

void Character::setHp(int hp) {
    // STUDENT ANSWER
    this->hp=hp;
}

int Character::getX() {
    // STUDENT ANSWER
    return this->x;
}

void Character::setX(int x) {
    // STUDENT ANSWER
    this->x=x;
}

int Character::getY() {
    // STUDENT ANSWER
    return this->y;
}

void Character::setY(int y) {
    // STUDENT ANSWER
    this->y=y;
}

int Character::getManhattanDistTo(Character* other) {
    return abs(this->x - other->x) + abs(this->y - other->y);
}