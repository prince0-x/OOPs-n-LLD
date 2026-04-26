#include <iostream>
#include <memory>
using namespace std;

/* =========================
   Stable Abstraction Layer
   ========================= */

class IStrategy {
public:
    virtual ~IStrategy() = default;
    virtual void onMarketData(double price) = 0;
};

/* =========================
   Concrete Strategies
   ========================= */

// 1. Mean Reversion Strategy
class MeanReversionStrategy : public IStrategy {
private:
    double mean_price;

public:
    MeanReversionStrategy(double mean)
        : mean_price(mean) {}

    void onMarketData(double price) override {
        if (price < mean_price)
            cout << "BUY (Mean Reversion)\n";
        else
            cout << "SELL (Mean Reversion)\n";
    }
};

// 2. Momentum Strategy
class MomentumStrategy : public IStrategy {
private:
    double last_price;

public:
    MomentumStrategy(double initial)
        : last_price(initial) {}

    void onMarketData(double price) override {
        if (price > last_price)
            cout << "BUY (Momentum)\n";
        else
            cout << "SELL (Momentum)\n";

        last_price = price;
    }
};

// 3. VWAP Strategy (New extension — no engine change)
class VWAPStrategy : public IStrategy {
public:
    void onMarketData(double price) override {
        cout << "Executing VWAP logic at price " << price << "\n";
    }
};

/* =========================
   Stable Execution Engine
   ========================= */

class StrategyEngine {
private:
    unique_ptr<IStrategy> strategy;

public:
    StrategyEngine(unique_ptr<IStrategy> strat)
        : strategy(move(strat)) {}

    void onTick(double price) {
        strategy->onMarketData(price);
    }
};

/* =========================
   Main
   ========================= */

int main() {

    // Choose strategy here
    unique_ptr<IStrategy> strat =
        make_unique<MeanReversionStrategy>(100.0);

    StrategyEngine engine(move(strat));

    engine.onTick(95.0);
    engine.onTick(105.0);

    return 0;
}
