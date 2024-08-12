#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

// Define a structure to hold book details
struct Book {
    std::string book_id;
    std::string author_name;
    std::string price;
    std::string no_of_pages;
    std::string publisher;
    std::string year_of_publishing;
};

// Function to read book details from a file
std::vector<Book> readBooksFromFile(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    std::string line;

    // Skip the header line
    std::getline(file, line);

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        Book book;

        std::getline(ss, book.book_id, ',');
        std::getline(ss, book.author_name, ',');
        std::getline(ss, book.price, ',');
        std::getline(ss, book.no_of_pages, ',');
        std::getline(ss, book.publisher, ',');
        std::getline(ss, book.year_of_publishing, ',');

        books.push_back(book);
    }

    return books;
}


// Function to write book details to a file
void writeBooksToFile(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream file(filename);

    // Write the header line
    file << "book_id,author_name,price,no_of_pages,publisher,year_of_publishing\n";

    for (const auto& book : books) {
        file << book.book_id << ','
             << book.author_name << ','
             << book.price << ','
             << book.no_of_pages << ','
             << book.publisher << ','
             << book.year_of_publishing << '\n';
    }
}