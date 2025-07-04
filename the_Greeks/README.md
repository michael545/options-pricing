# A Guide to the Option Greeks: Measuring an Option's Risk

The "Greeks" are a set of risk measures that describe the sensitivity of an option's price to changes in the underlying factors that determine its value. They are the essential tools used by traders to understand and manage the complex, multi-dimensional risk of an options portfolio. Each Greek is a partial derivative of the option pricing model (like Black-Scholes) with respect to one of its input parameters, providing a snapshot of how an option's value is expected to behave in a dynamic market.

## Mathematical Foundation

The formulas below are based on the Black-Scholes model for a European call option (C):

$$
C = S_0 N(d_1) - K e^{-rT} N(d_2)
$$

Where:

*   **$S_0$**: Current stock price
*   **$K$**: Strike price
*   **$r$**: Risk-free interest rate
*   **$T$**: Time to maturity (in years)
*   **$\sigma$**: Volatility
*   **$N(x)$**: The cumulative distribution function (CDF) of the standard normal distribution.
*   **$N'(x)$**: The probability density function (PDF) of the standard normal distribution:

$$
N'(x) = \frac{1}{\sqrt{2\pi}} e^{-\frac{x^2}{2}}
$$

*   **$d_1$**: 

$$
d_1 = \frac{\ln(\frac{S_0}{K}) + (r + \frac{\sigma^2}{2})T}{\sigma\sqrt{T}}
$$

*   **$d_2$**:

$$
d_2 = d_1 - \sigma\sqrt{T}
$$

---

## 1. Delta ($\Delta$): The Speed of the Option

*   **What it Measures**: Delta measures the rate of change of the option's price with respect to a \$1 change in the underlying asset's price. It is the first-order measure of the option's price sensitivity to the underlying stock, often thought of as its "speed."
*   **Why it Matters**: Delta provides an immediate estimate of how an option's value will react to a stock price move. For example, a call option with a Delta of 0.60 is expected to increase in value by approximately \$0.60 if the underlying stock price rises by \$1. Delta is also the cornerstone of hedging.
*   **Mathematical Formula**: Delta is the first partial derivative of the option price (C) with respect to the stock price ($S_0$).

$$
\Delta = \frac{\partial C}{\partial S_0} = N(d_1)
$$

---

## 2. Gamma ($\Gamma$): The Acceleration of the Option

*   **What it Measures**: Gamma measures the rate of change of an option's Delta with respect to a \$1 change in the underlying asset's price. If Delta is the speed, Gamma is the "acceleration" of the option.
*   **Why it Matters**: Delta is not a constant; it changes as the stock price moves. Gamma quantifies this change. A high Gamma indicates that Delta is highly sensitive and will change rapidly with stock price movements, making a delta-neutral hedge unstable and requiring frequent re-balancing.
*   **Mathematical Formula**: Gamma is the second partial derivative of the option price (C) with respect to the stock price ($S_0$).

$$
\Gamma = \frac{\partial^2 C}{\partial S_0^2} = \frac{N'(d_1)}{S_0 \sigma \sqrt{T}}
$$

---

## 3. Theta ($\Theta$): The Time Decay of the Option

*   **What it Measures**: Theta measures the rate of change of the option's price with respect to the passage of time, holding all other factors constant. It is almost always negative for long options, representing the erosion of extrinsic value.
*   **Why it Matters**: Theta represents the unavoidable cost of holding an option. A Theta of -0.05 means your option is expected to lose approximately \$0.05 in value each calendar day. This decay is not linear; it accelerates dramatically as the option approaches its expiration date.
*   **Mathematical Formula**: Theta is the negative of the first partial derivative of the option price (C) with respect to time (T).

$$
\Theta = -\frac{\partial C}{\partial T} = -\frac{S_0 N'(d_1) \sigma}{2\sqrt{T}} - rKe^{-rT}N(d_2)
$$

---

## 4. Vega ($\nu$): The Volatility Sensitivity

*   **What it Measures**: Vega measures the rate of change of the option's price with respect to a 1% change in the implied volatility of the underlying asset. (Note: Vega is not actually a Greek letter, but it has become the standard name for this risk measure).
*   **Why it Matters**: Higher volatility implies a greater probability of large price swings in either direction, which increases the chance of an option finishing profitably. Therefore, higher volatility makes options more valuable. Vega quantifies this relationship.
*   **Mathematical Formula**: Vega is the first partial derivative of the option price (C) with respect to volatility ($\sigma$):

$$
\nu = \frac{\partial C}{\partial \sigma} = S_0 \sqrt{T} N'(d_1)
$$

---

## 5. Rho ($\rho$): The Interest Rate Sensitivity

*   **What it Measures**: Rho measures the rate of change of the option's price with respect to a 1% change in the risk-free interest rate.
*   **Why it Matters**: Rho is generally the least significant Greek for most short-term options traders, as interest rates move slowly and the effect is small over short periods. Its impact becomes more pronounced for long-term options.
*   **Mathematical Formula**: Rho is the first partial derivative of the option price (C) with respect to the risk-free interest rate (r).

$$
\rho = \frac{\partial C}{\partial r} = K T e^{-rT} N(d_2)
$$
