
![Black-Scholes formula](https://latex.codecogs.com/svg.image?C%20%3D%20S_0%20\cdot%20N(d_1)%20-%20K%20\cdot%20e^{-rT}%20\cdot%20N(d_2))

# **An Intuitive Guide to Black-Scholes **

The Black-Scholes model provides a theoretical price for European-style options. Its core insight is that one can determine a fair price not by predicting the stock's direction, but by creating a risk-free position.

### **1\. The Core Idea: The "Riskless" Portfolio (Delta Hedging)**

The model's foundation is the concept of a **delta-hedged portfolio**. Imagine you sell a call option. To offset the risk of the stock price rising, you buy a certain number of shares of that same stock.

- **Portfolio:** You are simultaneously **short a call option** and **long the underlying stock**.
- **Delta (Δ):** You buy a specific number of shares (option's "delta") so that for small, instantaneous price changes, the gain on your stock position perfectly cancels out the loss on your option position (and vice-versa).
- **The Result:** For that moment, your portfolio's value doesn't change with the stock price. It is momentarily **riskless**.

Because this delta changes, a trader must continuously re-balance the portfolio to maintain this risk-free state. Also known as **dynamic (delta) hedging**.

### **2\. Mathematical Trick: The "Risk-Neutral World"**

Since the hedged portfolio is riskless, it must logically earn the **risk-free interest rate (r)**, just like a muni. Any other return would create an arbitrage opportunity.

This leads to a powerful mathematical simplification: we can price the option as if we were in a **risk-neutral world**. In this hypothetical world:

- All investors are indifferent to risk.
- The expected return on _every_ asset (including the stock) is the risk-free rate.

The price calculated in this imaginary world is the same as in the real world because it's based on the no-arbitrage condition of the hedged portfolio, not on anyone's risk appetite.

### **3\. the Formula (Intuition)**

The formula for a call option can be thought of as the net result of what you expect to receive versus what you expect to pay, all adjusted for probability and time.

**Formula:** 
![Black-Scholes equation](assets/bs_form.png)


This can be read as: **Call Price = (Present Value of Receiving the Stock) - (Present Value of Paying the Strike Price)**

#### **Term 1: S₀ \* N(d₁) — What You Expect to Get**

- **S₀**: The current stock price.
- **N(d₁)**: This is the **option's delta**. More deeply, this term represents the present value of the stock you will receive at expiration, _contingent on the option finishing in-the-money_. It's a probability-weighted value of your potential gain.

#### **Term 2: K \* e⁻ʳᵀ \* N(d₂) — What You Expect to Pay**

- **K**: The strike price.
- **e⁻ʳᵀ**: The standard discount factor that brings the future payment of K to present value.
- **N(d₂)**: This is the **risk-neutral probability that the option will be exercised** (i.e., that the stock price at expiration will be above the strike price).

So, you take the present value of the strike payment and multiply it by the probability that you'll actually have to make that payment.

### **4\. Key Assumptions & Limitations**

The model's elegance relies on several key assumptions that don't perfectly match the real world:

- **Constant Volatility & Interest Rates:** It assumes these are known and unchanging, which they are not.
- **Lognormal Price Distribution:** It assumes stock prices move randomly and smoothly, which doesn't account for sudden market shocks or crashes ("fat tails").
- **No Dividends:** The basic formula assumes the stock pays/will not pay no dividends.
- **Frictionless Markets:** It assumes no transaction costs, no taxes, and the ability to trade continuously.

Because of these assumptions, the Black-Scholes price is a theoretical benchmark, not always the exact market price.