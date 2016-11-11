#include <gtest/gtest.h>

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

using namespace std;

const unsigned int thread_count = 1024;

const unsigned int max_count = 4294966272;
const unsigned int count_per_thread = max_count / thread_count;

void threadCode(unsigned int& i)
{
    for (;;)
    {
        ++i;
        if (i >= count_per_thread)
        {
            break;
        }
    }
}

TEST(ThreadTest, Run_1)
{
    vector<unsigned int> values(thread_count, 0);
    vector<std::thread> threads;

    cout << "max_count " << max_count << "; count_per_thread " << count_per_thread << endl;

    for (auto& v : values)
    {
        threads.push_back(thread(threadCode, ref(v)));
    }

    for (;;)
    {
        this_thread::sleep_for(chrono::milliseconds(100));
//        for (vector<unsigned int>::size_type i = 0; i != values.size(); ++i)
//        {
//            cout << "value " << i << ": " << values[i] << endl;
//        }

        unsigned int sum = accumulate(values.cbegin(), values.cend(), 0);
        if (sum >= max_count)
        {
            for (auto& t : threads)
            {
                if (t.joinable())
                {
                    t.join();
                }
            }

            cout << "sum " << sum << endl;
            break;
        }
    }
}
