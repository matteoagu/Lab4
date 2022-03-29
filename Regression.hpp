#ifndef REGRESSION_HPP
#define REGRESSION_HPP

#include <stdexcept>
#include <vector>

struct Result {
  double A;
  double B;
};

class Regression {
  struct Point {
    double x;
    double y;
  };

  std::vector<Point> points_{};

 public:
  int size() const { return points_.size(); }

  void add(double, double);

  Result fit() const {
    Result res;
    double sum_x{};
    double sum_y{};
    double sum_xy{};
    double sum_x2{};

    if (points_.size() < 2) {
      throw std::runtime_error{"Not enough points to run a fit"};
    }

    for (auto const& p : points_) {
      sum_x += p.x;
      sum_y += p.y;
      sum_xy += p.x * p.y;
      sum_x2 += p.x * p.x;
    }

    double const d = points_.size() * sum_x2 - sum_x * sum_x;

    if (d == 0.) {
      throw std::runtime_error{"Trying to fit a vertical line"};
    }

    res.A = (sum_y * sum_x2 - sum_x * sum_xy) / d;          // termine noto
    res.B = (points_.size() * sum_xy - sum_x * sum_y) / d;  // coeff. di x

    return res;
  }
};

inline auto fit(Regression const& reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}

#endif