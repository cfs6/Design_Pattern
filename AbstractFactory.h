//抽象工厂模式
//电视机空调工厂实例
#include<iostream>
class Television{
public:
    virtual void play()=0;
};

class HaierTelevision:public Television{
public:
    void play(){
        std::cout<<"HaierTelevision is playing"<<std::endl;
    }
};

class TCLTelevision:public Television{
public:
    void play(){
        std::cout<<"TCLTelevision is playing"<<std::endl;
    }
};

class AirConditioner{
public:
    virtual void play()=0;
};

class HaierAirConditioner:public AirCondition{
public:
    void play(){
        std::cout<<"HaierAirConditioner is playing"<<std::endl;
    }
};

class TCLAirConditioner:public AirConditioner{
public:
    void play(){
        std::cout<<"TCLAirConditioner is playint"<<std::endl;
    }
};

class Factory{
public:
    virtual Television* ProduceTelevision()=0;
    virtual AirConditioner* ProduceAirConditioner()=0;
};

class HaierFactory:public Factory{
public:
    Television* ProduceTelevision(){
        std::cout<<"Produce HaierTelevision"<<std::endl;
        return (new HaierTelevision());
    }
    AirConditioner* ProduceAirConditioner(){
        std::cout<<"Produce HaierAirCondition"<<std::endl;
        return (new HaierAirConditioner());
    }
};

class TCLFactory:public Factory{
public:
    Television* ProduceTelevision(){
        std::cout<<"Produce TCLTelevision"<<std::endl;
        return (new TCLTelevision());
    }
    AirConditioner* ProduceAirConditioner(){
        std::cout<<"Produce TCLAirConditioner"<<std::endl;
        return (new TCLAirConditioner());
    }
};
