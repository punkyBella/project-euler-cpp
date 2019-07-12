#pragma once

#include <vector>
#include <algorithm>
#include <iterator>

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

    friend std::ostream &operator<<(std::ostream &out, const integer &rhs) {
        std::copy(rhs.digits_.rbegin(), rhs.digits_.rend(), std::ostream_iterator<uint16_t>(out, ""));
        return out;
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

    friend integer operator+(const integer &lhs, const integer &rhs) {
        std::vector<uint8_t> sum(std::max(lhs.digits_.size(), rhs.digits_.size()) + 1);
        for (int i = 0; i < lhs.digits_.size(); ++i) {
            sum[i] = lhs.digits_[i];
        }
        for (int j = 0; j < rhs.digits_.size(); ++j) {
            sum[j] += rhs.digits_[j];
        }
        for (int k = 0; k < sum.size(); ++k) {
            sum[k + 1] += sum[k] / 10;
            sum[k] %= 10;
        }
        if (sum.back() == 0) {
            sum.resize(sum.size() - 1);
        }
        integer result(0);
        result.digits_.swap(sum);
        return result;
    }
};

template <typename Integer>
Integer pow(const Integer &a, uint32_t n) {
    if (n == 0) return Integer(1);
    if (n % 2 == 1) return pow(a, n - 1) * a;
    Integer t = pow(a, n / 2);
    return t * t;
}

uint64_t divisor_sum(uint64_t n) {
    if (n == 0) return 0;
    uint64_t sum = 1;
    for (uint64_t c = 1; n % 2 == 0; n /= 2) {
        c *= 2;
        sum += c;
    }
    for (int k = 3; k <= n; k += 2) {
        uint64_t s = 1;
        for (uint64_t c = 1; n % k == 0; n /= k) {
            c *= k;
            s += c;
        }
        sum *= s;
    }
    return sum;
}

class PrimeSieve {
    std::vector<bool> bitset;   // bitset[k] == is_prime(2*k + 1)
public:
    PrimeSieve() = default;

    explicit PrimeSieve(uint32_t size) : bitset((size + 1) / 2, true) {
        bitset[0] = false;  // 1 is not prime
        for (int j = 1; (2 * j + 1) * (2 * j + 1) <= 2 * bitset.size() + 1; ++j) {
            for (int k = (2 * j + 1) * (2 * j + 1) / 2; k < bitset.size(); k += 2 * j + 1) {
                bitset[k] = false;
            }
        }
    }

    bool is_prime(uint32_t n) const {
        if (n % 2 == 0) return n == 2;
        if (n < 2 * bitset.size()) return bitset[n / 2];
        for (int k = 3; k * k <= n; k += 2) {
            if (n % k == 0)return false;
        }
        return true;
    }
};

