/* @author: mirkancal */

#include <iostream>
#include <vector>
using namespace std;

class Classroom {
public:
    void lock(){
        cout<<"Classroom locked"<<endl;
    }
    void unlock(){
        cout<<"Classroom unlocked"<<endl;
    }

    Classroom(){};
};

class Command {
public:
    virtual void Execute() = 0;
protected:
    Command(){};
};

class ClassroomLockCommand : public Command {
    Classroom *classroom;
public:

    ClassroomLockCommand(Classroom *c) {
        this->classroom = c;
    };

    void Execute() {
        this->classroom->lock();
    }
};

class ClassroomUnlockCommand : public Command {
    Classroom* classroom;
public:

    ClassroomUnlockCommand(Classroom* c){
        this->classroom = c;
    };

    void Execute(){
        this->classroom->unlock();
    }
};

class Teacher {
    Command* lock;
    Command* unlock;
public:
    Teacher(Command* lock, Command* unlock){
        this->lock=lock;
        this->unlock=unlock;
    };

    void lockClass(){
        this->lock->Execute();
    }
    void unlockClass(){
        this->unlock->Execute();
    }
};

int main() {
    Classroom *m101 = new Classroom();
    Command *command1 = nullptr;
    Command *command2 = nullptr;
    command1 = new ClassroomLockCommand(m101);
    command2 = new ClassroomUnlockCommand(m101);
    Teacher *teacher = new Teacher(command1, command2);
    teacher->lockClass();
    teacher->unlockClass();

}