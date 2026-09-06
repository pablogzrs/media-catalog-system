# 🎬 Video Collection Management System

Interactive command-line system for managing and rating a collection of movies and series episodes, written in C++ with an inheritance-based class hierarchy.

## ✨ Features

- 📋 Print the full collection
- ⭐ Rate movies and episodes on a 1–5 scale
- 🔍 Filter by minimum rating
- 🎭 Filter by genre
- 📊 Running average per title, displayed to one decimal
- 🎯 Type-aware filtering between movies and episodes

## 🛠️ Technologies

- **Language:** C++
- **Paradigm:** Object-Oriented Programming
- **Concepts applied:**
  - Inheritance from an abstract base class
  - Base-class pointers in a `vector<Filme*>`
  - `dynamic_cast` for runtime type identification
  - Operator overloading (`<<`)
  - Pure virtual function
  - File handling (`ifstream`)
  - String manipulation (`stringstream`, `stoi`)

## 📁 Project Structure

```
.
├── main.cpp           # Entry point and menu loop
├── coleccion.h/cpp    # Collection container
├── filme.h/cpp        # Abstract base class
├── pelicula.h/cpp     # Derived class for movies
├── capitulo.h/cpp     # Derived class for episodes
└── video.txt          # Input data file
```

## 🏗️ Architecture

```
        Filme (abstract)
           ↑
    ┌──────┴──────┐
    |             |
Pelicula      Capitulo
    |             |
    └──────┬──────┘
           |
      Coleccion
```

- **`Filme`** — abstract base: `id`, `titulo`, `genero`, `duracion`, `vector<int> calificaciones`
- **`Pelicula`** — inherits from `Filme`, adds nothing
- **`Capitulo`** — inherits from `Filme`, adds `serie`, `temporada`, `episodio`
- **`Coleccion`** — owns a `vector<Filme*>` and drives all operations

### A note on the pure virtual function

`Filme` declares `virtual void funcionInutil() = 0;`. It has no behavior. It exists only to make `Filme` polymorphic so that `dynamic_cast` can be used when filtering by type.

This is a workaround, not a design choice. Because `operator<<` is a `friend` function it cannot be virtual, so printing has to be dispatched externally by type instead of by the objects themselves. The cleaner alternative would be a `virtual void imprimir(ostream&) const = 0;` in `Filme`, with `operator<<` delegating to it — that would give real dynamic dispatch and remove both the dummy function and the `dynamic_cast` calls. It is documented here rather than hidden.

## 🚀 Compilation and Execution

**Linux/macOS:**
```bash
g++ -o coleccion main.cpp coleccion.cpp filme.cpp pelicula.cpp capitulo.cpp
./coleccion
```

**Windows (MinGW/g++):**
```bash
g++ -o coleccion.exe main.cpp coleccion.cpp filme.cpp pelicula.cpp capitulo.cpp
coleccion.exe
```

## 📖 Usage

```
****** OPTIONS *****
Enter 1 to show complete collection
Enter 2 to rate a film
Enter 3 to filter by rating
Enter 4 to filter by genre
Enter 9 to exit
```

**Rate a title:** option `2` → enter the ID (e.g. `20190001`) → enter a rating from 1 to 5. Values outside that range are rejected.

**Filter by rating:** option `3` → choose movies (1), episodes (2), or all (3) → enter a minimum rating from 1 to 5.

**Filter by genre:** option `4` → choose content type → enter a genre (e.g. `drama`, `accion`, `scifi`).

## 📄 Data File Format

`video.txt` is parsed by field count: 4 fields make a movie, 7 make an episode. Lines with any other count are silently skipped.

**Movies (4 fields):**
```
ID,Title,Duration,Genre
```

**Episodes (7 fields):**
```
ID,Title,Duration,Genre,Series,Season,Episode
```

**Example:**
```
20190001,Inception,148,scifi
20160150-S02E01,Chapter One,50,drama,Six Feet Under,2,1
```

## 🔧 Technical Highlights

- Base-class pointers storing derived objects
- `dynamic_cast` for runtime type identification during filtering
- Field-count parser that chooses the class to instantiate
- Overloaded `<<` for both `Filme` and `Capitulo`
- `"SC"` returned as the average for titles with no ratings yet

## 🎓 Academic Context

**Course:** Object-Oriented Programming
**Institution:** ITESM

## 📝 Notes

Some segments were developed with AI assistance (Claude), documented in comments in the source:
- The `cargarArchivoCrearObjetos()` file parser
- Decimal formatting in `promedio()`
- Type conversion (`stoi`, `stod`)
