
**Exercise: Standard Library Mastery Challenge**

### Problem Overview:
Create a program that manages a collection of books in a library. The library uses containers from the Standard Library, iterators, and ranges for efficient data manipulation and retrieval.

### Requirements:

1. **Define a Book class**:
    - Create a class `Book` with the following attributes:
        - `title` (string)
        - `author` (string)
        - `year` (integer)
        - `genre` (string)
    - Add a constructor to initialize these values.
    - Implement a method to display the book details in the format: `"Title by Author (Year) [Genre]"`.

2. **Library Class**:
    - Implement a class `Library` that manages a collection of `Book` objects.
    - Use `std::vector<Book>` to store the books.
    - Implement the following member functions:
        - `add_book(const Book& book)`: Adds a new book to the library.
        - `remove_book(const std::string& title)`: Removes a book from the library by title.
        - `find_book(const std::string& title)`: Searches for a book by title and returns it (if found) or prints an error message.
        - `get_books_by_author(const std::string& author)`: Returns a list of books by a specific author.
        - `get_books_by_genre(const std::string& genre)`: Returns a list of books that belong to a specific genre.

3. **Use Iterators**:
    - Demonstrate the use of iterators to traverse and display all books in the library.
    - Use a `std::vector<Book>::iterator` to iterate over the books in the container and print the book details.
    - Implement an iterator-based search function to find books by author.

4. **Use Ranges**:
    - Implement a function that filters books by year (e.g., books published after a certain year) using the ranges library.
    - Use `std::ranges::filter` to filter books based on genre.
    - Create a pipeline of operations to display books from a specific genre and sort them by year using `std::ranges::sort` and `std::ranges::transform`.

5. **Use Container Operations**:
    - Add books to the library.
    - Remove books using `erase()` and `remove_if()`.
    - Implement the ability to sort books by year in ascending or descending order.
    - Demonstrate the use of `std::find()` to locate books by title.

6. **Advanced Task (Optional)**:
    - Implement a **const iterator** to traverse the books without modifying them.
    - Demonstrate how to use **reverse iterators** to display the books in reverse order.

