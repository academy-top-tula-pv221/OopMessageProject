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


int main()
{
    IMovable* mptr = new Bird();

    return 0;
}
