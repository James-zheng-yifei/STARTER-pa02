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
    Movies movie;

    string line, movieName;
    double movieRating;
    // Read each file and store the name and rating
    while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
            // Use std::string movieName and double movieRating
            // to construct your Movie objects
            // cout << movieName << " has rating " << movieRating << endl;
            // insert elements into your data structure
            movie.insert(movieName, movieRating);
    }

    movieFile.close();
    movie.sortMovies();
    if (argc == 2){
            //print all the movies in ascending alphabetical order of movie names
            movie.printMoviesInOrder();
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
    for(const auto &prefix : prefixes) {

        auto matched = movie.getPrefixMovies(prefix);

        if(matched.empty()) {
            cout << "No movies found with prefix "
                << prefix;
        }

        else for(const auto &m : matched) {
            cout << m.first << ", "
                << fixed << setprecision(1)
                << m.second << endl;
        }
        cout << '\n';

    }
    //cout << "No movies found with prefix "<<"<replace with prefix>" << endl;

    //  For each prefix,
    //  Print the highest rated movie with that prefix if it exists.
    //cout << "Best movie with prefix " << "<replace with prefix>" << " is: " << "replace with movie name" << " with rating " << std::fixed << std::setprecision(1) << "replace with movie rating" << endl;
    for(const auto &prefix : prefixes) {

        auto best = movie.getBestMovieWithPrefix(prefix);

        if(best) {
            cout << "Best movie with prefix "
                << prefix
                << " is: "
                << best->first
                << " with rating "
                << fixed << setprecision(1)
                << best->second
                << endl;
        }
    }
    return 0;
}

/* 
Part 3: Time and Space Complexity Analysis

Algorithm design: Used lower_bound to find the start of the prefix range and scanned the interval to get matching movies.

getPrefixMovies:

Time: O(log n + k log k) — binary search for start (O(log n)) + sorting k matching movies (O(k log k))

Space: O(k) — it stores matching movies in a temporary vector

getBestMovieWithPrefix:

Time: O(log n + k) — binary search + scanning k matching movies to find max rating

Space: O(1) — no extra storage needed

Tradeoff: Optimizing for low time complexity requires sorting and storing matching movies, which increases space usage. If only the best movie is needed, space remains minimal.

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