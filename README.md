# Grade Management  
This is a basic grade management system for students.  

It allows the user to add years, semesters, and classes, each represented as an object.  

Additionally, it provides functionality to calculate the minimum and maximum grades, determine the average, and identify exams that need to be retaken—across all years, a specific year, or a semester within a year.  

## Features  
This program allows users to manage student grades efficiently. Key functionalities include:

### 🔹 Academic Structure Management  
- Add, edit, and delete **years, semesters, and subjects**.  
- Associate subjects with semesters and years dynamically.  

### 🔹 Grade Computation  
- Calculate **minimum and maximum grades** per semester, year, or overall.  
- Determine the **average grade** for any semester, year, or all years.  

### 🔹 Exam Retake Identification  
- Identify **exams that need to be retaken** based on failing grades.  
- Check retakes across **all years, a specific year, or a specific semester**.  

### 🔹 Data Handling & Memory Management  
- Delete all stored grades for a **year, semester, or the entire system**.  
- Prevent duplicate entries and handle invalid operations gracefully.  

## How to Use  
⚠ **WARNING:** To open the project, it is recommended to use the **Visual Studio IDE**.  
If you need the source files, they are located in the `GestiuneNote` folder.  

1. Clone the repository:  
   ```sh
   git clone https://github.com/CLuca27/Grade_Management.git
2. Open the GestiuneNote.sln file in Visual Studio from the Grade_Management folder.
3. The main function already contains predefined objects and method calls:
- The main class is GestiuneNote, where you can add year, semester, and class objects.
- Methods are available to calculate grades, identify retakes, and manage stored data.

