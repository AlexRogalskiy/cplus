#include <iostream>

using namespace std;

#define NAME_SIZE 50

class Person {
	int id;
	char name[NAME_SIZE];

	public:
	    explicit Person(int a = 0) : id(a) {
            //
	    }
	    virtual ~Person() {
            cout << "Deleting Person" << endl;
	    }
		virtual void about() {
			cout << "Person" << endl;
		}
		virtual bool addCourse(std::string s) = 0;
};

class Student : public Person {
    const int& b = 12;
	public:
	    explicit Student(int a = 0) : Person(a) {
            //
	    }
	    virtual ~Student() {
            cout << "Deleting Student" << endl;
	    }
		virtual void about() {
			cout << "Student" << endl;
		}
		bool addCourse(std::string s) {
            cout << "Added course: " << s << " to student" << endl;
            return true;
		}
};

int main()
{
    cout << "Hello world!!!" << endl;
    Student* p = new Student(1);
    p->about();
    p->addCourse("History");
    delete p;
    return 0;
}


template <class T>
class ShiftedList {
	T* array;
	int offset, size;
	public:
		explicit ShiftedList(int size) : offset(0), size(size) {
			array = new T[size];
		}
		virtual ~ShiftedList() {
			delete [] array;
		}
		void shiftBy(int n) {
			offset = (offset + n) % size;
		}
		T getAt(int i) {
			return array[convertIndex(i)];
		}
		void setAt(T item, int i) {
			array[convertIndex(i)] = item;
		}
	private:
		int convertIndex(int i) {
			int index = (i - offset) % size;
			while(index < 0) index += size;
			return index;
		}
};
