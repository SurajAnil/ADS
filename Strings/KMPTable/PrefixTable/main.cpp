/*
 * A C++ program to implement a Prefix table for the KMP algorithm
 *
 * MIT License
 *
 * Copyright (c) 2017 Benn
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#include <iostream>
#include <string>
#include <vector>

using namespace std;

void prefix_table(string s)
{
    int m = s.length();
    int i = 1, j = 0;

    vector<int> F(m, 0);

    while(i < m)
    {
        /* if they equal each other, increment F[i] by one,
         * increment the i and j counters.
         */
        if(s[i] == s[j])
        {
            F[i++] = j++ + 1;
        }
        /* If they don't equal each other,
         * assign j with the previous F[] value.
         */
        else if(j > 0)
        {
            j = F[j - 1];
        }
        /* Else the next F[] value should be 0.
         */
        else
        {
            F[i++] = 0;
        }
    }
}

// driver function
int main()
{
    string s = "abba";
    prefix_table(s);
    return 0;
}

