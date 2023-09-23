double BarrierOption::valueUpAndOutPut(double price, double strike, double barrier,
                                       double rate, double dividend, double vol, double rebate, double T, int N, char exercise)
{
    int i, j;
    double pd;
    double pm;
    double pu;
    double S[120][100];
    double p[120][100];
    double up = 0.0;
    double down = 0.0;
    double dt = T / N;
    double drift = rate – dividend – vol * vol / 2;
    double dx = vol * sqrt(3 * dt);
    // compute risk neutral probabilities
    pu = sqrt(dt / 12) * (drift / vol) + 0.16667;
    pd = -sqrt(dt / 12) * (drift / vol) + 0.16667;
    pm = 0.666667;
    up = exp(dx);
    down = 1 / up;
    // compute the stock price at each node
    for (i = N; i >= 0; i--)
    {
        for (j = -i; j <= i; j++)
        {
            S[i][j] = price * pow(up, j);
        }
    }
}
// compute payoff at maturity
for (j = N; j >= -N; j--)
{
    if (S[N][j] < barrier)
        p[N][j] = strike – S[N][j];
    else
        p[N][j] = rebate;
}
// compute payoffs at all other time steps
for (i = N - 1; i >= 0; i--)
{
    for (j = i; j >= -i; j--)
    {
        if (S[i][j] < barrier)
        {
            // for counters
            // down probability
            // middle probability
            // up probability
            // stores stock prices
            // put prices
            // up movement
            // down movement
            // time step
            // drift rate
            // state step
            p[i][j] = exp(-rate * dt) * (pu * p[i + 1][j + 1] + pm * p[i + 1][j] + pd * p[i + 1][j - 1]);
            if (exercise == ‘A’)
                p[i][j] = max(p[i][j], strike - S[i][j]);
            else
                p[i][j] = rebate;
            // Derman Kani adjustment
            if ((S[i][j] < barrier) && (S[i][j + 1] >= barrier))
            {
                p[i][j] = (rebate - p[i][j]) / (S[i][j + 1] – S[i][j]) * (barrier – S[i][j]);
            }
        }
    }
}
return p[0][0];
}