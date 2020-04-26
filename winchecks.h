#ifndef WINCHECKS_H
#define WINCHECKS_H

int win(Settings* settings, Logs* logs, char** board, int x, int y);
int checkRow(Settings* settings, Logs* logs, char** board, int x, int y);
int checkColumn(Settings* settings, Logs* logs, char** board, int x, int y);
int checkDiagonal(Settings* settings, Logs* logs, char** board, int x, int y);
int checkAntiDiagonal(Settings* settings, Logs* logs, char** board, int x, int y);
int traverse(int* x, int* y, int xChange, int yChange, Logs* logs, Settings* settings, char** board);
int withinBounds(Settings* settings, int x, int y);
#endif
