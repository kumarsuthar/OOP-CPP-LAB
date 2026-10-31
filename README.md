# OOP-CPP-LAB
# 💻 C++ Programming Practicals (1–12)

This repository contains C++ programming practicals designed to develop programming skills and understanding of object-oriented programming, memory management, templates, exception handling, file operations, and software design patterns.

---

## 👨‍🎓 Student Details

* **Name:** RAMESH KUMAR 
* **URN:** E25B001202
* **Branch:** Computer Science and Engineering (CSE)
* **Academic Year:** Second Year

## 📚 About the Repository

This repository contains C++ programs developed as part of the C++ Programming Practical course. Each practical focuses on a specific programming concept and includes implementation and sample output.

## 🛠️ Technologies Used

* **Programming Language:** C++
* **Compiler:** GCC / MinGW-w64
* **Code Editor:** Visual Studio Code
* **Version Control:** Git and GitHub

---

# 🔹 Practical 01 — C++ Fundamentals

## 🎯 Objective

To develop a basic understanding of C++ programming by working with variables, operators, conditional statements, and user input through a student marks evaluation program.

### 📝 Problem Statement

Develop a C++ program that accepts a student's name and marks in three subjects. Calculate the total and average marks, determine the student's result, and display suitable remarks for students with excellent performance or unsatisfactory results.

## 📖 Theory

C++ provides several fundamental features that help programmers perform calculations, process input, and make decisions.

* **Variables:** Store values that can be used and modified during program execution.
* **Data Types:** Define the kind of information a variable can hold, such as integers, decimal values, and text.
* **Constants:** Represent fixed values that should not change during execution.
* **Operators:** Perform arithmetic calculations and comparisons between values.
* **Conditional Statements:** Allow the program to execute different instructions depending on a condition.
* **Input and Output:** The `cin` and `cout` statements are used to receive input and display results.
* **Input Validation:** Checks whether the entered marks are within the permitted range.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-01.cpp`.

**Step 2:** Compile the program:

`g++ Practical-01.cpp -o student_marks`

**Step 3:** Run the executable:

`.\student_marks.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 02 — Classes, Access Specifiers and Member Functions

## ❓ Question

Create a C++ class representing a real-world object, such as a vehicle or bank account. Use appropriate data members, access specifiers, a constructor, and member functions to manage its information.

## 🎯 Objective

To understand how classes and objects organise data and functions into a single structure while controlling access to internal information.

## 📖 Theory

A class acts as a blueprint for creating objects. It defines the information an object stores and the operations that can be performed on that information.

### 🔐 Access Specifiers

* **Private:** Restricts direct access to class members from outside the class. This helps protect the object's internal data.
* **Public:** Makes selected members accessible through objects, allowing users to interact with the class.
* **Constructor:** Initialises an object when it is created.
* **Data Members:** Store the properties associated with an object.
* **Member Functions:** Define the operations that an object can perform.
* **Encapsulation:** Combines data and related functions within a class and controls how that data is accessed.

In this practical, a suitable class can be used to store information and demonstrate how its member functions operate on that information.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-02.cpp`.

**Step 2:** Compile the program:

`g++ Practical-02.cpp -o vehicle`

**Step 3:** Run the executable:

`.\vehicle.exe`

Alternatively, run the program using the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 03 — Constructors and Rule of Five

## ❓ Question

Implement a C++ class that demonstrates different constructors, assignment operators, and a destructor. Apply the Rule of Five to manage dynamically allocated resources safely.

## 🎯 Objective

To learn how objects are initialised, copied, moved, and destroyed when a class manages its own memory.

## 📖 Theory

Constructors and destructors control important stages in an object's lifetime. Copy and move operations determine how an object's resources are handled when another object is created or assigned.

### ⚙️ Types of Constructors and Special Member Functions

* **Default Constructor:** Creates an object without requiring arguments.
* **Parameterized Constructor:** Initialises an object using supplied values.
* **Copy Constructor:** Creates a new object by copying an existing object's contents.
* **Move Constructor:** Transfers resources from an existing object to a newly created object.
* **Copy Assignment Operator:** Copies data from one existing object into another.
* **Move Assignment Operator:** Transfers resources between existing objects.
* **Destructor:** Releases resources when an object reaches the end of its lifetime.

### 📌 Rule of Five

The Rule of Five applies when a class requires custom management of resources. It identifies five special member functions that may need to be defined together:

1. Destructor
2. Copy constructor
3. Copy assignment operator
4. Move constructor
5. Move assignment operator

Implementing these functions appropriately helps prevent memory leaks, double deletion, and incorrect resource ownership.

## ▶️ Compile/Run Instructions

**Step 1:** Save the program as `Practical-03.cpp`.

**Step 2:** Compile the program:

`g++ -std=c++17 Practical-03.cpp -o RuleFive`

**Step 3:** Execute the program:

`.\RuleFive.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 04 — RAII and Smart Pointers

## ❓ Question

Demonstrate resource management using `std::unique_ptr` and `std::shared_ptr`. Compare their ownership behaviour and investigate how automatic resource release helps prevent memory leaks.

## 🎯 Objective

To understand RAII and smart pointers and learn how C++ manages dynamically allocated objects without requiring manual memory cleanup in every situation.

## 📖 Theory

RAII stands for Resource Acquisition Is Initialization. It connects resource ownership to an object's lifetime so that resources can be released automatically when their owners are destroyed.

### 🧠 Important Concepts

* **RAII:** Associates resource management with object lifetime.
* **`std::unique_ptr`:** Provides exclusive ownership of an object. Another `unique_ptr` cannot independently share ownership of the same object.
* **`std::shared_ptr`:** Allows multiple smart pointers to share ownership of an object.
* **Automatic Destruction:** A smart pointer releases its managed object when its ownership ends.
* **Memory Leak:** Occurs when allocated memory is no longer accessible for proper release.
* **AddressSanitizer and Valgrind:** Tools that can help identify memory-management errors and leaks.

A `unique_ptr` is suitable when one owner controls a resource, while a `shared_ptr` is useful when multiple owners need to manage the same object.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-04.cpp`.

**Step 2:** Compile the program:

`g++ -std=c++14 Practical-04.cpp -o SmartPointers`

**Step 3:** Run the executable:

`.\SmartPointers.exe`

**Step 4:** If Valgrind is available in your environment, check for memory leaks:

`valgrind --leak-check=full ./SmartPointers`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 05 — Single and Multilevel Inheritance

## ❓ Question

Develop a university-management example using a class hierarchy consisting of `Person`, `Student`, and `GraduateStudent`.

## 🎯 Objective

To learn how inheritance establishes relationships between classes and allows derived classes to reuse the properties and functions of their base classes.

## 📖 Theory

Inheritance is an object-oriented programming mechanism that allows a new class to extend an existing class. It supports code reuse and helps represent relationships between different types of objects.

### 🧩 Types and Components of Inheritance

* **Base Class:** The class whose members are inherited by another class. Here, `Person` serves as the base class.
* **Derived Class:** A class that inherits members from another class. `Student` derives from `Person`.
* **Single Inheritance:** Occurs when one class inherits from a single base class, as in `Person → Student`.
* **Multilevel Inheritance:** Forms a sequence of inheritance relationships, such as `Person → Student → GraduateStudent`.
* **Constructors:** Initialise objects when they are created.
* **Display Functions:** Present the information stored in class objects.

The example demonstrates how personal information can be defined in a base class and extended with student and research-related information in derived classes.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-05.cpp`.

**Step 2:** Compile the program:

`g++ Practical-05.cpp -o Inheritance`

**Step 3:** Execute the program:

`.\Inheritance.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 06 — Runtime Polymorphism and Abstract Classes

## ❓ Question

Design an abstract `Shape` class and implement the `Circle`, `Rectangle`, and `Triangle` classes. Each derived class should provide its own implementation of the `area()` function.

## 🎯 Objective

To understand abstract classes, virtual functions, function overriding, and runtime polymorphism through the calculation of geometric areas.

## 📖 Theory

Polymorphism allows the same interface to produce different behaviour depending on the object that uses it.

### 🧠 Important Concepts

* **Abstract Class:** A class that cannot be instantiated directly because it contains at least one pure virtual function.
* **Virtual Function:** Enables a derived-class implementation to be selected through a base-class pointer or reference at runtime.
* **Pure Virtual Function:** A virtual function declared using `= 0`, requiring concrete derived classes to provide an implementation.
* **Function Overriding:** Allows a derived class to provide its own implementation of an inherited virtual function.
* **Runtime Polymorphism:** Selects the appropriate overridden function according to the actual object.
* **Virtual Destructor:** Supports correct destruction of derived objects when deleted through a base-class pointer.

In this practical, each shape calculates its area using its own formula while sharing the common `area()` interface.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-06.cpp`.

**Step 2:** Compile the program:

`g++ Practical-06.cpp -o Polymorphism`

**Step 3:** Run the executable:

`.\Polymorphism.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 07 — Compile-Time Polymorphism: Function and Operator Overloading

## ❓ Question

Write a C++ program that demonstrates function overloading and operator overloading by implementing addition operations for different numeric types and complex numbers.

## 🎯 Objective

To understand how C++ allows the same function name or operator to perform different operations according to the types and arguments involved.

## 📖 Theory

Compile-time polymorphism allows the compiler to determine which function or overloaded operator should be used during compilation.

### ⚙️ Important Concepts

* **Function Overloading:** Defines multiple functions with the same name but different parameter lists.
* **Operator Overloading:** Gives an existing operator additional behaviour for user-defined types.
* **Complex Number:** Contains a real component and an imaginary component.
* **Addition of Complex Numbers:** Adds the real components together and the imaginary components together.
* **Overloaded Functions:** Allow similar operations to be performed on different data types using a common function name.
* **Compile-Time Polymorphism:** Resolves overloaded function and operator calls during compilation.

For example, the `add()` function can accept integer or floating-point values, while the `+` operator can be implemented to add two complex-number objects.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-07.cpp`.

**Step 2:** Compile the program:

`g++ Practical-07.cpp -o Overloading`

**Step 3:** Execute the program:

`.\Overloading.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 08 — Factory Design Pattern

## ❓ Question

Implement the Factory Design Pattern in C++ to create different types of objects through a common interface. Explain its purpose and the advantages and limitations of using this pattern.

## 🎯 Objective

To understand how object creation can be separated from the code that uses the objects, making the program easier to organise and extend.

## 📖 Theory

Design patterns provide established approaches to recurring software design problems. The Factory Design Pattern focuses on creating objects without requiring the calling code to construct each concrete class directly.

### 🏗️ Important Concepts

* **Factory Design Pattern:** Encapsulates object creation behind a common creation method.
* **Abstract Base Class:** Defines the common interface that derived classes implement.
* **Derived Classes:** Provide different implementations of the shared interface.
* **Factory Class:** Decides which concrete object to create based on the requested type.
* **Smart Pointers:** Manage object ownership and automatically release resources.
* **Advantages:** Centralises object creation and reduces direct dependencies on concrete classes.
* **Trade-offs:** The factory introduces additional code and may need modification when new object types are added.

### ⚔️ Example: Weapon Factory

The program uses a common `weapons` interface with `sword` and `hammer` implementations. A `weaponFactory` creates the requested weapon through its `chooseWeapon()` function.

The calling code can use the returned object without directly managing the construction of each weapon class.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-08.cpp`.

**Step 2:** Compile the program:

`g++ -std=c++14 Practical-08.cpp -o FactoryPattern`

**Step 3:** Run the executable:

`.\FactoryPattern.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 09 — Generic Stack Using Templates

## ❓ Question

Create a generic Stack or Queue class using C++ templates. Test the implementation with integer, floating-point, and string values.

## 🎯 Objective

To explore generic programming and understand how a single class implementation can support multiple data types.

## 📖 Theory

Templates allow programmers to write reusable functions and classes without creating a separate implementation for each data type.

### 🧠 Important Concepts

* **Class Template:** Defines a class using a type parameter that can represent different data types.
* **Stack:** A linear data structure that follows the Last In, First Out (LIFO) principle.
* **Push Operation:** Inserts an element at the top of the stack.
* **Pop Operation:** Removes the element at the top of the stack.
* **Top Operation:** Returns access to the top element without removing it.
* **Empty Check:** Determines whether the stack contains any elements.
* **Generic Programming:** Allows the same implementation to work with different types.

### 🧪 Test Cases

* **Normal Operation:** Insert several elements and display the stack.
* **Integer Values:** Verify stack operations using `int`.
* **Floating-Point Values:** Test the stack using `float`.
* **String Values:** Store and retrieve `std::string` values.
* **Empty Stack:** Check that invalid operations are handled safely when the stack contains no elements.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-09.cpp`.

**Step 2:** Compile the program:

`g++ -std=c++11 Practical-09.cpp -o GenericStack`

**Step 3:** Execute the program:

`.\GenericStack.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 10 — Custom Exceptions: Banking Transaction

## ❓ Question

Develop a banking transaction program that defines custom exceptions and handles different withdrawal errors using `try`, `throw`, and `catch`.

## 🎯 Objective

To understand how exception handling can identify application-specific errors and prevent invalid transactions from modifying an account balance incorrectly.

## 📖 Theory

Exception handling provides a structured way to respond to runtime errors. Instead of allowing an error condition to pass unnoticed, the program can throw an exception and handle it appropriately.

### ⚠️ Important Concepts

* **Custom Exception:** A user-defined exception representing a specific application error.
* **`std::exception`:** A standard base class that can be inherited by custom exception types.
* **`throw`:** Signals that an exceptional condition has occurred.
* **`try`:** Encloses code that may throw an exception.
* **`catch`:** Handles an exception of a matching type.
* **Invalid Amount:** Represents a transaction amount that is zero or negative.
* **Insufficient Funds:** Indicates that the requested withdrawal exceeds the available balance.
* **Balance Validation:** Ensures that unsuccessful transactions do not incorrectly change the account balance.

The program tests successful withdrawals, withdrawals exceeding the available balance, and invalid withdrawal amounts.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-10.cpp`.

**Step 2:** Compile the program:

`g++ Practical-10.cpp -o Banking`

**Step 3:** Run the executable:

`.\Banking.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

# 🔹 Practical 11 — CSV Student Records Using File I/O

## ❓ Question

Create a C++ program that stores student information in a CSV file, reads the records back, and demonstrates the file-position functions `seekg()`, `seekp()`, `tellg()`, and `tellp()`.

## 🎯 Objective

To learn how file streams support persistent data storage and how file-position operations control reading and writing locations.

## 📖 Theory

File handling allows a program to preserve information beyond its execution. C++ provides stream classes for reading from and writing to files.

### 📂 Important Concepts

* **`ifstream`:** Opens files for input operations.
* **`ofstream`:** Opens files for output operations.
* **`fstream`:** Supports both input and output operations.
* **CSV Format:** Stores tabular information as text, with fields separated by commas.
* **`seekg()`:** Changes the input position in a file.
* **`seekp()`:** Changes the output position in a file.
* **`tellg()`:** Reports the current input position.
* **`tellp()`:** Reports the current output position.
* **File Validation:** Checks whether files open successfully and whether file operations complete correctly.

### 📝 Implementation Tasks

* Define a student record containing an ID, name, and marks.
* Write multiple student records to `students.csv`.
* Read the records and display them in a readable format.
* Demonstrate input-position operations using `seekg()` and `tellg()`.
* Demonstrate output-position operations using `seekp()` and `tellp()`.
* Verify the changes made to the output file.

## ▶️ Compile/Run Instructions

**Step 1:** Save the source code as `Practical-11.cpp`.

**Step 2:** Compile the program:

`g++ Practical-11.cpp -o CSVFileHandling`

**Step 3:** Execute the program:

`.\CSVFileHandling.exe`

Alternatively, use the C/C++ extension in Visual Studio Code.

---

---

# 🔹 Practical 12 — Library Management System Using OOP, STL, Exception Handling and File Handling

## ❓ Problem Statement

Develop a menu-driven Library Management System in C++ that allows users to add, search, display, issue, and return books. The system should use object-oriented programming concepts, STL containers, custom exception handling, input validation, and CSV file handling to manage book records efficiently.

## 🎯 Objective

To develop a practical understanding of object-oriented programming, Standard Template Library (STL), custom exceptions, and file handling by implementing a Library Management System.

## 📖 Theory

The Library Management System demonstrates how different C++ concepts can be combined to develop a real-world application.

### 🧠 Important Concepts

* **Structure (`struct`):** The `Book` structure stores book information, including ID, title, author, and availability status.
* **Class and Objects:** The `Library` class manages book records and provides functions to perform library operations.
* **Encapsulation:** Book management operations are organised within the Library class, keeping internal data private.
* **STL Map:** `map<int, Book>` stores book records using unique book IDs as keys.
* **STL Vector:** `vector<Book>` stores and returns a collection of book records for displaying the complete book list.
* **Custom Exception Handling:** User-defined exception classes handle errors such as invalid input, duplicate book IDs, missing books, and unavailable books.
* **File Handling:** `ifstream` and `ofstream` are used to read and write book records.
* **CSV File:** The `books.csv` file stores book information permanently so that records can be loaded when the application starts.
* **Input Validation:** Validates numeric input, book IDs, titles, author names, and menu choices.
* **Exception Handling:** Uses `try`, `throw`, and `catch` to handle runtime errors safely.

### ⚙️ Main Features

1. **Add Book:** Adds a new book using its ID, title, and author name.
2. **Search Book:** Searches for a book using its unique ID.
3. **List All Books:** Displays all available book records with their current status.
4. **Issue Book:** Changes a book's status from Available to Issued.
5. **Return Book:** Changes a book's status from Issued to Available.
6. **Save Records:** Automatically saves book information in the CSV file.
7. **Input Validation:** Prevents invalid menu choices and incorrect data entry.
8. **Custom Error Handling:** Displays meaningful error messages for invalid operations.

### ⚠️ Custom Exception Classes

The project implements the following custom exception classes:

* `LibraryException` — Base exception class for library-related errors.
* `InvalidBookData` — Handles invalid book information.
* `InvalidInput` — Handles incorrect user input.
* `DuplicateBookId` — Handles duplicate book IDs.
* `BookNotFound` — Handles searches or operations involving unknown book IDs.
* `BookUnavailable` — Handles attempts to issue an already-issued book.
* `BookAlreadyAvailable` — Handles attempts to return a book that is already available.

### 🧪 Test Cases

The application handles different valid and invalid operations.

| Test Case                    | Expected Behaviour                       |
| ---------------------------- | ---------------------------------------- |
| Add a new book               | Book added successfully                  |
| Add duplicate book ID        | Displays duplicate ID error              |
| Search existing book         | Displays book information                |
| Search unknown book ID       | Displays book not found error            |
| Enter non-numeric book ID    | Displays invalid input error             |
| Enter invalid menu choice    | Displays invalid menu choice error       |
| Issue an available book      | Book status changes to Issued            |
| Issue an already-issued book | Displays book already issued error       |
| Return an issued book        | Book status changes to Available         |
| Return an available book     | Displays book not currently issued error |
| Restart application          | Loads previously saved book records      |

## 🗂️ Project File Structure

```text
Project-12/
│
├── main.cpp
├── books.csv
├── README.md
├── Sample_Input_Output.txt
├── UML_Class_Diagram.png
└── OOP_Practical_12_Document_Final.docx
```

### 📌 UML Class Diagram

The UML Class Diagram represents the relationship between the Book structure, Library class, and custom exception hierarchy.

![UML Class Diagram](UML_Class_Diagram.png)

## ▶️ Compile/Run Instructions

**Step 1:** Open the `Project-12` folder in Visual Studio Code.

**Step 2:** Open the terminal and compile the program:

```bash
g++ -std=c++17 main.cpp -o LibraryManagementSystem.exe
```

**Step 3:** Run the executable:

```powershell
.\LibraryManagementSystem.exe
```

**Step 4:** Use the menu to perform library operations.

## 📋 Application Menu

```text
===== LIBRARY MANAGEMENT SYSTEM =====

1. Add book
2. Search book
3. List all books
4. Issue book
5. Return book
0. Save and exit

Enter your choice:
```

## 💾 Data Storage

The application uses `books.csv` to store book records.

The CSV file contains the following fields:

```text
id,title,author,available
```

* `id` — Unique book identification number.
* `title` — Name of the book.
* `author` — Author of the book.
* `available` — Book availability status (`1` for Available and `0` for Issued).

Book records are loaded when the application starts and saved whenever book information or availability changes.

## 🎓 Learning Outcomes

After completing this practical, the following concepts were implemented and understood:

* Object-Oriented Programming using classes and structures.
* Encapsulation and data management.
* STL containers such as `map` and `vector`.
* Custom exception classes and exception handling.
* File handling using CSV files.
* Input validation and error handling.
* Menu-driven application development.
* Persistent storage of application data.

---

## 🎓 Updated Conclusion

These twelve practicals cover the fundamentals of C++ programming and introduce important concepts used in software development. They provide hands-on experience with object-oriented programming, memory management, inheritance, polymorphism, design patterns, templates, exception handling, file operations, STL containers, and practical application development.

The final practical, Library Management System, combines multiple C++ concepts into a single menu-driven application with CSV-based data storage and custom exception handling.

The repository serves as a record of the practical exercises and programming concepts implemented throughout the course.

---

👨‍💻 **Maintained by:** Ramesh Kumar

📘 **Course:** C++ Programming Practicals
