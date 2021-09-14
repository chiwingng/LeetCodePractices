class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> counts(26);
        for (char&c : text) counts[c - 'a']++;
        int result1 = min(min(counts[0], counts[1]), counts[13]); // a,b,n
        int result2 = min(counts['l' - 'a'], counts['o' - 'a']);
        return min(result1, result2/2);
    }
};
