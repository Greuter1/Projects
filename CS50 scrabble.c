#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// Uppercase letters
char upper [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

// Lowercase letters
char lower [] = "abcderghijklmnopqrstuvwxyz";

// Defines score used in the scoring function compute_score
int score = 0;

// Introduces the scoring function compute_score
int compute_score(string word);

int main(void)
{
    // Gets input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Scores both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Prints "Player 1 wins!" if score1 is greater than score2
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    // Prints "Player 2 wins!" if score1 is less than score2
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    // Prints "Tie!" if score1 is equal to score2
    else
    {
        printf("Tie!\n");
    }

}

// Scoring function
int compute_score(string word)
{
    // Resets the score
    score = 0;

    // Defines the length of the input word
    int length = strlen(word);

    // Iterates through each letter of the input word and sums their scores
    for (int i = 0; i < length; i++)
    {
        // Temporarily stores each letter in the input word
        char word_character = word[i];
        // Iterates through the items in the point and letter arrays
        for (int j = 0; j < 26; j++)
        {
            // Temporarily stores each upper case letter
            char upper_character = upper[j];

            // Temporarily stores each lower case letter
            char lower_character = lower[j];

            // Checks if the current letter of the word is the same as the current letter of the alphabet regardless of case
            if (word_character == upper_character || word_character == lower_character)
            {
                // Adds the corresponding point value for each letter to score
                score += POINTS[j];
            }
        }
    }
    // Returns score
    return score;
}
