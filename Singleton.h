#include<iostream>
#include<mutex>
class Singleton{

public:
    static Singleton* getInstance(){
        if(instance!=nullptr){


        }
    }
private:
    Singleton(){};
    static Singleton* instance;
};
