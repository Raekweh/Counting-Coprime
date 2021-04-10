#include <iostream>
#include <vector>

// Full Name: Raymond Li
// Student Number: 18028813

using namespace std;

//GCD function for Brute force method
unsigned GCD(unsigned x, unsigned n)
{
    // Condition to check if number x is zero
    if (x == 0)
    {
        return n;
    }
    //Returns the modules between the two numbers and number n
    return GCD(n % x, x);
}

//Brute force Method
unsigned Bruteforce(unsigned n)
{
    //Create an array of n*n boolean flags, all intialized to true
    vector<bool> is_coprime(n * n, true);

    //Declaring count
    unsigned count = 0;
    for (unsigned i = 1; i <= n; i++)
    {
        // Displaying the amount of coprimes in the specific column
        unsigned displaycount = 0;
        for (unsigned j = 0; j < i; j++)
        {
            //Calls GCD function to check if GCD = 1
            if (GCD(j, i) == 1)
            {
                //Increment the count of Coprime numbers
                count++;
                //Increment the count of Coprime numbers in the specific column
                displaycount++;
            }
        }
        cout << displaycount << ' ';
    }
    cout << endl;
    return count;
}

//Sieve of Eratosthenes Method
unsigned SOE(unsigned n)
{
    //Create an array of n+1 boolean flags, all intialized to true
    vector <bool> is_prime(n + 1, true);
    for (unsigned i = 0; i <= n; i++)
    {
        //Set all numbers below 2 as non prime number
        if (i < 2)
        {
            is_prime[i] = false;
        }
        if (is_prime[i] == true)
        {
            //Set all multiples of i to false
            for (unsigned j = i * 2; j <= n; j += i)
            {
                is_prime[j] = false;
            }
        }
    }

    //Create an array of n*n boolean flags, all intialized to true
    vector<bool> is_coprime(n * n, true);

    //Initialize the count of Coprime numbers to zero
    unsigned counter = 0;

    for (unsigned cols = 0; cols < n; cols++)
    {
        for (unsigned rows = 0; rows < n; rows++)
        {
            //Condition for setting all the variables at nxn and under to false
            if (rows <= cols && (rows || cols != 0))
            {
                //Setting variables to false (zeros)
                is_coprime[rows * n + cols] = false;
            }

            //Condition to setting everything above nxn to false
            if ((is_prime[rows + 1] == true))
            {
                for (unsigned k = 0; k <= n; k++)
                {
                    //condition where number k mulitply rows is equal to columns
                    if (k * (rows + 1) == (cols + 1))
                    {
                        //Set all numbers that are multiples of the number and if they are prime to false
                        for (unsigned j = rows; j <= n; j += (rows + 1))
                        {
                            is_coprime[j * n + cols] = false;
                        }
                    }
                }
            }

            if (is_coprime[rows * n + cols] == 1)
            {
                //Increment the count of Coprime numbers
                counter++;
            }
            cout << is_coprime[rows * n + cols] << ' ';
        }
        cout << endl;
    }
    return counter;
}

//Main Function
int main()
{
    unsigned a;
    //Getting user to input a value to count the coprime
    cout << "What number would you like to enter?: ";
    cin >> a;
    //Calls for the Sieve of Eratosthenes function 
    unsigned coprimeSOE = SOE(a);
    //Returns the number of coprimes for Sieve of Eratosthenes
    cout << "The number of coprimes in Sieve of Eratosthenes " << a << " is " << coprimeSOE << endl;
    cout << endl;

    //Calls for the Brute Force function
    unsigned coprimeBruteForce = Bruteforce(a);
    //Returns the number of coprimes for Brute force methid
    cout << "The number of coprimes for brute force method is " << a << " is " << coprimeBruteForce << endl;
}