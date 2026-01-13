#include "Movie.h"
#include <iostream>

Movie::Movie()
{
    Movie("No name", G, 0);
}

Movie::Movie(const std::string &movie_name, MOVIE_RATING movie_rating, int watched)
    : movie_name{movie_name}, movie_rating{movie_rating}, watched{watched}
{
}

std::string Movie::getMovieName() const
{
    return movie_name;
}

void Movie::display_movie() const
{
    std::cout << movie_name  << " , " << getMovieRating() << " , " << watched << std::endl;
}

std::string Movie::getMovieRating() const
{
    switch (movie_rating)
    {
    case G:
        return "G";

    case PG:
        return "PG";
    case PG13:
        return "PG-13";
    case R:
        return "R";
    }
    return "INVALID!!!!!!!!!!!! from getMovieRating()";
}

void Movie::add_watch(){
    watched++;
}

/*
        std::string movie_name;
    MOVIE_RATING movie_rating;
    int watched;
*/