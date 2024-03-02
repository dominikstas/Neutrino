import sqlite3
import os


def add_flashcard(database_name):
    # Check if the database exists
    if not os.path.exists(f"../Sets/{database_name}.db"):
        print(f"The '{database_name}' set does not exist.")
        sys.exit()

    try:
        # Connect to the database
        connection = sqlite3.connect(f"../Sets/{database_name}.db")
        cursor = connection.cursor()

        while True:
            # Get flashcard details from the user
            name = input("Enter the name of the flashcard (or press Enter to finish): ")
            if not name:
                break  # Finish adding flashcards

            definition = input("Enter the definition of the flashcard: ")

            # Insert the flashcard into the table
            cursor.execute("INSERT INTO uno (name, definition) VALUES (?, ?)", (name, definition))
            print("Flashcard added successfully.")

        # Commit changes and close the connection
        connection.commit()
        connection.close()

    except Exception as e:
        print(f"Error: {e}")

if __name__ == "__main__":
    os.system('clear' if os.name == 'posix' else 'cls')
    try:
        # Get the name of the learning set
        database_name = input("Enter the name of the learning set: ")
        if not database_name:
            print("Set name cannot be empty.")
            sys.exit()

        # Check if the database exists
        if not os.path.exists(f"../Sets/{database_name}.db"):
            print(f"The '{database_name}' set does not exist.")
            sys.exit()

        # Clear the terminal
        os.system('clear' if os.name == 'posix' else 'cls')

        # Add flashcards to the set
        add_flashcard(database_name)

    except KeyboardInterrupt:
        # Exit on Ctrl+C
        print("\nExiting...")
        sys.exit()
    except Exception as e:
        print(f"Error: {e}")
        sys.exit()
