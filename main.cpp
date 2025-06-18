#include <ql/quantlib.hpp>
#include <boost/make_shared.hpp> // <-- Add this include for boost::make_shared
#include <iostream>
#include <string>
#include <vector>

int main() {
    try {
        std::cout << "QuantLib " << QL_VERSION << std::endl;
        std::cout << "--------------------------" << std::endl;

        // This dumbnes of the code 
        QuantLib::Calendar calendar = QuantLib::TARGET();
        QuantLib::Date settlementDate(18, QuantLib::June, 2025);
        QuantLib::Date todaysDate = calendar.adjust(settlementDate);
        QuantLib::Settings::instance().evaluationDate() = todaysDate;
        QuantLib::Date maturityDate = todaysDate + 3 * QuantLib::Months;

        // option params
        QuantLib::Option::Type optionType(QuantLib::Option::Call);
        QuantLib::Real underlyingPrice = 100.0;
        QuantLib::Real strikePrice = 110.0;
        QuantLib::Rate riskFreeRate = 0.05;
        QuantLib::Volatility volatility = 0.40;

        // use boost::make_shared instead of std::make_shared

        QuantLib::Handle<QuantLib::Quote> underlyingH(
            boost::make_shared<QuantLib::SimpleQuote>(underlyingPrice) // boost::
        );
        QuantLib::Handle<QuantLib::YieldTermStructure> flatTermStructure(
            boost::make_shared<QuantLib::FlatForward>(todaysDate, riskFreeRate, QuantLib::Actual365Fixed()) // Use boost::
        );
        QuantLib::Handle<QuantLib::BlackVolTermStructure> flatVolTS(
            boost::make_shared<QuantLib::BlackConstantVol>(todaysDate, calendar, volatility, QuantLib::Actual365Fixed()) // Use boost::
        );

        auto bsmProcess = boost::make_shared<QuantLib::BlackScholesMertonProcess>( 
            underlyingH, flatTermStructure, flatTermStructure, flatVolTS
        );

        // Create the option
        auto europeanExercise = boost::make_shared<QuantLib::EuropeanExercise>(maturityDate); 
        auto payoff = boost::make_shared<QuantLib::PlainVanillaPayoff>(optionType, strikePrice); 

        QuantLib::EuropeanOption europeanOption(payoff, europeanExercise);

        // Link the pricing engine
        europeanOption.setPricingEngine(
            boost::make_shared<QuantLib::AnalyticEuropeanEngine>(bsmProcess) 
        );

        QuantLib::Real optionPrice = europeanOption.NPV();
        std::cout << "Option Price:    " << optionPrice << std::endl;

    } catch (std::exception& e) {
        std::cerr << "unknows error occurred: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}