#include <stdbool.h>
#include <stdlib.h>

int hash(int key, int size);

void add_value(int key, int value);

bool check_key_exists(int key);

int get_value(int key);

int remove_value(int key);