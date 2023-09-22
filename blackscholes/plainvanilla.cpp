// Vanilla option (no discrete dividends, no barriers) on a single asset class VanillaOption : public Option
class VanillaOption : public Option
{
public:
    VanillaOption() {}
    VanillaOption(double price, double strike, double rate, double div, double vol,
                  double T,
                  Option::Type type, Option::Exercise exercise, const Handle<PricingEngine> &engine);
    double impliedVolatility(double targetValue, double accuracy = 1.0e-4,
                             Size maxEvaluations = 100, double minVol = 1.0e-4, double maxVol = 4.0)
        const;
    double delta() const;
    double gamma() const;
    double theta() const;
    double vega() const;
    double rho() const;

protected:
    void setupEngine() const;
    void performCalculations() const;
    virtual double calculate() const { return NPV_; }
    Date exerciseDate_;                           // exercise Date
    RelinkableHandle<TermStructure> riskFreeRate; // spot rate term structure
    // results
    mutable double delta_, gamma_, theta_, vega_, rho_, dividendRho_;
    // arguments
    Option::Type type_;
    Option::Exercise exercise_;
    double underlying_;
    double astrike;
    double dividendYield_;
    double riskFreeRate_;
    double maturity;
    double volatility;

private:
    // helper class for implied volatility calculation 
class ImpliedVolHelper : public ObjectiveFunction {
public:
    StatUtility util;
    ImpliedVolHelper(const Handle<PricingEngine> &engine, double targetValue);
    std::map<int, double> calcImpliedVols(double price, std::vector<double> opPrices,
                                          std::vector<int> strikes, double rate, double dividend, double T,
                                          Option::Type type);
    std::map<std::pair<double, int>, double> calcImpliedSurface(double price,
                                                                std::vector<double> opPrices, std::vector<int> strikes,
                                                                std::vector<double> T, std::map<double, double> rates, double dividend,
                                                                Option::Type type);
    double operator()(double x) const;

private:
    Handle<PricingEngine> engine_;
    double targetValue_;
    const OptionValue *results_;
};
}
;