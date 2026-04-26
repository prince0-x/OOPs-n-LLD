#include <iostream>
using namespace std;

/* =========================
   Small Focused Interfaces
   ========================= */

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual int generateSignal(double price) = 0;
};

class IExecution {
public:
    virtual ~IExecution() = default;
    virtual void sendOrder(int qty) = 0;
};

class ILogger {
public:
    virtual ~ILogger() = default;
    virtual void logTrade(int qty) = 0;
};

/* =========================
   Concrete Implementations
   ========================= */

class MeanReversionStrategy : public IStrategy {
private:
    double mean;
public:
    MeanReversionStrategy(double m) : mean(m) {}

    int generateSignal(double price) override {
        return (price < mean) ? 100 : 0;
    }
};

class ExchangeExecution : public IExecution {
public:
    void sendOrder(int qty) override {
        cout << "Order sent: " << qty << endl;
    }
};

class ConsoleLogger : public ILogger {
public:
    void logTrade(int qty) override {
        cout << "Logged trade: " << qty << endl;
    }
};

/* =========================
   Main
   ========================= */

int main() {

    IStrategy* strategy = new MeanReversionStrategy(100.0);
    IExecution* execution = new ExchangeExecution();
    ILogger* logger = new ConsoleLogger();

    double price = 95.0;

    int qty = strategy->generateSignal(price);

    if (qty > 0) {
        execution->sendOrder(qty);
        logger->logTrade(qty);
    }

    delete strategy;
    delete execution;
    delete logger;

    return 0;
}
