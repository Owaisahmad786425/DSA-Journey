class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int count = 0;

        while (k != 1) {
            // Find the largest power of 2 less than k
            long long power = 1;
            int index = 0;
            while (power * 2 < k) {
                power *= 2;
                index++;
            }

            k -= power;

            if (operations[index]) {
                count++;
            }
        }

        return 'a' + (count % 26);
    }
};
