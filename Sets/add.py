import sqlite3
import os

#set = database

def create_database(database_name):
    # Check if a database with the given name already exists
    if os.path.exists(f"../Sets/{database_name}.db"):
        raise FileExistsError(f"The '{database_name}' set already exists.")
    
    # If it doesn't exist, create a new database
    connection = sqlite3.connect(f"../Sets/{database_name}.db")
    cursor = connection.cursor()
    
    # Add an table
    cursor.execute('''CREATE TABLE IF NOT EXISTS uno (
                        id INTEGER PRIMARY KEY,
                        name TEXT NOT NULL,
                        definition TEXT NOT NULL
                    )''')

    # Commit changes and close the connection
    connection.commit()
    connection.close()

if __name__ == "__main__":
    try:
        # Ask the user for the name of the new set
        database_name = input("Enter the name of the new learning set: ")
        create_database(database_name)
        print(f"'{database_name}' created successfully.")
    except Exception as e:
        print(f"Error: {e}")
