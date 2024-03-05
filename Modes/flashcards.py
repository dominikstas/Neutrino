import sqlite3
import sys
import random
import time
import os

#to do: finish this

def clear_terminal():
    os.system('clear' if os.name == 'posix' else 'cls')

def display_flashcard(card):
    # Display the word on the screen
    print(f"Word: {card[1]}")

def display_definition(card):
    # Display the definition on the screen
    print(f"Definition: {card[2]}")
    user_input = input("Enter 'y' if you know the answer, 'n' otherwise: ")
    return user_input.lower()

def evaluate_answer(correct, user_answer):
    # Evaluate the user's answer
    return correct if user_answer == 'y' else not correct

def main():
    if len(sys.argv) < 2:
        print("Usage: python flashcards.py [setName]")
        return

    setName = sys.argv[1]
    
    # Connect to the database
    connection = sqlite3.connect(f"../Sets/{setName}.db")
    cursor = connection.cursor()

    # Fetch all flashcards from the database
    cursor.execute("SELECT * FROM uno")
    flashcards = cursor.fetchall()

    # Clear the terminal
    clear_terminal()

    # Initialize statistical variables
    incorrect_answers = []
    rounds = 0
    start_time = time.time()

    while flashcards:
        # Choose a random flashcard
        current_flashcard = random.choice(flashcards)

        # Display the flashcard
        display_flashcard(current_flashcard)
        input()

        # Display the definition
        display_definition(current_flashcard)

        # Evaluate the user's answer
        user_answer = display_flashcard(current_flashcard)
        correct_answer = evaluate_answer(True, user_answer)  # Assume the correct answer is 'y'

        # Update statistics
        if not correct_answer:
            incorrect_answers.append(current_flashcard)

        # Remove the used flashcard
        flashcards.remove(current_flashcard)

        # Increment the number of rounds
        rounds += 1

    # Calculate the session duration
    end_time = time.time()
    session_duration = end_time - start_time

    # Display statistics
    print(f"\nSession Summary:")
    print(f"Number of Rounds: {rounds}")
    print(f"Session Duration: {session_duration:.2f} seconds")
    print(f"Number of Incorrect Answers: {len(incorrect_answers)}")

    # Close the connection to the database
    connection.close()

if __name__ == "__main__":
    main()
