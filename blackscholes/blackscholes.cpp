// Black-Scholes-Merton option
class BlackScholesOption : public VanillaOption {
  public:
    BlackScholesOption() { }
    BlackScholesOption(Option::Type type, double underlying, double strike, double
dividendYield, double riskFreeRate, double residualTime, double volatility); virtual ∼BlackScholesOption() {}
// modifiers
virtual void setVolatility(double newVolatility);
    virtual void setRiskFreeRate(double newRate);
    virtual void setDividendYield(double newDividendYield);
    double calcBSCallPrice(double price, double strike, double vol, double rate,
      double div, double T);
    double calcBSPutPrice(double vol, double rate, double div, double strike,
      double price, double T);
  protected:
    Option::Type type_;
    Option::Exercise exercise_;
    double underlying_;
    double strike_;
    double dividendYield_;
    double riskFreeRate_;
    double residualTime_;
    double volatility_;
    double value_;
};