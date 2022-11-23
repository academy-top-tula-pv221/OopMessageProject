#include <iostream>
using namespace std;


class IMovable
{
public:
    virtual void SetSpeed(double) = 0;
    virtual double GetSpeed() = 0;
};

class Bird : public IMovable
{
    double speed;
public:
    void SetSpeed(double speed) override 
    {
        this->speed = speed;
    }
    double GetSpeed() { return speed; }

    void Voice()
    {
        cout << "kar-kar\n";
    }
};

class Car : public IMovable
{
public:
    void SetSpeed(double speed) override 
    {
    };
    double GetSpeed() override 
    {
        return 0;
    };

    void Sound()
    {
        cout << "bip-bip\n";
    }
};

class Message
{
protected:
    string message;
    Message(string message = "") : message{ message } {};
    
    void Input()
    {
        cout << "input message: ";
        cin >> this->message;
    }

    void SetMessage(string message)
    {
        this->message = message;
    }

    virtual void Send() = 0;

    virtual ~Message() = default;
};

class ConsoleMessage : public Message
{
public:
    void Send() override
    {
        cout << message << "\n";
    }
};

class SmsMessage : public Message
{
protected:
    string phone;
public:
    SmsMessage(string message = "", string phone = "+0-(000) 000-00-00")
        : Message(message), phone{ phone } {}
    void SetPhone(string phone)
    {
        this->phone = phone;
    }

    void Send() override
    {
        cout << "message: " << message << " send to phone: " << phone << "\n";
    }
};


class EmailMessage : public Message
{
protected:
    string email;
public:
    EmailMessage(string message = "", string phone = "noname@site.com")
        : Message(message), email{ email } {}
    void SetEmail(string email)
    {
        this->email = email;
    }

    void Send() override
    {
        cout << "message: " << message << " send on email: " << email << "\n";
    }
};

class A
{

};

class B : public A
{

};



int main()
{

    /*IMovable* imBird = new Bird();
    IMovable* imCar = new Car();
    IMovable* arr[2];
    arr[0] = new Bird();
    arr[1] = new Car();

    
    for (int i = 0; i < 2; i++)
        if (dynamic_cast<Car*>(arr[i]))
            dynamic_cast<Car*>(arr[i])->Sound();*/


    A* a = new A();
    B* b = new B();
    A* ab = new B();

    cout << sizeof(a) << "\n";
    cout << sizeof(b) << "\n";
    cout << sizeof(ab) << "\n";

    
    return 0;
}
