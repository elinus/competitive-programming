int Solution::solve(vector<string> &A) {
  if (A.size() < 3) {
    return 0;
  }

  double a = stod(A[0]);
  double b = stod(A[1]);
  double c = stod(A[2]);

  for (int i = 3; i < A.size(); i++) {
    if (a + b + c > 1 && a + b + c < 2) {
      return 1;
    }

    double t = stod(A[i]);

    if (a + b + c >= 2) {
      if (a > b && a > c) {
        a = t;
      } else if (b > c && b > a) {
        b = t;
      } else {
        c = t;
      }
    } else {
      if (a < b && a < c) {
        a = t;
      } else if (b < c && b < a) {
        b = t;
      } else {
        c = t;
      }
    }
  }

  if (a + b + c > 1 && a + b + c < 2) {
    return 1;
  } else {
    return 0;
  }
}
