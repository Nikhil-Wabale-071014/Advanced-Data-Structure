# Advanced-Data-Structure

A. Divide and Conquer Strategy:

A1. Number of Zeroes

Control Abstraction:

```plaintext
function countZeroes(array, start, end):
    if start > end:
        return 0
    if array[end] == 1:
        return 0
    if array[start] == 0:
        return end - start + 1
    mid = (start + end) / 2
    return countZeroes(array, start, mid) + countZeroes(array, mid+1, end)
```

Algorithm:

1. If the start index is greater than the end index, return 0 (base case).
2. If the last element is 1, return 0 (no zeroes).
3. If the first element is 0, return the length of the array (all zeroes).
4. Find the middle index.
5. Recursively count zeroes in the left half and right half of the array.
6. Return the sum of zeroes from both halves.


A2. Push Zeros to End

Control Abstraction:

```plaintext
function pushZerosToEnd(array, start, end):
    if start >= end:
        return
    mid = (start + end) / 2
    pushZerosToEnd(array, start, mid)
    pushZerosToEnd(array, mid+1, end)
    merge(array, start, mid, end)
```

Algorithm:

1. If the start index is greater than or equal to the end index, return (base case).
2. Find the middle index.
3. Recursively push zeros to end in the left half of the array.
4. Recursively push zeros to end in the right half of the array.
5. Merge the two halves, moving non-zero elements to the left and zeros to the right.


A3. Smallest Number with at Least n Trailing Zeroes in Factorial

Control Abstraction:

```plaintext
function smallestNumberWithNTrailingZeroes(n, low, high):
    if low > high:
        return low
    mid = (low + high) / 2
    if countTrailingZeroes(mid) < n:
        return smallestNumberWithNTrailingZeroes(n, mid+1, high)
    else:
        return smallestNumberWithNTrailingZeroes(n, low, mid-1)

function countTrailingZeroes(num):
    count = 0
    i = 5
    while num / i >= 1:
        count += num / i
        i *= 5
    return count
```

Algorithm:

1. If the low bound is greater than the high bound, return the low bound (base case).
2. Find the middle number between low and high.
3. Count the trailing zeroes in the factorial of the middle number.
4. If the count is less than n, recursively search in the upper half.
5. Otherwise, recursively search in the lower half.
6. The countTrailingZeroes function counts the number of factors of 5 in the factorial.


B. Greedy Strategy:

B1. Activity Selection with K Persons

Control Abstraction:

```plaintext
function activitySelectionWithKPersons(activities, k):
    sort activities by end time
    assigned = 0
    for each person i from 1 to k:
        last_end = 0
        for each activity j:
            if activity[j].start >= last_end:
                assign activity[j] to person i
                last_end = activity[j].end
                assigned++
    return assigned
```

Algorithm:

1. Sort the activities based on their end times.
2. For each person (up to K):
a. Initialize the last end time to 0.
b. For each activity:

1. If the activity's start time is greater than or equal to the last end time:

1. Assign the activity to the current person.
2. Update the last end time to the current activity's end time.
3. Increment the count of assigned activities.






3. Return the total number of assigned activities.


B2. Maximize Profit by Trading Stocks

Control Abstraction:

```plaintext
function maximizeProfit(prices):
    min_price = prices[0]
    max_profit = 0
    for each price in prices:
        if price < min_price:
            min_price = price
        else:
            max_profit = max(max_profit, price - min_price)
    return max_profit
```

Algorithm:

1. Initialize the minimum price as the first price and maximum profit as 0.
2. For each price in the array:
a. If the current price is less than the minimum price, update the minimum price.
b. Otherwise, calculate the potential profit and update the maximum profit if it's greater.
3. Return the maximum profit.


B3. Minimum Work per Day to Finish Tasks

Control Abstraction:

```plaintext
function minimumWorkPerDay(tasks, D):
    low = max(tasks)
    high = sum(tasks)
    while low < high:
        mid = (low + high) / 2
        if canFinish(tasks, D, mid):
            high = mid
        else:
            low = mid + 1
    return low

function canFinish(tasks, D, work_per_day):
    days = 0
    for task in tasks:
        days += ceil(task / work_per_day)
    return days <= D
```

Algorithm:

1. Set the lower bound as the maximum task duration and upper bound as the sum of all task durations.
2. While the lower bound is less than the upper bound:
a. Calculate the middle value.
b. Check if it's possible to finish all tasks in D days with this work per day.
c. If possible, reduce the upper bound; otherwise, increase the lower bound.
3. Return the lower bound as the minimum work per day.
4. The canFinish function checks if it's possible to complete all tasks in D days with the given work per day.


C. Dynamic Programming:

C1. Coin Change Problem

Control Abstraction:

```plaintext
function coinChange(coins, sum):
    dp = array of size sum+1 initialized with 0
    dp[0] = 1
    for coin in coins:
        for i from coin to sum:
            dp[i] += dp[i - coin]
    return dp[sum]
```

Algorithm:

1. Create a DP array of size sum+1 and initialize all elements to 0.
2. Set dp[0] to 1 (there's one way to make sum 0).
3. For each coin:
a. For each sum from coin to the target sum:

1. Add the number of ways to make the current sum minus the coin value.



4. Return the value in dp[sum], which represents the total number of ways to make the target sum.


C2. Subset Sum Problem

Control Abstraction:

```plaintext
function subsetSum(set, sum):
    dp = 2D array of size (n+1) x (sum+1) initialized with false
    for i from 0 to n:
        dp[i][0] = true
    for i from 1 to n:
        for j from 1 to sum:
            if j < set[i-1]:
                dp[i][j] = dp[i-1][j]
            else:
                dp[i][j] = dp[i-1][j] or dp[i-1][j-set[i-1]]
    return dp[n][sum]
```

Algorithm:

1. Create a 2D DP array of size (n+1) x (sum+1) and initialize all elements to false.
2. Set the first column to true (empty subset can make sum 0).
3. For each element in the set:
a. For each possible sum:

1. If the current sum is less than the current element, copy the value from the previous row.
2. Otherwise, either include or exclude the current element.



4. Return the value in dp[n][sum], which represents whether it's possible to make the target sum.


C3. String Interleaving

Control Abstraction:

```plaintext
function isInterleave(s1, s2, s3):
    if len(s1) + len(s2) != len(s3):
        return false
    dp = 2D array of size (len(s1)+1) x (len(s2)+1) initialized with false
    dp[0][0] = true
    for i from 0 to len(s1):
        for j from 0 to len(s2):
            if i > 0:
                dp[i][j] |= (dp[i-1][j] and s1[i-1] == s3[i+j-1])
            if j > 0:
                dp[i][j] |= (dp[i][j-1] and s2[j-1] == s3[i+j-1])
    return dp[len(s1)][len(s2)]
```

Algorithm:

1. If the sum of lengths of s1 and s2 is not equal to the length of s3, return false.
2. Create a 2D DP array of size (len(s1)+1) x (len(s2)+1) and initialize all elements to false.
3. Set dp[0][0] to true (empty strings interleave to form an empty string).
4. For each character in s1:
a. For each character in s2:

1. If the current character in s1 matches s3, update dp[i][j] based on dp[i-1][j].
2. If the current character in s2 matches s3, update dp[i][j] based on dp[i][j-1].



5. Return the value in dp[len(s1)][len(s2)], which represents whether s3 is an interleaving of s1 and s2.


These control abstractions and algorithms provide a high-level overview of how to approach each problem using the specified strategies. The actual implementation may require additional details and optimizations based on the specific requirements of each problem.
[04/12, 11:37 pm] Nikhil Wabale: I'll provide control abstractions and algorithms for problems D1, D2, and D3 using the backtracking strategy. Let's go through them one by one:

D1. N-Queens Problem

Control Abstraction:

```plaintext
function solveNQueens(n):
    board = initialize n x n chessboard with all empty squares
    solutions = empty list
    backtrack(board, 0, solutions)
    return solutions

function backtrack(board, row, solutions):
    if row == n:
        add current board configuration to solutions
        return
    
    for col in 0 to n-1:
        if isSafe(board, row, col):
            place queen at board[row][col]
            backtrack(board, row + 1, solutions)
            remove queen from board[row][col]

function isSafe(board, row, col):
    check if no queen threatens position (row, col)
    return true if safe, false otherwise
```

Algorithm:

1. Initialize an empty n x n chessboard.
2. Start the backtracking process from the first row (row 0).
3. For each column in the current row:
a. Check if it's safe to place a queen at the current position.
b. If safe, place the queen and recursively try to place queens in the next row.
c. If placing queens in subsequent rows leads to a solution, add it to the list of solutions.
d. If not, remove the queen (backtrack) and try the next column.
4. The isSafe function checks if the current position is under attack from any previously placed queens.
5. When all rows are filled (base case), add the current board configuration to the solutions.
6. Return all found solutions.


D2. Count All Paths in a Graph

Control Abstraction:

```plaintext
function countAllPaths(graph, start, end):
    visited = initialize all nodes as unvisited
    pathCount = 0
    dfs(graph, start, end, visited, pathCount)
    return pathCount

function dfs(graph, current, end, visited, pathCount):
    visited[current] = true
    
    if current == end:
        pathCount += 1
    else:
        for each neighbor of current in graph:
            if not visited[neighbor]:
                dfs(graph, neighbor, end, visited, pathCount)
    
    visited[current] = false  // Backtrack
```

Algorithm:

1. Initialize all nodes as unvisited and set the path count to 0.
2. Start DFS from the start node.
3. For each node:
a. Mark the current node as visited.
b. If the current node is the end node, increment the path count.
c. If not, for each unvisited neighbor of the current node:

1. Recursively perform DFS on the neighbor.
d. After exploring all neighbors, mark the current node as unvisited (backtrack).



4. Return the final path count.


D3. Print All Subsets of a Given Set or Array

Control Abstraction:

```plaintext
function printAllSubsets(set):
    subset = empty list
    backtrack(set, subset, 0)

function backtrack(set, subset, index):
    print subset
    
    for i from index to set.length - 1:
        add set[i] to subset
        backtrack(set, subset, i + 1)
        remove set[i] from subset (backtrack)
```

Algorithm:

1. Start with an empty subset.
2. Begin the backtracking process from index 0.
3. Print the current subset (initially empty).
4. For each element in the set, starting from the current index:
a. Add the current element to the subset.
b. Recursively generate subsets with the current element included, starting from the next index.
c. Remove the current element from the subset (backtrack).
5. This process generates all possible combinations of elements, including the empty set and the full set.


These control abstractions and algorithms provide a high-level overview of how to approach each problem using the backtracking strategy. The actual implementation may require additional details and optimizations based on the specific requirements of each problem.
