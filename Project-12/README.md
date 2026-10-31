# 📚 Library Management System (C++)

A console-based Library Management System developed using C++. This project allows users to manage book records, search books, issue books and return books. It uses Object-Oriented Programming concepts, STL containers, CSV file handling and custom exception handling.

---

## 👨‍🎓 Student Information

* **Student Name:** Ramesh Kumar
* **URN:** E25B001202
* **Course:** B.Tech CSE
* **Subject:** Object-Oriented Programming (OOP)
* **Practical:** 12
* **Project:** Library Management System

---

## 🎯 Objective

The objective of this project is to develop a simple Library Management System that manages book records efficiently.

The system provides basic library operations and stores book information permanently using a CSV file. It also handles invalid inputs and library-related errors using custom exception handling.

---

## ✨ Features

1. **Add Book:** Add new books using Book ID, title and author name.
2. **Search Book:** Search for a book using its unique ID.
3. **List All Books:** Display all available and issued books.
4. **Issue Book:** Issue an available book.
5. **Return Book:** Return a previously issued book.
6. **CSV File Handling:** Save and load book records using `books.csv`.
7. **Input Validation:** Prevent invalid IDs, empty fields and non-numeric inputs.
8. **Exception Handling:** Handle duplicate IDs, unavailable books and unknown book IDs.
9. **Data Persistence:** Maintain book records even after the program is closed.

---

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Compiler:** MinGW GCC
* **C++ Standard:** C++17
* **IDE:** Visual Studio Code
* **File Storage:** CSV
* **STL Containers:** `map` and `vector`
* **Exception Handling:** Custom exception classes and `try-catch`

---

## 📂 Project Structure

```text
Practical-12-Library-Management-System/
│
├── main.cpp
├── books.csv
├── README.md
├── Sample_Input_Output.txt
├── UML_Class_Diagram.png
└── OOP_Practical_12_Document.docx
```

### File Description

| File                           | Description                         |
| ------------------------------ | ----------------------------------- |
| main.cpp                       | Complete C++ backend implementation |
| books.csv                      | Stores book records                 |
| README.md                      | Project documentation               |
| Sample_Input_Output.txt        | Actual sample inputs and outputs    |
| UML_Class_Diagram.png          | UML class diagram                   |
| OOP_Practical_12_Document.docx | Practical documentation             |

---

## 🧩 OOP Concepts Used

### 1. Classes and Objects

The `Library` class manages book records and provides functions for library operations.

### 2. Structures

The `Book` structure stores:

* Book ID
* Book Title
* Author Name
* Availability Status

### 3. Encapsulation

The `Library` class uses private data members and public member functions to manage book information.

### 4. STL Containers

* `map<int, Book>` stores books using their unique IDs.
* `vector<Book>` stores and returns book records for listing.

### 5. Exception Handling

Custom exceptions are used to handle errors safely.

The exception classes include:

* `LibraryException`
* `InvalidBookData`
* `InvalidInput`
* `DuplicateBookId`
* `BookNotFound`
* `BookUnavailable`
* `BookAlreadyAvailable`

### 6. File Handling

The `ifstream` and `ofstream` classes are used to read and write book records in `books.csv`.

---

## ⚙️ Installation and Execution

### Step 1: Install a C++ Compiler

Install MinGW GCC and make sure the compiler is accessible from your system.

### Step 2: Open Project Folder

Open the project folder in Visual Studio Code.

### Step 3: Open Terminal

Use:

```bash
Ctrl + `
```

### Step 4: Compile the Program

```powershell
& "C:\MinGW\bin\g++.exe" -std=c++17 main.cpp -o LibraryManagementSystem.exe
```

### Step 5: Execute the Program

```powershell
.\LibraryManagementSystem.exe
```

---

## 🖥️ Application Menu

```text
Library Management System
Book records loaded from books.csv (if the file exists).

===== LIBRARY MANAGEMENT SYSTEM =====
1. Add book
2. Search book
3. List all books
4. Issue book
5. Return book
0. Save and exit

Enter your choice:
```

---

## 🧪 Exception Handling and Test Cases

The following invalid inputs and error conditions are handled:

| Test Case                 | Expected Result                  |
| ------------------------- | -------------------------------- |
| Non-numeric Book ID       | Invalid input message            |
| Invalid menu choice       | Invalid menu choice message      |
| Duplicate Book ID         | Duplicate ID exception           |
| Unknown Book ID           | Book not found exception         |
| Negative Book ID          | Invalid Book Data exception      |
| Empty book title          | Empty field exception            |
| Empty author name         | Empty field exception            |
| Issue already issued book | Book unavailable exception       |
| Return available book     | Book already available exception |
| Title containing comma    | Invalid book data exception      |

For detailed test results, refer to `Sample_Input_Output.txt`.

---

## 💾 Data Storage

The application uses a CSV file named `books.csv` to store book records.

The file contains:

```text
id,title,author,available
101,The Alchemist,Paulo Coelho,1
102,Atomic Habits,James Clear,0
```

Availability values:

* `1` = Available
* `0` = Issued

Book records are loaded when the application starts and saved after successful book operations.

---

## 📊 UML Class Diagram

The UML class diagram represents the structure of the implemented system, including:

* Book structure
* Library class
* Program and helper functions
* LibraryException base class
* Derived custom exception classes
* Class relationships

Refer to `UML_Class_Diagram.png`.

---

## 📄 Practical Documentation

The practical document contains:

* Problem Statement
* Objective
* Theory
* Algorithm
* Source Code
* Sample Input and Output
* UML Class Diagram
* Result

Refer to `OOP_Practical_12_Document.docx`.

---

## ✅ Conclusion

The Library Management System successfully demonstrates Object-Oriented Programming concepts in C++. It provides basic book management operations, uses STL containers for record management, stores data using CSV file handling and handles invalid inputs through custom exception handling.

The project provides a simple and practical example of applying C++ programming concepts to a real-world library management problem.

---

**Developed by Ramesh Kumar**
**URN: E25B001202**
