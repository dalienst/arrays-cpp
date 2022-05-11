#include "splashkit.h"

#include <vector>

using std::vector;
using namespace std;

//returns a string of the input from the terminal
string read_string(string prompt)
{
    string result;
    write(prompt);
    result = read_line();
    return result;
}

//to read an integer from the user
int read_integer(string prompt) 
{
    string line;
    line = read_string(prompt);
    return convert_to_integer(line);
}

//to read a double from user
double read_double(string prompt)
{
    string line;
    line = read_string(prompt);
    return convert_to_double(line);
}

//function to get the total length of elements in the array
int total_length(vector<string> names)
{
    int result = 0;

    for(int i = 0; i < names.size(); i++)
    {
        string name = names[i];
        result += name.length();
    }

    return result;
}

//function to show whether or not the array contains a certain value/element
//returns 1/True if the element is present or 0/False if the element is not present
bool contains(vector<string> names, string value)
{
    for(int i = 0; i < names.size(); i++)
    {
        if (to_lowercase(names[i]) == to_lowercase(value))
        {
            return true;
        }
    }
    return false;
}

//function to show the longest name in the array
string longest_name(vector<string> names)
{
    string max;
    max = names[0];

    for(int i = 0; i < names.size(); i++)
    {
        if(max.length() < names[i].length())
        {
            max = names[i];
        }
    }
    return max;
}

//function to show index/position of an element in the array
int index_of(vector<string> names, string value)
{
    for(int i = 0; i < names.size(); i++)
    {
        if (to_lowercase(names[i]) == to_lowercase(value))
        {
            return i;
        }
    }
    return -1;
}

//procedure to print out the summary
void print_summary(const vector<string> &names)
{

    write("Total length: ");
    write_line(total_length(names));

    write("Longest name: ");
    write_line(longest_name(names));

    write("Contains London: ");
    write_line(contains(names, "London"));

    write("Index of Everest: ");
    write_line(index_of(names, "Everest"));
}


//main() body
int main()
{
    // #define SIZE 3
    vector<string> names;

    names.push_back(read_string("Enter a name: "));
    names.push_back(read_string("Enter a name: "));
    names.push_back(read_string("Enter a name: "));

    for(int i = 0; i < names.size(); i++)
    {
        write_line(names[i]);
    }

    // int i = 0;
    // while (i < SIZE)
    // {
    //     names[i] = read_string("Enter a name: ");
    //     i++;
    // }
    
    // for(i = 0; i < SIZE; i++)
    // {
    //     write_line(names[i]);
    // }

    print_summary(names);

    return 0;
}