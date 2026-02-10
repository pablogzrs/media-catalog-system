# 🎬 Video Collection Management System

Interactive command-line system for managing and rating a collection of movies and series, developed in C++ using object-oriented programming.

## ✨ Features

- 📋 Complete collection visualization
- ⭐ Rating system for movies and episodes (1-5 scale)
- 🔍 Filter by minimum rating
- 🎭 Filter by genre
- 📊 Automatic rating average calculation
- 🎯 Differentiation between movies and series episodes

## 🛠️ Technologies

- **Language:** C++
- **Paradigm:** Object-Oriented Programming
- **Concepts applied:**
  - Inheritance and polymorphism
  - Dynamic memory with pointers
  - Operator overloading
  - Pure virtual functions
  - Dynamic cast for type identification
  - File handling (ifstream)
  - String manipulation (stringstream)

## 📁 Project Structure

```
.
├── main.cpp           # Entry point and main menu
├── coleccion.h/cpp    # Collection container class
├── filme.h/cpp        # Abstract base class
├── pelicula.h/cpp     # Derived class for movies
├── capitulo.h/cpp     # Derived class for episodes
└── video.txt          # Input data file
```

## 🏗️ Architecture

```
        Filme (abstract class)
           ↑
           |
    ┌──────┴──────┐
    |             |
Pelicula      Capitulo
    |             |
    └──────┬──────┘
           |
      Coleccion
```

### Main Classes

- **`Filme`**: Abstract base class with common attributes (id, title, genre, duration, ratings)
- **`Pelicula`**: Inherits from Filme, represents individual movies
- **`Capitulo`**: Inherits from Filme, adds series, season, and episode attributes
- **`Coleccion`**: Manages a vector of Filme pointers to store movies and episodes

## 🚀 Compilation and Execution

### Prerequisites
- C++ compiler compatible with C++11 or higher (g++, MinGW, MSVC, etc.)
- Operating system: Windows, Linux, or macOS

### Compile the project

**On Windows (MinGW/g++):**
```bash
g++ -o coleccion.exe main.cpp coleccion.cpp filme.cpp pelicula.cpp capitulo.cpp
```

**On Linux/macOS:**
```bash
g++ -o coleccion main.cpp coleccion.cpp filme.cpp pelicula.cpp capitulo.cpp
```

### Run

**Windows:**
```bash
coleccion.exe
```

**Linux/macOS:**
```bash
./coleccion
```

## 📖 Usage

When running the program, you'll see the following menu:

```
****** OPTIONS *****
Enter 1 to show complete collection
Enter 2 to rate a film
Enter 3 to filter by rating
Enter 4 to filter by genre
Enter 9 to exit
```

### Usage Examples

**1. Rate a movie:**
- Select option `2`
- Enter the film ID (e.g., `20190001`)
- Enter rating from 1 to 5

**2. Filter by rating:**
- Select option `3`
- Choose whether to see movies (1), episodes (2), or all (3)
- Enter minimum rating

**3. Filter by genre:**
- Select option `4`
- Choose content type
- Enter genre (e.g., `drama`, `accion`, `scifi`)

## 📄 Data File Format

The `video.txt` file must follow this format:

**For movies (4 fields):**
```
ID,Title,Duration,Genre
```

**For episodes (7 fields):**
```
ID,Title,Duration,Genre,Series,Season,Episode
```

### Example:
```
20190001,Inception,148,scifi
20160150-S02E01,Chapter One,50,drama,Six Feet Under,2,1
```

## 🔧 Technical Highlights

- **Polymorphism:** Use of base class pointers to store derived objects
- **Dynamic cast:** Runtime type identification
- **File reading:** Automatic parser that creates objects based on field count
- **Memory management:** Use of `new` for dynamic object creation
- **Operator overloading:** Custom `<<` operator for object printing

## 👨‍💻 Author

Developed myself as an academic project for Object-Oriented Programming course.

## 📝 Notes

Some code segments were developed with AI assistance (Claude AI) for:
- File parser implementation
- Decimal number formatting
- Data type conversion (stod, stoi)

These contributions are documented in comments within the source code.

---

⭐ If you found this project useful, consider giving it a star!
