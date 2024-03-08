import sqlite3
import sys
import random
import time
import os

def clear_terminal():
    os.system('clear' if os.name == 'posix' else 'cls')

def display_flashcard(card):
    # Display the word on the screen
    print(f"Word: {card[1]}")

def display_definition(card):
    # Display the definition on the screen
    print(f"Definition: {card[2]}")

def get_user_input():
    # Wait for the user to press Enter
    input("Press Enter to continue...")

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
    all_flashcards = cursor.fetchall()

    # Initialize stack with all flashcards
    flashcard_stack = list(all_flashcards)

    # Clear the terminal
    clear_terminal()

    # Initialize statistical variables
    incorrect_answers = []
    rounds = 0
    start_time = time.time()

    # Display initial message
    print("Welcome to Flashcards Mode!")

    while flashcard_stack:
        # Increment the number of rounds
        rounds += 1

        # Display statistics at the beginning of each round
        print(f"\nRound {rounds}\n")

        # Shuffle the flashcards for each round
        random.shuffle(flashcard_stack)

        # Iterate through the flashcards in the current round
        for current_flashcard in flashcard_stack:
            # Display the flashcard
            display_flashcard(current_flashcard)

            # Wait for the user to press Enter
            get_user_input()

            # Display the definition
            display_definition(current_flashcard)

            # Get user input for the answer
            user_answer = input("Enter 'y' if you know the answer, 'n' otherwise: ")

            # Evaluate the user's answer
            correct_answer = evaluate_answer(True, user_answer.lower())  # Assume the correct answer is 'y'

            # Update statistics
            if not correct_answer:
                incorrect_answers.append(current_flashcard)

        # Display statistics at the end of each round
        print(f"\nEnd of Round {rounds} Summary:")
        print(f"Session Duration: {time.time() - start_time:.2f} seconds")
        print(f"Number of Incorrect Answers: {len(incorrect_answers)}\n")

        # Clear the stack for the next round
        flashcard_stack.clear()

        # Refill the stack with incorrect flashcards
        flashcard_stack.extend(incorrect_answers)

        # Clear the list of incorrect answers
        incorrect_answers.clear()

    # Calculate the session duration
    end_time = time.time()
    session_duration = end_time - start_time

    # Display final statistics
    print(f"\nSession Summary:")
    print(f"Number of Rounds: {rounds}")
    print(f"Session Duration: {session_duration:.2f} seconds\n")

    # Close the connection to the database
    connection.close()

if __name__ == "__main__":
    main()
