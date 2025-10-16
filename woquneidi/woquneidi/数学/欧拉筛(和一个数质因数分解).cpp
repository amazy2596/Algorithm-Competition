struct LinearSieve 
{
    int n;
    vector<int> minp;
    vector<int> primes;
    vector<int> phi;
    vector<int> mu;
 
    LinearSieve(int n = 2e6 + 5) : n(n), minp(n + 1), phi(n + 1), mu(n + 1)
    {
        for (int i = 2; i <= n; i++) 
        {
            if (minp[i] == 0) 
            {
                minp[i] = i;
                phi[i] = i - 1;
                mu[i] = -1;
                primes.push_back(i);
            }
            for (int p : primes) 
            {
                if (i * p >= n || p > minp[i])
                    break;
 
                minp[i * p] = p;
                 
                if (p == minp[i])
                {
                    phi[i * p] = p * phi[i];
                    mu[i * p] = 0;
                    break;
                }
                else
                {
                    phi[i * p] = (p - 1) * phi[i];
                    mu[i * p] = -mu[i];
                }
            }
        }
 
        phi[1] = 1;
        mu[1] = 1;
    }
 
    map<int, int> factorize(int x) {
        map<int, int> facts;
 
        if (x <= n)
        {
            while (x > 1)
            {
                facts[minp[x]]++;
                x /= minp[x];
            }
 
            return facts;
        }
 
        for (int p : primes) 
        {
            if (p * p > x) break;
 
            if (x % p == 0) 
            {
                int count = 0;
                while (x % p == 0) 
                {
                    x /= p;
                    count++;
                }
                facts[p] = count;
            }
        }
 
        if (x > 1) facts[x] = 1;
 
        return facts;
    }
 
    bool is_prime(int x) 
    {
        if (x < 2 || x > n) return false;
        return minp[x] == x;
    }
}