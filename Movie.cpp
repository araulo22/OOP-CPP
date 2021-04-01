//
// Created by araul on 28.03.2021.
//

#include "Movie.h"
#include <algorithm>
#include <iostream>

Movie::Movie(const std::string &a, const std::string &b, const std::string &c, int d, int e) {
    title = a;
    genre = b;
    trailer = c;
    year = d;
    likes = e;
}

const std::string& Movie::getTitle() const {
    return title;
}

void Movie::setTitle(const std::string &title) {
    Movie::title = title;
}

const std::string& Movie::getGenre() const {
    return genre;
}

void Movie::setGenre(const std::string &genre) {
    Movie::genre = genre;
}

const std::string& Movie::getTrailer() const {
    return trailer;
}

void Movie::setTrailer(const std::string &trailer) {
    Movie::trailer = trailer;
}

int Movie::getYear() const {
    return year;
}

void Movie::setYear(int year) {
    Movie::year = year;
}

int Movie::getLikes() const {
    return likes;
}

void Movie::setLikes(int likes) {
    Movie::likes = likes;
}

bool Movie::operator==(const Movie &movie) const {
    return title == movie.getTitle();
}

bool Movie::operator!=(const Movie &movie) const {
    return !(movie == *this);
}

void Movie::operator=(const Movie &movie) {
    title = movie.getTitle();
    genre = movie.getGenre();
    trailer = movie.getTrailer();
    year = movie.getYear();
    likes = movie.getLikes();
}

std::string Movie::toString() const {
    std::string movie = "Title: " + title + ", Genre: " + genre + ", Released: " + std::to_string(year) + ", Likes: " + std::to_string(likes) + ", Trailer: " + trailer + ";";
    return movie;
}

std::ostream &operator<<(std::ostream &out, const Movie &movie) {
    out << movie.toString();
    return out;
}