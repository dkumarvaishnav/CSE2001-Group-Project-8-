#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>

struct Book {
    std::string book_id;
    std::string author_name;
    std::string price;
    std::string no_of_pages;
    std::string publisher;
    std::string year_of_publishing;
};

std::vector<Book> readBooksFromFile(const std::string& filename) {
    std::vector<Book> books;
    std::ifstream file(filename);
    std::string line;

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


void writeBooksToFile(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream file(filename);

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

int main() {
    std::string input_file = "books.csv";
    std::string output_file = "sorted_books.csv";

    std::vector<Book> books = readBooksFromFile(input_file);

    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.author_name < b.author_name;
    });

    writeBooksToFile(output_file, books);

    std::cout << "Books have been sorted by author name and saved to " << output_file << std::endl;

    return 0;
}