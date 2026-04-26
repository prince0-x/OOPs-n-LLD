#include <iostream>
#include <memory>
#include <stdexcept>
using namespace std;

/* =========================
   Order Structure
   ========================= */

struct Order {
    int quantity;   // must be >= 0
};

/* =========================
   Strategy Contract
   ========================= */

class IStrategy {
public:
    virtual ~IStrategy() = default;

    // Contract:
    // - Must NOT throw
    // - Must return non-negative quantity
    virtual Order generateSignal(double price) noexcept = 0;
};

/* =========================
   Valid Strategy
   ========================= */

class MeanReversionStrategy : public IStrategy {
private:
    double mean;

public:
    MeanReversionStrategy(double m) : mean(m) {}

    Order generateSignal(double price) noexcept override {
        if (price < mean)
            return {100};
        else
            return {0};
    }
};

/* =========================
   LSP Violating Strategy
   ========================= */

class BadStrategy : public IStrategy {
public:
    Order generateSignal(double price) noexcept override {

        // Violates contract by returning invalid order
        if (price > 100)
            return {-500};   // invalid quantity

        return {100};
    }
};

/* =========================
   Execution Engine
   ========================= */

class ExecutionEngine {
private:
    unique_ptr<IStrategy> strategy;

public:
    ExecutionEngine(unique_ptr<IStrategy> s)
        : strategy(move(s)) {}

    void onTick(double price) {
        Order order = strategy->generateSignal(price);

        // Engine assumes LSP is respected
        if (order.quantity > 0)
            cout << "Sending order of size "
                 << order.quantity << endl;
        else
            cout << "No trade\n";
    }
};

/* =========================
   Main
   ========================= */

int main() {

    // Try replacing with BadStrategy to see LSP violation
    unique_ptr<IStrategy> strat =
        make_unique<MeanReversionStrategy>(100.0);

    ExecutionEngine engine(move(strat));

    engine.onTick(95.0);
    engine.onTick(120.0);
    engine.onTick(78.0);

    return 0;
}
