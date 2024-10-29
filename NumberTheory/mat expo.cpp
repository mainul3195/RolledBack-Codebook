mt19937 mt_rand(chrono::high_resolution_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
// const int N = 5e5 + 6;
// No of terms in the Recurrence Relation.
const int N = 4;
const long long M = 1000000007;
// Multiplies two matrices A and B and stores the result in A.
void multiply (long long A[N][N], long long B[N][N]){
  long long R[N][N];
  // Multiply A and B and store result in R.
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      R[i][j] = 0;
      for (int k = 0; k < N; k++){
        R[i][j] = (R[i][j] + A[i][k] * B[k][j]) % M;
      }
    }
  }
  // Copy contents of R in A.
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      A[i][j] = R[i][j];
    }
  }
}
// Raise matrix A to the power of n in O(log n).
void power_matrix (long long A[N][N], ll n){
  long long B[N][N];
  // B = Identity Matrix.
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      B[i][j] = A[i][j];
    }
  }
  // A = A * A ^ (n - 1).
  n = n - 1;
  while (n > 0){
    // If n is odd, A = A * B.
    if (n & 1)
      multiply (A, B);
    // B = B * B.
    multiply (B, B);
    // n = n / 2.
    n = n >> 1;
  }
}
// A = Coefficient Matrix, B = Base Matrix.
// It returns the nth term of the recurrence relation formed from A and B in O(log n).
long long solve_recurrence (long long A[N][N], long long B[N][1], ll n){
  //Base Cases.
  if (n < N)
    return B[N - 1 - n][0];
  // A = A ^ (n - N + 1).
  power_matrix (A, n - N + 1);
  long long result = 0;
  for (int i = 0; i < N; i++)
    result = (result + A[0][i] * B[i][0]) % M;
  return result;
}
void Solve()
{
  /*
        The recurrence relation used here is: -
        R(n) = 2 * R(n-1) + R(n-2) + 3 * R(n-3) + 3.
        Base Cases: R(0) = 1, R(1) = 2, R(2) = 3.
    */
  // Forming the Coefficient Matrix
  long long A[N][N] = {{3, 2, 1, 1}, {1, 0, 0, 0}, {0, 1, 0, 0}, {0, 0, 0, 1}};
  //Forming the Base Matrix
  long long B[N][1] = {{3}, {2}, {1}, {3}};
  ll n;
  cin >> n;
  if (n <= 2){
    cout << n + 1 << endl;
    return ;
  }
  long long R_n = solve_recurrence (A, B, n + 1);
  // cout << "R_" << n << " = " << R_n;
  cout << R_n << endl;
}