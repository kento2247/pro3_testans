extern int Over_count;

double update_variance(double x) {
  static double x2_sum = 0;
  static int n = 0;
  static double sum = 0;
  double u2;
  double sigma2;

  n++;
  sum += x;
  x2_sum += x * x;
  u2 = (sum / n) * (sum / n);

  sigma2 = x2_sum / n - u2;
  if (sigma2 > 3.0) Over_count++;
  return sigma2;
}