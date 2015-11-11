#ifndef VEC2
#define VEC2

struct Vec2{
        int x;
        int y;
        Vec2 operator -(Vec2 vector) { Vec2 newVector; newVector.x = this->x + vector.x; newVector.y = this->y + vector.y; return newVector;};
        Vec2 operator +(Vec2 vector) { Vec2 newVector; newVector.x = this->x + vector.x; newVector.y = this->y - vector.y; return newVector;};
        Vec2 operator *(int scalar){ Vec2 newVector; newVector.x = this->x * scalar; newVector.y = this->y * scalar; return newVector;};
        Vec2 operator /(int scalar){ Vec2 newVector; newVector.x = this->x / scalar; newVector.y = this->y / scalar; return newVector;};

};
#endif
