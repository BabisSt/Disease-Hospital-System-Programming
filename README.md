# Disease Hospital with System Programming

Uses lists, hashtables, and AVL trees to manage a hospital with patients.
It can print results if a query is given.

sdi1600278 Stevis Charalampos-Antonius
System Programming Assignment 1

After running `make`, the program can be executed with the following command:

`./diseaseMonitor -p data.txt -h1 10 -h2 10 -b 16`


The file from which we run is `data.txt`.
Note about the bucket size at the end of the README.

## Folder Structure:
The folder contains the following:

- **Makefile**: For compilation
- **SRC Folder**: Contains all `.c` files
  - `avl.c`, `date.c`, `hash.c`, `list.c`, `main.c`, `patient.c`
- **HEADERS Folder**: Contains all `.h` files
  - `avl.h`, `date.h`, `hash.h`, `list.h`, `patient.h`
- **BUILD Folder**: Contains all `.o` files after running `make` from the Makefile
- **TXT Folder**: Contains the text file from which patient data is read

## Description of Structures:

### PATIENT (`patient.h` / `patient.c`)
These files are responsible for reading a line from a file, initializing a patient, printing their data, and deleting the patient record.

### LIST (`list.h` / `list.c`)
These files handle the initialization, expansion, printing, and deletion of a list. There is also a feature to search for an element in the list (e.g., checking for duplicate `recordID`).

### DATE (`date.h` / `date.c`)
These files allow comparison between two dates. After accepting the dates, they split them and return the result based on the comparison:
- Returns -1 if `exitDate` is earlier or if `date2 > date1`
- Returns 1 if `date1 > date2`
- Returns 0 if both dates are equal

### AVL (`avl.h` / `avl.c`)
These files implement AVL trees. They handle initialization, printing, and deletion. Additionally, there are functions for inserting into the tree, inserting a node, creating new nodes, performing rotations to balance the tree, finding the height of the tree, and determining the number of nodes in the tree.

### HASH (`hash.h` / `hash.c`)
These files manage hash tables. Each hash table consists of hash buckets, and within each bucket, there is a `bucketarray` structure. The files support the initialization, deletion, and printing of hash tables, hash buckets, and bucket arrays. There is also a hashing function used for indexing. New buckets are inserted when the previous one is full.

### Queries:
The following queries are available within this file:
- **globalDiseaseStats**: Prints all patients for each disease. If dates are provided, it compares them and only prints the relevant results (this seems to work correctly).
- **diseaseFrequency**: Prints patients with a specific disease (this does not work correctly).
- **insertPatientRecord**: Creates a new patient and adds them to the list and both hash tables (`disease`, `country`) (this works correctly).
- **recordPatientExit**: Changes the `exitDate` of a patient (this works somewhat correctly).
- **numCurrentPatients**: Prints how many patients are still hospitalized (this does not work correctly).

### MAIN (`main.c`)
This file contains the main program. It opens and reads a file containing patient data (strings). It creates a list and two hash tables, storing the patients in both the list and the hash tables. Then, it enters a loop to process the input queries and calls the corresponding functions. Finally, it frees any allocated resources.

### Missing Implementations:
The assignment does not include an implementation of the heap and the queries that require it.
The `bucketsize` provided is fixed at 16. This is because the `bucketarray` structure is 16 bits. I tried using multiples of 16, but it didn't work correctly.

