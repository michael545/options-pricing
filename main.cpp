#include <ql/quantlib.hpp>
#include <boost/make_shared.hpp>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::setprecision
#include <chrono>

// European, American, and Asian options.
int main() {
    auto start = std::chrono::high_resolution_clock::now();

    try {
        std::cout << "QuantLib " << QL_VERSION << std::endl;
        std::cout << "--------------------------" << std::endl;

        // Common parameters for all options
        QuantLib::Calendar calendar = QuantLib::TARGET();
        QuantLib::Date settlementDate(18, QuantLib::June, 2025);
        QuantLib::Date todaysDate = calendar.adjust(settlementDate);
        QuantLib::Settings::instance().evaluationDate() = todaysDate;
        QuantLib::Date maturityDate = todaysDate + 3 * QuantLib::Months;

        // Option parameters
        QuantLib::Option::Type optionType(QuantLib::Option::Call);
        QuantLib::Real underlyingPrice = 100.0;
        QuantLib::Real strikePrice = 110.0;
        QuantLib::Rate riskFreeRate = 0.05;
        QuantLib::Volatility volatility = 0.40;

        // Market data handles
        QuantLib::Handle<QuantLib::Quote> underlyingH(
            boost::make_shared<QuantLib::SimpleQuote>(underlyingPrice)
        );
        QuantLib::Handle<QuantLib::YieldTermStructure> flatTermStructure(
            boost::make_shared<QuantLib::FlatForward>(todaysDate, riskFreeRate, QuantLib::Actual365Fixed())
        );
        QuantLib::Handle<QuantLib::BlackVolTermStructure> flatVolTS(
            boost::make_shared<QuantLib::BlackConstantVol>(todaysDate, calendar, volatility, QuantLib::Actual365Fixed())
        );

        // Black-Scholes-Merton process
        auto bsmProcess = boost::make_shared<QuantLib::BlackScholesMertonProcess>(
            underlyingH, flatTermStructure, flatTermStructure, flatVolTS
        );

        // Common payoff for all options
        auto payoff = boost::make_shared<QuantLib::PlainVanillaPayoff>(optionType, strikePrice);

        // Set precision for output
        std::cout << std::fixed << std::setprecision(4);

        // --- 1. European Option (Original Example) ---
        std::cout << "\n--- European Option ---" << std::endl;
        auto europeanExercise = boost::make_shared<QuantLib::EuropeanExercise>(maturityDate);
        QuantLib::EuropeanOption europeanOption(payoff, europeanExercise);
        europeanOption.setPricingEngine(
            boost::make_shared<QuantLib::AnalyticEuropeanEngine>(bsmProcess)
        );
        std::cout << "European Option Price: " << europeanOption.NPV() << std::endl;

        // --- 2. American Option using a Binomial Tree Engine ---
        std::cout << "\n--- American Option (Binomial Tree) ---" << std::endl;
        // can be exercised at any time up to maturity.
        //o closed-form solution like Black-Scholes, so numerical methods like binomial trees are used.[2]
        auto americanExercise = boost::make_shared<QuantLib::AmericanExercise>(todaysDate, maturityDate);
        QuantLib::VanillaOption americanOption(payoff, americanExercise);

        // The BinomialVanillaEngine uses a binomial tree to price the option.
        // We specify the model (e.g., "crr" for Cox-Ross-Rubinstein) and the number of time steps.[1, 3]
        QuantLib::Size timeSteps = 100;
        auto binomialEngine = boost::make_shared<QuantLib::BinomialVanillaEngine<QuantLib::CoxRossRubinstein>>(bsmProcess, timeSteps);
        americanOption.setPricingEngine(binomialEngine);
        std::cout << "American Option Price: " << americanOption.NPV() << std::endl;


        // --- 3. Asian Option (Geometric Average, Analytic Engine) ---
        std::cout << "\n--- Asian Option (Geometric Average, Analytic) ---" << std::endl;
        // option's payoff depends on the average price of the underlying over a period.
        // A closed-form solution exists for discretely-sampled geometric averages.
        QuantLib::Average::Type averageTypeGeometric = QuantLib::Average::Geometric;
        
        //the dates on which the underlying price is observed for the average.
        std::vector<QuantLib::Date> fixingDates;
        for (QuantLib::Date d = todaysDate; d <= maturityDate; d = calendar.advance(d, 1, QuantLib::Weeks)) {
            fixingDates.push_back(d);
        }

        // Create the Asian option instrument
        QuantLib::DiscreteAveragingAsianOption geometricAsianOption(
            averageTypeGeometric,
            0, // runningAccumulator: initial average value is zero
            0, // pastFixings: number of past fixings is zero
            fixingDates,
            payoff,
            europeanExercise // Asian options are typically European style
        );

        // Use the analytic engine for discrete geometric average price Asian options.[4, 5]
        auto geometricAsianEngine = boost::make_shared<QuantLib::AnalyticDiscreteGeometricAveragePriceAsianEngine>(bsmProcess);
        geometricAsianOption.setPricingEngine(geometricAsianEngine);
        std::cout << "Geometric Asian Price: " << geometricAsianOption.NPV() << std::endl;


        // --- 4. Asian Option (Arithmetic Average, Monte Carlo Engine) ---
        std::cout << "\n--- Asian Option (Arithmetic Average, Monte Carlo) ---" << std::endl;
        // Arithmetic Asian options are more common but lack a closed-form solution.[4]
        // We must use a numerical method like Monte Carlo simulation.[6]
        QuantLib::Average::Type averageTypeArithmetic = QuantLib::Average::Arithmetic;

        QuantLib::DiscreteAveragingAsianOption arithmeticAsianOption(
            averageTypeArithmetic,
            0.0, // runningAccumulator
            0,   // pastFixings
            fixingDates,
            payoff,
            europeanExercise
        );

        // Use the Monte Carlo engine for discrete arithmetic average price Asian options.[7]
        QuantLib::Size requiredSamples = 100;
        auto mcArithmeticAsianEngine = boost::make_shared<QuantLib::MCDiscreteArithmeticAPEngine<QuantLib::PseudoRandom>>(
            bsmProcess,
            false, // brownianBridge
            true,  // antitheticVariate
            false, // controlVariate
            requiredSamples,
            1e-3,  // requiredTolerance
            QuantLib::Null<QuantLib::Size>(), // maxSamples
            0      // seed
        );
        arithmeticAsianOption.setPricingEngine(mcArithmeticAsianEngine);
        std::cout << "Arithmetic Asian Price (MC): " << arithmeticAsianOption.NPV() << std::endl;


    } catch (std::exception& e) {
        std::cerr << "unknown error occurred: " << e.what() << std::endl;
        return 1;
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "\nElapsed time: " << elapsed.count() << " seconds." << std::endl;
    return 0;
}