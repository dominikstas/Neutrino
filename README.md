# Neutrino - work in progress

Neutrino is a command-line tool designed to help (me) with (my) studies. It provides features such as creating, editing, and deleting  learning sets, as well as entering different learning modes.

## Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Learning Modes](#learning-modes)
- [Contributing](#contributing)
- [License](#license)

## Introduction

Neutrino aims to simplify the learning process by offering an organized way to manage sets of information. Whether you're studying for exams, learning new languages, or preparing for interviews, Neutrino has you covered.

## Features

- **Set Management**: Create, edit, and delete sets of information using database.
- **Learning Modes**: Choose between flashcards, exam mode, and test questions. (not finished yet)
- **Interactive Interface**: User-friendly command-line interface for a seamless experience.

## Getting Started

1. **Clone the Repository**

    ```bash
    git clone https://github.com/your-username/neutrino.git
    ```

2. **Build the Project**

    ```bash
    cd neutrino
    cmake .
    make
    ```

3. **Run Neutrino**

    ```bash
    ./Neutrino
    ```

## Usage

Neutrino supports various commands to perform different actions. Here are some basic commands to get you started:

- `help`: Display all available commands.
- `start [set]`: Begin learning with a specific set.
- `add`: Add a new learning set.
- `add-cards`: Add flashcards to a set.
- `ls`: List all created sets.
- `set`: Display the content of a set.
- `delete [set]`: Delete a learning set.

## Learning Modes

Neutrino will offer 3 learning modes to cater to different study preferences:
- flashcards
- exam
- quiz

## Technology

**C++:**
Neutrino is primarily developed in C++, utilizing the same terminal code that I employed in my Swallow app.

**SQLite3:**
SQLite3 is utilized to store users' learning sets, such as flashcards. It serves as the database management system for the application.

**Python:**
Python scripts play a crucial role in interacting with SQL databases. This choice is motivated by Python's simplicity and effectiveness in this domain compared to C++.

**CMake:**
CMake is implemented as the build system for Neutrino. It facilitates the generation of build files across various platforms and streamlines the compilation and linking processes of the project.
