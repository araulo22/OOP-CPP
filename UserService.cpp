//
// Created by araul on 28.03.2021.
//
#include "UserService.h"
#include <iostream>

///Constructor
///currentMoviePosition is the position in the watch list
UserService::UserService(Repository& repository, int currentMoviePosition) : repository{ repository }, currentMoviePosition{ currentMoviePosition }, currentMoviesByGenre{repository.getAllMovies()}{}

///Get the list of movies in the watch list
std::vector<Movie> UserService::userGetWatchList()
{
    return repository.getAllWatchListMovies();
}

///Get the list of movies with a given genre
int UserService::listMoviesByGenre(const std::string& genreGiven)
{
    currentMoviesByGenre = repository.getMoviesByGenre(genreGiven);
    if (currentMoviesByGenre.empty())
        return -1;
    currentMoviePosition = 0;
    return 1;
}

///Add a movie to the watch list by the current movie position
int UserService::addMovieToWatchList()
{
    return repository.addMovieToWatchlist(currentMoviesByGenre[currentMoviePosition]);
}

///Add a movie to the watch list by the given title
int UserService::addMovieToWatchListByTitle(const std::string& titleOfTheMovieToAdd)
{
    return repository.addMovieToWatchListByTitle(titleOfTheMovieToAdd);
}

///Iterate to the next movie in the list
void UserService::goToNextMovieByGenre()
{
    currentMoviePosition++;
    if(currentMoviePosition == currentMoviesByGenre.size())
        currentMoviePosition = 0;
}

///Get the current movie in the list
Movie UserService::getCurrentMovie()
{
    return currentMoviesByGenre[currentMoviePosition];
}

int UserService::removeMovieFromWatchList(const std::string &title, bool liked) {
    return repository.deleteMovieFromWatchList(title, liked);
}

std::vector<Movie> UserService::userGetMovieList() {
    return repository.getAllMovies();
}

int UserService::getWatchListLength() {
        return repository.getNumberOfMoviesWatchList();
}
