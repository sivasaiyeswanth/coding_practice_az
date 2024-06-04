// Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

// You have the following three operations permitted on a word:

// Insert a character
// Delete a character
// Replace a character
// Input Format
// Input contains 2 strings word1 and word2.

// Output Format
// Output the minimum number of operations required to convert 
// �
// �
// �
// �
// 1
// word1 to 
// �
// �
// �
// �
// 2
// word2.

#include <bits/stdc++.h>
using namespace std;

void solution()
{
    string word1, word2;
    cin >> word1 >> word2;
    int n = word1.size(), m = word2.size();
    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i; // remove this many characters to convert word1 to word2
    }
    for (int j = 0; j <= m; j++)
    {
        dp[0][j] = j; // insert this many characters to convert word1 to word2
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]});
                // insert     // remove     // replace
            }
        }
    }
    cout << dp[n][m] << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solution();
    return 0;
}
// To apply DP, we define the state 
// �
// �
// [
// �
// ]
// [
// �
// ]
// dp[i][j] to be the minimum number of operations to convert 
// �
// �
// �
// �
// 1
// [
// 0..
// �
// )
// word1[0..i) to 
// �
// �
// �
// �
// 2
// [
// 0..
// �
// )
// word2[0..j).

// For the base case, that is, to convert a string to an empty string, the minimum number of operations (deletions) is just the length of the string. So we have 
// �
// �
// [
// �
// ]
// [
// 0
// ]
// =
// �
// dp[i][0]=i and 
// �
// �
// [
// 0
// ]
// [
// �
// ]
// =
// �
// dp[0][j]=j.

// For the general case to convert 
// �
// �
// �
// �
// 1
// [
// 0..
// �
// )
// word1[0..i) to 
// �
// �
// �
// �
// 2
// [
// 0..
// �
// )
// word2[0..j), we break this problem down into sub-problems. Suppose we have already known how to convert 
// �
// �
// �
// �
// 1
// [
// 0..
// �
// −
// 1
// )
// word1[0..i−1) to 
// �
// �
// �
// �
// 2
// [
// 0..
// �
// −
// 1
// )
// word2[0..j−1) 
// (
// �
// �
// [
// �
// −
// 1
// ]
// [
// �
// −
// 1
// ]
// )
// (dp[i−1][j−1]), if 
// �
// �
// �
// �
// 1
// [
// �
// −
// 1
// ]
// =
// =
// �
// �
// �
// �
// 2
// [
// �
// −
// 1
// ]
// word1[i−1]==word2[j−1], then no more operation is needed and 
// �
// �
// [
// �
// ]
// [
// �
// ]
// =
// �
// �
// [
// �
// −
// 1
// ]
// [
// �
// −
// 1
// ]
// dp[i][j]=dp[i−1][j−1].

// If 
// �
// �
// �
// �
// 1
// [
// �
// −
// 1
// ]
// !
// =
// �
// �
// �
// �
// 2
// [
// �
// −
// 1
// ]
// word1[i−1]!=word2[j−1], we need to consider three cases.

// Replace 
// �
// �
// �
// �
// 1
// [
// �
// −
// 1
// ]
// word1[i−1] by 
// �
// �
// �
// �
// 2
// [
// �
// −
// 1
// ]
// (
// �
// �
// [
// �
// ]
// [
// �
// ]
// =
// �
// �
// [
// �
// −
// 1
// ]
// [
// �
// −
// 1
// ]
// +
// 1
// )
// ;
// word2[j−1](dp[i][j]=dp[i−1][j−1]+1); If 

// word1[0..i−1)=word2[0..j) then delete 

// word1[i−1](dp[i][j]=dp[i−1][j]+1); 

// Ifword1[0..i) + word2[j - 1] = word2[0..j)

// theninsertword2[j - 1]

// toword1[0..i) (dp[i][j] = dp[i][j - 1] + 1)$.

// So when 

// word1[i−1]!=word2[j−1], 

// dp[i][j] will just be the minimum of the above three.