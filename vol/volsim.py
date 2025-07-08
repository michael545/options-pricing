import os
import pandas as pd
import numpy as np

print(os.getcwd())
df = pd.read_excel('Historical_Prices_EQ_IONQ_2025-07-08.xlsx')  

print("First 5 rows to check chronological order:")
print(df[['UTC Date', 'Close']].head())
print("\nLast 5 rows:")
print(df[['UTC Date', 'Close']].tail())

# Calculate daily log returns
df['Daily_Return'] = np.log(df['Close'] / df['Close'].shift(1))
df = df.dropna(subset=['Daily_Return'])

# Calculate volatility
daily_std = df['Daily_Return'].std()
annualized_vol = daily_std * np.sqrt(252)

# DEBUG: 
print("=== DEBUGGING VOLATILITY CALCULATION ===")
print(f"Min daily return: {df['Daily_Return'].min():.6f}")
print(f"Max daily return: {df['Daily_Return'].max():.6f}")
print(f"Mean daily return: {df['Daily_Return'].mean():.6f}")
print(f"Daily std dev: {daily_std:.6f}")

extreme_returns = df[abs(df['Daily_Return']) > 0.5]  # >50% daily moves
if len(extreme_returns) > 0:
    print(f"\n⚠️  Found {len(extreme_returns)} extreme daily moves (>50%):")
    print(extreme_returns[['UTC Date', 'Close', 'Daily_Return']])

big_jumps = df[abs(df['Daily_Return']) > 0.2]  # >20% daily moves
if len(big_jumps) > 0:
    print(f"\n📊 Large daily moves (>20%):")
    print(big_jumps[['UTC Date', 'Close', 'Daily_Return']].head(10))

# rolling vol to see if it's consistently high
df['Rolling_Vol_30d'] = df['Daily_Return'].rolling(30).std() * np.sqrt(252)

print("\n=== MAIN RESULTS ===")
print(f"Number of trading days: {len(df)}")
print(f"Daily return standard deviation: {daily_std:.6f}")
print(f"Annualized historical volatility (σ): {annualized_vol:.6f} ({annualized_vol:.2%})")
print(f"30-day rolling volatility (current): {df['Rolling_Vol_30d'].iloc[-1]:.2%}")
print("\nLast 5 days of data:")
print(df[['UTC Date', 'Close', 'Daily_Return']].tail())
