import sqlite3
import os

#TO DO: REWORK
#IT WORKS, BUT HAS TOO MUCH BUGS

def add_flashcard(database_name):
    # Check if the database exists
    if not os.path.exists(f"../Sets/{database_name}.db"):
        print(f"The '{database_name}' set does not exist.")
        return

    try:
        # Connect to the database
        connection = sqlite3.connect(f"../Sets/{database_name}.db")
        cursor = connection.cursor()

        # Get flashcard details from the user
        name = input("Enter the name of the flashcard: ")
        definition = input("Enter the definition of the flashcard: ")

        # Insert the flashcard into the table
        cursor.execute("INSERT INTO uno (name, definition) VALUES (?, ?)", (name, definition))

        # Commit changes and close the connection
        connection.commit()
        connection.close()

        print("Flashcard added successfully.")
    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    try:
        # Ask the user for the name of the set
        database_name = input("Enter the name of the learning set: ")

        # Clear the terminal
        os.system('clear' if os.name == 'posix' else 'cls')

        while True:
            # Get flashcard details from the user and add to the set
            add_flashcard(database_name)

            # Ask the user if they want to add another flashcard
            try:
                # Clear the terminal
                os.system('clear' if os.name == 'posix' else 'cls')

                # Print the request for name and definition again
                print("Add flashcard to set: (click ctrl+c to)")
                print("Enter the name of the flashcard:")

                # Get the name from the user
                name = input()

                # Print the request for definition
                print("Enter the definition of the flashcard:")

                # Get the definition from the user
                definition = input()

                # Clear the terminal
                os.system('clear' if os.name == 'posix' else 'cls')

            except KeyboardInterrupt:
                # Exit on Ctrl+C
                print("\nExiting...")
                break

    except Exception as e:
        print(f"Error: {e}")
