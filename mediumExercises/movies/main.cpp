#include <iostream>
#include "Movies.h"

using namespace std;

void ExecuteMovies();

/*
    developing the foundation for a program
    for movie fanatics to keep track of what movies they have watched
    and how many times they watched each movie.

*/

int main()
{
    ExecuteMovies();
    return 0;
}

void ExecuteMovies()
{
    Movies my_movies;
    my_movies.display_movies();
    cout << "=======Test1========" << endl;
    my_movies.add_movie("Big", Movie::PG13, 2); // work
    my_movies.add_movie("Star Wars", Movie::PG, 5); // work
    my_movies.add_movie("Cinderella", Movie::PG, 7); // work
    cout << "=======Test2========" << endl;
    my_movies.display_movies(); // Big, Star Wars, Cinderella

    my_movies.add_movie("Cinderella" , Movie::PG , 7); // already exists
    my_movies.add_movie("Ice Age" , Movie::PG , 12); // work
    cout << "========Test3=======" << endl;
    my_movies.display_movies();   // Big, Star Wars, Cinderella, Ice Age

    my_movies.watchedMovie("Big");  // watched need to be 3
    my_movies.watchedMovie("Ice Age"); // watched need to be 13
    cout << "=======Test4========" << endl;
    my_movies.display_movies(); // should see watched increasment
    cout << "========Test5=======" << endl;
    my_movies.watchedMovie("Doest exists movie"); // not found!!
}