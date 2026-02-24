// Winter'24
// Instructor: Diba Mirza
// Student name: Yifei Zheng
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>
#include <sstream>
using namespace std;

#include "utilities.h"
#include "movies.h"

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " moviesFilename prefixFilename " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
    // Create an object of a STL data-structure to store all the movies

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
    }

    movieFile.close();

    if (argc == 2){
            //print all the movies in ascending alphabetical order of movie names
            return 0;
    }

    ifstream prefixFile (argv[2]);

    if (prefixFile.fail()) {
        cerr << "Could not open file " << argv[2];
        exit(1);
    }

    vector<string> prefixes;
    while (getline (prefixFile, line)) {
        if (!line.empty()) {
            prefixes.push_back(line);
        }
    }

    //  For each prefix,
    //  Find all movies that have that prefix and store them in an appropriate data structure
    //  If no movie with that prefix exists print the following message
    cout << "No movies found with prefix "<<"<replace with prefix>" << endl;

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    cout << "Best movie with prefix " << "<replace with prefix>" << " is: " << "replace with movie name" << " with rating " << std::fixed << std::setprecision(1) << "replace with movie rating" << endl;

    return 0;
}

/* 
Part 3: Time and Space Complexity Analysis

Let n = number of movies, m = number of prefixes, k = number of movies matching a given prefix.

Time Complexity:
- For each prefix, I scan all n movies to check prefix match: O(n)
- For each prefix, collecting matching movies takes O(k), finding the highest rating takes O(k)
- Therefore, per prefix: O(n + k + k) = O(n)
- For m prefixes: O(m * n)

Space Complexity:
- I use a temporary vector to store matching movies: O(k) <= O(n)
- Other variables use O(1)
- Overall space complexity: O(n)

Optimized approach (without temporary vector):
- Keep only the current best movie while scanning: O(1) extra space
- Time complexity remains O(m * n)
*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    int commaIndex = line.find_last_of(",");
    movieName = line.substr(0, commaIndex);
    movieRating = stod(line.substr(commaIndex+1));
    if (movieName[0] == '\"') {
        movieName = movieName.substr(1, movieName.length() - 2);
    }
    return true;
}