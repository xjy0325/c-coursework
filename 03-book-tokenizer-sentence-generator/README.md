# FrankenText — Book Tokenizer & Sentence Generator

## Description
Reads the full text of Frankenstein by Mary Shelley, tokenizes it into words, and generates random sentences based on word-successor statistics.

## Features
- Tokenizes the entire book
- Builds a successor map for every token
- Generates random sentences until one ends with ? and one with !

## How to Run
Compile with: gcc main.c -o main
Then run: ./main

## Concepts
- String tokenization (strtok)
- Dynamic arrays and pointer arrays
- Text processing and randomized generation

## Files
- main.c — the program
- sentences generated.txt — sample generated sentences
- flowchart-Franktxt.drawio.png — program flowchart

## Note
Pair project — my contribution was around 15%.