#include <cstring>
#include <cstdio>

class Book {
private:
    char* title;
    char* authors;
    int publishingYear;

public:
    Book() {
        publishingYear = 0;
        title = nullptr;
        authors = nullptr;
    }

    Book(const char* title, const char* authors, int publishingYear) {
        this->publishingYear = publishingYear;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    Book(const Book &book) {
        publishingYear = book.publishingYear;
        title = new char[strlen(book.title) + 1];
        strcpy(title, book.title);
        authors = new char[strlen(book.authors) + 1];
        strcpy(authors, book.authors);
    }
    
    void setTitle(const char* title) {
        delete[] this->title;
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    void setAuthors(const char* authors) {
        delete[] this->authors;
        this->authors = new char[strlen(authors) + 1];
        strcpy(this->authors, authors);
    }

    void setPublishingYear(int publishingYear) {
        this->publishingYear = publishingYear;
    }

    char* getTitle() const {
        return title;
    }

    char* getAuthors() const {
        return authors;
    }

    int getPublishingYear() const {
        return publishingYear;
    }

    ~Book() {
        delete[] title;
        delete[] authors;
    }

    void printBook() {
        printf("%s\n%s\n%d\n", this->title, this->authors, this->publishingYear);
    }
};