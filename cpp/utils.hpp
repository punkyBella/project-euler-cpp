#pragma once

class integer {
    std::vector<uint8_t> digits_ {};
public:
    explicit integer(uint64_t n) {
        while (n != 0) {
            digits_.push_back(n % 10);
            n /= 10;
        }
    }

    const std::vector<uint8_t> &digits() const {
        return digits_;
    }

    friend integer operator*(const integer &lhs, const integer &rhs) {
        std::vector<uint32_t> sum(lhs.digits_.size() + rhs.digits_.size());
        for (int i = 0; i < lhs.digits_.size(); ++i) {
            for (int j = 0; j < rhs.digits_.size(); ++j) {
                sum[i + j] += lhs.digits_[i] * rhs.digits_[j];
            }
        }
        for (int k = 0; k < sum.size(); ++k) {
            sum[k + 1] += sum[k] / 10;
            sum[k] %= 10;
        }
        if (sum.back() == 0) {
            sum.resize(sum.size() - 1);
        }
        integer prod(0);
        prod.digits_.resize(sum.size());
        std::copy(sum.begin(), sum.end(), prod.digits_.begin());
        return prod;
    }
};

integer pow(const integer &a, uint32_t n) {
    if (n == 0) return integer(1);
    if (n % 2 == 1) return pow(a, n - 1) * a;
    integer t = pow(a, n / 2);
    return t * t;
}