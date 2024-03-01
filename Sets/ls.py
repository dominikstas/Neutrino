import os
import sqlite3

#to do: add cls

def display_set(set_name):
    sets_folder = "../Sets"
    set_path = os.path.join(sets_folder, f"{set_name}.db")

    # Check if the set file exists
    if os.path.exists(set_path):
        print(f"Contents of set '{set_name}':")

        # Connect to the database and retrieve flashcards
        try:
            connection = sqlite3.connect(set_path)
            cursor = connection.cursor()

            query = "SELECT name, definition FROM uno"
            cursor.execute(query)

            rows = cursor.fetchall()
            for row in rows:
                name, definition = row
                print(f"Name: {name}\nDefinition: {definition}\n")

            connection.close()
        except sqlite3.Error as e:
            print(f"Error: {e}")
    else:
        print(f"Error: Set '{set_name}' not found.")

# Test
set_name = input("Enter the name of the set you want to display: ")
display_set(set_name)
