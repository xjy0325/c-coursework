# Singly Linked List (Playlist)

## Description
A playlist manager built on a singly linked list. It loads track titles from a file, prints them, inserts and deletes tracks, and saves the result back to a file.

## Features
- Load tracks from playlist.txt into a linked list
- Print the playlist
- Delete a node at a given index
- Insert a node at a given index
- Save the playlist to playlist-out.txt

## How to Run
Compile with: gcc main.c singly_linked_list.c -o main
Then run: ./main

## Concepts
- Singly linked lists
- Dynamic memory (malloc / free)
- File I/O
- Pointers and pointer-to-pointer

## Files
- main.c — main program
- singly_linked_list.c / singly_linked_list.h — list operations
- playlist.txt — input data