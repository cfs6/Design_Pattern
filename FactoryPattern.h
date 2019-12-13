//简单工厂模式
//电视机工厂实例
#include<iostream>
#include<string>
class TV{
public:
    virtual void play()=0;
};

class HaierTV:public TV{
public:
    void play(){
        std::cout<<"Haier TV is playing."<<std::endl;
    }
};

class HisenseTV:public TV{
public:
    void play(){
        std::cout<<"Hisense TV is playing."<<std::endl;
    }
};

class TVFactory{
public:
    TV* ProduceTV(string TVName){
        if(strcpy(TVName,"Haier")==0){
            std::cout<<"Produce Haier TV"<<std::endl;
            return new HaierTV();
        }
        else if(strcpy(TVName,"HisenseTV")==0){
            std::cout<<"Prodoce HisenseTV"<<std::endl;
            return new HisenseTV();
        }
        else{
            std::cout<<"Invalid type"<<std::endl;
            return nullptr;
        }
    }
};


//权限管理实例
enum UserType{Employee,Manager,Administer};
class User{
public:
    virtual void SameOperation()=0;
};

class Employee:public User{
public:
    Employee(){
        std::cout<<"Create Employee object"<<std::endl;
    }
    void SameOperation(){
        std::cout<<"Change personal data"<<std::endl;
    }
    void DiffOperator(){
        std::cout<<"Employee priority"<<std::endl;
    }
};

class Manager:public User{
    Manager(){
        std::cout<<"Create Manager obeject"<<std::endl;
    }
    void SameOperation(){
        std::cout<<"Change personal data"<<std::endl;
    }
    void DiffOperation(){
        std::cout<<"Manager priority"<<std::endl;
    }
};

class Administer:public User{
    Administer(){
        std::cout<<"Create Administer obeject"<<std::endl;
    }
    void SameOperation(){
        std::cout<<"Change personal data"<<std::endl;
    }
    void DiffOperation(){
        std::cout<<"Administer priority"<<std::endl;
    }
};

class UserFactory{
    User* GetUser(UserType uType){
        switch(uType)
        {
        case Employee:
            return (new Employee());
            break;
        case Manager:
            return (new Manager());
            break;
        case Administer:
            return (new Administer());
            break;
        default:
            return nullptr;
        }
    }
};
