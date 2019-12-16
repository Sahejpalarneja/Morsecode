//
// Created by sahejpal on 11/30/19.
//

#ifndef TRIAL_MORSE_H
#define TRIAL_MORSE_H

typedef struct Tree{
    char data;
    struct Tree *dot;
    struct Tree *dash;
} Tree;
Tree *NODE();
void preorder(Tree *root);
void assignDATA(Tree *root,char morse[],char data);
char decode(Tree *root,char morse[]);
void dictionary(char c);
void encode(char word[]);

#endif //TRIAL_MORSE_H
