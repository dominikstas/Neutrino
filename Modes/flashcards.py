import sqlite3
import sys
import random
import time
import os

def clear_terminal() -> None:
    """Clear the terminal screen."""
    os.system('clear' if os.name == 'posix' else 'cls')

def display_flashcard(word: str) -> None:
    """Display the word on the screen."""
    print(f"Word: {word}")

def display_definition(definition: str) -> None:
    """Display the definition on the screen."""
    print(f"Definition: {definition}")

def wait_for_user() -> None:
    """Wait for the user to press Enter."""
    input("Press Enter to continue...")

def evaluate_user_answer(correct: bool, user_input: str) -> bool:
    """Evaluate the user's answer."""
    return correct if user_input == 'y' else not correct

def fetch_flashcards(cursor: sqlite3.Cursor) -> list[tuple]:
    """Fetch all flashcards from the database."""
    cursor.execute("SELECT * FROM uno")
    return cursor.fetchall()

def main() -> None:
    if len(sys.argv) < 2:
        print("Usage: python flashcards.py [setName]")
        return

    set_name = sys.argv[1]

    # Connect to the database
    try:
        connection = sqlite3.connect(f"../Sets/{set_name}.db")
        cursor = connection.cursor()
    except sqlite3.Error as e:
        print(f"Error connecting to database: {e}")
        return

    flashcards = fetch_flashcards(cursor)
    flashcard_stack = list(flashcards)

    clear_terminal()
    incorrect_answers = []
    rounds = 0
    start_time = time.time()

    print("Welcome to Flashcards Mode!")

    while flashcard_stack:
        rounds += 1
        print(f"\nRound {rounds}\n")
        random.shuffle(flashcard_stack)

        for card in flashcard_stack:
            display_flashcard(card[1])
            wait_for_user()
            display_definition(card[2])
            user_answer = input("Enter 'y' if you know the answer, 'n' otherwise: ").lower()
            correct = evaluate_user_answer(True, user_answer)

            if not correct:
                incorrect_answers.append(card)

        print(f"\nEnd of Round {rounds} Summary:")
        print(f"Session Duration: {time.time() - start_time:.2f} seconds")
        print(f"Number of Incorrect Answers: {len(incorrect_answers)}\n")

        flashcard_stack = incorrect_answers.copy()
        incorrect_answers.clear()

    session_duration = time.time() - start_time

    print(f"\nSession Summary:")
    print(f"Number of Rounds: {rounds}")
    print(f"Session Duration: {session_duration:.2f} seconds\n")

    connection.close()

if __name__ == "__main__":
    main()
