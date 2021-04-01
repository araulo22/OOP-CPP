//
// Created by araul on 28.03.2021.
//

#ifndef A45_ARAULO22_REPOSITORY_H
#define A45_ARAULO22_REPOSITORY_H
#endif //A45_ARAULO22_REPOSITORY_H
#pragma once
#include "Movie.h"
#include <vector>
#include <algorithm>


class Repository
{
private:
    std::vector<Movie> movieList;
    std::vector<Movie> userWatchList;
public:
    Repository();
    int addMovie(const Movie& movieToAdd);
    int deleteMovie(const Movie& movieToDelete);
    int updateMovie(const Movie& ToUpdateWith);
    std::vector<Movie> getMoviesByGenre(const std::string& genreGiven = "");
    std::vector<Movie> getAllMovies();
    std::vector<Movie> getAllWatchListMovies();
    Movie getMovieAtPosition(int positionOfMovie);
    int getNumberOfMovies();
    int addMovieToWatchlist(const Movie& movieToAdd);
    int addMovieToWatchListByTitle(const std::string& tempMovie);
    int getNumberOfMoviesWatchList();
    int deleteMovieFromWatchList(const std::string& title, bool liked);
    void addLike(const std::string& title);
};