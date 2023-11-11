#include <iostream>
#include <vector>

// Function to calculate mean
double mean(const std::vector<double>& v) {
    double sum = 0;
    for (auto& i : v) sum += i;
    return sum / v.size();
}

// Function to calculate covariance
double covariance(const std::vector<double>& x, const std::vector<double>& y) {
    double sum = 0;
    for (size_t i = 0; i < x.size(); i++)
        sum += (x[i] - mean(x)) * (y[i] - mean(y));
    return sum / (x.size() - 1);
}

// Function to calculate variance
double variance(const std::vector<double>& v) {
    double sum = 0;
    for (auto& i : v) sum += (i - mean(v)) * (i - mean(v));
    return sum / (v.size() - 1);
}

// Main function to perform linear regression
void linearRegression(const std::vector<double>& x, const std::vector<double>& y) {
    double a = covariance(x, y) / variance(x);
    double b = mean(y) - a * mean(x);

    std::cout << "Linear Regression Equation: y = " << a << " * x + " << b << std::endl
