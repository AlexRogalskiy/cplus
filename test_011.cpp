#include <typeinfo>
#include <string>
#include <iostream>

using namespace std;

enum ShapeType {circle, square};

class Shape {
    public:
        virtual void Draw() const = 0;
        bool operator<(const Shape& s) {
            return Precedes(s);
        }
    protected:
        virtual bool Precedes(const Shape&) const = 0;
    private:
        static const char* typeOrderTable[];
};

const char* Shape::typeOrderTable = {typeid(Circle).name(), typeid(Square).name(), 0};

class Square : public Shape {
    public:
        virtual void Draw() const;
};

class Circle : public Shape {
    public:
        virtual void Draw() const;
};

bool Shape::Precedes(const Shape& s) const {
    const char* thisType = typeid(*this).name();
    const char* argType = typeid(s).name();

    bool done = false;
    int thisOrd = -1, argOrd = -1;
    for(int i=0; !done; i++) {
        const char* tableEntry = typeOrderTable[i];
        if(tableEntry != 0) {
            if(strcmp(tableEntry, thisType) == 0) {
                thisOrd = i;
            }
            if(strcmp(tableEntry, argType) == 0) {
                argOrd = i;
            }
            if(argOrd >= 0 && thisOrd >= 0) {
                done = true;
            }
        } else {
            done = true;
        }
        return thisOrd < argOrd;
    }
};

void drawAllShapes(vector<Shape*>& list) {
    vector<Shape*>::iterator i;
    for(i = list.begin(); i!=list.end(); i++) {
        (*i)->Draw();
    }
};

void drawAllShapesInOrder(vector<Shape*>& list) {
    vector<Shape*> orderedList = list;
    sort(orderedList.begin(), orderedList.end(), ShapeComparator<Shape*>());
    vector<Shape*>::iterator i;
    for(i = list.begin(); i!=list.end(); i++) {
        (*i)->Draw();
    }
};

template <typename P>
class ShapeComparator {
    public:
    bool operator() (const P first, const P last) {
        return (*p) < (*q);
    }
};
