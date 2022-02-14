# 121. Best Time to Buy and Sell Stock

LeetCode Problem Link: <https://leetcode.com/problems/best-time-to-buy-and-sell-stock/>

## Description

You are given an array `prices` where `prices[i]` is the price of a given stock on the `i^th` day.

You want to maximize your profit by choosing a **single day** to buy one stock and choosing a **different day** in the future to sell that stock.

Return *the maximum profit you can achieve from this transaction*. If you cannot achieve any profit, return `0`.

## Constraints

- `1 <= prices.length <= 10^5`
- `0 <= prices[i] <= 10^4`

## Solution Thoughts

### Observations

- You can only sell a stock if you bought one, so sell day must be later than buy day.
- Initializing `profit` to 0 will handle the boundary case of no profit automatically.

### Logic

- Initialize the `cost` value to the maximum number to indicate that one has not buy any stock, while `profit` is initialized at 0 as no transaction is taken.
- Loop over the stock prices:
   - if we encounter a lower `price` than the `cost`, we update `cost` to be current `price` as any future sale will achieve better profit if we buy on this day.
   - otherwise we update the profit if we make a larger one by selling on this day.

### Complexities

- **Time Complexity** = `O(N)`
   - One pass through the input list is `O(N)`

- **Space Complexity** = `O(1)`
   - Only one extra variable `cost` is stored.

## Examples

### Example 1

> **Input**: prices = [7,1,5,3,6,4]
>
> **Output**: 5
>
> **Explanation**: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
>
> Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

### Example 2

> **Input**: prices = [7,6,4,3,1]
>
> **Output**: 0
>
> **Explanation**: In this case, no transactions are done and the max profit = 0.
