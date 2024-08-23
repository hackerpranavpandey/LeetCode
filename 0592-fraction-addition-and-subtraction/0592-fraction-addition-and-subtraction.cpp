class Solution {
private:
    int find_lcm(int a, int b) {
        if (a % b == 0)
            return a;
        else if (b % a == 0)
            return b;
        int lcm = a * b, min_num = min(a, b), max_div = 1;
        for (int i = 2; i <= min_num; i++) {
            if (a % i == 0 && b % i == 0)
                max_div = i;
        }
        return lcm / max_div;
    }

    int find_hcf(int a, int b) {
        int hcf = 1;
        for (int i = 2; i <= min(a, b); i++) {
            if (a % i == 0 && b % i == 0)
                hcf = i;
        }
        return hcf;
    }

public:
    string fractionAddition(string expression) {
        vector<int> den;
        vector<int> num;
        int i = 0, n = expression.size();

        while (i < n) {
            int sign = 1;
            if (expression[i] == '+' || expression[i] == '-') {
                if (expression[i] == '-')
                    sign = -1;
                i++;
            }

            int numerator = 0;
            while (i < n && isdigit(expression[i])) {
                numerator = numerator * 10 + (expression[i] - '0');
                i++;
            }
            numerator *= sign;

            if (i < n && expression[i] == '/') {
                i++;
                int denominator = 0;
                while (i < n && isdigit(expression[i])) {
                    denominator = denominator * 10 + (expression[i] - '0');
                    i++;
                }
                num.push_back(numerator);
                den.push_back(denominator);
            }
        }

        // Calculate the LCM of all denominators
        int lcm = den[0];
        for (int i = 1; i < den.size(); i++) {
            lcm = find_lcm(lcm, den[i]);
        }

        // Adjust numerators to the common denominator and calculate the sum
        int sum = 0;
        for (int i = 0; i < num.size(); i++) {
            num[i] = num[i] * (lcm / den[i]);
            sum += num[i];
        }

        if (sum == 0)
            return "0/1";

        int hcf = find_hcf(abs(sum), lcm);
        sum /= hcf;
        lcm /= hcf;

        return to_string(sum) + "/" + to_string(lcm);
    }
};
