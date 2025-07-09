# **An Intuitive Guide to the Bachelier Model**

The Bachelier model, developed by Louis Bachelier in 1900, was the first mathematical model for option pricing and the foundation of modern quantitative finance. While predating Black-Scholes by 73 years, it introduced the revolutionary concept that stock prices follow a random walk and laid the groundwork for all subsequent option pricing theory.

### **1\. The Core Idea: Arithmetic Brownian Motion**

Unlike Black-Scholes which assumes stock prices follow geometric Brownian motion (preventing negative prices), the Bachelier model assumes stock prices follow **arithmetic Brownian motion**.

- **Price Process:** Stock prices can move up or down by equal amounts with equal probability
- **Random Walk:** Each price change is independent of previous changes
- **Normal Distribution:** Price changes (not log returns) are normally distributed
- **Key Insight:** The model introduced the concept that uncertainty increases with the square root of time

### **2\. Mathematical Foundation: The Heat Equation**

Bachelier's breakthrough was recognizing that option pricing is fundamentally a diffusion problem, similar to heat conduction.

The stock price follows:
$$
dS = \sigma dW
$$

Where:
- $dS$ = change in stock price
- $\sigma$ = volatility (constant)
- $dW$ = Wiener process (random walk)

This leads to the **diffusion equation** (heat equation):
$$
\frac{\partial V}{\partial t} + \frac{1}{2}\sigma^2 \frac{\partial^2 V}{\partial S^2} = 0
$$

### **3\. The Bachelier Formula (Intuition)**

The Bachelier formula for a call option is elegantly simple and was derived purely from first principles of probability theory.

**Formula:**

$$
C = (S - K) \cdot \Phi(d) + \sigma\sqrt{T} \cdot \phi(d)
$$

Where:

$$
d = \frac{S - K}{\sigma\sqrt{T}}
$$

And:
- $\Phi(d)$ = cumulative standard normal distribution function
- $\phi(d)$ = standard normal probability density function

$$
\phi(x) = \frac{1}{\sqrt{2\pi}} e^{-\frac{x^2}{2}}
$$

$$
\Phi(x) = \int_{-\infty}^{x} \frac{1}{\sqrt{2\pi}} e^{-\frac{t^2}{2}} dt
$$

This can be read as: **Call Price = (Intrinsic Value × Probability of Exercise) + (Time Value)**

#### **Term 1: $(S - K) \cdot \Phi(d)$ — Expected Intrinsic Value**

- **(S - K)**: The current intrinsic value if exercised today
- **$\Phi(d)$**: The probability that the option will finish in-the-money
- **Combined**: The expected intrinsic value at expiration

#### **Term 2: $\sigma\sqrt{T} \cdot \phi(d)$ — Pure Time Value**

- **$\sigma\sqrt{T}$**: The standard deviation of price changes over time T
- **$\phi(d)$**: The probability density at the current "moneyness" level
- **Combined**: The additional value from the possibility of favorable price movements

### **4\. Key Differences from Black-Scholes**

| Aspect | Bachelier Model | Black-Scholes Model |
|--------|----------------|-------------------|
| **Price Process** | Arithmetic Brownian Motion | Geometric Brownian Motion |
| **Price Distribution** | Normal | Log-Normal |
| **Negative Prices** | Possible | Impossible |
| **Interest Rates** | Ignored | Explicitly modeled |
| **Mathematical Basis** | Heat equation | Risk-neutral valuation |
| **Relative Changes** | Not modeled | Constant volatility of returns |

### **5\. When Bachelier Works Well**

The Bachelier model can be surprisingly accurate for:

- **Short-term options** (where interest rates matter less)
- **High-priced stocks** (where negative prices are unrealistic anyway)
- **Currency options** (where negative "prices" represent currency appreciation/depreciation)
- **Interest rate options** (where rates can indeed go negative)

### **6\. Limitations & Why Black-Scholes Emerged**

The model's elegance comes with significant limitations:

- **Negative Prices:** Stock prices can theoretically go negative, which is economically nonsensical for equity
- **No Interest Rates:** Ignores the time value of money and risk-free discounting
- **Absolute vs Relative Changes:** Doesn't capture that a $1 move means more for a $10 stock than a $100 stock
- **Constant Absolute Volatility:** Assumes volatility is independent of stock price level

### **7\. Historical Significance**

Bachelier's work was revolutionary because it:

- **Introduced randomness** to finance for the first time
- **Connected mathematics to markets** using probability theory
- **Established the square-root-of-time rule** for uncertainty scaling
- **Laid foundations** for all modern derivative pricing theory
- **Anticipated Einstein's work** on Brownian motion

### **8\. Modern Applications**

While largely superseded by Black-Scholes for equity options, Bachelier's insights remain relevant in:

- **Interest rate modeling** (where rates can be negative)
- **Currency options** (for carry trades)
- **Short-term trading models** (where interest rates are negligible)
- **Academic research** 

The Bachelier model stands as a testament to the power of mathematical thinking in finance, proving that even a "wrong" model can provide profound insights and pave the way for future breakthroughs.
