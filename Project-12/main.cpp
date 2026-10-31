#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <stdexcept>

using namespace std;

// ==================================================
// SECTION 1: BOOK MODEL
// Stores information about each book.
// ==================================================

struct Book
{
    int id;
    string title;
    string author;
    bool available;
};

// ==================================================
// SECTION 2: CUSTOM EXCEPTION CLASSES
// These classes handle different library errors.
// ==================================================

class LibraryException : public runtime_error
{
public:
    explicit LibraryException(const string &message)
        : runtime_error(message) {}
};

class InvalidBookData : public LibraryException
{
public:
    explicit InvalidBookData(const string &message)
        : LibraryException(message) {}
};

class InvalidInput : public LibraryException
{
public:
    explicit InvalidInput(const string &message)
        : LibraryException(message) {}
};

class DuplicateBookId : public LibraryException
{
public:
    explicit DuplicateBookId(const string &message)
        : LibraryException(message) {}
};

class BookNotFound : public LibraryException
{
public:
    explicit BookNotFound(const string &message)
        : LibraryException(message) {}
};

class BookUnavailable : public LibraryException
{
public:
    explicit BookUnavailable(const string &message)
        : LibraryException(message) {}
};

class BookAlreadyAvailable : public LibraryException
{
public:
    explicit BookAlreadyAvailable(const string &message)
        : LibraryException(message) {}
};

// ==================================================
// SECTION 3: LIBRARY CLASS
// Manages books using STL map and vector.
// ==================================================

class Library
{

private:
    map<int, Book> books;
    string filePath;

    // Load book records from CSV file.
    void loadFromFile()
    {

        ifstream file(filePath);

        if (!file)
            return;

        string line;
        bool firstLine = true;

        while (getline(file, line))
        {

            if (line.empty())
                continue;

            if (firstLine &&
                line == "id,title,author,available")
            {

                firstLine = false;
                continue;
            }

            firstLine = false;

            stringstream row(line);

            string idText, title, author, availableText;

            if (!getline(row, idText, ',') ||
                !getline(row, title, ',') ||
                !getline(row, author, ',') ||
                !getline(row, availableText))
            {

                throw LibraryException(
                    "Invalid record found in CSV file.");
            }

            try
            {

                size_t used = 0;
                int id = stoi(idText, &used);

                if (used != idText.size() || id <= 0)
                    throw LibraryException("Invalid book ID in CSV.");

                if (availableText != "0" &&
                    availableText != "1")
                    throw LibraryException("Invalid availability value.");

                Book book = {
                    id, title, author,
                    availableText == "1"};

                if (books.find(id) != books.end())
                    throw LibraryException("Duplicate book ID in CSV.");

                books.emplace(id, book);
            }
            catch (const invalid_argument &)
            {
                throw LibraryException("Non-numeric book ID in CSV.");
            }
            catch (const out_of_range &)
            {
                throw LibraryException("Book ID is out of range.");
            }
        }
    }

    // Save all book records to CSV file.
    void saveToFile() const
    {

        ofstream file(filePath);

        if (!file)
            throw LibraryException("Unable to open CSV file.");

        file << "id,title,author,available\n";

        for (const auto &entry : books)
        {

            const Book &book = entry.second;

            file << book.id << ","
                 << book.title << ","
                 << book.author << ","
                 << (book.available ? 1 : 0)
                 << '\n';
        }

        if (!file)
            throw LibraryException("Error while saving data.");
    }

    // Validate book title and author.
    void validateBookText(
        const string &value,
        const string &fieldName) const
    {

        if (value.empty())
            throw InvalidBookData(fieldName + " cannot be empty.");

        if (value.find(',') != string::npos)
            throw InvalidBookData(
                fieldName + " cannot contain commas.");
    }

public:
    // Constructor loads existing book records.
    explicit Library(const string &path = "books.csv")
        : filePath(path)
    {

        loadFromFile();
    }

    // Add a new book.
    void addBook(const Book &book)
    {

        if (book.id <= 0)
            throw InvalidBookData(
                "Book ID must be a positive integer.");

        validateBookText(book.title, "Book title");
        validateBookText(book.author, "Author name");

        if (books.find(book.id) != books.end())
            throw DuplicateBookId(
                "A book with this ID already exists.");

        books.emplace(book.id, book);

        try
        {
            saveToFile();
        }
        catch (...)
        {
            books.erase(book.id);
            throw;
        }
    }

    // Search book using its ID.
    Book searchBook(int id) const
    {

        map<int, Book>::const_iterator it = books.find(id);

        if (id <= 0 || it == books.end())
            throw BookNotFound(
                "No book found with ID " +
                to_string(id) + ".");

        return it->second;
    }

    // Display all books.
    vector<Book> listBooks() const
    {

        vector<Book> result;

        result.reserve(books.size());

        for (const auto &entry : books)
            result.push_back(entry.second);

        return result;
    }

    // Issue a book.
    void issueBook(int id)
    {

        map<int, Book>::iterator it = books.find(id);

        if (id <= 0 || it == books.end())
            throw BookNotFound(
                "No book found with ID " +
                to_string(id) + ".");

        if (!it->second.available)
            throw BookUnavailable(
                "This book is already issued.");

        it->second.available = false;

        try
        {
            saveToFile();
        }
        catch (...)
        {
            it->second.available = true;
            throw;
        }
    }

    // Return an issued book.
    void returnBook(int id)
    {

        map<int, Book>::iterator it = books.find(id);

        if (id <= 0 || it == books.end())
            throw BookNotFound(
                "No book found with ID " +
                to_string(id) + ".");

        if (it->second.available)
            throw BookAlreadyAvailable(
                "This book is not currently issued.");

        it->second.available = true;

        try
        {
            saveToFile();
        }
        catch (...)
        {
            it->second.available = false;
            throw;
        }
    }
};

// ==================================================
// SECTION 4: INPUT AND DISPLAY FUNCTIONS
// ==================================================

// Read integer input safely.
int readInteger(const string &prompt)
{

    cout << prompt;

    string input;

    if (!getline(cin, input))
        return 0;

    try
    {

        size_t used = 0;

        int value = stoi(input, &used);

        if (used != input.size())
            throw InvalidInput(
                "Please enter a whole number only.");

        return value;
    }
    catch (const invalid_argument &)
    {
        throw InvalidInput(
            "Invalid input. Please enter a whole number.");
    }
    catch (const out_of_range &)
    {
        throw InvalidInput(
            "The entered number is too large.");
    }
}

// Read text input.
string readText(const string &prompt)
{

    cout << prompt;

    string value;

    if (!getline(cin, value))
        throw InvalidInput("Input was interrupted.");

    if (value.empty())
        throw InvalidBookData(
            "This field cannot be empty.");

    return value;
}

// Display book information.
void showBook(const Book &book)
{

    cout << "Book ID: " << book.id << '\n';
    cout << "Title: " << book.title << '\n';
    cout << "Author: " << book.author << '\n';

    cout << "Status: "
         << (book.available ? "Available" : "Issued")
         << '\n';
}

// Display main menu.
void showMenu()
{

    cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
    cout << "RAMESH KUMAR\n E25B0011202\n";
    cout << "1. Add book\n";
    cout << "2. Search book\n";
    cout << "3. List all books\n";
    cout << "4. Issue book\n";
    cout << "5. Return book\n";
    cout << "0. Save and exit\n";
}

// ==================================================
// SECTION 5: MAIN FUNCTION
// Controls the complete Library Management System.
// ==================================================

int main()
{

    try
    {

        Library library("books.csv");

        cout << "Library Management System\n";

        cout << "Book records loaded from books.csv "
             << "(if the file exists).\n";

        bool running = true;

        while (running)
        {

            try
            {

                showMenu();

                int choice = readInteger(
                    "Enter your choice: ");

                switch (choice)
                {

                // Add book.
                case 1:
                {

                    Book book;

                    book.id = readInteger(
                        "Enter book ID: ");

                    book.title = readText(
                        "Enter book title (no commas): ");

                    book.author = readText(
                        "Enter author name (no commas): ");

                    book.available = true;

                    library.addBook(book);

                    cout << "Book added and saved successfully.\n";

                    break;
                }

                // Search book.
                case 2:
                {

                    int id = readInteger(
                        "Enter book ID to search: ");

                    showBook(library.searchBook(id));

                    break;
                }

                // List all books.
                case 3:
                {

                    vector<Book> allBooks =
                        library.listBooks();

                    if (allBooks.empty())
                    {

                        cout << "No books found in the library.\n";
                    }
                    else
                    {

                        cout << "\n--- Book List ---\n";

                        for (size_t i = 0;
                             i < allBooks.size(); ++i)
                        {

                            cout << '\n';

                            showBook(allBooks[i]);
                        }
                    }

                    break;
                }

                // Issue book.
                case 4:
                {

                    int id = readInteger(
                        "Enter book ID to issue: ");

                    library.issueBook(id);

                    cout << "Book issued successfully.\n";

                    break;
                }

                // Return book.
                case 5:
                {

                    int id = readInteger(
                        "Enter book ID to return: ");

                    library.returnBook(id);

                    cout << "Book returned successfully.\n";

                    break;
                }

                // Exit program.
                case 0:
                {

                    running = false;

                    cout << "Exiting Library Management System. "
                         << "Data is saved.\n";

                    break;
                }

                // Handle invalid menu choice.
                default:

                    throw InvalidInput(
                        "Invalid menu choice. "
                        "Select a number from 0 to 5.");
                }
            }

            // Handle library-related exceptions.
            catch (const LibraryException &error)
            {

                cout << "Error: "
                     << error.what() << '\n';
            }
        }
    }

    // Handle errors while starting the application.
    catch (const LibraryException &error)
    {

        cerr << "Fatal library error: "
             << error.what() << '\n';

        return 1;
    }

    return 0;
}
