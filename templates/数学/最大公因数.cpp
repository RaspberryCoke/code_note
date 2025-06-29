int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int gcdIterative(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}