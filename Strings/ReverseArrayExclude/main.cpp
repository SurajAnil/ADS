/*
 * A C++ Program that Reverses a string without affecting any special characters
 * within the string
 *
 * Input:   s = "a,b$c"
 * Output:  s = "c,b$a"
 *
 * Copyright (c) 2017 Suraj Bennur
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
 * OUT  OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/**
 * @brief reverseString : Function to reverse a string without moving special characters
 * @param s : Given string
 */
void reverseString(string &s)
{
    int end = s.length() - 1;
    int start = 0;
    // iterate untill start >= end
    while(start < end)
    {
        /* isalnum -> is alpha numeric */
        if(!isalnum(s[start])) {start++; continue;}
        if(!isalnum(s[end])) {end--; continue;}
        swap(s[start++], s[end--]);
    }
}

// driver function
int main()
{
    string s = "Ab,c,de!$";
    reverseString(s);
    cout << s << endl;
    return 0;
}
