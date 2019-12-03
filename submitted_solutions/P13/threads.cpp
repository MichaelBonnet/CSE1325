#include <cmath>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

// To measure performance, use
// $ make timep
//
// which relies on the bash command
// $ time (./a.out > results.txt)

class Prime_numbers {
  public:
    Prime_numbers(int num_threads = 1): NUM_THREADS{num_threads} { }

    // Returns true if "number" is a prime number
    bool is_prime (int number) 
    {
        if (number < 2) 
        {
            return false;
        }
        for (int i=2; i <= std::sqrt(number); ++i) 
        {
            if ((number % i) == 0) return false;
        }
        return true;
    }

    // find_primes is the algorithm to be run as multiple threads,
    //     adding each prime found to the shared vector "primes".
    // NOTE: You'll likely need to break out the for loop as a separate
    //     method, which will be the code executed by each thread.
    //     The find_prime method will just create and managed the threads.
    void find_primes(int lower, int upper) 
    {
        int range = ceil((upper - lower) / NUM_THREADS);
        int ranges[NUM_THREADS+1];
        for (int i = 0; i < NUM_THREADS; ++i)
        {
            ranges[0] = lower;
            ranges[i+1] = ranges[i] + range;
        }
        ranges[NUM_THREADS] = upper;

        /*
        int range = (upper - lower) / NUM_THREADS;
        int ranges[NUM_THREADS+1];
        for (int i = 0; i < NUM_THREADS; ++i)
        {
            ranges[0] = lower;
            ranges[i+1] = ranges[i] + range;
        */

        // for (int i = 0; i < NUM_THREADS, ++i)
        // {
        //     for (int j = lower, j <= upper, ++j)
        //     {
        //         ranges1[i]
        //     }
        // }

        // Launch a group of threads
        std::thread t[NUM_THREADS];
        for (int i = 0; i < NUM_THREADS; ++i) 
        {
            t[i] = std::thread(&Prime_numbers::find_primes_thread, this, ranges[i], ranges[i+1]);
        }

        // Join the threads with the main thread
        for (int i = 0; i < NUM_THREADS; ++i) t[i].join();
    }   

    void find_primes_thread(int lower, int upper)
    {
        for (int i=lower; i<=upper; ++i) 
        {
            if (is_prime(i)) 
            {
                m.lock(); primes.push_back(i); m.unlock();
            }
        }
    } 

    typedef std::vector<int> Primes;

    // Iterating Prime_numbers will iterate attribute primes
    typedef Primes::iterator iterator;
    typedef Primes::const_iterator const_iterator;

    iterator begin() 
    {
        return primes.begin();
    }

    iterator end() 
    {
        return primes.end();
    }

  private:
    const int NUM_THREADS;
    std::mutex m;

    // Vector primes will contain all of the primes found
    Primes primes;
};

int main(int argc, char* argv[]) {
    // Determine number of threads requested
    int threads = 2;
    if(argc > 1) threads = atoi(argv[1]);
    Prime_numbers prime_numbers(threads);

    // Determine maximum integer to search
    int max_int = 15000000;
    if(argc > 2) max_int = atoi(argv[2]);

    // Search and identify all primes between 2 and max_int
    prime_numbers.find_primes(2, max_int);

    // Print all primes that were found  
    for (int p : prime_numbers) std::cout << p << '\n';
    std::cout << std::endl;
}
