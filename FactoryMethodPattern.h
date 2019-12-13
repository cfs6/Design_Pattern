//工厂方法模式
//电视机工厂实例
#include<iostream>

class TV{
    virtual void Play()=0;
};

class HaierTV:public TV{
public:
    void Play(){
        std::cout<<"Haier TV is playing"<<std::endl;
    }
};

class HisenseTV:public TV{
public:
    void Play(){
        std::cout<<"Hisense TV is playing"<<std::endl;
    }
};

class TVFactory{
    virtual TV* ProduceTV()=0;
};

class HaierTVFactory:public TVFactory{
public:
    TV* ProduceTV(){
        std::cout<<"Producing Haier TV"<<std::endl;
        return (new HaierTV());
    }
};

class HisenseTVFactory:public TVFactory{
    TV* ProduceTV(){
        std::cout<<"Producing Hisense TV"<<std::endl;
        return (new HisenseTV*());
    }
};
