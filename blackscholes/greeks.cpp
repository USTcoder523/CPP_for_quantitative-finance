#include <ql/quantlib.hpp>
#include <ql/pricingengines/blackcalculator.hpp>
#include <iostream>
struct BlackScholesParameters {
   double S0;
   double K;
   double rd;
   double rf;
   double tau;
   double vol;
};
void callBlackScholes(BlackScholesParameters  &bp)
{
   // Create a vanilla option (standard option type)
   boost::shared_ptr<QuantLib::PlainVanillaPayoff>
      vanillaPut(new QuantLib::PlainVanillaPayoff(QuantLib::Option::Put,bp.K));
   // Compute discount rates
   double cur_disc = std::exp(-bp.rd  * bp.tau);  // current discount rate
   double for_disc = std::exp(-bp.rf  * bp.tau);  // forward  discount rate
   double stdev    = bp.vol * std::sqrt(bp.tau);  // standard deviation
   QuantLib::BlackScholesCalculator putPricer(vanillaPut, bp.S0, for_disc, stdev,
   cur_disc);
   // Print option Greeks
   std::cout << "value:" << putPricer.value() << std::endl;
   std::cout << "delta:" << putPricer.delta() << std::endl;
   std::cout << "gamma:" << putPricer.gamma() << std::endl;
   std::cout << "vega:"  << putPricer.vega(bp.tau)  << std::endl;
   std::cout << "theta:" << putPricer.theta(bp.tau) << std::endl;
   std::cout << "delta Fwd:" << putPricer.deltaForward() << std::endl;
   std::cout << "gamma Fwd:" << putPricer.gammaForward() << std::endl;
}


void testBlackScholes()
{
   BlackScholesParameters bp;
bp.S0 = 95.0;
bp.K  = 100.0;
bp.rd = 0.026;
bp.rf = 0.017;
bp.tau= 0.62;
bp.vol= 0.193;
// current price
// strike
// current rate of return
// forward rate of return
// tau (time greek)
// volatility
   callBlackScholes(bp);

}

int main(){
    testBlackScholes();
}
